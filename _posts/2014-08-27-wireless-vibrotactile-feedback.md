---
title: Wireless Vibrotactile Feedback
---

This project was the final project for my EE 478 Embedded systems capstone, a
little description of the project goes like this: The user of our device was to
be able to control a robotic manipulator via the use of EMG signals sent via
wireless RF simpliciTI protocol, further the force sensed at the tips of the
robotic manipulator when grasping an object was sent back via wireless and this
force was used to modulate the amplitude of a tactor's vibration to provide
force feedback allowing the user to control the amount of force he/she used and
to avoid a crushing fragile object e.g. fragile plastic cups, wine
glasses, Styrofoam cups ... etc.

Here is a 
[link to the video](https://youtu.be/c2x28yLYL-k)

Here is the complete project report:

[Wireless Vibrotactile Feedback Report](/assets/2014-08-27-wireless-vibrotactile-feedback_1.pdf)

And below are the pictures of a few important parts of the project:

![The EMG acquisition circuit](/assets/2014-08-27-wireless-vibrotactile-feedback_2.jpg)

Here is a brief description of the circuit, I am sorry since i did this sometime
ago and I cant remember the details but here it is, there is basically an
instrumentation amplifier circuit implemented using discrete op-amps, the
configuration is such as to give us the maximum common mode rejection ratio to
get rid of the electromagnetic noise surrounding all of us that introduce noise
into the EMG signals, after doing that we amplify the signal as much as possible
using an inverting amplifier scheme then passes that signal through
an electrolytic capacitor to get rid of any DC component, then we further
amplify the signal to bring it as close as possible to rails, then we take that
signal and pass it through a full wave rectifier so that we end up with an only
positive signal then we pass this through an active low pass filter with an
inverting configuration and finally we take that signal and invert it again and
we have a potentiometer to provide variable gain for users with different EMG
signals.

![EZ430RF2500 (MSP microcontroller with integrated CC2500 radio](/assets/2014-08-27-wireless-vibrotactile-feedback_3.jpg)

We used the micro controller to digitize the signal coming in from both the
force sensing resistors at the tip of the robotic manipulator and the signal
from the EMG acquisition circuit, the integrated radio is used for bidirectional
transmission.

It was a nice team project, hope you enjoyed the video and the pictures.
