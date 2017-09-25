--- 
title: 'Linux Wireless LAN (adhoc-wlan): Assigning IP Addresses and Connection'
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

You will need to manually assign IP address in the same range. The following 
steps assume you are using the standard Mint/Cinnamon interface. Repeat these 
steps for each computer.

* Click the Network indicator on the panel (top right).

* From the drop-down, select Edit Connections...

* In the Network Connections dialog box, click the Add button.

* When prompted to choose a connection type, choose Ad hoc, and click the Create... button.

* Name your connection and SSID "ad\_hoc\_wlan" or some other meaningful name.

* In the Mode drop down menu select: Ad-Hoc

* In the Device MAC address drop-down, select wlan0. Leave everything else as is.

* In the Wifi-security tab select WAP & WPA2 personal.
    - Put your password. **it must be the same in all computers**

* Switch to the IPv4 Settings tab.
    - Change the Method to Manual.
    - click the Add button to add an IP address as follows.

Example settings for Computer #1:  

* Address: 192.168.1.157  
    The static IP addess you want (any will do).

* Netmask: 255.255.255.0  
    You can also use 24 as the netmask.

* Gateway: (leave empty)

Example settings for Computer #2:  

* Address: 192.168.1.158 

* Netmask: 255.255.255.0  

* Gateway: (leave empty)

Once that's set up, connect to the Ad hoc network on each computer (sometimes 
you need to use the "connect to a hidden network" button). 
Now, Try pinging each other (make sure the firewall is disabled or that 
firewall rules have been added).

`user@computer1:~$ ping 192.168.1.158`

The output should look something like this:

~~~
PING 192.168.1.158 (192.168.1.158) 56(84) bytes of data.
64 bytes from 192.168.1.158: icmp_seq=1 ttl=128 time=0.457 ms
~~~

{% include issues_comments.md %}
