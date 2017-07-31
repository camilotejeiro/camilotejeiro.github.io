---
title: Using Workrave for Activity Breaks
---

We all know that taking activity breaks is a healthy habit, but like many
healthy habits, they can be hard to adopt.

Over the past few months, I have been using 
[Workrave](http://www.workrave.org/) with really good results.

* Micro-break: 1 min for every work-min.
	
* Rest-break: 10 mins for every work-hour.


note: this might seem excessive for activity breaks, but remember that this is
**work-time** (work-mins, work-hours ...etc) and **not elapsed time**, read on
if you are curious as to what this means.

The remaining part of this post covers some common questions and features of
Workrave.

### Natural Breaks vs. Prompted Breaks

In principle Workrave measures the time you are actively working on your
computer (by monitoring user input) and after a given amount of _work-time_, it
prompts you to take a break for X _rest-time_ **(this is a prompted break),**
after the break it restarts the work-time counter.

If on the other hand, you voluntarily take a break (e.g. by going to the
bathroom) for the same X rest-time. Workrave also treats this as a break and
restarts the work-time counter.

This raises another question:

### How does Workrave know when a user is actively using the computer?

In its simplest form, Workrave keeps track of keyboard and mouse user input. By
default if you press a key, it starts the work-time counter, but if it does not
see any user input within the next 5 seconds it pauses the counter and
additionally if you are inactive for X rest-time, it restarts the counter (it
assumes you just took a natural break).

_This is the reason why **work-time** is not jut the time elapsed, it can be
quite a bit more (e.g. 10 work-mins can end up being 20 actual minutes)._

### Noise Filtering Features

In addition, to better determine when you are actively using the computer (as
opposed to say playing a video or scrolling through your picture library
...etc), Workrave ships with some internal extra _noise-filtering_ features you
can tune, mainly:

#### Activity time

How far apart do two input events need to be to be considered a valid activity
i.e. to start the work-time counter.
	
* default activity-time setting: 1 second.

i.e. Workrave needs to see two or more input events in a one second window in
order to start the work-time counter.

#### Noise time

If two "events" (mouse movement or keystrokes) occur and the time between those
two events is more than noise time, the activity is ignored.
  
* default noise-time setting: 9 seconds.

e.g. starting in an idle state if you press a key and then 10 seconds later you
press another key, Workrave still considers you as being idle i.e. it does not
start the work-time counter.

#### Idle time

Idle time: after this time workrave considers the user idle and stops/pauses the
work-time counter.
	
* default idle-time setting: 5 seconds.

_See the question above for an example: How does Workrave know when a user is
actively using the computer?_

### Changing Workrave Internal Preferences: Modifying Noise Filtering Settings

For example, because I want every keystroke or mouse movement to be considered
an activity: I want to disable the activity-time and noise-time.

Here is an example of how you would do it through the terminal (Workrave 1.10.1
on Linux Mint 17).
	
* Activity-time, change to 0:

`gsettings set org.workrave.monitor activity 0`

* Noise-time, change to 0:

`gsettings set org.workrave.monitor noise 0`

* Idle-time, keep at default 5 seconds (for illustration-purposes only):

`gsettings set org.workrave.monitor idle 5000`

Then, check and make sure our settings were changed. Type in the terminal:

`gsettings list-recursively org.workrave.monitor`

And you should get your Workrave settings back:
    
`org.workrave.monitor activity 0 org.workrave.monitor idle 5000 
org.workrave.monitor noise 0` 

And that's it for today, thank you for watching!

{% include issues_comments.md %}
