---
title: 'AIC-1: Analog Integrated Circuits 1 -- Course Syllabus' 
---
_Please note this syllabus is updated continuously to reflect progress in the
course, and update references to submitted lab reports._

Course Description 
------------------

### Objective 

Gaining familiarity with common analog IC topologies through SPICE simulation analyses.

**Note this class is not intended to be an in-depth analysis of specific circuits, 
this material will be covered in AIC-2.** 

The whole purpose of this class is to gain familiarity, experience and 
ultimately intuition for the operation of common analog IC topologies. 

This is essential knowledge required to put our results and future circuit 
analyses in context (see AIC-2).

### Textbook

The reference textbook we will use for this class is:

* [Designing Analog Chips (Hans Camenzind)](http://designinganalogchips.com)

### SPICE Simulation Software 

The circuit simulator we will use for this class is:

* [NGSPICE](http://ngspice.sourceforge.net/presentation.html)

The SPICE models device parameters we will use for this class are:

* CMOS Devices ([NCSU CDK](https://www.eda.ncsu.edu/wiki/NCSU_CDK)): 
    + 0.35uM Hewlett Packard GMOS10QA process
    + 0.35uM TSMC\_CMOS035 process 

* Bipolar Devices (reference textbook): 20V bipolar process.

Assignments and Lab Reports 
---------------------------

### Assignments (to be done first)

Remember: every chapter must be read completely and each section must be 
    understood and explained in your lab notebook (where circuits are covered)
    before the start of that section's lab report, specifically:

* Read textbook chapter
    + Define lab sections

* For each individual section (only if circuit topologies are covered)
    + Understand each individual circuit topology 
    + Write up (in lab notebook) circuit overview and explanation of 
        results

### Lab Reports (only necessary if circuit topologies are covered)

* See the [lab report template below](#lab-report-example-structure) for an 
    example of what needs to be covered for every lab report.

* Unless otherwise noted: individual lab reports need to be submitted for
    every topology section covered on each chapter.

* Remember to update the "explanation of results" section to account for your 
    own simulation results.
    + If there are significant differences, make sure to explain them in your
        report.

#### Submission Timelines

* Individual section lab reports should be submitted every two to four weeks.
    (depending on the complexity of the circuit topology)

* All the required section lab reports for each chapter should be completed in 
    a month or less. i.e. so that we are covering at least a chapter per month.

Course Schedule
---------------

* Chapter 1: Devices, history and intro to analog IC design.

* Chapter 2: Intro to AICs simulation -- SPICE
    + [Lab 2: SPICE Simulations with NGSPICE]({% post_url 2017-08-19-aic-1-2-simulation %})

* Chapter 3: Current Mirrors
    + [Lab 3.1: Widlar Current Mirror]({% post_url 2017-09-09-aic-1-3-1-widlar-current-mirror %})
    + [Lab 3.2: Lateral PNP Current Mirror]({% post_url 2017-09-13-aic-1-3-2-lateral-pnp-current-mirror %})
    + [Lab 3.3: Simple MOS Current Mirror]({% post_url 2017-09-15-aic-1-3-3-simple-mos-current-mirror %})
    + [Lab 3.4: Emitter Resistors (Negative Feedback)]({% post_url 2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback %})
    + [Lab 3.5: Wilson Current Mirror]({% post_url 2017-09-20-aic-1-3-5-wilson-current-mirror %})
    + [Lab 3.6: PNP Wilson Current Mirror]({% post_url 2017-09-21-aic-1-3-6-pnp-wilson-current-mirror %})
    + [Lab 3.7: Four Transistor Current Mirror]({% post_url 2017-09-28-aic-1-3-7-four-transistor-current-mirror %})
    + [Lab 3.8: Scaling Currents (Ratios)]({% post_url 2017-10-03-aic-1-3-8-scaling-currents-ratios %})
    + [Lab 3.9: Generating Multiple Currents]({% post_url 2017-10-03-aic-1-3-9-generating-multiple-currents %})
    + [Lab 3.10: MOS Current Mirror With Cascode Stage]({% post_url 2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage %})
    + [Lab 3.11: Widely Used MOS Current Mirrors]({% post_url 2017-10-11-aic-1-3-11-widely-used-mos-current-mirrors %})

* Chapter 5: Current Sources

* Chapter 6: Analog Measures
    Understand analog measures used to assess the operating characteristics 
    and performance of circuits. 

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

---

Lab Report Example Structure
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

### Results

Describe the results of your simulation: figures of merit, error measurements
...etc.  Anything necessary to compare the performance of the circuit with other
topologies.

### Source Code

**Preferably** you should provide the individual links to the source code files used
for the circuit simulation in this section. 

Alternatively, you can provide the source code in this section verbatim.

### References

Don't repeat references on each report, simply provide a link to the previous
report and syllabus.

* [AIC-1 lab files](https://github.com/camilotejeiro/aic_1_lab)

* [Textbook](http://designinganalogchips.com/_count/designinganalogchips.pdf) 
    + Designing Analog Chips -- Hans Camenzind

* [NGSPICE User Manual](http://ngspice.sourceforge.net/docs/ngspice26-manual.pdf) 

* [Eeschema (Kicad)](http://kicad-pcb.org/discover/eeschema) will be used to draw
    schematic diagrams 

* [Gnuplot](http://www.gnuplot.info) will be used for plot print-outs 
    + Interactive plotting during simulation with built-in plot command 
        (i.e.  Ngnutmeg)

* [Inkscape](https://inkscape.org/en) will be used for Scalable Vector Graphics 
    (SVG) media 

{% include issues_comments.md %}
