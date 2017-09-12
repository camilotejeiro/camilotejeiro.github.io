---
title: 'AIC-1.3.1: Current Mirrors -- The Widlar Current Mirror' 
---


## Schematic Diagram

![Widlar Current Mirror Schematic](/linked_files/2017-09-09-aic-1-3-1-widlar-current-mirror_1.svg)

## SPICE Simulations 

### Operating Point Analysis <a name="operating-point-analysis-section">

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

### DC Analysis <a name="dc-analysis-section">

In our DC analysis, we are measuring the variation of the mirrored output current 
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

## General Circuit Overview

The Widlar current mirror is named after it's inventor [Bob Widlar](https://en.wikipedia.org/wiki/Bob_Widlar),
A renowned bright analog IC designer with an "interesting" character.

Given our diode-connected (collector-base-tied transistor) Q1 and our bias
current I1, we should see a "diode" voltage drop from collector-base to emitter
(V_be). Thus, because Q1 and Q2 share the same base-emitter voltage, therefore
the collector current of Q2 should match identically that of Q1, except for two
errors:

1. From our [simulation results above](#operating-point-analysis-section) with
    our 1V load, we can see that currents v1\#branch and v2\#branch are very
    close, but not exactly identical. (and it gets worse as soon as we
    "introduce" a load) 
    
    The reason for this has to do with the base currents of both Q1 and Q2.

    Given a current gain (or beta = i_collector/i_base) of roughly 100, we can
    expect 1% of I1 to go to the base of Q1 and 1% to go to the base of Q2, for
    the worst case.

    **Error (worst case)**: 2% of current source reference, or 1uA in our case.

2. [The early effect](https://en.wikipedia.org/wiki/Early_effect) degrades the
    current matching performance of Q2 under different loads.

    While the collector voltage of Q1 remains fixed at V_be, the collector
    voltage of Q2 can change: Our load voltage can be anything. Now, due to
    the early effect for bipolar transistors, as the collector voltage
    increases, the collector current also increases and no longer matches that
    of I1. 
    
    This means our current mirror does not accurately match the source 
    current under different loads; We can see the extent of this error in our
    [DC analysis plot](#dc-analysis-section).

    **Error measurement**: Variation of 48.8uA to 53uA over current mirror operating
    region (roughly above 0.3V collector voltage). 
    This is equivalent to an error of 4.2uA or 8.4% relative to our current 
    reference. 
       
There are ways to compensate for these errors through the use of additional
transistors. These will be explored in upcoming labs.

### Source code

**widlar\_current\_mirror\_simulation\_testbench.spice**

~~~
The Widlar Current Mirror Simulation Testbench 

.INCLUDE widlar_current_mirror_simulation_netlist.spice

* Interactive simulation main entry *
* Note: which plotter are we using? 
*   * plot (for quick interactive plots during simulation)
*       - remember to remove filename from plot command (we are not writing a file) 
*   * gnuplot (for pint-quality lab report plots)
*       - remember to add a filename to gnuplot command (we are writing a file)
.CONTROL

* Make a directory for our output simulation files.
shell mkdir -p results 
* Generic prefix for our output files
set generic_prefix = 'results/widlar_current_mirror_simulation'

echo  '* Operating point analysis: Current match '

OP                      
print all               
* Output current over input current (at "no load"): should be 1 for best match.
print (v2#branch/v1#branch)         

echo '* DC analysis: Voltage dependence of current mirror'

DC V2 0V 5V 0.1V          ; Sweep Collector voltage from 0v to 20v in 0.1v increments.

* set our plot scale (i.e. x axis to the n2 vector)
setscale n2 
* plotting properties
set title = 'DC Analysis: Current Output vs Collector Voltage' 
set xlabel = 'Collector Volage (V)'
set ylabel = 'Current Output (uA)'
set yhigh = 55
set ylow = 45
set filename = {$generic_prefix}{'_dc_analysis'}
gnuplot $filename (v2#branch*-1e+06) ylimit $ylow $yhigh title $title xlabel $xlabel ylabel $ylabel 

echo '* Writing all simulation data to a textfile'

set filetype=ascii
set filename = {$generic_prefix}{'_results.raw'}
write $filename

.ENDC
~~~

**widlar\_current\_mirror\_simulation\_netlist.spice**

~~~
* The Widlar Current Mirror Netlist

.INCLUDE ../../device_parameter_libraries/bipolar_20v_process.spice

* Circuit Elements: Devices
* dev <nets>          <values>
* ------------------------------
V1    n_pos 0         5V		
I1    n_pos n1        50uA		
XQ1   n1    n1 0 0    npn1		
XQ2   n2    n1 0 0    npn1		
V2    n2    0         1V		

.END
~~~

_SPICE model device parameters are referenced in the course syllabus_ 

### References and Notes

* Reference textbook chapter 3 (pages 3-1 and 3-2)

* [Lab files](https://github.com/camilotejeiro/aic_1_lab/tree/master/lab_assignments/3_current_mirrors/1_widlar_current_mirror)

* [Previous report]({% post_url 2017-08-19-aic-1-2-simulation %}).
    Lab 2: Simulation -- SPICE Simulations with NGSPICE

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

{% include issues_comments.md %}
