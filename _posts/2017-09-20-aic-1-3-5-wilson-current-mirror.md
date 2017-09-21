---
title: 'AIC-1.3.5: Current Mirrors -- Wilson Current Mirror'
---

## Schematic Diagram 

![Wilson Current Mirror Schematic](/linked_files/2017-09-20-aic-1-3-5-wilson-current-mirror_1.svg)

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
n1                      .6654 V
n2                      1.0 V
n3                      1.3312 V
n_pos                   5.0 V
v1#branch               -50.0 uA
v2#branch               -49.4016 uA
(v2#branch/v1#branch)   .9880
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

![Wilson Current Mirror Simulation DC](/linked_files/2017-09-20-aic-1-3-5-wilson-current-mirror_2.svg)

## Results

The [Wilson Current Mirror](https://en.wikipedia.org/wiki/Wilson_current_mirror)
was invented by George Wilson, an Analog IC design engineer who worked as head
of the Integrated Circuits Group at Tektronix. It is said that he invented the
circuit over an overnight challenge with [Barrie Gilbert](https://en.wikipedia.org/wiki/Barrie_Gilbert)
to design an improved current mirror that would use only 3 transistors. (or so
the story goes)

In this circuit the combination of the load, Q3 and Q2 form a [Cascode stage](https://en.wikipedia.org/wiki/Cascode).
This stage introduces a negative feedback loop into the system and shields the
simple current mirror (Q1 and Q2) from load voltage fluctuations. 

Initially all transistors are OFF, shortly thereafter a small current starts to
flow into the base of Q3 which starts to conduct, the emitter current of Q3 then
biases the current mirror formed by Q1 and Q2. As Q1 starts to conduct (and
given our constant current reference), it reduces the base current of Q3. In
turn, Q3 emitter current decreases which leads to reductions in Q1 and Q2
collector currents, the reduction in Q1's collector current makes more current
available for the base of Q3 and the process repeats itself from the beginning
until loop errors are reduced (i.e. subtracted from Q3 base current); a
constant setpoint is reached when the load current matches closely the reference
current. (see a detailed explanation of the circuit
[here](http://www.play-hookey.com/analog/current_mirrors/current_mirror_wilson.html))

Furthermore, it is worth noting that the base error previously found in the
simple 2-transistor (Widlar) current mirror is minimized. I.e. while the 
base current for Q3 is still taken from the reference (1), it is amplified by 
the current gain of Q3 and a small fraction of Q3's larger emitter current is 
fed-back to drive the bases of Q1 and Q2 (2). These effects compensate for each other, 
with the collector current of Q3 (the output current) greater than that of Q1 and
more closely matched to our current reference.

For the Wilson current mirror in the reference textbook, the following are the
**error measurements**: 

* Variation of 49.409uA to 49.467uA over an operating range of 1.1V to 5V.  
    This is equivalent to an error of 0.116% relative to the current reference.

* The minimum voltage of the load (the voltage compliance) is given by the need
    to maintain a collector voltage for Q3 of: V\_be for Q2, plus the (collector
    to emitter) saturation voltage for Q3 (see figures of merit).

* The current mirror transistors Q1 and Q2 are not perfectly matched: the
    collector voltage of Q1 is at 2V\_be while that of Q2 is at V\_be. This error
    will be explored and minimized in upcoming lab reports.

### Figures of Merit

* **Output Resistance**: 67.24MR (from 1.1 to 5V linear range)

* **Compliance Voltage**: 1.1V (from ground)

_The compliance voltage of this circuit is rather high which limits the use of
this topology outside of the scope of most low power applications_

There is also a PNP equivalent Wilson current mirror which will be explored in
the next lab report.

### Source code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/5_wilson_current_mirror/wilson_current_mirror_simulation_netlist.spice)

* [SPICE Simulation Testbench](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/5_wilson_current_mirror/wilson_current_mirror_simulation_testbench.spice)

### References

* [Reference Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#reference-textbook) 
    + Chapter 3 (page 3-4) 

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/5_wilson_current_mirror)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback %})
    + Lab 3.4: Current Mirrors -- Emitter Resistors (Negative Feedback) 

* [Next report]({% post_url 2017-09-21-aic-1-3-6-pnp-wilson-current-mirror %})
    + Lab 3.6: Current Mirrors -- PNP Wilson Current Mirror

{% include issues_comments.md %}
