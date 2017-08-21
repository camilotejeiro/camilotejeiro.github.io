---
title: 'AIC-1.2: Simulation -- SPICE Simulations with NGSPICE'
---

## 1. The Common-Emitter Amplifier <a name="section-1"></a>

### Schematic Diagram

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_1.svg)

### SPICE Simulations 

#### Operating point

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

#### Transient Analysis

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_2.svg)

#### DC Analysis

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_3.svg)

#### AC Analysis

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_4.svg)

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_5.svg)

![Common Emitter Amplifier](/linked_files/2017-08-19-aic-1-2-simulation_6.svg)
