---
title: 'Audio Sensory Substitution'
---

Ever since I worked on sensory substitution projects during my undergrad years, I have been thinking
of the idea of somehow using the same concept to allow audio sensory substitution through
vibrotactile feedback i.e. being able to somehow record and convert an audio stream to 
to a spatial arrangement (grid or otherwise) of multiple tactors on a person skin.

Later on, spending time with my family back home (I have some relatives who are deaf), I noticed
that they were able to dance as long as the bass marked the beat and the rythm of the song; I though this
was really neat and got me thinking again if it was possible to somehow devise a means of auditory
sensory substution that could make use of tactile feedback.

_A bit of very simplified technical background, omitting many details: skip if desired_

During my grad school years I had a chance to take classes in radio-frequency (RF) integrated
circuit (IC) design and I learned of frequency (mixer) up/down conversion as a staple of RF design.

Frequency up-conversion is used in RF transmitter (TX) chains to take baseband signals (say 20KHz audio) 
to high RF frequencies (say 2.4GHz + 20KHz) via use of a mixer with a local oscillator (LO here is at 2.4GHz).  

Conversely, frequency down-conversion is used in RF receiver (RX) chains to take RF signals (say the
same 2.4GHz + 20KHz) down to baseband frequencies (back to 20KHz audio) via use of a mixer down-converter
with an LO (LO here is at 2.4GHz as well); one can come down to an intermediate frequency (IF)
instead (advantageous in many cases) but that is another topic.

_End of bit of technical part is here ;)_

The cool thing about the frequency up/down conversion technique is that we can apply it in a similar fashion
to the audio sensory substitution idea. 

Imagine the following, we have an audio signal with a bandwidth of 20KHz (a bit less for adults but
that's ok), we can filter and divide the 20KHz bandwidth into say 200 x 100Hz bins which we then
down-convert independently and use to drive 200 vibrotactile transducers (channels) each with a 100Hz
bandwidth (vibrotactile bandwidth is a bit less than 100Hz but that's close enough).

In reality it's a bit simpler (or more complex depending on how you see it ;)), we can use multiple
low-frequency local-oscillators (each at 100Hz from each other, but no need to be very precise) that
we can use as inputs to independent passive mixers. Once down-converted, at baseband we can use identical 
100Hz bandwidth low-pass-filters (LPFs) followed by identical output drivers .  

The above is very (very) simplified, and to be scalable to many channels, it will really benefit
from integration. 

Note we have not discussed the human interface factors which are most important and can in some
cases simplify our design. 

As an example, our auditory perception approximately follows a logarithmic scale base 2 i.e.
Although an octave in music represents a doubling in frequency, we "feel" a musical octave as a
linear increase in pitch, our auditory system uses a logarithmic front end to increase the dynamic
range of signals we can hear, additional questions arise also with regards to the filtering function
of the ear itself at high frequencies. What about the frequency response of our vibro-tactile sense?
From the above and many other human factors research, we can come up with interesting ideas for how
we divide and equalize the input audio spectrum, the down-conversion and baseband signal processing
and lastly the output drive requirements.

If I wasn't so busy this would be the first project on my list! But I will get around to it, life is
just too short for certain things and too long for others.

