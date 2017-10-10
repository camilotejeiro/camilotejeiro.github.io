---
title: 'AIC-1.3.3: Current Mirrors -- Simple MOS Current Mirror' 
---

## Schematic Diagram 

![Simple MOS Current Mirror Schematic](/linked_files/2017-09-15-aic-1-3-3-simple-mos-current-mirror_1.svg)

## SPICE Simulations 

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

Relevant source code lines:

~~~
OP                      
print all               
* Output current over constant input current (with 1V load): should be 1 for best match.
print (v2#branch/v1#branch)
~~~

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      1.1049 V
n2                      1.0 V
n_pos                   3.0 V
v1#branch               -50.0 uA
v2#branch               -49.8939 uA
(v2#branch/v1#branch)   .9979
~~~

### DC Analysis 

In our DC analysis, we are measuring the variation of the mirrored output current 
under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 3V in 0.1V 
increments. 

We are plotting the output current magnitude vs drain voltage. 
(our load voltage at n2)

Relevant source code lines:

~~~
DC V2 0V 3V 0.1V          ; Sweep Drain voltage from 0v to 3v in 0.1v increments.

gnuplot $filename (v2#branch*-1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 
~~~

![Simple MOS Current Mirror Simulation DC](/linked_files/2017-09-15-aic-1-3-3-simple-mos-current-mirror_2.svg)

## Results 

Similar to the Widlar current mirror but now with MOS devices: a simple current
mirror can be constructed by placing two back to back NMOS FETs. The first
transistor M1 has it's drain and gate tied together in a "diode connected"
fashion, albeit this is a misnomer as there is no internal diode PN junction,
instead the gate to source threshold voltage is largely determined by the
geometry of the device. 

For the Simple MOS Current Mirror in the reference textbook, and because the
channel dimension were chosen to be quite large:

1. The variation of the drain current with changes in load voltage is as
    follows:

    **Error Measurement**: Variation of 49.89uA to 51.39uA over an operating
    range of 1 to 3V.  
    This is equivalent to an error of 1.5uA or 3% relative to our current 
    reference. 

2.The current mirror requires at least a 0.5V load voltage to be operational
    (this can be seen from the plot above). However lower compliance voltages can 
    be achieved through the use of larger devices.

Note that this topology is symmetrical and can be inverted by using PMOS 
    transistors connected to the positive supply rail instead. 

### Figures of Merit

* **Output Resistance**: 750KR (from 1 to 3V linear range)

* **Compliance Voltage**: 0.5V (from ground)

## Source code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/03_simple_mos_current_mirror/simple_mos_current_mirror_simulation_netlist.spice)

* [SPICE Simulation Testbench](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/03_simple_mos_current_mirror/simple_mos_current_mirror_simulation_testbench.spice)

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-3)

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/03_current_mirrors/03_simple_mos_current_mirror)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-13-aic-1-3-2-lateral-pnp-current-mirror %})
    + Lab 3.2: Current Mirrors -- Lateral PNP Current Mirror

* [Next report]({% post_url 2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback %})
    + Lab 3.4: Current Mirrors -- Emitter Resistors (Negative Feedback)

{% include issues_comments.md %}
