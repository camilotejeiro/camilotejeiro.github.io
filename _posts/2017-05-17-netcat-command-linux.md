---
title: Netcat (nc) Command for File Transfers on Linux 
---

_Tested on Linux Mint 17 (Ubuntu 14.04 based)_

Netcat -- The TCP/IP Swiss Army Knife -- is a versatile utility for writing and
reading data through TCP and UDP connections.

## Sending a text file through netcat (Serving the file for a client)

### Server machine serving the file:
 
`nc -v -l -q 0 -p 11055 < file.txt`
 
Arguments: -v (verbose), -l (listening/server mode), -q 0 (quit 0 secs after 
Stdin sees end of file), -p (port number) 11055.
 
You can also use pipes to feed the file contents to netcat:
 
`cat file.txt | nc -v -l -p 11055`
    
And you can monitor progress and speed using the pipe viewer utility pv:

`cat file.txt | pv | nc -v -l -p 11055`
    
### Client machine receiving the file:
    
`nc 127.0.0.1 11055 > file_received.txt` 
    
Arguments: 127.0.0.1 (desired server IP address), 11055 (server port to connect to).
 
**Remember** the sender of the file must quit after done, otherwise the link
remains up.

## Sending a text file through netcat (client sends file to server)

### Server machine receiving the file:
    
`nc -v -l -p 11055 > file_received.txt`
    
### Client maching sending the file:

`nc -q 0 127.0.0.1 11055 < file.txt`

Or (using pipes) and pipe viewer:
    
`cat file.txt | pv | nc 127.0.0.1 11055`

**Remember** since now the client is the sender -- the one sending the file -- 
it is the responsibility of the client to end the connection (see -q 0 
argument)

## Tar + Netcat: Copying multiple files (Serving the file for a client)

### Server machine serving the file 

`tar cz directory_name | nc -v -l -q 0 -p 11055
    
Arguments: tar (compress using tar utility), c (create archive), z (compress using gzip)

### Client machine receiving the file

`nc 127.0.0.1 11055 | tar xz
    
Arguments: x (extract), z (using gzip)

## Tar + Netcat: Copying multiple files (client sends file to server)

### Server machine receiving and uncompressing the files 

`nc -v -l -q 0 -p 11055 | tar xz

### Client machine sending the file

`tar cz | nc 127.0.0.1 11055

**Remember** you can send the file from the client to the server or vice-versa, 
the only reason for one or the other is if one of the machines is behind a 
firewall.

{% include issues_comments.md %}
