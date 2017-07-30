---
title: Regarding KiCad Library Management - No Complaints
---

**It's actually not bad**

KiCad has more flexibility than most other CAD software packages (don't all open
source programs always do :)). You just have to keep in mind what official
libraries are (in Altium, KiCad, Eagle or any other PCB Cad package) and what
they will always be: **a starting point!** Never a personal manufacturing-ready
library.

You can always use the official libraries as a starting point when you are
learning (and having good official libraries - GitHub is a great move in this
direction - streamlines the process because you can follow tutorials, and copy
and paste good components) but you should **always make sure you build your own
personal libraries with only the components you need and are willing to
maintain**.

Why? because:

* You will never use all of the components that are published in the official repo.

* You can only maintain (i.e. keep verified) a small subset of the official 
    repo i.e. you can only guarantee the quality of the parts you work with.

* You must always verify the components you add to your projects, it is your  
    responsibility if the board comes back wrong (you cannot blame the official 
    libraries).

So yes, learn using the official libraries, go on and use them as a reference
(most land patterns are accurate) but **do make sure you put forth the time to
build and maintain your own libraries** and do it in a way that works best for
you. **Do not expect a one size fit all solution.**

_note: this post represents only my opinions_

{% include issues_comments.md %}
