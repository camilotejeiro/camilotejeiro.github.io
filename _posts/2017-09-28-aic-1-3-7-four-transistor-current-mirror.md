---
title: 'AIC-1.3.7: Current Mirrors -- Four Transistor Current Mirror'
---

## Schematic Diagram 

![Four Transistor Current Mirror Schematic](/linked_files/2017-09-28-aic-1-3-7-four-transistor-current-mirror_1.svg)

## SPICE Simulations 

_For the SPICE simulation code, see ["Source Code"](#source-code) section below._

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      .6657 V
n2                      1.0 V
n3                      1.3318 V
n4                      .6663 V
n_pos                   5.0 V
v1#branch               -50.0 uA
v2#branch               -49.9800 uA
(v2#branch/v1#branch)   .9996
~~~

### DC Analysis 

In our DC analysis, we are measuring the variation of the mirrored output current 
under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 5V in 0.1V 
increments. 

We are plotting the output current magnitude vs collector voltage. 
(our load voltage at n2)

![Four Transistor Current Mirror Simulation DC](/linked_files/2017-09-28-aic-1-3-7-four-transistor-current-mirror_2.svg)

### Monte Carlo Analysis

Given that we now have more devices for our current mirror, the reference book
emphasizes the importance of a [Monte Carlo](https://en.wikipedia.org/wiki/Monte_Carlo_method#Engineering) 
simulation to measure the effect of transistors' mismatch on the performance of
our current mirror i.e. how small variations in individual transistors when
added together can affect the performance of the overall circuit.

Performing a Monte Carlo (mismatch) simulation on NGSPICE turned out to be 
difficult **but possible** with some effort.

The Monte Carlo Testbench SPICE [source code](#source-code) provided below has
been thoroughly commented to ease understanding. I have also added helpful 
[references](#references) at the bottom of this post, and a "montecarlo\_examples" 
directory in the lab files repository.

The main thing to keep in mind in simulating device mismatches is that 
**the transistor model with its respective parameters needs to be placed
inside a SPICE subcircuit.** This is the only way to be able to modify
parameters independently for every transistor in the netlist, otherwise a change
in model parameters propagates to all transistors.

The Monte Carlo simulation was performed for 100 runs with a sigma value of 3.

As per the book reference (in the simulation chapter) for bipolar transistors:
independent variations of Is, Bf and the junction capacitances were simulated
for each transistor.

![Four Transistor Current Mirror Simulation Montecarlo](/linked_files/2017-09-28-aic-1-3-7-four-transistor-current-mirror_3.svg)

## Results

As mentioned before for the [Wilson Current Mirror]({% post_url 2017-09-20-aic-1-3-5-wilson-current-mirror %})
lab report, there was a matching error for transistors Q1 and Q2: their
collector voltages were not the same.

Thus a fourth transistor (Q4) was added, its main job to decrease the voltage
at n3 by one V_be in order to bring the voltages n4 and n1 (the collector
voltages for the current matching transistors Q1 and Q2) more closely in line.

The results as we can see from our [Operating Point Analysis](#operating-point-analysis) 
(v2#branch/v1#branch) is that we now have a 99.96% current match given a 1V load
which is quite remarkable.

But indeed as mentioned in the reference book, variations due to transistors
mismatch can account for as much as +2% to -5.6% (from our montecarlo simulation) 
relative to our reference current value.

For the "Four Transistor" current mirror in the reference textbook, the
following are the **error measurements**: 

* Variation of 49.9797uA to 50.0468uA over an operating range of 1V to 5V.  
    This is equivalent to an error of 0.1342% relative to the current reference.

* The minimum voltage of the load (the voltage compliance) is given by the need
    to maintain a V_be voltage for Q2 plus a (collector to emitter) saturation
    voltage for Q3 (see figures of merit below).

### Figures of Merit

* **Output Resistance**: 59.61MR (from 1 to 5V linear range)

* **Compliance Voltage**: 1V (from ground)

### Source Code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/7_four_transistor_current_mirror/four_transistor_current_mirror_simulation_netlist.spice)

* [SPICE Simulation Testbench DC Analysis](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/7_four_transistor_current_mirror/four_transistor_current_mirror_simulation_testbench_dc.spice)

* [SPICE Simulation Testbench Montecarlo Analysis](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/3_current_mirrors/7_four_transistor_current_mirror/four_transistor_current_mirror_simulation_testbench_montecarlo.spice)

### References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-5) 

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/7_four_transistor_current_mirror)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [NGSPICE Example Montecarlo Simulations](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/7_four_transistor_current_mirror/montecarlo_examples)

* [NGSPICE Discussion Thread: Local Mismatch](https://sourceforge.net/p/ngspice/discussion/133842/thread/5d3537b2)

* [Previous report]({% post_url 2017-09-21-aic-1-3-6-pnp-wilson-current-mirror %})
    + Lab 3.6: Current Mirrors -- PNP Wilson Current Mirror 

{% include issues_comments.md %}
