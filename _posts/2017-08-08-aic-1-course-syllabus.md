---
title: 'AIC-1: Analog Integrated Circuits 1 -- Course Syllabus' 
---

Course Description
------------------

* **Class Objective:** Achieving familiarity with common analog IC topologies
    through SPICE simulation analyses.

* **Class Reference Textbook:** Designing Analog Chips (Hans Camenzind)

Lab Assignments Reports
----------------------

* See the [lab report template below](#lab-report-example-section) for an 
    example of what needs to be covered for every assignment report.

* Unless otherwise noted: individual assignment reports need to be submitted for
    every topology covered on each chapter.

Class Syllabus
--------------

* Chapter 1: Devices, history and intro to analog IC design.
    + Assignment: None.

* Chapter 2: Intro to AICs simulation -- SPICE.
    + Assignments:
        - AIC-1.2.1 (Report): SPICE Simulation with NGSPICE -- The CE amplifier
            exercise.
        - AIC-1.2.2: Real-world SPICE models and parameters for CMOS (MOSIS)
            and bipolar semiconductor processes.

* Chapter 3: Current Mirrors
    + Assignments (reports): For every sub-topology on chapter, e.g:
        - AIC-1.3.1: Current Mirrors -- The Widlar Current Mirror
        - AIC-1.4.1: Current Mirrors -- Lateral PNP Current Mirror
        - ...etc.

* Chapter 4: Differential Pairs

* Chapter 5: Current Sources

* Chapter 6: Analog Measures
    + Assignments: Understand analog measures used to assess the
        operating characteristics and performance of circuits. 

* Chapter 7: Bandgap References

* Chapter 8: Op Amps

* Chapter 9: Comparators

* Chapter 10: Transconductance Amplifiers

* Chapter 11: Timers and Oscillators

* Chapter 12: Phase-Locked Loops

* Chapter 13: Filters

* Chapter 14: Power Conversion 

* Chapter 15: A to D and D to A converters 

* Chapter 16: Other Circuits (Miscellaneous)

* Chapter 17: Introduction to Analog ICs Layout
    + Assignments: Gain familiarity with IC design layout techniques for next 
        AIC-2 course (See course description in I&P file). 

Notes: 

* Before the beginning of every chapter it is important to read about the
    historical context for the invention of the circuit topologies you will be
    covering, and subsequently gain a quantitative and qualitative
    understanding of the circuit.

---

Lab Report Example Structure <a name="lab-report-example-section">
----------------------------

### Schematic Diagram

Here goes the Eeschema schematic diagram (SVG Format): 

* Width (default): 800 px width **locked aspect ratio**.

* Page Margin: Fit to content.

### SPICE Simulations

The SPICE analyses are normally different for every chapter, i.e. to be able to 
measure the performance characteristics of that specific topology, some
examples:

#### Operating point Analysis

* Description of SPICE analysis

* Relevant source code lines

* Labelled plots (SVG format)

#### Transient Analysis

#### DC Analysis

#### AC Analysis

### Circuit Analysis

**You need to research, write-down and understand the topology in detail 
(reference books, online sources ...etc).** Take at least a day to do this 
(with pen and paper). Then, describe the following in your report:

* Context of circuit (background, brief history and why/how was/is it useful)

* Quantitative analysis: derivation of circuit results.

* Qualitative/intuitive analysis: describe in your own words how the circuit
    works.

### Source Code

**simulation\_testbench.spice**

~~~
Here goes the SPICE code
...
~~~

**netlist.spice**

~~~
Here goes the SPICE code
...
~~~

**models.spice**

~~~
Here goes the SPICE code
...
~~~

### References

* [Lab # Files](https://github.com/camilotejeiro/aic_1_lab)

* Designing Analog Chips -- Hanz Camenzind: Chapter #.

* [NGSPICE User Manual](http://ngspice.sourceforge.net/docs/ngspice26-manual.pdf) 

{% include issues_comments.md %}
