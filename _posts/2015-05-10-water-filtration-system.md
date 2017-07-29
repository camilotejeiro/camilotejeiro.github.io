---
title: Water Filtration System
---

Can we build an open hardware expandable filtration system to keep our aquariums
clean with little maintenance?

_You can get all of the relevant files for this project at the bottom of this
post_

So I have two messy turtle pets that love to eat but don't like to clean up
after themselves :). In the past, every so often I had to take a few hours on
the weekend to dispose of the dirty water and clean up the tank thoroughly, then
fill the tank again with clean water and put the turtles back in. This was a
wasteful, inconsiderate (clean water is a limited resource, more so here in
CA) and time consuming process.

Much like other aquatic pet owners I wanted a better alternative and also I
wanted to learn a bit about CAD tools and 3D printers, it seemed like the
perfect opportunity to kill two birds with one shot.

With a bit of research I discovered that there are different kinds of water
contaminants, what you see is only half the story (i.e. large dirt residues) for
example there are chemical contaminants that can become toxic in large
concentrations without you ever noticing. Therefore in order for a filtration
system to be efficient all of the types of contaminants need to be considered.
In my case I decided to remove the contaminants by utilizing multiple filter
stages. It turns out that this is exactly the same approach that aquarium
canister filters use, that was reassuring, at least I was on the right path.

I settled on a very common filtration setup that seemed to be effective with
commercial filters with the option of increasing the number of stacked stages as
required to increase the efficacy of the filter:

Stage 1: Filter Head Mechanical filtration, cleans up large dirt residues, keeps
pump healthy and keeps the fine mesh filter (Stage 3) unclogged.

Stage 2: Pump.  The pump will be our second stage pumping the water up to the
other filtration stages, the pump stage needs to be submerged in the water.

Stage 3: Fine Mechanical Filtering Cleans up Small particles, mesh is fine
pitched (e.g. like coffee mesh )

Stage 3: Chemical Filtering Activated Carbon to remove toxic chemicals from
tank.

Stage 4: Biological Filtering Porous Ceramic Rings to provide the environment
for healthy bacteria to grow. At this point the water should be relatively
clean.

On top of the multiple filtration stages I wanted the filter to be placed inside
the tank to have the ability to work like a floor vacuum. Say for instance if
dirt accumulates in one corner of the tank you just do a quick floor sweep and
bingo the house is clean :)

So at this point I had lots of design drawings and a rough idea about the inner
details of each individual filter stage, all in text files and sketches (b.t.w
check out xournal is a pretty cool open source hand notes suite for linux, kind
of like OneNote for windows users).

Time to start the quick mechanical prototyping to identify the winner designs,
but there was a problem: no 3D printer yet, plus it seemed every print was going
to take forever and I had lots of little small ideas I wanted to try out. I
wanted some sort of  non-toxic water safe, stackable structures that I could
actually test out in the tank itself, any ideas?

I'll give you a hint: it involves overpriced plastic bricks, hehehe Legos! Oh
how they bring back good memories!

So for a while I tried multiple stackable geometries, multiple stages and filter
media. Leaving  the test setup in the tank for a few days at a time to see it's
effectiveness and make new improvements.

Finally with some rough technical specs in hand I was ready to start the CAD
modeling and bring the aquarium filter to life. In my search for a CAD modeler,
I found an awesome open source 3D CAD suite (http://www.freecadweb.org/).

Learning to use FreeCAD was very rewarding, while the learning curve was steep
seeing the sketched models with all the specs come to life was really exciting.

Having the first drafts of the 3D models ready, I needed a 3D printer to proof
the concept and tweak the final designs to be suitable for long term use. The
Printrbot simple kit seemed like a good candidate for my purposes,  the
assembly, calibration and setup of the 3D printer are described in 
[one of my previous posts]({% post_url 2015-02-18-printrbot-simple-1405-rev-f-3d-printer-startup-guide %}).  

After two spools of PLA (I put some research to understand potential toxicity
concerns in water, here is one interesting post: 
[http://www.quora.com/How-toxic-is-ABS-PLA](http://www.quora.com/How-toxic-is-ABS-PLA)) 
and lots of fine tuning in my models (getting the stages to be lego compliant
was kind of a pain: close to the bed the plastic expands and at the top it cools
off and contracts) I got the final design up and ready.

_Alright so at last to the substance of this post, here is the meat and the
veggies :)_

All of the CAD resources can be found in my 
[water filtration github repo](https://github.com/Osohm/water_filtration_system)

e.g. If you want to test drive the filter system you can browse to the
individual filter sub-directories, and simply use the .stl files to 3D print the
filter sections.

You will also need the following inexpensive items:

* Fine filter mesh: e.g. Marineland PA0100 Bonded Filter Pad, 312-Square-Inch.

* Biological filtration media: e.g. Fluval Biomax Bio Rings - 500 grams/17.63 
ounces.

* Chemical Filtration media: Activated carbon, e.g. Fluval Carbon, style C3.

* Water Hose:  Silicone Tubing 7/16-Inch OD x 5/16-Inch ID

* Water pump: just a standard aquarium water pump (mine is just a cheap one 
from e-bay)

The final filter sections are arranged as follows (starting from the bottom of
the tank to the top), each section with pictures:

sorry for the water, i took the pictures during a quick filter cleanup.

**Turtles Filter Head 1**

Function: Large mechanical Filtration

![Filter Head 1](/assets/2015-05-10-water-filtration-system_1.jpg)

**Turtles Filter Head 2**

Function: Large mechanical Filtration

![Turtles Filter Head 2](/assets/2015-05-10-water-filtration-system_2.jpg)

![Turtles Filter Head 2](/assets/2015-05-10-water-filtration-system_3.jpg)

**Turtles Pump Stage**

Function: Housing for the pump

![Turtles Pump Stage](/assets/2015-05-10-water-filtration-system_4.jpg)

![Water Pump](/assets/2015-05-10-water-filtration-system_5.jpg)

**Turtles Filter Stage 1**

function: Biological Filtration

![Turtles Filter Stage 1](/assets/2015-05-10-water-filtration-system_6.jpg)

**Turtles Filter Stage 2-Chemical**

function: Chemical Filtration

![Filter Stage 2-chem](/assets/2015-05-10-water-filtration-system_7.jpg)

![Chemical Filtration Stage](/assets/2015-05-10-water-filtration-system_8.jpg)

**Turtles Filter Stage 2-Mechanical**

function: fine mechanical filtration

![Filter stage 2 mech](/assets/2015-05-10-water-filtration-system_9.jpg)

And that's it those are all the stages of our filter: Filter Head 1, Filter
Head2, Pump Stage, Filter Stage 1, Filter Stage 2-chem, Filter Stage 2-mech.

**Complete Filter (Dirty after one month)**

Now here are some pictures of the dirty filter after operation for around one
month.

![Filter Dirty 1](/assets/2015-05-10-water-filtration-system_10.jpg)

![Dirty Filter 2](/assets/2015-05-10-water-filtration-system_12.jpg)

**Complete Filter (Clean)**

right after cleaning all of the filter sections.

![Filter Clean 1](/assets/2015-05-10-water-filtration-system_13.jpg)

![Filter Clean 2](/assets/2015-05-10-water-filtration-system_14.jpg)

In conclusion, the filter works better than I would have ever hoped for!

Enjoy and share with others :)
