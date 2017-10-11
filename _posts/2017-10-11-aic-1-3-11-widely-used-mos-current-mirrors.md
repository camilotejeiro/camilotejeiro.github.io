---
title: 'AIC-1.3.11: Current Mirrors -- Widely Used MOS Current Mirrors'
---

This report covers the simulation (and comparison) of 3 of the most commonly
used MOS current mirror topologies (refer to pages 3-7 and 3.8 from our class
textbook [below](#references)), mainly: 

1. Book figure 3-23 (widely used mirror)
2. Book figure 3-24 (fewer devices, same performance)
3. Book figure 3-25 (best performance)

## Schematic Diagram 

### 1. Widely Used Mirror

![Widely Used MOS Current Mirrors 1 Schematic](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_1.svg)

### 2. Fewer Devices, Same Performance

![Widely Used MOS Current Mirrors 2 Schematic](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_2.svg)

### 3. Best Performance

![Widely Used MOS Current Mirrors 3 Schematic](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_3.svg)

## SPICE Simulations 

_For the SPICE simulation code, see ["Source Code"](#source-code) section below._

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuits.

**Note:** Node DC measurements (re-formatted for display). 


#### 1. Widely Used Mirror

~~~
Node                    Measurements
----                    ------------
n1                      1.1692 V
n2                      1.0 V
n3                      1.1786 V
n4                      .4162 V
n5                      .4166 V
n_pos                   3.0
v1#branch               -100.0 uA
v2#branch               -49.9838 uA
(v2#branch/(-50e-06))   .9997
~~~

#### 2. Fewer Devices, Same Performance

~~~
Node                    Measurements
----                    ------------
n1                      1.1711 V
n2                      1.0 V
n3                      .4108 V
n4                      .4104 V
n_pos                   3.0 V
v1#branch               -50.0 uA
v2#branch               -49.9827 uA
(v2#branch/(-50e-06))   .9997
~~~

#### 3. Best Performance

~~~
Node                    Measurements
----                    ------------
n1                      .9555 V
n2                      1.0 V
n3                      1.2055 V
n4                      .4371 V
n5                      .4373 V
n_pos                   3.0 V
v1#branch               -50.0 uA
v2#branch               -50.0007 uA
(v2#branch/(-50e-06))   1.0000 
~~~

### DC Analysis 

In our DC analysis, we are measuring the variation of the mirrored output
current under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 3V in 0.1V 
increments. 

We are plotting the output current magnitude vs drain voltage. 
(our load voltage at n2)

#### 1. Widely Used Mirror

![Widely Used MOS Current Mirrors 1 Simulation DC](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_4.svg)

#### 2. Fewer Devices, Same Performance

![Widely Used MOS Current Mirrors 1 Simulation DC](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_5.svg)

#### 3. Best Performance

![Widely Used MOS Current Mirrors 1 Simulation DC](/linked_files/2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors_6.svg)

## Results

_Lab report in progress._

**Error measurement**: 

### Figures of Merit

_Lab report in progress._

* **Output Resistance**: 

* **Compliance Voltage**: 

## Source Code

* [SPICE Simulation Netlist 1 (first circuit)](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/11_widely_used_mos_current_mirrors/widely_used_mos_current_mirrors_simulation_netlist_1.spice)

* [SPICE Simulation Netlist 2 (second circuit)](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/11_widely_used_mos_current_mirrors/widely_used_mos_current_mirrors_simulation_netlist_2.spice)

* [SPICE Simulation Netlist 3 (third circuit)](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/11_widely_used_mos_current_mirrors/widely_used_mos_current_mirrors_simulation_netlist_3.spice)

* [SPICE Simulation Testbench DC Analysis](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/11_widely_used_mos_current_mirrors/widely_used_mos_current_mirrors_simulation_testbench.spice)

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (pages 3-7 and 3-8) 

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/03_current_mirrors/11_widely_used_mos_current_mirrors)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage %})
    + Lab 3.10: Current Mirrors -- MOS Current Mirror With Cascode Stage 

{% include issues_comments.md %}
