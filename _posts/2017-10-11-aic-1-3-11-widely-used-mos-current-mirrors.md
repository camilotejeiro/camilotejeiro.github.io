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

This lab explores the simulation of 3 common MOS current mirror topologies. 

As noted in the book (refer to pages 3-7 and 3-8 [below](#references)), we can
see that a common technique used for all the circuits is the addition of a cascode
stage at the output. This stage helps to shield the lower current matching 
transistors from fluctuations in load voltage and reduces the output current
dependence on voltage. (improving our output resistance figure) 

Biasing for the cascode stage transistors (required to keep them in saturation 
where drain current dependence on drain voltage is small) is provided by both the
use of additional devices (e.g. M1 for [circuit 1](#1-widely-used-mirror) and 
R1 for [circuit 3](#3-best-performance)) and by changing the dimensions
of MOS devices. I.e. By changing the dimensions of MOS devices one can affect
their threshold voltage **indirectly**. (V\_th is actually dependent on many other
physical and process parameters which vary depending on the semiconductor
technology being used) 

Furthermore, we can see that there are additional transistors (M1 for both
circuits [2](#2-fewer-devices-same-performance) and [3](#3-best-performance) and
M2 for circuit [1](#1-widely-used-mirror)) added in order to bring the drain
voltages of our lower current matching transistors to equal each other and
reduce our current match error. 

**This report concludes our simulations for chapter 3 of the book -- current
mirrors -- upcoming reports will explore "Differential Pair" IC topologies with
bipolar and MOS devices.**

### Error Measurements 

#### 1. Widely Used Mirror

For the first circuit, we have a variation of 49.9617uA to 50.1523uA over an
operating range of 0.8V to 3V. This is equivalent to an error of 0.3812%
relative to the current reference.

#### 2. Fewer Devices, Same Performance

For the second circuit, we have a variation of 49.9594uA to 50.1617uA over an
operating range of 0.8V to 3V. This is equivalent to an error of 0.4046%
relative to the current reference. 

#### 3. Best Performance

For the third circuit, we have a variation of 49.9947uA to 50.0256uA over an
operating range of 0.7V to 3V. This is equivalent to an error of 0.0618%
relative to the current reference.

### Figures of Merit

#### 1. Widely Used Mirror

* **Output Resistance**: 11.5425MR (from 0.8 to 3V linear range)

* **Compliance Voltage**: 0.8V (from ground)

#### 2. Fewer Devices, Same Performance

* **Output Resistance**: 10.8749MR (from 0.8 to 3V linear range)

* **Compliance Voltage**: 0.8V (from ground)

#### 3. Best Performance

* **Output Resistance**: 74.4337MR (from 0.7 to 3V linear range)

* **Compliance Voltage**: 0.7V (from ground)

Looking at our results above, we can see that indeed the second circuit is
comparable in performance to the first circuit (while employing fewer
transistors and references) as described in the book, and the third
circuit is evidently superior in both output resistance and compliance voltage
and presents the best performance of the 3 topologies.

Thus our simulations agree with our reference book results and expectations, and
that is always a great thing.

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
