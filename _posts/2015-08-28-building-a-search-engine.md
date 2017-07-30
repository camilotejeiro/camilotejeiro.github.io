---
title: Building a Search Engine
---

One of the projects I am working on is implementing a simple search engine for
my company platform. It has taken me a while to get all of the pieces together
so I thought I would share some of my learning notes.

Keep in mind: These notes are intended to provide some familiarity with the
concept of building a search engine to facilitate learning and exploration but
are in no way intended to go into specific technical details.

So, a standard search engine normally consists of three important components,
mainly:

* We need a [web crawler](https://en.wikipedia.org/wiki/Web_crawler) to gather 
raw content from multiple web pages (or from the overall web).

* We need an [indexer](https://en.wikipedia.org/wiki/Search_engine_indexing) 
to structure our parsed content so that we can search it quickly at a later 
date, think of a book index. We can use the index to find content in the 
book fast by using keywords.

* And finally we need the actual [search query](https://en.wikipedia.org/wiki/Web_search_query), 
here we can enter text which can be searched in our stored index.

After some research (initially I was working with the
[Sphinx](https://en.wikipedia.org/wiki/Sphinx_%28search_engine%29) search
engine), I settled on a pair of really good open source programs that spawned
from the [Apache Lucene](https://en.wikipedia.org/wiki/Lucene) search project.

* [Apache Nutch](https://en.wikipedia.org/wiki/Nutch): A widely used and 
stable web crawler. It is written primarily in Java.

* [Apache Solr](https://en.wikipedia.org/wiki/Apache_Solr): A popular search 
server that does both indexing and querying and can be integrated with Nutch.

Now that we know "the name" of the tools we will be using, and why they are
necessary, we need to learn how to actually use them.

For this purpose I wrote 3 short tutorials, they are intended to introduce the
search tools, run a few commands and get familiar with the software. At the end
you will have a little search engine and a starting point for all sorts of
interesting projects.

1. [Solr5 Quick Tutorial, Indexing Content.]({% post_url 2015-08-27-solr5-tutorial-indexing-content %})

2. [Nutch1 Quick Tutorial, Learning to Crawl.]({% post_url 2015-08-27-nutch1-quick-tutorial-learning-to-crawl %})

3. [Nutch1-Solr5 Integration, Searching the Web.]({% post_url 2015-08-28-nutch1-solr5-integration-searching-the-web %})

Have fun searching, enjoy and share :)

{% include issues_comments.md %}
