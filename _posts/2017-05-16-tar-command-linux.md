---
title: 'Tar command on Linux: Create, Compress and Manipulate Archives'
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

The following are some useful TAR arguments with explanations: 

_Don't execute these, see full complete commands in the next real-life examples 
section afterwards_

* Extract (x parameter) while listing (v parameter) verbosely the files to the 
screen.

`tar xv`

* Lists the files from the archive without extracting them.

`tar tv`

* Create (c arg) a tar archive and list files verbosely.

`tar cv`

* Provide the output filename (f argument) and create (c arg) a tar archive listing 
files verbosely (v arg).

`tar xvf`

* Extract (x) from the archive file (f) and list files verbosely (v).

`tar cvf`

* Extract a gzip (z arg) compressed tar archive.

`tar xvfz`

* Create a bz2 (j arg) compressed tar archive.

`tar cvfj`

### Real-life Examples

* Create a tar archive (archive\_name.tar) from the files in directory (directory\_name)

`tar cvf archive_name.tar directory_name/`

* Create a gzip compressed tar archive (compressed\_archve\_name.tar.gz) from the 
files in directory (directory\_name)

`tar cvfz compressed_archive_name.tar.gz directory_name`

* Create a bzip compressed tar archive (compressed\_archve\_name.tar.bz2) from the 
files in directory (directory\_name)

`tar cvfj compressed_archive_name.tar.bz2 directory_name`
 
* Extract a gzip compressed tar archive (compressed\_archve\_name.tar.gz)

`tar xvfz compressed_archive_name.tar.gz directory_name`

* Extract a bzip2 compressed tar archive (compressed\_archve\_name.tar.bz2)

`tar xvfj compressed_archive_name.tar.bz2 directory_name`
 
### GZIP Compression

* Create a GZIP compressed file.

`gzip file.tar`

* Extract from compressed file.

`gunzip file.tar.gz`

You can also use bzip2 to compress and uncompress similarly.

{% include issues_comments.md %}
