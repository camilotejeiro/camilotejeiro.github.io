---
title: Nutch1-Solr5 Integration, Searching the Web
---

Now we are going to Integrate our web crawler with our search server to have our complete search engine solution.

Platform: Linux Ubuntu

Note: before following these guidelines make sure you have followed the quick
tutorial on [Solr]({% post_url 2015-08-27-solr5-tutorial-indexing-content %}) 
and [Nutch]({% post_url 2015-08-27-nutch1-quick-tutorial-learning-to-crawl %}), 
otherwise this won't make much sense.

So, we want to post the crawled data from Nutch (our crawler) to Solr for
indexing and subsequent searching.

**1. Start the Solr server.** First make sure the Solr Server is up and running.

> bin/solr start.

**2. Create a new Solr core** Let's create a core we will use to store the nutch
crawled data and index it. (note there are underscores in the core name,
sometimes they don't show up on wordpress...)

> bin/solr create -c nutch_solr_data_core

**3. Modifying the core schema settings.**

Solr creates our new core with the default managed settings: e.g.
field_types(int, long ,date ...), field_names (my_int, my_long ...) and other
settings.  However Nutch posts data with slightly different field types and
settings. Therefore we have to modify the schema configuration file; the
instructions on the Nutch tutorial only got me so far and there were several
errors at core initialization, so I tried to learn a bit and modified the file
such that Solr is happy and things "appear" to be working.

Backup the current schema file.

> cd /opt/solr-5.2.1/server/solr/nutch_solr_data_core/conf

> mv managed-schema solr_managed-schema.bak 

Now [download the modified schema.xml](/linked_files/2015-08-28-nutch1-solr5-integration-searching-the-web_1.xml) 
file and put it in the configuration directory.

**4. Modifying the Solr configuration file.**

Now, because we are providing our own schema.xml file, Solr needs to know that
we don't need it to auto generate it's managed schema file, we want it to load
our core based on our modified schema.

Backup the current solrconfig file.

> cd /opt/solr-5.2.1/server/solr/nutch_solr_data_core/conf

> mv solrconfig.xml solrconfig.xml.bak 

Now [download the modified solrconfig.xml](/linked_files/2015-08-28-nutch1-solr5-integration-searching-the-web_2.xml)
file and put it in the configuration directory.

**5. Restart the Solr server** Now restart the server for changes to take
effect.

> cd /opt/solr-5.2.1 

> bin/solr restart.

Now you can go on to the browser to make sure solr restarted with no errors or
core exceptions.

**6. Post Nutch data to Solr for Indexing** Now we are going to take our
previously fetched data from Nutch and post it to Solr.  i.e.

> cd /opt/apache-hutch-1.10/bin/nutch 

> solrindex http://localhost:8983/solr/nutch_solr_data_core crawl/crawldb/ -linkdb crawl/linkdb/ $s1 

If all works well there shouldn't be any errors and indexing should complete
successfully.

**7. Querying your new Index.** Now let's actually use Solr search functionality
to search in our index.

> curl "http://localhost:8983/solr/nutch_solr_data_core/select?wt=json&amp;indent=true&amp;q=foundation"

**8. Deleting duplicates** Once indexed the entire contents, it must be disposed
of duplicate urls, in this way ensures that the urls are unique.

> /bin/nutch dedup http://localhost:8983/solr/nutch_solr_data_core 

**9. Cleaning Solr Index** The class scans a crawldb directory looking for
entries with status DB_GONE (404) and sends delete requests to Solr for those
documents. Once Solr receives the request the aforementioned documents are duly
deleted. This maintains a healthier quality of Solr index.

> /bin/nutch solrclean crawl/crawldb/ http://localhost:8983/solr/nutch_solr_data_core 

**10. Putting all commands on one script.** Now if you want to: inject the
seeds, generate a fetch list, fetch content, invert linkes and post the data to
solr for indexing in one command...  The guys at Nutch already thought of it:

> bin/crawl -i -D solr.server.url=http://localhost:8983/solr/nutch_solr_data_core urls/ crawl/ 2 

This concludes our series of three very quick tutorials on Solr, Nutch and both
working together.

I got to say, I am sure I have typos here and there, If you find one, let me
know so others can benefit as well :)

Cheers, that was not bad!

{% include issues_comments.md %}
