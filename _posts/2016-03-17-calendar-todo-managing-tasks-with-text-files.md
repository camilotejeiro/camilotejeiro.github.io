---
title: Text Simple Planner, Managing Tasks With Text Files
---

> No fancy apps, plain and simple, just a text based planner.

This post is for those that love the utter simplicity and flexibility of text
files (.txt), the following are some advantages you might have heard of :

1. You can open text files literally anywhere (your phone, your tablet, your
desktop computer ...etc) and they are supported by every operating system I
know of (talk about cross-platform).

2. You don't need any special software to open text-files (no calendar,
planning apps ...etc. none of that nonsense), hell you can even use a browser
(not that you would particularly want to do that).

3. Completely open format.

4. No [vendor lock-in](https://en.wikipedia.org/wiki/Vendor_lock-in). (thanks
to bullet points 1, 2 and 3) This is extremely important: i.e. do you want to
be forced to purchase a copy of your favorite planning software just to be
able to open your notes? or do you want to be monitored 24x7 to be served with
"better ads"? better ads, for who? Nah. (Here is more info on the [benefits of
open formats/technology](https://osohm.github.io/faq/))

5. Dead simple interface. What you see is what you get, and it ain't pretty,
no fancy colors or multiple fonts or ... you get the point. I personally don't
care too much about these except when you have to send it to other people and
they complain (so you have to put a nice ribbon around it).

So a while ago (a couple of years ago) I started to use text files to handle my
day to day planning, it was a bit rough at the beginning but over the years the
system has evolved and has gotten more efficient, to the point where it might
actually be useful to others (though nowhere as developed as
[Todo.txt](http://todotxt.com/) or other applications).

Here is the [default directory setup](https://github.com/Osohm/text_simple_planner/tree/master/templates) 
with folders and text files, plus spreadsheet and drawing files (I know, I know, I
cheated but sometimes these are useful for formulas, tables, block diagrams
...etc, plus they are open tools):


and here is my personal setup in use (note that I keep a reference of old files
simply by appending a date at the end, current files are undated):

```
    notes_templates
    ├── ideas_projects
    │   └── ideas_projects.txt
    ├── inkpad
    │   └── inkpad.xoj
    ├── license
    ├── quotes
    │   └── quotes.txt
    ├── readme.md
    ├── spreadsheet
    │   └── spreadsheet.ods
    ├── textpad
    │   └── textpad.txt
    └── todo
        ├── calendar_todo.txt
        ├── pending_todo.txt
        └── recurrent_todo.txt
```

And I just keep a simple text editor open to edit the files directly (I am using
[Geany](http://www.geany.org/)).

![notes workspace](/assets/2016-03-17-calendar-todo-managing-tasks-with-text-files_1.png)

Finally here is a brief snippet illustrating how each one of these text files
looks like (I loosely use [Markdown](https://en.wikipedia.org/wiki/Markdown) for
the syntax, just for aesthetics) and how I use them in my real day to day
planning (If you haven't done so, go on and download the 
[template setup](https://github.com/Osohm/text_simple_planner/tree/master/templates) 
from my Github account, otherwise the next paragraphs might not make much sense, you
have been warned, hey).

**camilo_ideas_projects.txt**

```
    **********************
    # Ideas and Projects #
    **********************
    
    ***********************
    ## Quick Guidelines. ##
    ***********************
    Only project ideas and ongoing projects should be here, 
    the rest should be moved out and stored in our textpad 
    for reference.  
    
    **********************
    ## Current Projects ##
    **********************
    
    ----
    ### Assorted book summaries (part-time).
    ----
    Ongoing transcription of book summaries from finished 
    common books.
    [...]
    
    *********************
    ## Future Projects ##
    *********************
    
    ----
    ### Search Notes Script - Add support for ODF formats.
    ----
    It can search in all text files as well as open 
    spreadsheets and other open office documents.
    [...]
```

**camilo_quotes.txt**

```    
    **********
    # Quotes #
    ----------
    ## 2016 ##
    **********
    
    Perfection is impossible. Improvement is our goal.
    
    Listen attentively and ask questions. Always give 
    others the benefit of doubt.
    
    Have a general intuitive understanding of physics, 
    and a deep understanding of a single specific area 
    of research. 
    
    While proprietary technology will probably continue 
    to be our standard for product development, our 
    efforts to grow open technology as a viable 
    alternative will plant the seed that will inspire 
    future generations to bring about change.
    [...]
```

**camilo_textpad.txt**

```
    ************
    # Textpad #
    -----------
    ##  2016  #
    ***********
    
    ----
    ### C and C++, a couple of notes.
    ----
    C is designed to model how the hardware processes the 
    information (forcing the programmer to understand the 
    hardware details) C++ is designed to model how the 
    programmer/user thinks when designing complex 
    applications (while still allowing those 
    interested/curious to peak under the hood.)
    
    #### Practical usage.
    [...]
    
    ----
    ### KiCad Libraries
    ----
    It's actually not bad, KiCad actually has more 
    flexibility than any other CAD software package 
    (don't all open source programs always do :)). You 
    just have to keep in mind what official libraries 
    are (in Altium, KiCad, Eagle or any other PCB Cad 
    package) and what they will always be: a starting 
    point. Never a personal manufacturing-ready library. 
    You can always use the official libraries as a 
    starting point (and having good official libraries 
    - github is a great move in this direction - 
    streamlines the process because you can copy and 
    paste good components) but you should always make 
    sure you build your own personal libraries with 
    only the components you need. 
    [...]
```

**camilo_calendar_todo.txt**

```
    ******************
    # Calendar Todo #
    -----------------
    ##    2016     ##
    ******************
    
    [...]
    
    ----------------------
    ### Wed 03/16/2016 ###
    ----------------------
    * Transcribe your quotes 
        Took a while, let's clear them more often.
        > Done.
    
    * See if we can finish the notes templates blog post
        Lots of info, will take a while...
        > Done.
    [...]
    
    ----------------------
    ### Thu 03/17/2016 ###
    ----------------------
    * Solidify cat RCL spreadsheet for KiCad.
        Based on IPC standards.
```

**camilo_pending_todo.txt**

```
    *****************
    # Pending Todo #
    *****************
    
    [...]
    
    -------------------------
    ### Unscheduled Tasks ###
    -------------------------
    * Fix music mp3 tags.
    
    * Do taxes.
    
    [...]
```

**camilo_recurrent_todo.txt**

```
    ******************
    # Recurrent Todo #
    ******************
    
    --------------------
    ### Monthly Todo ###
    --------------------
    * Unison Synchronization of all devices.
    
    * Transcribe your personal quotes.
    [...]
    
    ------------------
    ### Daily Todo ###
    ------------------
    * Work on book summary.
    
    * Learn about KiCad (tasks in order).
    
    * Practice accordion.
    [...]
    
    --------------------
    ### Sundays Todo ###
    --------------------
    * Do Laundry.
    
    * Clean/organize Room.
    
    [...]
```

As an added bonus, I also have been working on [a couple of
scripts](https://github.com/Osohm/text_simple_planner/tree/master/scripts) to
help me manipulate these text files (e.g. find text, create new annual calendar
...etc).

Let me know what y'all think, hope it helps some lost soul somewhere out there.

enjoy and share with others :)
