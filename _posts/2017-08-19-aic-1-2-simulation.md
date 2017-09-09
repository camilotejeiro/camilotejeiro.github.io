---
title: 'AIC-1.2: Simulation -- SPICE Simulations with NGSPICE'
---

## 1. The Common-Emitter Amplifier

### Schematic Diagram

![Common Emitter Amplifier Schematic](/linked_files/2017-08-19-aic-1-2-simulation_1.svg)

### SPICE Simulations 

#### Operating point Analysis

Here, we are calculating DC voltages (bias voltages) at every node 
under no input source.

i.e. DC analysis with Vin = 0V (capacitors opened, inductors shorted).

Relevant source code lines:
~~~
OP                      
print all               
print (n1-n2)       ; vbe bias point.
~~~

**Results:** node DC voltages. 

~~~
Node       Voltage
----       -------
n_pos           12
n_in             0
n1         2.07461
n_out      7.00346
n2         1.29397
(n1-n2)    .780638
~~~

_Note a DC operating point analysis is always performed before transient or 
AC analyses, thus we did not really need to perform this analysis excplicitly,
it was done for instructional/learning purposes._

#### Transient Analysis

The transient analysis was performed over a time-length of 2mS (tstop) with steps 
(sample points) every 10nS (tsep).

An AC voltage source was used as the input signal: simple sinusoid with 0V offset, 
1Vpeak amplitude and 1KHz frequency.

We are plotting the output voltage at "net out" (n\_out), the input voltage at
"net in" (n\_in), and the voltage at "net1" (n1) after AC coupling.

Relevant source code lines:
~~~
V2   n_in 0  dc 0 ac 1.0 sin(0 1 1KHz)

TRAN 10nS 2mS

gnuplot $filename n_out n_in n1 title $title xlabel $xlabel ylabel $ylabel 
~~~

![Common Emitter Amplifier Simulation Transient](/linked_files/2017-08-19-aic-1-2-simulation_2.svg)

#### DC Analysis

In our DC analysis, we are measuring the DC output voltage dependence over 
power supply variations (over a DC sweep).

We are applying a DC sweep to our supply voltage (V1) from 0 to 12V in 0.1V
increments. 

We are plotting the DC output voltage at "net out" (n\_out) vs supply voltage
(V1).

Relevant source code lines:
~~~
DC V1 0 12 0.1

gnuplot $filename n_out title $title xlabel $xlabel ylabel $ylabel 
~~~

![Common Emitter Amplifier Simulation DC](/linked_files/2017-08-19-aic-1-2-simulation_3.svg)

#### AC Analysis

In our AC analysis, we are performing a logarithmic sweep with decade scaling 
(decade variation) with 10 points per decade. The frequency sweep goes from
0.01Hz to 1KHz.

We are computing the transfer function for the circuit, to calculate the gain of
the amplifier, and phase shift at different frequencies.

We are plotting:

* The transfer function magnitude in a linear scale: i.e. the gain of the 
    circuit in V/V.

* The transfer function magnitude in a logarithmic (dB) scale: i.e. the gain of
    the circuit in dB.

* The transfer function phase in degrees: i.e. the phase shift of the output
    voltage waveform with respect to the input.

Relevant source code lines:
~~~
AC dec 10 0.01Hz 1KHz  ; Parametters: dec(log sweep), 10 pts/dec, 0.01->100Hz 

gnuplot $filename mag(n_out/n_in) title $title xlabel $xlabel ylabel $ylabel 

gnuplot $filename db(n_out/n_in) title $title xlabel $xlabel ylabel $ylabel 

gnuplot $filename phase(n_out/n_in)*180/pi title $title xlabel $xlabel ylabel $ylabel 
~~~

![Common Emitter Amplifier Simulation AC Magnitude Linear](/linked_files/2017-08-19-aic-1-2-simulation_4.svg)

![Common Emitter Amplifier Simulation AC Magnitude dB](/linked_files/2017-08-19-aic-1-2-simulation_5.svg)

![Common Emitter Amplifier Simulation AC Phase](/linked_files/2017-08-19-aic-1-2-simulation_6.svg)

### Circuit Description (mostly a sanity check)

Let's start with a quick qualitative analysis. From a Common-emitter Amplifier circuit topology we
should expect:

* We have an AC coupled input to the CE amplifier, thus we should
    expect a signal shifted "up" from 0V to the voltage at n\_1 (our bias voltage
    for Q1, more on this later).
    > Check.

* A CE amplifier is an inverting amplifier, thus we should expect an amplified
    and inverted output waveform (and accordingly a 180 degrees phase shift at the 
    output w.r.t the input).
    > Makes sense: we can see this both from the transient analysis plot and 
    > the AC analysis phase transfer function plot, check.

* As we sweep our supply voltage from 0 to 12V. Initially our transistor is OFF, 
    there should be no current flow (our transistor is an "open" at this
    point) and we should expect to see our output voltage tracking our supply
    voltage (at least until our transistor turns ON, more on this later).
    > OK, we can see this in our DC sweep plot: a 1 to 1 slope initially,
    > check.

* In our AC analysis, we should see no gain initially (input capacitor is open
    at DC), and an increase in gain as we raise the frequency until our gain
    figure settles into a constant factor (at high frequency our capacitor is a 
    short), furthermore we should see a phase shift of -180 degrees as this is
    an inverting amplifier (also mentioned above).
    > Check and check.

OK, From a very quick qualitative analysis, our intuition agrees with our
simulation results, but let's calculate our node voltages at Vin = 0V just to make 
sure our operating point results are correct.  

Our base voltage (i.e. the voltage at n\_1) is just a voltage divider (not
quite, minus a little bit due to our base current, but more on this later)

~~~
Vn_1 = 12V * (R2 / (R1 + R2))
     = 12V * (24KR / 124KR) 
     = 12V * 0.193 
     = 2.32V 
~~~

Our emitter voltage (i.e. n\_2), should be our base voltage minus about ~0.65V,
i.e:

~~~
Vn_2 = Vn_1 - 0.65V
     = 2.32V - 0.65V
     = 1.67V
~~~

Now given our emitter resistor R4, we can calculate the current through our
transistor (collector to emitter) and R3, mainly: 

~~~
I_qc = Vn_2 / R4
     = 1.67V / 1KR
     = 1.67mA
~~~

Now, let's talk about the base current. Given a generic discrete NPN BJT 
we can assume it will have a (beta) current gain (Ic/Ib) of about 100. Thus we can
calculate how much bias base current will go into our transistor: 

~~~
I_qb = I_qc / beta
     = I_qc / 100
     = 1.67mA / 100
     = 16.73uA
~~~

Now this will reduce our bias voltage at n\_1 a little bit. Given our branch
current through R1 and R2 of:

~~~

I_r2 = 12V / (R1 + R2)
     = 12V / 124KR 
     = 96.77uA 
~~~

Minus our base current, we will have an actual current through R2 of:

~~~
I_r2 = 96.77uA - 16.73uA
     = 80.05uA
~~~

And a bias voltage at the base (i.e. at n\_1):

~~~
Vn_1 = I_r2 * R2
     = 80.05uA * 24KR
     = 1.92V
~~~

Now, we can repeat the process to calculate our emitter voltage (at n\_2), and
our collector current:

~~~
Vn_2 = Vn_1 - 0.65V
     = 1.92V - 0.65V
     = 1.27V
~~~

~~~
I_qc = Vn_2 / R4
     = 1.27V / 1KR
     = 1.27mA
~~~

And given our collector current we can calculate the voltage drop through R3 and 
our output voltage Vn\_out:

~~~
Vn_out = 12V - (I_qc * R3)
       = 12V - (1.27mA * 3.9KR)
       = 7.04V 
~~~

Thus our DC analysis (at Vin = 0V) i.e. our hand calculated operating point figures 
are as follows:

~~~
Vn_1   = 1.92V
Vn_out = 7.04V
Vn_2   = 1.27V
~~~

And these figures are rather close for our purposes. 

**Thus our analyses of what the circuit should do and what the circuit 
actually does in our simulation are in agreement -- that's a good thing.**


### Source code

**ce\_amplifier\_simulation\_testbench.spice**

~~~
Common-Emitter Amplifier Simulation 

.INCLUDE ce_amplifier_simulation_netlist.spice

* Circuit Elements: Simulation Sources.
* V2: AC input source with sinusoid (0V offset, 1Vpeak amplitude and 1KHz frequency)		
* dev   <nets>  <values>
* -------------------------- 
V2      n_in 0  dc 0 ac 1.0 sin(0 1 1KHz)

* Interactive simulation main entry *
* Note: which plotter are we using? 
*   * plot (for quick interactive plots during simulation)
*       - remember to remove filename from plot command (we are not writing a file) 
*   * gnuplot (for pint-quality lab report plots)
*       - remember to add a filename to gnuplot command (we are writing a file)
.CONTROL

* Make a directory for our output simulation files.
shell mkdir -p results 
* Generic prefix for our output files
set generic_prefix = 'results/ce_amplifier_simulation'

echo  '* Operating point analysis '

OP                      
print all               
print (n1-n2)                   ; vbe bias point.

echo '* Transient analysis '

TRAN 10nS 2mS                   ; Parametters: tstep, tstop.

set title = 'Transient Analysis' 
set xlabel = 'Seconds (S)'
set ylabel = 'Voltage (V)'
set filename = {$generic_prefix}{'_transient_analysis'}
gnuplot $filename n_out n_in n1 title $title xlabel $xlabel ylabel $ylabel 

echo '* DC analysis'

DC V1 0 12 0.1          ; Sweep vcc from 0v to 12v in 0.1v increments.

set title = 'DC Analysis' 
set xlabel = 'Supply Volage (V)'
set ylabel = 'Output Voltage (V)'
set filename = {$generic_prefix}{'_dc_analysis'}
gnuplot $filename n_out title $title xlabel $xlabel ylabel $ylabel 

echo '* AC analysis'

AC dec 10 0.01Hz 1KHz  ; Parametters: dec(log sweep), 10 pts/dec, 0.01->100Hz 

* Plot the Transfer Function (magnitude in linear scale).
* Results are all Vpeak values centered around 0 (i.e. ac coupled).
set title = 'AC Analysis: Transfer Function (Vout/Vin) Magnitude' 
set xlabel = 'Frequency (Hz)'
set ylabel = 'Magnitude (V/V)'
set filename = {$generic_prefix}{'_ac_analysis_mag'}
gnuplot $filename mag(n_out/n_in) title $title xlabel $xlabel ylabel $ylabel 

* Plot the Transfer Function (magnitude in logarithmic dB scale)
set title = 'AC Analysis: Transfer Function Magnitude (dB)' 
set xlabel = 'Frequency (Hz)'
set ylabel = 'Magnitude (dB)'
set filename = {$generic_prefix}{'_ac_analysis_magdb'}
gnuplot $filename db(n_out/n_in) title $title xlabel $xlabel ylabel $ylabel 

* Plot the Transfer Function (Phase in degrees)
set title = 'AC Analysis: Transfer Function Phase (Degrees)'
set xlabel = 'Frequency (Hz)'
set ylabel = 'Phase (+/-180 degrees scale)'
set filename = {$generic_prefix}{'_ac_analysis_phase'}
gnuplot $filename phase(n_out/n_in)*180/pi title $title xlabel $xlabel ylabel $ylabel 

echo '* Writing all simulation data to a textfile'

set filetype=ascii
set filename = {$generic_prefix}{'_results.raw'}
write $filename

.ENDC
~~~

**ce\_amplifier\_simulation\_netlist.spice**

~~~
* Common-Emitter Amplifier Netlist

.INCLUDE ce_amplifier_simulation_models.spice

* Circuit Elements: Devices
* dev   <nets>          <values>
* ---------------------------------- 
V1      n_pos 0         12V		
C1      n_in  n1        10uF		
R1      n_pos n1        100KR		
R2      n1    0         24KR		
Q1      n_out n1 n2     generic 
R3      n_pos n_out     3.9KR		
R4      n2    0         1KR		

.END
~~~

**ce\_amplifier\_simulations\_models.spice**

~~~
* Device Models

*      Name     Type(parameters) 
* ------------------------------
.MODEL generic  NPN
~~~

### References and Notes

* AIC-1 lab 2 [files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/2_simulation)
* NGSPICE user manual chapter 21.1 -- [Example Circuits](http://ngspice.sourceforge.net/docs/ngspice-manual.pdf)
* Schematic drawn with [Eeschema (Kicad)](http://kicad-pcb.org/discover/eeschema)
* Plot print-outs done with [Gnuplot](http://www.gnuplot.info)
    - Interactive plotting during simulation with built-in plot command 
        (i.e.  Ngnutmeg)
* Scalable Vector Graphics (SVG) done with [Inkscape](https://inkscape.org/en)
* Next lab 3.1 report: [The Widlar Current Mirror]({% post_url 2017-09-09-aic-1-3-1-widlar-current-mirror %})

{% include issues_comments.md %}
