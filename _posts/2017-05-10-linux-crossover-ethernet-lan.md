---
title: 'Linux Crossover Ethernet LAN: Assigning IP Addresses and Connection'
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

## Hardware Requirements:

In order to connect two computers without a router, you will need one of the following:

* A standard Ethernet cable, which should work with most modern hardware, or

* An Ethernet crossover cable (for older computers), or

* A simple Ethernet hub (and two Ethernet cables).

## Graphical User Interface Steps:

You will need to manually assign IP address in the same range. The following 
steps assume you are using the standard Mint/Cinnamon interface. Repeat these 
steps for each computer.

* Click the Network indicator on the panel (top right).

* From the drop-down, select Edit Connections...

* In the Network Connections dialog box, click the Add button.

* When prompted to choose a connection type, choose Ethernet, and click the Create... button.

* Name your connection "ethernet\_crossover" or some other meaningful name of
    your choice.

* In the Device MAC address drop-down, select (etho) or the one corresponding 
    to the interface you plan to use.

* Switch to the IPv4 Settings tab.
    - Change the Method to Manual.
    - click the Add button to add an IP address as follows.

Example settings for Computer #1:  

* Address: 10.0.0.5   
    The static IP addess you want.

* Netmask: 255.255.255.0   
    You can also use 24 as the netmask.

* Gateway: (leave empty)

Example settings for Computer #2:  

* Address: 10.0.0.6  

* Netmask: 255.255.255.0  

* Gateway: (leave empty)

Once that's set up, and the computers are wired together, try pinging each other 
(make sure the firewall is disabled or that firewall rules have been added).

`user@computer1:~$ ping 10.0.0.6`

The output should look something like this:

~~~
PING 10.0.0.6 (10.0.0.6) 56(84) bytes of data.
64 bytes from 10.0.0.6: icmp_seq=1 ttl=128 time=0.457 ms
~~~

{% include issues_comments.md %}
