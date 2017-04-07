#!/bin/bash
echo os and version :
uname -o
echo release number :
uname -r
echo kernel version :
uname -v
echo available shells:
cat /etc/shells
echo mouse settings
xinput --list 11
echo cpu info:
lscpu # or cat /proc/cpuinfo
echo memory info :
free -h # or cmstat or cat /proc/memoryinfo
echo harddisk info :
lsblk #fdisk -l
echo filesystem mounted :
df #or mount -l
