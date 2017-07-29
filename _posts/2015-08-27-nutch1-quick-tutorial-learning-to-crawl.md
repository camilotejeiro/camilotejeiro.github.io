---
title: Nutch1 Quick Tutorial, Learning to Crawl
layout: post
---

Here is a quick hands-on tutorial to gain some familiarity with 
[Apache Nutch-1x](https://en.wikipedia.org/wiki/Nutch) (A web crawler) as well 
as for my own reference just in case my memory bails on me :).

Note this is _not_ intended to be an official guide or anything formal per-se, I
am not discussing the architecture, implementation details or the history of the
project (For all details regarding Nutch refer to the 
[Official Nutch Wiki](https://wiki.apache.org/nutch)).

Platform: Linux Ubuntu

**1. Download and extract Apache Nutch 1.x** 
Go to the Apache Nutch website and
[download the Apache Nutch 1.10 (bin.tar.gz)](http://nutch.apache.org/downloads.html); 
we want the binary version.

Now extract the compressed archive into your /opt/ directory. (you can use tar
if your would like or the explorer, it doesn't matter)

**2. Check your Nutch Install** 
In the terminal cd to the /opt/apache-nutch-1.10 directory. 
Now check your installation, run the binary nutch command:

> cd /opt/apache-nutch-1.10 bin/nutch 

You should get a nutch version and a snapshot of the usage of the nutch command.

**3. Setup your java home.** 
Note: the location of your java home is system dependent (but this worked 
for me).  In order to set up the environment variable temporarily, do:

> export JAVA_HOME=/usr 

If you want to make it persistent over login sessions, edit your ~/.profile file
and add the line:

> export JAVA_HOME=/usr 

**4. Setup your Crawl Properties.** 
change directory to /opt/apache-hutch-1.10/conf and modify the nutch-site.xml file.

> cd /opt/apache-hutch-1.10/conf nano nutch-site.xml

Add your agent name property(to the .xml) for external servers to recognize.

```
<property>     
    <name>http.agent.name</name>     
    <value>My Nutch Spider</value> 
</property> 
```

**5. Create a seed list, a list of URLs to crawl.** 
Create a new URLs directory and a text file containing a single URL per line.

> mkdir -p urls cd urls nano seed.txt 

add the url you would like to crawl (I will use the nutch website as a valid
example), add the following line to the seed.txt file: https://nutch.apache.org

**6. Limit your crawling scope, configure regular expression filters.** 
Now we would like to limit our crawling to only our chosen url and any other 
url in that domain only. (i.e. we don't want to do a whole-web crawl).

We need to edit the file conf/regex-urlfilter.txt

> cd /opt/apache-hutch-1.10/conf nano regex-urlfilter.txt

now replace the last line and its comment:

```
# accept anything else

+.  
```

For

```
# Limit our search to this domain and any pages within it.

+^https://([a-z0-9]*\.)*nutch.apache.org/ 
```

NOTE: Not specifying any domains to include within regex urlfilter.txt will lead
to all domains linking to your seed URLs file being crawled as well.

**7. Seeding the nutch crawl database with urls** 
We can use the nutch injector to add our seed list to the crawl database.

> cd /opt/apache-hutch-1.10/ 

> bin/nutch inject crawl/crawldb urls 

**8. Generate a fetch list** 
Now we need to generate a list of pages to be fetched from our domain urls, 
you can imagine that each domain url might have a large number of links, 
we need to gather all of these into a list before we can start crawling, 
do the following:

> bin/nutch generate crawl/crawldb crawl/segments -topN 10

This generates a fetch list for all of the pages due to be fetched, we are
limiting the number of pages in our list to 10 (to keep the example short and
simple), but you can remove this argument if you want to list all of the pages
in the domain.  The fetch list is placed in a newly created segment directory.
The name of the directory is the timestamp of when it was created. For easiness
we would like to set a shell variable to keep track of this segment, for example
in my case:

> s1=crawl/segments/20150813112625 

and check the variable value

> echo $s1 

**9. Start fetching content.** 
Now that we have our list of pages ready, let's start fetching content from 
our newly created segment.

> bin/nutch fetch $s1 

and parse all of our entries

> bin/nutch parse $s1 

Finally update our crawl database with our fetched results.

> bin/nutch updatedb crawl/crawldb $s1 

**10. prepare the database for indexing, invert links** 
Before indexing we first invert all of the links, so that we may index incoming 
anchor text with the pages.

> bin/nutch invertlinks crawl/linkdb -dir crawl/segments

Great!  We just crawled a website with Apache Nutch, fun :)

The next step is to index our data using Apache Solr, for that make sure you
went through the Solr tutorial already and then refer to the quick tutorial on
Nutch Solr integration.

If I have any errors/typos or if I missed something, post a comment or e-mail
and let me know, Thanks!

Reference for this post: [Official Nutch Tutorial](https://wiki.apache.org/nutch/NutchTutorial)
