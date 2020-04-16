#!/bin/bash

# MAKE SCRIPT FILE

CC=gcc

# compile main
$CC -c main.c

#compile socket
$CC -c ./src/socket.c

#compile bin
$CC -o ./bin/sock4t main.o socket.o

#clean

rm -rf *.o
