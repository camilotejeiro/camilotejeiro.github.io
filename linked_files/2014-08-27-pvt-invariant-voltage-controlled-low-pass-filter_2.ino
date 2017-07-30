/**
 * This program implements a PID controller
 * to keep the cuttoff frequency of  a low
 * pass filter constant over PVT 
 * variations
 *
 * Project:
 * PVT Invariant Tunnable gm-C Filter
 * 
 * Author(s): Camilo Tejeiro
 *            Moise Nistrian
 *            __
             '_')
              \(---.
             ((_)___\
             // \\ \\
 */
 
/************* LIBRARY INCLUDES **********,=,e */
#include <avr/io.h>
#include <avr/interrupt.h>

/************** DEFINES *************,=,e */
/** pin used to turn an LED on to indicate calibrated state */
#define READYLEDPIN 2
/** pin used to turn an LED on to indicate busy state */
#define BUSYLEDPIN 3
/** digital pin used to input the VCO frequency into the uC */
#define FREQPIN 4
/** pin used to send digital serial data to the DAC */
#define DINPIN 5
/** pin used as the clock to the DAC */
#define SCKPIN 6
/** NCS / load pin used for the DAC */
#define LDPIN 7
/** digital pin used to isolate the calibration stage */
#define CALONPIN 8
/** pin used to isolate the input stage */
#define INPUTONPIN 9
/** pin used to monitor the timer Interrupt */
#define TIMEROUTPIN 10
/** analog pin used to read the analog desired frequency (voltage) by the user*/ 
#define SETPOINTPIN A5
/** analog pin used to read the peak voltage measured from the peak detector */
#define VPEAKPIN A4
/** control code to enable DACa */
#define DACAOUT 9
/** control code to enable DACb */
#define DACBOUT 10
/** define used to keep track of positive peaks for frequency measurement */
#define POSPEAK true
/** define used to keep track of negative peaks for frequency measurement */
#define NEGPEAK false
/** frequency used to calculate the dc gain of the filter */
#define TESTFREQ 11000

/******* Global Vars *******,=,e*/
/** vriable used to indicate when the timer finished counting */
boolean timer2Done = false;
/** global var used to store the frequency measurement */
float measuredFrequency = 0;
/** variable used to keep track of the newly desired frequency */
float currentSetPoint = 0;
/** variable used to keep track of the previous desired frequency */
float oldSetPoint = 0;
/** low pass filter cuttoff voltage */
float fcVoltage = 0;
/** current reading from the peak to peak detector */
float currentPeakVoltage = 0;
/** control variable used to modulate cuttoff*/
float gmcVControl = 2.5;
/** control variable used to modulate vcoFrequency */
float vcoVControl = 2.5;
/** variable to store current state of the state machine */
byte currentState = 0;
/** calculated desired frequency based on input setpoint voltage */
float desiredFrequency = 0;
/** error LED to flash when state machine works erroneoulsy */
boolean errorLedOn = false; 

/** real time binary search midpoint */
float midPoint = 2.5;
/** real time binary search minpoint */
float minPoint  = 0;
/** real time binary search maxpoint */
float maxPoint = 5;
/** create a float for error response */
float oldPeakVoltage = 0;
/** error var */
boolean errorCheck = false;

void setup() 
{
  // set the direction of the digital pins
  pinMode(TIMEROUTPIN, OUTPUT);
  pinMode(FREQPIN, INPUT);
  pinMode(CALONPIN, OUTPUT);
  pinMode(DINPIN, OUTPUT);  // set up pin 8 (mosfet pin) to output
  pinMode(SCKPIN, OUTPUT);
  pinMode(LDPIN, OUTPUT); 
  pinMode(READYLEDPIN, OUTPUT);
  pinMode(BUSYLEDPIN, OUTPUT);
  // set the direction of the analog pins
  pinMode(SETPOINTPIN, INPUT);
  pinMode(VPEAKPIN, INPUT);

  
  // set the initial value of the pins
  digitalWrite (CALONPIN, LOW);
  digitalWrite (DINPIN, LOW);
  digitalWrite (SCKPIN, LOW);
  digitalWrite (LDPIN, HIGH);
  digitalWrite (BUSYLEDPIN, LOW);
  digitalWrite (READYLEDPIN, LOW);
  
  /** make sure the timer2 is initialized to 0 and is not counting */
  TCCR2A = 0; 
  // set the entire TCCR2B register to 0    
  TCCR2B = 0; 

  // serial comm for debuggin purposes
  Serial.begin(9600);
}

void loop() 
{
  // this is the main switch statement describing the state machine
  switch (currentState)
  {
    case 0:
    {
      
      Serial.println("State A");
      // in this state setup calibration (turn on mosfet)
      setupCalibration();
      // initialize the GMC to 22.5 KHz (gmcVcontrol = 2.5V)
      gmcVControl = 2.5;
      // format and send to DACB
      setGMCVControl(gmcVControl);
      delay(1);
      // read the desired frequency
      currentSetPoint = (((float)analogRead(SETPOINTPIN)*5)/1023);
      Serial.println("setPoint is:");
      Serial.println(currentSetPoint);
      
      // calculate frequency from voltge and store in global
      recordDesiredFrequency (currentSetPoint);
      // go to next state
      currentState = 1;
      
      break;
    }
    case 1:
    {
      Serial.println("State B");
      vcoVControl = 2.5;
      // initialize the VCO so that it start oscillating
      setVCOVControl(vcoVControl);
      // go to next state
      currentState = 2;
      break;
    }
    case 2:
    {
      Serial.println("State C");
      // look at the output of the VCO and calculate frequency
      measuredFrequency = measureFrequency();
      if (measuredFrequency > (TESTFREQ + 50))
      {
        // if the frquency is to high go to state 3
       currentState  = 3; 
      }
      else if (measuredFrequency < (TESTFREQ - 50))
      {
        // if the frequency is to small go to state 4
        currentState = 4;
      }
      else
      {
        // if the frequency is correct go to state 5 and
        // reset the real time binary search variables
        minPoint = 0;
        midPoint = 2.5;
        maxPoint = 5;
        currentState = 5;
      }
      break;
    }
    case 3:
    {
      Serial.println("State D");
      /** this state deals with the upper half binary search */
      
      // eliminate everything above measured F
      // determine new max point and midpoint
      maxPoint = vcoVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      // set vcoVcontrol to the new midPoint
      vcoVControl = midPoint;
      
      // send the control voltage to the VCO
      setVCOVControl (vcoVControl);
      // go back to measure new frequency
      currentState = 2;
      break;
    }
    case 4:
    {
      Serial.println("State E");
      /** this state deals with the lower half binary search */
      
      // eliminate everything below measured F
      // determine new min voltage
      minPoint = vcoVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      vcoVControl = midPoint;
      
      // send the voltage to the vco
      setVCOVControl (vcoVControl);
      // go back to measure the frequency
      currentState = 2;
      break;
    }
    case 5:
    {
      Serial.println("State F");
      
      // at 11 kHz we are in the flat pass band read the
      // current peak from the peak detector
      currentPeakVoltage = (((float)analogRead(VPEAKPIN)*5)/1023);
      currentPeakVoltage = currentPeakVoltage*1.0521 + 0.802826;
      // calculate the 3 db point
      fcVoltage = currentPeakVoltage * 0.708;
      Serial.println("measured 3db voltage is:");
      Serial.println(fcVoltage);
      // now, go to next state
      currentState = 6;
      break;
    }
    case 6:
    {
      Serial.println("State G");
      // now set the VCO back to 2.5 volts to initialize
      // a new real time binary search
      vcoVControl = 2.5;
      setVCOVControl(vcoVControl);
      // now go to next state
      currentState = 7;
      break;
    }
    case 7:
    {
      Serial.println("State H");
      // read the frequency from the VCO
      measuredFrequency = measureFrequency();
      if (measuredFrequency > (desiredFrequency + 50))
      {
       // if the frequency is above that desired by the user go 
       // to state 8
       currentState  = 8; 
      }
      else if (measuredFrequency < (desiredFrequency - 50))
      {
        // if the frequency is below that desired by the user
        // go to state 9
        currentState = 9;
      }
      else
      {
        // if the frequency is right on go to state 10 &
        // reset the real time binary search variables
        minPoint = 0;
        midPoint = 2.5;
        maxPoint = 5;
        currentState = 10;
      }
      break;
    }
    case 8:
    {
      Serial.println("State I");
      /** this state deals with the upper half binary search */
      
      // eliminate everything above measured F
      // determine new max point and midpoint
      maxPoint = vcoVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      // set vcoVcontrol to the new midPoint
      vcoVControl = midPoint;
      
      // send the control voltage to the VCO
      setVCOVControl (vcoVControl);
      // go back to measure new frequency
      currentState = 7;
      break;
    }
    case 9:
    {
      Serial.println("State J");
      /** this state deals with the lower half binary search */
      
      // eliminate everything below measured F
      // determine new min voltage
      minPoint = vcoVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      vcoVControl = midPoint;
      
      // send the voltage to the vco
      setVCOVControl (vcoVControl);
      // go back to measure new frequency
      currentState = 7;
      break;
    }
    case 10:
    {
      Serial.println("State k");
      
      // now read the peak voltage from the analog peak to peak detector
      //currentPeakVoltage = (((float)analogRead(VPEAKPIN)*5)/1023);
      //oldPeakVoltage = currentPeakVoltage;
      
      for (int i = 0 ; i < 500 ; i++)
      {
        currentPeakVoltage += (((float)analogRead(VPEAKPIN)*5)/1023);
        delayMicroseconds(10);
      }
      
      currentPeakVoltage = currentPeakVoltage/500;
      currentPeakVoltage = currentPeakVoltage*1.0521 + 0.802826;
      
      Serial.println("measured peak Voltage:");
      Serial.println(currentPeakVoltage);
      

      if (currentPeakVoltage > (fcVoltage + 0.1))
      {
        // if the voltage is more than the calculated 3db
        // go over to state 11
        currentState = 11;
      }
      else if (currentPeakVoltage < (fcVoltage - 0.1))
      {
        //if the voltage is less than the measured 3 db
        // go over to state 12
        currentState = 12;
      }
      else
      {
        // if the voltage is right on, proceed to state 13 &
        // reset the real time binary search variables
        minPoint = 0;
        midPoint = 2.5;
        maxPoint = 5;
        currentState  = 13;
      }
      
      break;
    }
    case 11:
    {
      Serial.println("State L");
      /** this state deals with the upper half binary search */
      
      // eliminate everything above measured F
      // determine new max point and midpoint
      maxPoint = gmcVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      // set gmcVcontrol to the new midPoint
      gmcVControl = midPoint;
      // send the control voltage to the VCO
      setGMCVControl (gmcVControl);
      // go back to measure new frequency
      currentState = 10;
      break;
    }
    case 12:
    {
      Serial.println("State M");
      /** this state deals with the lower half binary search */
      
      // eliminate everything below measured F
      // determine new min voltage & midpoint
      minPoint = gmcVControl;
      midPoint = (((maxPoint - minPoint)/2) + minPoint);
      gmcVControl = midPoint;
      
      // send the voltage to the vco
      setGMCVControl (gmcVControl);
      // go back to measure new frequency
      currentState = 10;
      break;
    }
    case 13:
    {
      Serial.println("State N");
      
      /** the system is calibrated turn everything back to initial state */
      vcoVControl = 2.5;
      // turn off the VCO
      setVCOVControl(vcoVControl);
      // store the old set point value
      oldSetPoint = currentSetPoint;
      // stop the calibration path
      // open the calibration switch. close the input signal switch
      stopCalibration();
      // go to state 14
      currentState = 14;
      break;
    }
    case 14:
    {
      Serial.println("State O");
      // measure current set point
      currentSetPoint = (((float)analogRead(SETPOINTPIN)*5)/1023);
      Serial.println("case 8: new control voltage");
      Serial.println(currentSetPoint);
      // compare it with old set point to decide if system needs to
      // be recalibrated
      if (currentSetPoint > (oldSetPoint + 0.10) || currentSetPoint < (oldSetPoint - 0.10))
      {
        // if system needs to be recalibrated go back to state 0;
        currentState = 0;
      }
      break;
    }
    default:
    {
      // there is an issue should not have gotten here!!!
      // make sure to fix the error!
      if (errorLedOn == false)
      {
        digitalWrite(13, HIGH);
        errorLedOn = true;
      }
      else
      {
        digitalWrite(13, LOW);
        errorLedOn = false;
      }
      break;
    }
  }
  delay(1000);
}

void setupCalibration()
{
  // here is the code that opens the input signal switch
  // and closes the calibration signal switch
  digitalWrite (INPUTONPIN, LOW);
  delay(1);
  digitalWrite (CALONPIN, HIGH);
  
  digitalWrite (BUSYLEDPIN, HIGH);
  digitalWrite (READYLEDPIN, LOW);
}
void stopCalibration()
{
  // here is the code that opens the calibration switch and
  // closes the input signal switch
  digitalWrite (CALONPIN, LOW);
  delay(1);
  digitalWrite (INPUTONPIN, HIGH);
  
  digitalWrite (BUSYLEDPIN, LOW);
  digitalWrite (READYLEDPIN, HIGH);
}
void recordDesiredFrequency (float setPointVoltage)
{
  // linear equation to calculate frequency from setpoint
  desiredFrequency = 3000*setPointVoltage + 15000; 
  Serial.println("desired frequency:");
  Serial.println(desiredFrequency); 
}
void setGMCVControl(float desiredVoltage)
{
  // convert the desired voltage into a digital value and send to DAC A
  unsigned int gmcDigitalValue = (unsigned int)((desiredVoltage*1023)/5);
  sendToDAC(DACBOUT, gmcDigitalValue);  
}
void setVCOVControl(float desiredVoltage)
{
  // convert the desired voltage into a digital value and send to DAC B
  unsigned int vcoDigitalValue = (unsigned int)((desiredVoltage*1023)/5);
  sendToDAC(DACAOUT, vcoDigitalValue);
}

void sendToDAC(unsigned int dacControl, unsigned int digitalValue)
{
  // local variables used to define needed bitwise shifts and 
  // current bits after masking
  unsigned int currentBit = 0;
  unsigned int controlShift =3;
  unsigned int dataShift = 13;
  
  // set the SCK line low 
  digitalWrite (SCKPIN, LOW);
  delayMicroseconds (1);
  
  // set load low indicating the start of a word to the DAC
  digitalWrite (LDPIN, LOW);
  delayMicroseconds (1);
  
  // a word is 16 bit long so a for loop will go bit by bit
  for (int i = 0 ; i < 16 ; i++)
  {
    // everytime we have to turn the clock low after each bit 
    // is clocked on the positive edge
    digitalWrite(SCKPIN, LOW);
    delayMicroseconds(5);
    
    if ( i < 4)
    {
      // this code inputs the control code into the dac
      currentBit = ((dacControl >> (controlShift -i)) & 1);
      digitalWrite(DINPIN, currentBit);
      delayMicroseconds(1);
      digitalWrite (SCKPIN, HIGH);
      delayMicroseconds (5);
    }
    else if (i >= 4 && i < 15)
    {
      // this code inputs the data (digital value) into the dac
      currentBit = ((digitalValue >> (dataShift -i)) & 1);
      digitalWrite(DINPIN, currentBit);
      delayMicroseconds(1);
      digitalWrite (SCKPIN, HIGH);
      delayMicroseconds (5);
    }
    else
    {
      // this code inputs the dont care last two bits into the dac
      digitalWrite(DINPIN, LOW);
      delayMicroseconds (1);
      digitalWrite(SCKPIN, HIGH);
      delayMicroseconds (5);
    }
  }
  
  // after the for loop is over take SCK low
  digitalWrite (SCKPIN, LOW);
  delayMicroseconds (5);
  // and put the load line high to indicate to the dac that the values
  // are correct
  digitalWrite(LDPIN, HIGH);
  
}
float measureFrequency()
{
  // temp variable used to count the ticks for the frequency measurement
  int frequencyCounter = 0;
  // temp variable used to store the value of the old tick for frequency
  boolean squareOldTick = false;
  // variable used to store the value of the new tick for frequency 
  boolean squareNewTick = false;
  // variable used to store temporary frequency calculation
  float tempFrequency = 0;
  // enable the timer t run
  enableTimer(234);
  // delay until it starts 
  delayMicroseconds(2);
  
  // start counting ticks
  while (timer2Done == false )
  {
    // check whether it was a positive or a negative peak
    if (digitalRead(FREQPIN)!= 0)
    {
      squareNewTick = POSPEAK;
    }
    else
    {
      squareNewTick = NEGPEAK;
    }
    
    if (squareOldTick != squareNewTick)
    {
      // if the tick is deifferent than before count it and increment
      // frequency counter, store new tick
      frequencyCounter++;
      squareOldTick = squareNewTick;
    } 
  }
  // we are done with the frequency measurement turn off the counter
  disableTimer();
  // reinitialize the timerDone flag
  timer2Done = false;
  
  // calculate the computed frequency 
  tempFrequency = ((float)(frequencyCounter)/2)/(0.01504);
  
  //display it serially for debugging purposes
  Serial.println(tempFrequency);

  return tempFrequency;
}
void enableTimer(int timeCounts)
{ 
  // Disable Interrupts
    cli();   
    
    // set the entire TCCR2A register to 0
    TCCR2A = 0;
    
    // set the entire TCCR2B register to 0    
    TCCR2B = 0; 

    // prescaler set to 1024
    TCCR2B = TCCR2B | B00000111;    // CS22 and CS21 set to 1
    // CTC mode chosen
    TCCR2A = TCCR2A | B00000010;    // WGM21 set to 1 
    
        
    // OCCR2A is the compare match register
    // set it to 124
    // from time = resolution * (timercounts + 1)
    OCR2A = timeCounts;

    // enable timer compare interrupt:
    TIMSK2 = TIMSK2 | B00000010;
    // enable global interrupts:
    sei();
  
  
}
void disableTimer()
{
    // Disable Interrupts
    cli();   
    
    // set the compare match register to 0
    OCR2A = 0;
    
    // set the entire TCCR2A register to 0
    TCCR2A = 0;
    
    // set the entire TCCR2B register to 0    
    TCCR2B = 0; 
    

    
    // enable timer compare interrupt:
    TIMSK2 = TIMSK2 & B11111101;
    
    // enable global interrupts:
    sei();
    
}
 
ISR(TIMER2_COMPA_vect)
{
    // interrupt service routine for timer 2 when the compare flag is set
    if (timer2Done == false)
    {
      // we are done counting set the flag
      timer2Done = true;
    }
    // flip a digital output for troubleshooting purposes
    digitalWrite(TIMEROUTPIN, !digitalRead(TIMEROUTPIN));
}
