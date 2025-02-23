---
title: 'HP Elitebook 2760p Linux Mint 22 Cinnamon setup'
---

This (future self reference) post aims to record the steps taken for setting up the HP elitebook
2760p as a working linux notebook using Linux Mint (22) as the distribution and Cinnamon as the desktop
environment of choice (this is an older notebook).

Note: this post will be a (forever) work in progress as optimization happens over time.

Bios setup
---

* Press Esc button

* Change the boot order to allow boot from USB

Install Windows
---
* Only used as needed, give it ~64GB (some tools still require windows to run)

Install Linux Mint
---
* Install alongside windows, allocate ~96GB to linux partition (we'll edit partitions later)

* Plus recommended system updates, then reboot PC

Check Grub
---
* Check that the grub menu displays both and that both OS'es boot

* Debug otherwise (it happens)

Partition drive
---
* Use gparted within the live USB to:

* Remove any windows unnecessary partitions (recovery, reserved ...etc)

* Create linux swap ~20GB partition

* Create data ntfs shared partition

Data partition
---
* Copy over data from external HDD

* Use Unison to sync Notebook and tablet

Use swap partition -- instead of swap file
---

* Same/similar as tablet setup (see blog post)

Automount shared data partition
---

* Same/similar as tablet setup (see blog post)

Enable hibernation
---

* Same/similar as tablet setup (see blog post)

Startup applications
---

* disable unnecessary default applications at boot

* Disable touch: `xsetwacom set "Wacom Serial Penabled 2FG Touchscreen Finger touch" Touch off`

* Remap jog dial left/right to pagedown/pageup  keys

~~~
sudo setkeycodes e006 104
sudo setkeycodes e007 109
~~~

* For this to work the commands need to be added to the sudoers file: `sudo vim /etc/sudoers.d/setkeycodes`

* And add the following lines

~~~
ALL ALL = NOPASSWD:/bin/setkeycodes e006 104                                                         
ALL ALL = NOPASSWD:/bin/setkeycodes e007 109
~~~

Power optimizations
---

* Install tlp for auto-optimizations (refer to tablet guide)

* Use powertop to monitor usage (refer to tablet guide)

Re-map Bezel hardware buttons
---

### Left/right jog dial

* The left/right jog dial needs to be remapped through setkeycodes and is executed at
  startup (see the startup applications section); it does not work through udev

### press jog dial

* The press jog dial to trigger full screen is done through udev (refer to the tablet setup for a bit
  more background)

* Edit hwdb file: `sudo vim /etc/udev/hwdb.d/61-keyboard-local.hwdb`

* Add the following lines:

~~~
# Input device ID: bus 0011 vendor 0001 product 0001 version AB83
# evdev:input:b<bus_id>v<vendor_id>p<product_id>e<version_id>-<modalias>
evdev:input:b0011v0001p0001*
 KEYBOARD_KEY_1c=f11
~~~

* Then update and trigger the rules:

~~~
sudo udevadm trigger
sudo systemd-hwdb update
~~~

Other recommended software apps
---
Install with your desired preferences
* Unison Sync
* Redshift
* VIM
* Thunderbird
* Plus others

{% include issues_comments.md %}

