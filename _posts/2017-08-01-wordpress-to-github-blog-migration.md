---
title: Wordpress to GitHub Pages Blog Migration
---

For so long, I have been meaning to make my blog completely static (plain old
HTML will do). No more dynamic _fancy decorations_ for a simple blog.

The following are the steps I followed to migrate my blog from wordpress.com to
GitHub pages:

* Create an initial personal [GitHub Page](https://pages.github.com) repository
    online.
   
* Clone remote repository to local computer:

    `git clone https://github.com/username/username.github.io`

* [Follow the instructions](https://help.github.com/articles/setting-up-your-github-pages-site-locally-with-jekyll) 
    to set up Jekyll for GitHub pages locally on your computer
    - Install Ruby from official sources.
    - Install Bundler.
    - Install Jekyll using Bundler.

* Build/preview your site locally (from the root directory of your repository) 
    before publishing posts to GitHub servers. 

    `bundle exec jekyll serve`

* Export your data from wordpress
    - Go to the WP Admin tab for your blog, then go to tools and export. 
    - Export all content.

* Download the [Exitwp tool](https://github.com/thomasf/exitwp) 
    created by Thomas Frössman (Thank you).
    - I tried several tools, this one worked the best for me.
    - Follow the tool instructions.

* Import data using the Exitwp tool.
    - See the build directory for the imported posts and pages.

## Manual Tedious Work (get a coffee)

_Build/preview your site locally at every step to check your progress._

* Copy posts in the `_posts` directory to your local Jekyll `_posts` directory.
    
* Rename and copy pages to Jekyll top directory. 

* Fix the YAML Front Matter at the top of every post.
    - Get rid of extraneous unneeded variables.

* Create resources directory for linked images and docs (referred by posts)
    - You can name this directory however you want.

* Download linked images and docs from wordpress servers to your resources
    directory.
    - This might take some time.

* Go over every post to make sure out-links are working and post images
    and docs are loaded from your resources directory and not from 
    wordpress servers.
    - This will take some time.

* Install Jekyll RSS plugin.
    - Jekyll-feed

* Clean up your blog build configuration (`_config.yml`)
    - Define site properties: blog name, author, contact ...etc.
    - Define build configuration: theme (minima is a good start), markdown
      parser, gems used ...etc.
    - Define default variables: so that you don't have to define them in every
      post.
 
* Find a commenting solution.
    - Disqus, GitHub Issues ...etc.

* Set-up URL redirects from previous wordpress.com blog.
    
* Preview your blog locally (make sure everything looks good)

    `bundle exec jekyll serve`

* Push changes to GitHub pages.
    - Give it a couple of seconds to build your site.

* Keep you Jekyll build tools updated. Check for updates every once in a while.

    `bundle update`

Other references (good reads):

* [GitHub Help: Customizing GitHub Pages](https://help.github.com/categories/customizing-github-pages)

* [Jekyll Docs, quite user friendly](http://jekyllrb.com/docs/home)

{% include issues_comments.md %}
