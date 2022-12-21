#create Simulator
set ns [new Simulator]

#Open Trace and NAM Trace File
set ntrace [open ex3.tr w]
$ns trace-all $ntrace
set namfile [open ex3.nam w]
$ns namtrace-all $namfile

#Finish Procedure
proc Finish {} {
global ns ntrace namfile

#Dump all trace data and close the files
$ns flush-trace
close $ntrace
close $namfile

#Execute the nam animation file
exec nam ex3.nam &
exit 0
}

$ns color 1 Blue
$ns color 2 Red

#Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns simplex-link $n2 $n3 1Mb 10ms DropTail
$ns simplex-link $n3 $n2 1Mb 10ms DropTail

#Set queue size and Monitor the queue
$ns queue-limit $n0 $n2 10
$ns simplex-link-op $n0 $n2 queuePos 0.5

#Set TCP Connection between n0 and n3
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0
$tcp0 set fid_ 1

#Attach FTP Application over TCP
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type_ FTP

#Set TCP Connection between n1 and n3
set tcp1 [new Agent/TCP]
$ns attach-agent $n1 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1
$tcp1 set fid_ 2

#Attach Telnet Application over UDP
set telnet [new Application/Telnet]
$telnet attach-agent $tcp1
$telnet set type_ Telnet

#Schedule Events
$ns at 0.5 "$telnet start"
$ns at 0.5 "$ftp0 start"
$ns at 24.5 "$telnet stop"
$ns at 24.5 "$ftp0 stop"
$ns at 25.0 "Finish"



$ns run
