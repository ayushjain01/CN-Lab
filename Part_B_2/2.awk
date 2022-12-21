BEGIN {
numTCP1=0;
tcpSize1=0;
numTCP2=0;
tcpSize2=0;
totaltcp1=0;
totaltcp2=0;
}
{
event=$1;
pkttype= $5;
fromnode=$9;
tonode=$10;
pktsize=$6;
if(event == "r" && pkttype == "tcp" && fromnode == "0.0" && tonode == "3.0")
{
numTCP1++;
tcpSize1 = pktsize;
}
if(event == "r" && pkttype == "tcp" && fromnode == "1.0" && tonode == "3.1")
{
numTCP2++;
tcpSize2 = pktsize;
}
}
END {
totaltcp1=numTCP1*tcpSize1*8;
totaltcp2=numTCP2*tcpSize2*8;
throughputtcp1= totaltcp1/24; # because simulation time is 24.5 ¬ 0.5 = 24
throughputtcp2= totaltcp2/24; # because simulation time is 24.5 ¬ 0.5 = 24
printf("The Throughput of FTP application is %d \n", throughputtcp1);
printf("The Throughput of TELNET application is %d \n", throughputtcp2);
}
