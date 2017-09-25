---
title: Uncomplicated Firewall (UFW) Configuration on Linux
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

A couple of useful commands:

* To inquire the status of the firewall:
    
    `sudo ufw status`

* To disable to firewall:
    
    `sudo ufw disable`

* To enable the firewall:

    `sudo ufw enable`

* To add a specific "allow" firewall rule, e.g.:
  
    `sudo ufw allow in wlan0 from 192.168.1.0/24 to any port 11055`
    
    Where: wlan0 (network adapter, e.g. can also be eth0), 192.168.1.0/24 (Client 
    IP address and netmask for IP range 192.168.1.1 - 192.168.1.254), 
    11055 (server port number). Other examples are:
    
    `sudo ufw allow in eth0 from 10.0.0.0/24 to any port nfs`
    
* List firewall rules, numbered:
    
    `sudo ufw numbered`
    
* Delete firewall rule by number:
    
    `sudo ufw delete rule_number`
 
{% include issues_comments.md %}
