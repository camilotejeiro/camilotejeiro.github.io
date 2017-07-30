---
title: Solr5 Tutorial, Indexing Content
---

This guide is to gain a bit of familiarity with the Solr search server, it is
not intended as an official guide or anything formal per-se (For formal details
refer to the official 
[Apache Solr Reference Guide](https://cwiki.apache.org/confluence/display/solr/Apache+Solr+Reference+Guide))

Platform: Ubuntu Linux

Let's start.

**1. Download and extract Solr 5.x**

Go to the Apache Solr website and [download Solr5x.tgz](http://www.apache.org/dyn/closer.cgi), 
then extract the compressed archive into your /opt/ directory. (you can use tar 
if your would like or the explorer, it doesn't matter)

**2. Start the Solr server.** 
In the terminal cd to your /opt/solr5.2.1
directory. now start the solr search server with the default configurations.

> cd /opt/solr5.2.1 

> bin/solr start 

You should get:

> Waiting to see Solr listening on port 8983 [|] Started

> Solr server on port 8983 (pid=some_numbers) Happy searching! 

You can also open up your browser and see your search server online, go to:

http://localhost:8983/solr

You can also try other server control commands, for example: Restart your search
server with:

> bin/solr restart

Check the status of your search server with:

> bin/solr status 

Stop your search server with:

> bin/solr stop 

**3. Creating a core (standalone) or collection (SolrCloud)** 
We are using Solr in standalone mode so we will be creating a core.

For creating a core with the default managed configuration, we do:

> bin/solr create -c solr-docs-search-core 

_Note from Solr help: Create a core or collection depending on whether Solr is
running in standalone (core) or SolrCloud mode (collection). In other words,
this action detects which mode Solr is running in, and then takes the
appropriate action (either create_core or create_collection)._

**4.Posting documents to be indexed** 
Now that we have a core we can pass some documents so that Solr can index them. 
The logic is that you index your documents so that you can search fast at a later 
date, Solr does both indexing and searching for us.

Post a set of documents to Solr, we can use the simplePost tool and a few text
documents in our Solr home:

> bin/post -c solr-docs-search-core README.txt 

> bin/post -c solr-docs-search-core LICENSE.txt 

> bin/post -c solr-docs-search-core NOTICE.txt

You should see your commands posting every document individually and Solr doing
the indexing work.

**5. Searching our index** 
Now we can use Solr to search for words or phrases in its index FAST.

We can use curl to issue search queries

> curl "http://localhost:8983/solr/solr-docs-search-core/select?wt=json&amp;amp;indent=true&amp;amp;q=foundation"

This command says go to our solr_docs_search-core, we want our results in json
indented format, now search for the term foundation in our index.

You should get a nice response from Solr indicating whether the word in the
query was found.

**6. Deleting our core** 
Now since we are done with our little tutorial you might want to unload (delete) 
your core.

You can do that by issuing the command:

> bin/solr delete -c solr-docs-search-core 

And... you are back where you started.

You can now proceed to the [Nutch Tutorial]({% post_url 2015-08-27-nutch1-quick-tutorial-learning-to-crawl %}),
to get familiar with the Web Crawler we'll be using.

If I have any errors/typos or if I missed something, post a comment or e-mail
and let me know, Thanks!

Reference for this post: [Solr Quickstart](http://lucene.apache.org/solr/quickstart.html)

{% include issues_comments.md %}
