---
title: 'AIC-1.3.1: Current Mirrors -- The Widlar Current Mirror' 
---

## Schematic Diagram

![Widlar Current Mirror Schematic](/linked_files/2017-09-09-aic-1-3-1-widlar-current-mirror_1.svg)

## SPICE Simulations 

### Operating point Analysis

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

Relevant source code lines:

~~~
OP                      
print all               

* Output current over input current (at "no load"): should be 1 for best match.
print (v2#branch/v1#branch)         
~~~

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      665.4844 mV
n2                      1.0 V
n_pos                   5.0 V
v1#branch               -50.0 uA
v2#branch               -49.4646 uA
(v2#branch/v1#branch)   .9892925
~~~

### DC Analysis

In our DC analysis, we are measuring the variation in the mirrored output current 
under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 5V in 0.1V 
increments. 

We are plotting the output current magnitude vs collector voltage. 
(our load voltage at n2)

Relevant source code lines:

~~~
DC V2 0V 5V 0.1V

gnuplot $filename (v2#branch*-1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 
~~~

![Widlar Current Mirror Simulation DC](/linked_files/2017-09-09-aic-1-3-1-widlar-current-mirror_2.svg)

## Circuit Description 

Lab report in progress.

### References and Notes

* AIC-1 lab 3 [files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/1_widlar_current_mirror)
* Reference textbook: [Designing Analog Chips](http://designinganalogchips.com)
* Previous lab 2 report and references: [SPICE Simulations with NGSPICE]({% post_url 2017-08-19-aic-1-2-simulation %})

{% include issues_comments.md %}
