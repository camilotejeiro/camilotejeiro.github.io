---
title: 'Panasonic FZ-G1 Linux Mint 22 XFCE setup'
---

This (future self reference) post aims to record the steps taken for setting up the Panasonic FZ-G1
as a working linux tablet using Linux Mint (22) as the distribution and XFCE as the light desktop
environment of choice (this is an older tablet).

Note: this post will be a (forever) work in progress as optimization happens over time.

Bios setup
---

* First make sure you have the latest bios install: do this from windows

* Afterwards, reboot the PC

* Press F2 or the A2 bezel button

* Change the boot order to allow boot from USB

* (not needed, reference only) Optional kit configuration password: toughkit

Install Linux Mint
---

* Install alongside windows, allocate ~64GB to linux partition (we'll edit partitions later)

* Plus recommended system updates, then reboot PC

Intel CPU c-states
---

* Temporarily resolves issue with freezing on idle by reducing deepest cstate processors are allowed
  to go to, also it's better to use teo cpuidle governor

* Edit: `sudo vim /etc/default/grub`

* Add to the end of the line for: `GRUB_CMDLINE_LINUX_DEFAULT="cpuidle.governor=teo intel_idle.max_cstate=7`

* Afterwards: `sudo update-grub`

* And reboot the PC

Partitions: custom setup Linux + Windows
---

* Disable windows recovery partition ~0.5GB, from an admin command line on windows: `reagentc /disable` 

* Then back on linux

* Use Gparted to delete it as we are not intending to use it.

* Extend linux ext4 partition to use the freed up ~0.5GB space

* Re-size windows partition down to ~64GB (to be seldom used, but to have handy)

* Create data NTFS partition with free'ed up space ~110GB (to be shared between Windows and Linux)

* Now boot linux from live USB (swap order on BIOS):

* Re-size linux system partition down by 11GB to 

* Use free'ed up ~11GB space for swap partition

* Apply and reboot

### Use swap partition instead of swap file

* Turn swap off: `sudo swapoff /swapfile`

* Update fstab file to remove swapfile line: `sudo vim /etc/fstab`

* Now remove the actual swapfile: `sudo rm -f /swapfile`

* Re-open fstab file and add: `UUID=xyz none swap sw 0 0`

* Replacing xyz above for the swap partition UUID

* turn swap on: `sudo swapon -a`

* check it's working: `swapon`

### Automount shared data partition

* Edit fstab file and add the shared data partition: `sudo vim /etc/fstab`

* Add a line of the like: `UUID=xyz /media/user/data ntfs-3g users,permissions,exec,noatime 0 0`

* Where xyz is the UUID of the shared data partition and user is your username

* Save and close

Enable hibernation
---

* Make sure secure boot is not enabled: `sudo mokutil --sb-state`

* Check that swap has been setup and is enabled: `sudo swapon`

* Edit the grub file: `sudo vim /etc/default/grub`

* Append to the line: `GRUB_CMDLINE_LINUX_DEFAULT="resume=/dev/sda6"`

* Update grub: `sudo update-grub`

* Add option to shutdown menu: `sudo vim /etc/polkit-1/rules.d/10-enable-hibernate.rules`

* Add the following lines

```
polkit.addRule(function(action, subject) {
    if (action.id == "org.freedesktop.login1.hibernate" ||
        action.id == "org.freedesktop.login1.hibernate-multiple-sessions" ||
        action.id == "org.freedesktop.upower.hibernate" ||
        action.id == "org.freedesktop.login1.handle-hibernate-key" ||
        action.id == "org.freedesktop.login1.hibernate-ignore-inhibit")
    {
        return polkit.Result.YES;
    }
});
```

Log-in with pin code
---

* Make sure you have the libraries needed: `sudo apt install libpam-pwdfile whois`

* Create the pin file: `sudo sh -c 'echo "username:$(mkpasswd -5)" > /etc/mypinfile'`

* Change the permissions to restrict r only to user: `sudo chmod 400 /etc/mypinfile`

* Create back-up: `sudo cp /etc/pam.d/lightdm /etc/pam.d/lightdm.backup`

* Update file: `sudo vim /etc/pam.d/lightdm`

* Inserting the new line: `auth sufficient  pam_pwdfile.so pwdfile=/etc/mypinfile`

Startup applications
---

* Disable blueman applet (bluetooth)

* Disable geoclue demo agent

* Disable "Support for NVIDIA..."

* Disable Warpinator

* Disable mintwelcome

* Enable onboard

* Disable print queue applet

Enable touch and pen, and bind to tablet screen: script and panel button
---
Script below, added to a launcher icon and placed in the panel
```
#!/bin/bash
# update coordinates to get touch working in landscape mode with dual monitors
xinput map-to-output 'eGalax Inc. eGalaxTouch EXC3102-1099-06.00.02' eDP-1
xinput map-to-output 'Wacom ISD-V4 Pen stylus' eDP-1
xinput map-to-output 'Wacom ISD-V4 Pen eraser' eDP-1

xinput enable 'eGalax Inc. eGalaxTouch EXC3102-1099-06.00.02'
xinput enable 'Wacom ISD-V4 Pen stylus'
xinput enable 'Wacom ISD-V4 Pen eraser'

# start touchegg service -- need to be in sudoers file
sudo systemctl start touchegg
```

* Added as well to cron to execute at reboot: `sudo contrab -e`

* Add the following line to the cron file: `@reboot sh /media/user/data/path_to_file/bind_touch_pen_edp1.sh`

Enable pen / Disable touchscreen: script and panel button
---
Script below, added to a launcher icon and placed in the panel
```
#!/bin/bash
xinput disable 'eGalax Inc. eGalaxTouch EXC3102-1099-06.00.02'
xinput enable 'Wacom ISD-V4 Pen stylus'
xinput enable 'Wacom ISD-V4 Pen eraser'

# disable touchegg service -- needs to be in sudoers file
sudo systemctl stop touchegg
```

Enable touchscreen / Disable pen: script and panel button
---
Script below, added to a launcher icon and placed in the panel
```
#!/bin/bash
xinput enable 'eGalax Inc. eGalaxTouch EXC3102-1099-06.00.02'
xinput disable 'Wacom ISD-V4 Pen stylus'
xinput disable 'Wacom ISD-V4 Pen eraser'

# enable gestures -- make sure sudo enabled in sudoers file
sudo systemctl start touchegg
```

* For the above scripts make sure to add a sudoer file 

* Cd to the directory: `cd /etc/sudoers.d`

* Add the following lines

```
ALL ALL = NOPASSWD:/bin/systemctl stop touchegg
ALL ALL = NOPASSWD:/bin/systemctl start touchegg
```

Rotate screen toggle: script and panel button
---
Script below, added to a launcher icon and placed in the panel
```
#!/bin/bash
case $(xrandr -q --verbose | grep eDP-1 | sed 's/primary //' | awk '{print $5}') in
    normal) # currently screen is not rotated, next is right
        xrandr --output eDP-1 --rotate right
        ;;
    right) # currently top is rotated right, next is inverted
        xrandr --output eDP-1 --rotate inverted
        ;;
    inverted) # currently top is rotated inverted, next is left
        xrandr --output eDP-1 --rotate left
        ;;
    left) # currently top is rotated left, next is normal
        xrandr --output eDP-1 --rotate normal
        ;;
    esac
# re-bind touch and pen to eDP-1, call script
bash bind_touch_pen_edp1.sh
```

Power optimizations
---

* Install tlp for auto-optimizations: `sudo apt-get install tlp`

* Use powertop to monitor usage: `sudo apt-get install powertop`

* Inspect all report via powertop, especially regarding c-states

Re-map Bezel hardware buttons
---

### A1
**to-do:** no scancodes -- kernel does not map this buttons

### A2
**to-do:** no scancodes -- kernel does not map this buttons

### Volume up and down
* We want to re-map these to page up and page down keys

* First find out scancodes of the bezel buttons: `sudo evtest`

* Choose the number corresponding to "Panasonic Laptop Support"

* Get the modalias (replace x below with number from above as well): `cat /sys/class/input/eventx/device/modalias`

* Copy down all characters before "-" (not including -)

* Update the file: `sudo vim /etc/udev/hwdb.d/61-keyboard-local.hwdb`

* And add the following lines:

```
evdev:input:{number-above}*
 KEYBOARD_KEY_05=pagedown
 KEYBOARD_KEY_06=pageup
```

### Rotate

* On the bios setup 

* Change the mapping of the rotate button to ctrl+alt+del (to allow you to see it once you boot up on linux)

* Then on the 61-keyboard-local.hwdb file, In a different line do

```
evdev:input:{number-above}*
 KEYBOARD_KEY_38=f8
```

* Notice the space before the KEYBOARD word

* Then re-generate database and re-load codes

```
sudo systemd-hwdb update
sudo udevadm trigger
```

* Then to execute the rotation script upon pressing the rotate button 

* Map f8 to the rotation script with the system utility

### Windows
* This button is mapped correctly to open app menu

UI and appearance
---

* appearance --> Settings --> Window Scaling: 2x

* appearance --> custom DPI setting --> 80

* Window manager --> Theme: Default-xhdpi

* Panel preferences --> Items --> Whisker Menu --> Behavior: Uncheck stay visible when focus is lost

* Setup the panel as desired

* Thunar --> Edit -> Preferences -> Behavior -> Navigation -> Single click to activate items: yes

* Mouse and Touchpad --> Theme --> Cursor size: 32

* Login Window" > Settings > HiDPI support : Enable.

* Login Window" > Settings > On-screen keyboard layout : Phone.

* Setup power management settings as desired

### Enable scrollbars visibility 

`vim ~/.config/gtk-3.0/settings.ini`

~~~
[Settings]
gtk-overlay-scrolling = false
~~~

* Increase scrollbars size

`vim ~/.config/gtk-3.0/gtk.css`

```
/* Set thickness of scrollbars */
scrollbar.vertical slider {
    min-width: 15px;
}
scrollbar.horizontal slider {
    min-height: 15px;
}
```

* On firefox about:config

`widget.non-native-theme.scrollbar.size.override 30`
`widget.non-native-theme.scrollbar.style 4`

* On firefox: Settings > General > Browsing > Always show scrollbars 

* On .profile file add

`export GTK_OVERLAY_SCROLLING=0`

* On thunderbid: Settings --> Always show scrollbars

Gestures support
---

### Enable scrolling via touch

* For firefox, type

`sudo vim /etc/security/pam_env.conf`

* go to the end of the file and add this line:

`MOZ_USE_XINPUT2 DEFAULT=0       OVERRIDE=1`

### Enable long touch = right click

**Not working so well, can omit this section**

We will be using PeterCxy evdev right click emulation program

* Install dependencies

`sudo apt-get install libevdev-dev`
`sudo apt-get install livevdev-tools`

* Download zip from [Evdev right click emulation](https://github.com/PeterCxy/evdev-right-click-emulation)

* [Fix Makefile for evdev right click emulation](https://github.com/PeterCxy/evdev-right-click-emulation/pull/5/commits/06c9506ce8cbb4d741f852359d7b77e300b12e49)

* Extract contents locally and make: `make all`

* Now update crontab to make sure it's launched on startup, update data path for your case: `sudo crontab -e`

* Add the following line: `@reboot /home/username/folder_where_the_file_located/evdev-right-click-emulation-master/out/evdev-rce`

* Update environment variable to reduce long touch time to right click (todo)

### Gestures support with touchegg

* Install [Touchegg](https://github.com/JoseExposito/touchegg)

* Install helper config GUI app: [Touche](https://github.com/JoseExposito/touche)

* For two finger scrolling, we will also need [xdotool](https://github.com/jordansissel/xdotool)

* Define your desired gestures, in my case, after some thought and use:

```
Gesture/fingers |      1     |        2        |     3       |      4       |      5      |
----------------|------------|-----------------|-------------|--------------|-------------|  
Tap             |Left-click  |Alt. Right-click |Middle-click |Apps Menu     |Full screen  |
----------------|------------|-----------------|-------------|--------------|-------------|
Hold            |Right-click |N/A              |N/A          |N/A           |N/A          |
                |(disabled)  |                 |             |              |             |
----------------|------------|-----------------|-------------|--------------|-------------|
Swipe Up        |Scroll-down |Alt. Sroll-down  |Tile-up      |Prev. Desktop |Screenshot   |
----------------|------------|-----------------|-------------|--------------|-------------|
Swipe Down      |Scroll-up   |Alt. Scroll-up   |Tile-down    |Next Desktop  |Onboard KBD  |
----------------|------------|-----------------|-------------|--------------|-------------|
Swipe Left      |Scroll-right|Alt. Scroll-right|Tile-left    |Prev. Open App|Files Browser|
----------------|------------|-----------------|-------------|--------------|-------------|
Swipe Right     |Scroll-left |Alt. Scroll-left |Tile-right   |Next Open App |Web Browser  |
----------------|------------|-----------------|-------------|--------------|-------------|
Pinch In        |N/A         |Zoom out         |Minimize Win.|Show Desktop  |Close Window |
----------------|------------|-----------------|-------------|--------------|-------------|
Pinch Out       |N/A         |Zoom in          |Maximize Win.|Windows Menu  |Hibernate    |
----------------|------------|-----------------|-------------|--------------|-------------|
```

* Apply the above gestures table using touche

* Make sure keyboard shortcuts are properly setup on the windows manager

* Or alternatively edit the touchegg config file: `vim ~/.config/touchegg/touchegg.conf`

* Adding these lines, these also show how the gestures were mapped in more detail

```
<touchégg>
  <settings>
    <property name="animation_delay">150</property>
    <property name="action_execute_threshold">20</property>
    <property name="color">auto</property>
    <property name="borderColor">auto</property>
  </settings>
  <application name="All">
    <gesture type="SWIPE" fingers="2" direction="DOWN">
      <action type="RUN_COMMAND">
        <repeat>true</repeat>
        <command>xdotool click 4</command>
        <decreaseCommand>xdotool click 5</decreaseCommand>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="2" direction="UP">
      <action type="RUN_COMMAND">
        <repeat>true</repeat>
        <command>xdotool click 5</command>
        <decreaseCommand>xdotool click 4</decreaseCommand>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="3" direction="LEFT">
      <action type="TILE_WINDOW">
        <direction>left</direction>
        <animate>true</animate>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="3" direction="RIGHT">
      <action type="TILE_WINDOW">
        <direction>right</direction>
        <animate>true</animate>
      </action>
    </gesture>
    <gesture type="TAP" fingers="2" direction="UNKNOWN">
      <action type="MOUSE_CLICK">
        <button>3</button>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="TAP" fingers="3" direction="UNKNOWN">
      <action type="MOUSE_CLICK">
        <button>2</button>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="PINCH" fingers="2" direction="IN">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>minus</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="PINCH" fingers="2" direction="OUT">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>equal</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="PINCH" fingers="3" direction="IN">
      <action type="MINIMIZE_WINDOW"></action>
    </gesture>
    <gesture type="PINCH" fingers="3" direction="OUT">
      <action type="MAXIMIZE_RESTORE_WINDOW"></action>
    </gesture>
    <gesture type="SWIPE" fingers="3" direction="UP">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>Super_L+Up</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="3" direction="DOWN">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>Super_L+Down</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="TAP" fingers="4" direction="UNKNOWN">
      <action type="RUN_COMMAND">
        <command>xfce4-popup-whiskermenu</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="TAP" fingers="5" direction="UNKNOWN">
      <action type="FULLSCREEN_WINDOW"></action>
    </gesture>
    <gesture type="SWIPE" fingers="5" direction="DOWN">
      <action type="RUN_COMMAND">
        <command>xfce4-screenshooter -r</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="5" direction="UP">
      <action type="RUN_COMMAND">
        <command>onboard</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="5" direction="LEFT">
      <action type="RUN_COMMAND">
        <command>thunar</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="5" direction="RIGHT">
      <action type="RUN_COMMAND">
        <command>firefox</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="PINCH" fingers="4" direction="OUT">
      <action type="RUN_COMMAND">
        <command>xfdesktop --windowlist</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="PINCH" fingers="4" direction="IN">
      <action type="SHOW_DESKTOP"></action>
    </gesture>
    <gesture type="PINCH" fingers="5" direction="IN">
      <action type="CLOSE_WINDOW"></action>
    </gesture>
    <gesture type="PINCH" fingers="5" direction="OUT">
      <action type="RUN_COMMAND">
        <command>systemctl hibernate</command>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="2" direction="LEFT">
      <action type="RUN_COMMAND">
        <command>xdotool click 7</command>
        <repeat>true</repeat>
        <animation>NONE</animation>
        <decreaseCommand>xdotool click 6</decreaseCommand>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="2" direction="RIGHT">
      <action type="RUN_COMMAND">
        <command>xdotool click 6</command>
        <repeat>true</repeat>
        <animation>NONE</animation>
        <decreaseCommand>xdotool click 7</decreaseCommand>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="4" direction="UP">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>Alt_L+Right</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="4" direction="DOWN">
      <action type="SEND_KEYS">
        <modifiers>Control_L</modifiers>
        <keys>Alt_L+Left</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="4" direction="LEFT">
      <action type="SEND_KEYS">
        <modifiers>Alt_L</modifiers>
        <keys>Tab</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
    <gesture type="SWIPE" fingers="4" direction="RIGHT">
      <action type="SEND_KEYS">
        <modifiers>Alt_L</modifiers>
        <keys>Shift_L+Tab</keys>
        <repeat>false</repeat>
        <animation>NONE</animation>
        <on>begin</on>
      </action>
    </gesture>
  </application>
</touchégg>
```

Other recommended software apps
---
Install with your desired preferences
* Cheese (camera: front and back cameras work)
* Redshift
* Unison Sync
* VIM
* Thunderbird

Related sources:
---

* [How to optimize XFCE4 for tablets](https://blog.bitsandbobs.net/blog/xfce-for-tablets)
* [Enable hibernate Linux Mint] (https://fostips.com/enable-hibernate-linux-mint)
* [Bios sub-configuration passwords Panasonic toughbook](https://www.reddit.com/r/toughbook/comments/t7ben5/bios_sub_configuration_passwords_able_to_reset/)
* [Log into linux with pin number](https://fostips.com/log-into-linux-pc-pin-number/)
* [How Can I Make Mint XFCE More Touch Friendly?](https://forums.linuxmint.com/viewtopic.php?t=413583)
* [Evdev right click emulation](https://github.com/PeterCxy/evdev-right-click-emulation)
* [Fix Makefile for evdev right click emulation](https://github.com/PeterCxy/evdev-right-click-emulation/pull/5/commits/06c9506ce8cbb4d741f852359d7b77e300b12e49)
* [How to get make to find libevdev objects](https://stackoverflow.com/questions/69461211/how-to-get-make-to-find-libevdev-objects)
* [Guide enabling right click emulation](https://www.reddit.com/r/xfce/comments/k5e0fu/guide_enabling_right_click_simulation_on)
* [Scrollbar width](https://www.reddit.com/r/firefox/comments/ujo1xy/how_to_increase_firefox_100_scrollbar_width)
* [Remap keyboard keys ubuntu](https://ubuntuhandbook.org/index.php/2024/09/remap-keyboard-keys-ubuntu)
* [Touche](https://github.com/JoseExposito/touche)
* [Touchegg](https://github.com/JoseExposito/touchegg)
* [xdotool](https://github.com/jordansissel/xdotool)

{% include issues_comments.md %}

