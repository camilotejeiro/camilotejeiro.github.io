--- 
title: Open tools for circuit design - Learning QUCS, KiCad and Freecad
---

The Wah Pedal 
=============

Not so long ago a friend showed me a little circuit which I thought was quite
interesting ([The Wah Pedal](http://www.geofex.com/article_folders/wahpedl/wahped.htm)), 
a simple variable active filter with a couple of transistors but with no variable
reactive components. So I thought eventually, some day, I should take the time
to understand it more deeply, simulate it and put it in a little PCB; a great
example project for learning a couple of new design tools. Well I did!

The Final Design 
---

### The Circuit simulation

![wah pedal simulation](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_1.png)

### The Board Layout


* Note that [stitching vias around the ground plane](https://forum.kicad.info/t/via-stitching-in-pcbnew/138) 
    is somewhat counterintuitive.

### The 3D Model

![wah pedal 3d view](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_3.png)

_Below you can find more information about how this board came about.
Specifically about the open tools I used and the learning process. At the end
you can find the design linked_files._

### The Printed Circuit Boards

![Individual PCB](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_4.jpg)
![Multiple PCBs](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_5.jpg)

## Choosing the tools

For a while now I have been meaning to find a set of open
([FLOSS](https://en.wikipedia.org/wiki/Free_and_open-source_software)) tools
that I can learn and use for my [future hardware projects](https://osohm.org/projects/). 
Specially I was looking for circuit simulation, PCB design and 3D CAD modeling software.

I came across the following viable alternatives (though there are a lot more):
    
* Circuit Simulation
    - [QUCS](http://qucs.sourceforge.net/)
    - [Ngspice](http://ngspice.sourceforge.net/)
    
* PCB Design
    - [KiCad](http://kicad-pcb.org/)
    - [gEDA](http://www.geda-project.org/)
    
* 3D CAD Modeling
    - [FreeCAD](http://www.freecadweb.org/)
    - [OpenSCAD](http://www.openscad.org/)

After some research (I use [Open Hub](https://www.openhub.net/) quite a bit) and
some tinkering with each software I settled on: QUCS, KiCad and FreeCAD.

## Learning QUCS

I went over to their [documentation](http://qucs.sourceforge.net/docs.html) page
and completed their [getting started tutorial](http://qucs.sourceforge.net/docs/tutorial/getstarted.pdf); 
It was well written and easy to follow. In Qucs, the user interface and the overall process
is quite intuitive so I was up and running in no time.

After completing the tutorial I started my own QUCS project for simulating the
Wah Pedal: finding the component models, wiring the schematic, setting up the
sources, preparing the simulations ...etc. _Except for a few hiccups here and
there (for help, you can [join their mailing list](https://lists.sourceforge.net/lists/listinfo/qucs-help)), 
things went pretty smooth. No complaints._

## Learning KiCad

The process of learning KiCad to use it for my own project was as follows (your
mileage may vary):
    
1. Read the [Getting Started](http://docs.kicad-pcb.org/stable/en/getting_started_in_kicad.html)
Guide and Complete the KiCad example project.
    
2. **Briefly** read all the [docs](http://kicad-pcb.org/help/documentation/)
about every KiCad software component (e.g. KiCad Project Manager, EESchema,
PCBNew ...etc). It really helps to know how everything fits together (perfect
opportunity to grab a latte and spend a relaxed afternoon reading about KiCad).

3. Learn about KiCad Libraries, and how to build your own components (don't
listen to the rants :) ): 
    - Schematic Library Editor
    - Footprint Library Editor

4. Create your own personal component's library [here's why]({% post_url 2016-04-22-regarding-kicad-library-management-no-complaints %})
    - Here are the [Kicad Library Conventions](https://github.com/KiCad/kicad-library/wiki/Kicad-Library-Convention)
        (KLC).  
    - Here are [my own library conventions](https://github.com/camilotejeiro/kicad_cat_libraries/blob/master/kicad_cat_library_conventions.md)
        (very similar to KLC).  
    - Here are [my libraries for reference](https://github.com/camilotejeiro/kicad_cat_libraries) (these are constantly changing).

> Try to always build your libraries on a **need to have basis**, do not build
> parts you don't need (more parts **does not** mean better libraries).
> Otherwise they will go unmaintained and mix with the good parts and clutter
> your libraries making them useless. (i.e. you don't know which parts are good
> anymore)

After you build your libraries for every component you need in the circuit, you
can proceed to create the schematic project in EESchema, assign footprints to
finally plot the Gerbers for manufacturing.

## Learning FreeCAD

In KiCad you need some 3D models to assign to your footprints such that the
whole board can be rendered nicely and you can inspect for mistakes before
sending the board to the fab.

Normally, KiCad 3D component models are built with [Wings 3D](http://www.wings3d.com/), 
but we need FreeCAD to import the .stp linked_files we get from the manufacturers 
(plus I have a little bit of experience working with FreeCAD).

My learning process for FreeCAD (as it relates to KiCad) went like this:

1. [FreeCAD Getting Started Guide](http://www.freecadweb.org/wiki/?title=Getting_started): 
    Quick Read.

2. [Part Design Basic Tutorial](http://www.freecadweb.org/wiki/index.php?title=Basic_Part_Design_Tutorial):
    Super helpful, but optional if you are in a rush.

3. Building 3D component models using the manufacturer CAD STEP file.
    - [Build and export directly for KiCad](https://www.youtube.com/watch?v=O6vr8QFnYGw) 
        using the [StepUp](https://sourceforge.net/projects/kicadstepup/) Tool.

4. Building Kicad component models from scratch based on the manufacturer
    datasheet.
    - [Build the component model yourself](https://www.youtube.com/watch?v=S63DLV5HOPA) 
        using FreeCAD.
    - [Export the model to Wings 3D](https://www.youtube.com/watch?v=bGp9ejC2vU8) 
        for coloring and creating the .wrl file for compliance with KiCad.

After you are done building your models and you have exported the .wrl linked_files
that KiCad needs, open up the footprint editor in KiCad and assign your 3D
models to their respective footprints (footprint properties -> 3D models).

Here are some models I built while learning:

![potentiometer](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_6.png)

![inductor](/linked_files/2016-05-03-open-tools-for-circuit-design-learning-qucs-kicad-and-freecad_7.png)

## The linked_files

And finally,
    
* Here are the [design linked_files](https://github.com/camilotejeiro/the_wah_pedal) 
    for the Wah Pedal Project.

* And the [shared project](https://oshpark.com/shared_projects/yCZvyTVz) ready 
    for fabrication through OSH Park.

Hope it helps someone, somewhere, anywhere? :)

Enjoy and share with others!

Feedback? questions? Please let me know in the comments below.

{% include issues_comments.md %}
