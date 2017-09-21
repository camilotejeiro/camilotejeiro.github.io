---
title: 'AIC-1.3.4: Current Mirrors -- Emitter Resistors (Negative Feedback)' 
---

## Schematic Diagram 

![Emitter Resistors Negative Feedback Schematic](/linked_files/2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback_1.svg)

## SPICE Simulations 

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

Relevant source code lines:

~~~
OP                      
print all               

* Output current over input current (with 1V load): should be 1 for best match.
print (v2#branch/v1#branch)
~~~

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      .9630 V
n2                      1.0 V
n3                      .2975 V
n4                      .2975 V
n_pos                   5.0 V
v1#branch               -50.0 uA
v2#branch               -49.1760 uA
(v2#branch/v1#branch)   .9835
~~~

### DC Analysis 

In our DC analysis, we are measuring the variation of the mirrored output current 
under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 5V in 0.1V 
increments. 

We are plotting the output current magnitude vs collector voltage. 
(our load voltage at n2)

Relevant source code lines:

~~~
DC V2 0V 5V 0.1V          ; Sweep Collector voltage from 0v to 5V in 0.1v increments.

gnuplot $filename (v2#branch*-1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 
~~~

![Emitter Resistors Negative Feedback Simulation DC](/linked_files/2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback_2.svg)

## Results 

Adding emitter resistors to the Widlar Current Mirror can help us introduce
negative feedback to help minimize the error in the output current with changes
in load voltage. (i.e. the error in the collector current with changes in
collector voltage)

From the circuit above we can see that as the emitter current increases, the
voltage across R2 increases, this subsequently reduces the base emitter voltage
(V\_be) of Q2 which then acts to decrease the emitter current, next the voltage
drop across R2 decreases and V\_be increases, more current flows ... and the
process repeats itself until a set-point is reached and loop errors are
subtracted. 

In principle for the circuit above, because the base voltage is fixed, the 
process repeats itself until the voltage drop across R2 (which is proportional
to our output current) remains constant and equal to the voltage drop across R1
(our setpoint, which is proportional to our current reference), with any errors
in R2's voltage (due to collector voltage dependence) subtracted from our input
(V\_be).

In the reference textbook example, having 6KR emitter resistors acts to 
reduce the output current dependence on load voltage and increases the output 
resistance of the mirror (see "figures of merit" section below), more 
specifically: 

* **Error Measurement**: Variation of 49.13uA to 49.51uA over an
    operating range of 0.6 to 5V.  
    This is equivalent to an error of 0.38uA or 0.76% relative to the current
    reference.

However, the extra resistors also increase the minimum collector voltage the mirror
can operate at (the compliance voltage), as we now have to account for both the
voltage drop accross R2 in addition to the voltage across Q2 in saturation.
Furthermore, there is the case of the base current error which has not been 
resolved either.

_Note that we can also use resistors for negative feedback in MOS current 
mirrors by placing the resistors in the sources of both transistors._

### Figures of Merit

* **Output Resistance**: 11.58MR (from 0.6 to 5V linear range)

* **Compliance Voltage**: 0.6V (from ground)

### Source code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/4_emitter_resistors_negative_feedback/emitter_resistors_negative_feedback_simulation_netlist.spice)

* [SPICE Simulation Testbench](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/4_emitter_resistors_negative_feedback/emitter_resistors_negative_feedback_simulation_testbench.spice)

### References 

* [Reference Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#reference-textbook) 
    + Chapter 3 (page 3-3)

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/4_emitter_resistors_negative_feedback)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-15-aic-1-3-3-simple-mos-current-mirror %})
    + Lab 3.3: Current Mirrors -- Simple MOS Current Mirror 
 
* [Next report]({% post_url 2017-09-20-aic-1-3-5-wilson-current-mirror %})
    + Lab 3.5: Current Mirrors -- Wilson Current Mirror
 
{% include issues_comments.md %}
