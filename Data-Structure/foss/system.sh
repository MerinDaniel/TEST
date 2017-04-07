#!/bin/bash
whoami
echo user          :$USER  logname:$LOGNAME 
echo current shell :$SHELL
echo home directory:$HOME
echo current os    :$OSTYPE
uname -o    #command for os
echo current path setting:$PATH
echo current working directory:$PWD
pwd
echo number of logged users :
users|wc -w
