---
title: 'AIC-1.3.8: Current Mirrors -- Scaling Currents (Ratios)'
---

_The book does not provide simulation results for these pages, thus this report
is simply a brief lab note for future reference_.

## Bipolar Devices

**given a bipolar current mirror, how does one scale output currents?**

As noted in the book (refer to pages 3-5 [below](#references)), the current
ratio is determined by increasing or decreasing the geometry of one of the
matching transistors (Q1 or Q2 for for the 
[Widlar Current Mirror]({% post_url 2017-09-09-aic-1-3-1-widlar-current-mirror %})).
More specifically for a bipolar transistor the ratio is determined by the size
of the emitter -- the active emitter length. This is accomplished by increasing
the number (and size) of identical emitter diffusions as well as the number (and
size) of the surrounding base diffusions, subsequently the single collector
diffusion is increased proportionally in size (but not in number) to support
larger currents. (refer to book pages 1-19 [below](#references))

For example:

* **Scale Up:** By increasing the number of identical emitters to three for Q2, you
    **multiply** the output current by a factor of three relative to the current
    reference.

* **Scale Down:** By increasing the number of identical emitters to three for
    Q1, you **divide** the output current by a factor of three.

_Any ratio is possible by varying the emitter length of one of the current
matching transistors._ Keep in mind however that the base current of Q2 will
change proportionally with the scaled collector current and this will have
an effect in the base current error of the mirror.

## MOS Devices

**Given a MOS current mirror, how does one scale output currents?**

As noted in the book (refer to pages 3-6 [below](#references)), one can scale
the output current by varying the channel widths for the current matching
transistors (M1 or M2 for the 
[Simple MOS Current Mirror]({% post_url 2017-09-15-aic-1-3-3-simple-mos-current-mirror %})).
However a better alternative is to use multiple identical devices in parallel
which provides better matching.

## References

* [Textbook (Hans Camenzind)]({% post_url 2017-08-08-aic-1-course-syllabus %}#textbook) 
    + Chapter 3 (page 3-5 and 3-6) 
    + Chapter 1 (page 1-19)

* [AIC-1 Course Syllabus]({% post_url 2017-08-08-aic-1-course-syllabus %})

* [Previous report]({% post_url 2017-09-28-aic-1-3-7-four-transistor-current-mirror %})
    + Lab 3.7: Current Mirrors -- Four Transistor Current Mirror 

* [Next report]({% post_url 2017-10-03-aic-1-3-9-generating-multiple-currents %})
    + Lab 3.9: Current Mirrors -- Generating Multiple Currents

{% include issues_comments.md %}
