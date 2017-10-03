---
title: 'AIC-1.3.6: Current Mirrors -- PNP Wilson Current Mirror'
---

## Schematic Diagram 

![PNP Wilson Current Mirror Schematic](/linked_files/2017-09-21-aic-1-3-6-pnp-wilson-current-mirror_1.svg)

## SPICE Simulations 

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

Relevant source code lines:

~~~
OP                      
print all               
* Output current over constant input current (with 1V load): should be 1 for best match.
print (v2#branch/50e-06)
~~~

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      4.2884 V
n2                      4.0 V
n3                      3.5763 V
n_pos                   5.0 V
v1#branch               -99.9362 uA
v2#branch               48.0836 uA
(v2#branch/50e-06)      .9617
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

gnuplot $filename (v2#branch*1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 
~~~

![PNP Wilson Current Mirror Simulation DC](/linked_files/2017-09-21-aic-1-3-6-pnp-wilson-current-mirror_2.svg)

## Results

_Note we are using lateral PNP models for both Q1 and Q2._

As shown above, there is a PNP equivalent circuit for the Wilson current mirror,
it uses a split collector simple current mirror (Q1) to start,  and adds an extra 
PNP transistor (Q2) to complete the  the cascode stage and shield the collector
of Q1 from load voltage fluctuations.

For the Wilson current mirror in the reference textbook, the following are the
**error measurements**: 

* Variation of 48.17uA to 48.54uA over an operating range of 3.9V to 0V.  
    This is equivalent to an error of 0.74% relative to the current reference.

* The minimum voltage of the load (the voltage compliance) is given by the need
    to maintain a V_eb voltage for Q1 plus an (emitter to collector) saturation 
    voltage for Q2.

### Figures of Merit

* **Output Resistance**: 10.54MR (from 3.9 to 0V linear range)

* **Compliance Voltage**: 3.9V (from positive supply)

## Source code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/6_pnp_wilson_current_mirror/pnp_wilson_current_mirror_simulation_netlist.spice)

* [SPICE Simulation Testbench](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/6_pnp_wilson_current_mirror/pnp_wilson_current_mirror_simulation_testbench.spice)

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-4) 

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/6_pnp_wilson_current_mirror)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-20-aic-1-3-5-wilson-current-mirror %})
    + Lab 3.5: Current Mirrors -- Wilson Current Mirror 

* [Next report]({% post_url 2017-09-28-aic-1-3-7-four-transistor-current-mirror %})
    + Lab 3.7: Current Mirrors -- Four Transistor Current Mirror 

{% include issues_comments.md %}
