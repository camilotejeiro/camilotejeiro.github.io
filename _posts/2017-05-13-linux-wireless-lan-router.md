--- 
title: 'Linux Wireless LAN (router-wlan): Assigning Static IP Addresses and Connection'
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

You will need to manually assign IP address in the same range. The following 
steps assume you are using the standard Mint (Cinnamon) interface. Repeat 
these steps for each computer.

* Connect to the wireless network as you would do normally:
    select network from menu, click and enter your password. 
    This would create a new network profile for you automatically (which we'll use). 

* Click the Network indicator on the panel (top right).

* From the drop-down, select Edit Connections...

* In the Network Connections dialog box, click edit for the network that 
    was created automatically.

* Switch to the IPv4 Settings tab (all other tabs should be correct).
    - Change the Method to Manual.
    - click the Add button to add an the IP address and information as follows.

Example settings for Computer #1:
  
* Address: 192.168.1.157   
    The static IP address you want must not be in 
    the router DHCP range/scope, otherwise you could have IP conflicts as DHCP 
    addresses are allocated dynamically, we are choosing a sufficiently high 
    address 157 to be safe.
    
* Netmask: 255.255.255.0   
    Same as using 24.

* Gateway: 192.168.1.1    
    This is the router IP address, how the router can be reached from the local 
    network.

* DNS Servers: 8.8.8.8   
    Google Domain Name Servers, tend to be good and safe.

Example settings for Computer #2:  

* Address: 192.168.1.158  

* Netmask: 255.255.255.0  

* Gateway: 192.168.1.1

* DNS Servers: 8.8.8.8.

Once that's set up, try pinging each other. 
(make sure the firewall is disabled or that firewall rules have been added).

`user@computer1:~$ ping 192.168.1.158`

The output should look something like this:

~~~
PING 192.168.1.158 (192.168.1.158) 56(84) bytes of data.
64 bytes from 192.168.1.158: icmp_seq=1 ttl=128 time=0.457 ms
~~~

{% include issues_comments.md %}
