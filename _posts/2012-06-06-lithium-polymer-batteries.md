---
title: Lithium Polymer Batteries
---

Over this last few months I have been learning a little bit about this
technology, which currently provides one of the best energy densities (meaning
you can pack more mAh in a smaller package) with a great charge / discharge
efficiency (the energy the battery can deliver as compared to that used to
charge it to full capacity) which is 98% theoretically (Wikipedia :) ). So I
decided to give it a try for a few of my projects, again the size of these
batteries for the same capacity of non-rechargeable AA or AAA or rechargeable
NIMH or NICD is great!

Now there are a few things to consider when using these batteries:

* Each lithium polymer cell is rated at 3.7 volts, however after charged its 
voltage oscillates around 4V, so make sure you have a regulator to be able 
to power devices running on 3.3 V.

* You can buy Li-Po battery packs of multiples of 3.7 volts (1s = 3.7 V, 2s =7.4 V, 
3s = 11.1 V, 4s = 14.8 V … etc.)

* You need to look at the battery charge and discharge rate (“the C rating”) 
to make sure that the battery can provide the current you need, and that you 
don’t charge the battery at a higher C rating or source more current than it  
can take since the battery might overheat and catch on fire!.

* You need to use a Lithium Polymer specific charger.

* For a single cell: You can use a single cell Lithium Polymer charger.

* For a multiple cell charger: You have to use a balance Lithium polymer 
charger rated for the battery capacity and for the number of cells you have.

* Do not overcharge Lithium Polymer batteries as again they might overheat 
and catch on fire.

* Do not over discharge Lithium Polymer batteries as they can get damaged,
you can’t let the battery voltage drop under 3V per cell under load that
means you can’t just leave the battery plugged in in your circuit idle as
it will discharge to 0 V. You have to design a circuit or use a micro
controller and read the battery voltage continuously and cut it off above
~3V.

Other Notes:

* If you are serious about using Li-Po’s consider buying a Lithium Polymer 
fire proof bag or “LIPOSACK” as a safety measure

* Always keep an eye on charging batteries, if a Li-Po battery is heating or 
deforming while charging disconnect it immediately.

* Make sure the balancer taps for the charger are the same as those of the 
battery pack

Here are a few pictures of the batteries I have been using for my projects:

![Battery Pictures](/linked_files/2012-06-06-lithium-polymer-batteries_1.jpg)

Ok, time to start cranking out your portable electronics ideas!

Hope it helps someone that is considering using Li-Po batteries, I will add some
more notes or items as I remember them, also let me know if I missed something

Thanks!

{% include issues_comments.md %}
