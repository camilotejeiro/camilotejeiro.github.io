---
title: 'AIC-1.3.10: Current Mirrors -- MOS Current Mirror With Cascode Stage'
---

## Schematic Diagram 

![MOS Current Mirror With Cascode Stage Schematic](/linked_files/2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage_1.svg)

## SPICE Simulations 

_For the SPICE simulation code, see ["Source Code"](#source-code) section below._

### Operating Point Analysis 

Here, we are calculating the DC voltages (bias voltages) at every node of our
circuit.

**Results:** Node DC measurements (re-formatted for display). 

~~~
Node                    Measurements
----                    ------------
n1                      .8593 V
n2                      1.0 V
n3                      1.3593 V
n4                      .4921 V
n_pos                   3.0 V
v1#branch               -50.0 uA
v2#branch               -49.4728 uA
(v2#branch/v1#branch)   .9895
~~~

### DC Analysis 

In our DC analysis, we are measuring the variation of the mirrored output current 
under different loads.

We are applying a DC sweep to V2 (our load voltage) from 0 to 3V in 0.1V 
increments. 

We are plotting the output current magnitude vs drain voltage. 
(our load voltage at n2)

![MOS Current Mirror With Cascode Stage Simulation DC](/linked_files/2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage_2.svg)

### Monte Carlo Analysis

In our Montecarlo analysis, we are measuring the effect of transistors' mismatch
on the performance of our current mirror i.e. how small variations in individual
transistors when added together can affect the performance of the overall
circuit.

The Monte Carlo simulation was performed for 100 runs with a sigma value of 3.

As per the book reference (in the simulation chapter) for MOS transistors:
It is important to model variations of the threshold voltage, transconductance
and capacitances. However, these parameters do not match one-to-one with the
SPICE BSIM3v3.3 model parameters (see reference [below](#references)), thus we
have chosen key BSIM3v3 parameters which affect directly the threshold voltage,
transconductance and capacitances of MOS devices, mainly:

1. Vth0: Threshold voltage for large geometry devices at V_bs = 0V. 
    + The actual threshold voltage of each MOSFET (Vth) is directly dependent on Vth0.

2. U0: Carrier mobility at nominal temperature. 
    + The MOS device transconductance is 
        [directly proportional](http://www-inst.eecs.berkeley.edu/~ee105/fa98/lectures_fall_98/091898_lecture11.pdf) 
        to the carrier mobility in the semiconductor.

3. Tox: Gate Oxide Thickness.
    + The Gate Oxide Capacitance (Cox) is inversely proportional to the Gate Oxide
        Thickness (Cox = 3.9Eox/Tox; for Silicon Dioxide SiO2), furthermore, 
    + The MOS device transconductance is directly proportional to the Gate Oxide
        Capacitance (Cox).

_Note we are not including any additional capacitances in the MOS model since we are
running our simulation at DC._

![MOS Current Mirror With Cascode Stage Simulation Montecarlo](/linked_files/2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage_3.svg)

## Results

As noted in the book (refer to page 3-7 [below](#references)), one alternative
commonly used to reduce the output current dependence with drain voltage for the
[simple MOS current mirror]({% post_url 2017-09-15-aic-1-3-3-simple-mos-current-mirror %}) 
is to use a simple cascode stage. Here a resistor (R1) is used to set the gate
voltage of M3 which in turn shields the current matching transistor M2 from
fluctuations in the load voltage.

The advantage of using R1 is that one can have finer control over the gate
voltage of M3. For example by reducing the value of R1 we can have a slightly
larger compliance voltage range at the cost of a lower output resistance and a
worse current match, on the other hand increasing R1 increases the output
resistance and current match of the mirror at the cost of a smaller compliance
voltage range. 

Looking at the montecarlo mismatch analysis above, we can see that small
variations due to transistors mismatch can account for about as much as +/- 15%
relative to our reference current value.  

_This error is larger than that of the book, unfortunately we don't have the
exact values used for the Montecarlo (mismatch) simulation in the book, nor the
actual SPICE device parameters modified for every transistor during the
simulation (this makes it almost impossible to compare results objectively).
However we will keep this report updated if any errors are found._

**Error measurement**: For the "MOS Current Mirror With Cascode Stage", we have a
variation of 49.4560uA to 49.5291uA over an operating range of 0.7V to 3V. This
is equivalent to an error of 0.1462% relative to the current reference.

### Figures of Merit

* **Output Resistance**: 31.46MR (from 0.7 to 3V linear range)

* **Compliance Voltage**: 0.7V (from ground)

## Source Code

* [SPICE Simulation Netlist](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/10_mos_current_mirror_cascode_stage/mos_current_mirror_cascode_stage_simulation_netlist.spice)

* [SPICE Simulation Testbench DC Analysis](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/10_mos_current_mirror_cascode_stage/mos_current_mirror_cascode_stage_simulation_testbench_dc.spice)

* [SPICE Simulation Testbench Montecarlo Analysis](https://github.com/camilotejeiro/aic_1_lab/blob/master/lab_assignments/03_current_mirrors/10_mos_current_mirror_cascode_stage/mos_current_mirror_cascode_stage_simulation_testbench_montecarlo.spice)

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-7) 

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/03_current_mirrors/10_mos_current_mirror_cascode_stage)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [BSIM3v3.3 MOSFET Model Manual](http://ngspice.sourceforge.net/external-documents/models/bsim330_manual.pdf)

* [Previous report]({% post_url 2017-10-03-aic-1-3-9-generating-multiple-currents %})
    + Lab 3.9: Current Mirrors -- Generating Multiple Currents

{% include issues_comments.md %}
