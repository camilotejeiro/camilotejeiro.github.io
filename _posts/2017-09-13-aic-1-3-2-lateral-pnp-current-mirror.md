---
title: 'AIC-1.3.2: Current Mirrors -- Lateral PNP Current Mirror' 
---

## Schematic Diagram

![Lateral PNP Current Mirror Schematic](/linked_files/2017-09-13-aic-1-3-2-lateral-pnp-current-mirror_1.svg)

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
n_pos                   5.0 V
v1#branch               -99.3714 uA
v2#branch               48.4859 uA
(v2#branch/50e-06)      .9697
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
DC V2 0V 5V 0.1V    

gnuplot $filename (v2#branch*1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 
~~~

![Lateral PNP Current Mirror Simulation DC](/linked_files/2017-09-13-aic-1-3-2-lateral-pnp-current-mirror_2.svg)

## Results

One of the few advantages of lateral PNP transistors (see reference textbook
page 1-22) is that you can split the collector of the device into multiple
sections and achieve excellent matching between collector currents (albeit at
small currents only): thus the appropriate use of this device in a current
mirror topology.

In the circuit above, Q1 is the split-collector lateral PNP transistor. I1
biases the transistor and stablishes a "diode" voltage drop from emitter to base
(V_eb), the emitter current is then divided "identically" into two branches. (due
to the split collector layout). However, there are two errors:

1. There is a large collector current variation with changes in collector
    voltage (due to the early effect), moreover the effect is more pronounced
    for the lateral PNP current mirror than it was for the Widlar current
    mirror, mainly:

    **Error measurement**: Variation of 53.5uA to 47.5uA over current mirror 
    operating region (below 4.7V collector voltage).
    This is equivalent to an error of 6uA or 12% relative to our current 
    reference. 
     
2. The second error (due to the use of a lateral PNP transistor) has to do with
    substrate currents (There is a competing PNP transistor: emitter, base, substrate). 
    During normal operation a current about half the base current flows from
    emitter to substrate and under saturation the current increases to be almost
    the same as that of the collector.

    In the [graph above](#dc-analysis), this happens at a collector
    voltage of 4.7V or about 0.3V from the 5V positive supply. 

### Figures of Merit

* **Output Resistance**: 783.3 KR (from 0 to 4.7V range)

* **Compliance Voltage**: 0.3 V (from positive supply)

## Source code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/02_lateral_pnp_current_mirror/lateral_pnp_current_mirror_simulation_netlist.spice)

* [SPICE Simulation Testbench](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/02_lateral_pnp_current_mirror/lateral_pnp_current_mirror_simulation_testbench.spice)

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-2)

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/03_current_mirrors/02_lateral_pnp_current_mirror)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-09-aic-1-3-1-widlar-current-mirror %})
    + Lab 3.1: Current Mirrors -- Widlar Current Mirror

* [Next report]({% post_url 2017-09-15-aic-1-3-3-simple-mos-current-mirror %})
    + Lab 3.3: Current Mirrors -- Simple MOS Current Mirror

{% include issues_comments.md %}
