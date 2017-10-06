---
title: 'AIC-1.3.9: Current Mirrors -- Generating Multiple Currents'
---

_The book does not provide simulation results for these pages, thus this report
is simply a brief lab note for future reference_.

**Given a single current reference, how does one generate mutiple matched
currents to be used for different circuit-blocks in an integrated circuit?**

## Bipolar Devices

As noted in the book (refer to pages 3-6 [below](#references)), in the simplest
case you can take the 
[Widlar Current Mirror]({% post_url 2017-09-09-aic-1-3-1-widlar-current-mirror %})
and connect additional transistors in parallel -- base and emitters tied together.
Then, for every output transistor you can connect their individual collectors to
different circuit-blocks.

There is a problem however, the more output transistors you add in parallel, the
larger the base current error of the mirror. To remedy this error, you can add
an additional current buffer transistor Q3 (see the reference schematic in the
[book](#references)), this transistor provides the base current for all the
current matching transistors from the power supply instead (with a very small
base current taken from the reference). Now you can add a large number of output
transistors with a very minor influence to the reference current.

On the other hand, this extra transistor introduces a small error: the
collector voltages of Q1 and Q2 are no longer matched. We can partially
compensate for this by adding emitter resistors (negative feedback) as explained
in our [Lab 3.4: Emitter Resistors (Negative Feedback)]({% post_url 2017-09-18-aic-1-3-4-emitter-resistors-negative-feedback %}). 
_Keep in mind however, all of the emitter resistors for the output transistors
must add up to match that of Q1's single emitter resistor._

## MOS Devices

As noted in the book (refer to pages 3-6 and 3-7 [below](#references)), MOS
devices do not have a DC gate current which fortunately means we can add as many
output transistor devices as we want.

The only error to be concerned about is the current output dependence with drain
voltage. To compensate for this error, we can utilize some of the techniques
explored in previous lab reports e.g. adding source resistors (negative
feedback) or using a Wilson Current Mirror topology (though this topology is not
particularly optimal for MOS devices) among others.

A better alternative for MOS devices however, is to add a different cascode
stage at the output of each mirror and we will explore this topology in the next
lab report.

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-6 and 3-7) 

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-10-03-aic-1-3-8-scaling-currents-ratios %})
    + Lab 3.8: Current Mirrors -- Scaling Currents (Ratios)

* [Next report]({% post_url 2017-10-06-aic-1-3-10-mos-current-mirror-cascode-stage %})
    + Lab 3.10: Current Mirrors -- MOS Current Mirror With Cascode Stage 

{% include issues_comments.md %}
