# MAKEFILE
#	makefile for Principles of Embedded Systems Project One
#	Author: Katherine Hemzacek
	
CC=gcc
CFLAGS=-Wall -Werror -o

all: ProgramOne.c ProgramTwo.c ProgramThree.c
	$(CC) $(CFLAGS) ProgramOne ProgramOne.c
	$(CC) $(CFLAGS) ProgramTwo ProgramTwo.c
	$(CC) $(CFLAGS) ProgramThree ProgramThree.c

one: ProgramOne.c
	$(CC) $(CFLAGS) ProgramOne ProgramOne.c

two: ProgramTwo.c
	$(CC) $(CFLAGS) ProgramTwo ProgramTwo.c

three: ProgramThree.c
	$(CC) $(CFLAGS) ProgramThree ProgramThree.c

.PHONY: clean

clean:
	rm ProgramOne.exe ProgramTwo.exe ProgramThree.exe