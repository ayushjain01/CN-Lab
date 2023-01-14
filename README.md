# CN-Lab

This repository contains the following lab program for Computer Networks Lab, 5th sem, ISE.

### Part A: Implement the following using C/C++:

1. Write a program for implementing the error detection technique for data transfer in unreliable network code using CRC (16-bits) Technique.
2. Write a program to implement internet checksum for error correction and detection.
3. Given a graph, each node A knows the shortest path to node Z and node A can determine its shortest path to Z by calculating the minimum cost. Now when packet flows through a path it incurs some cost to the network, find shortest paths from source to all nodes in the given graph using Distance vector routing Algorithm.
4. Given a graph find shortest paths from source to all nodes using Dijkstra’s shortest path algorithm.
5. Write a program to archive Traffic management at Flow level by implementing Leaky Bucket Algorithm.
6. Write a program for simple RSA algorithm to encrypt and decrypt the data.
7. Write a program to implement the Diffie-Hellman Key Exchange algorithm.

### Part B: Simulation Using NS-2
1. Simulate three nodes point-to-point networks with duplex links between them. Set the queue size and vary the bandwidth and find the number of packets dropped
2. Simulate the different types of internet traffic such as FTP and TELNET over network and analyze the throughput
3. Simulate a four-node point-to-point network, and connect the links as follows: `n0->n2, n1- >n2 and n2->n3` . Apply TCP agent changing the parameters and determine the number of packets sent/received by TCP/UDP
4. Simulate the transmission of ping messages over a network topology consisting of 6 nodes and find the number of packets dropped due to congestion.

#

### Steps to execute Network Simulation Programs

**Step 1** - Create the `.tcl` file.

**Step 2** - Oepn Terminal and type the following command 

    ns <filename>.tcl

**Step 3** - The animator opens, run the simulation.

**Step 4** - Create the `.awk` file.

**Step 5** - Execute the `.awk` file using the following commond

    awk -f <filename>.awk filename.tr 

Note - the `.tr` file name is the file defined in the `.tcl` file.

**Step 7** - The above command, depending on the question, generates a output. Note down this output in a `.txt` file.

**Step 6** - Change the bandwitdh in the `.tcl` file and repeat the steps.

**Step 7** - Generate a graph for the output, using the below command

    xgraph <filename>.txt
