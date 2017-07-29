---
title: Linux Tablet Computer Notes
layout: post
---

I hope this post will provide some brief pointers to all those aiming to explore
the functionality of Linux for tablet computers,.

My current distribution is: Linux Mint 17 Cinnamon (64 bit)

Current Computer: HP Elitebook 2760p

Helpful Notes:

* Make sure you check the application Xournal, its very minimal but has a lot 
of the features that I use to love from Windows OneNote, I personally really like it.


* Check that your current tablet Input devices are recognized by the OS, in 
the terminal type

> xinput list 

* Make sure the Wacom drivers or Atmel Graphic drivers are installed in your 
distribution, check the forums for your distribution.

* Set the properties for the drivers as needed (e.g. if you want to keep the 
touch OFF while keeping the stylus on) you can do the following (for wacom 
drivers only) from the terminal.

> xsetwacom set "Serial Wacom Tablet touch" Touch off

* Look into the help command for more options.

> xsetwacom -h 

Please refer to the Linux Wacom Project for more info:

[Linux Wacom Project](http://linuxwacom.sourceforge.net/index_old.php/howto/main)

Hopefully these tips prove helpful to all you note takers out there.
