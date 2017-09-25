---
title: Network File Sharing (NFS) Configuration on Linux
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

## Server Side

* Install NFS server packages: 

    `sudo apt-get install nfs-kernel-server`

* Modify /etc/exports file to specify folders to share, add line:

    `/media/user/folder 10.0.0.5 (rw,sync,no_subtree_check,no_root_squash)`

    _10.0.0.5 is the server IP address_

* Restart server

    `sudo /etc/init.d/nfs-kernel-server restart`
    
* Setup firewall rule

    `sudo ufw allow in on eth0 from 10.0.0.0/24 to any port nfs`
    
    note: this 24 is the netmask it is equivalent to a range 10.0.0.1 - 10.0.0.254

* Check firewall rules in order

    `sudo ufw numbered`
    
* Delete firewall rules if needed

    `sudo ufw delete rule_number`
    
## Client Side

* Install NFS client packages

    `sudo apt-get install nfs-common`

* Make directories to mount nfs share

    ~~~
    cd /mnt/
    sudo mkdir nfs
    sudo chown user:user nfs
    cd nfs
    mkdir data
    cd data
    mount 10.0.0.6:/media/user/data .
    ~~~
    
    _10.0.0.6 is the client IP address_

* Add shortcut in file explorer.

{% include issues_comments.md %}
