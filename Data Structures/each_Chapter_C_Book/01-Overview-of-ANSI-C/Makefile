# Makefile for programs in directory 01-Overview-of-ANSI-C
# ***************************************************************

PROGRAMS = \
    addlist \
    average3 \
    calendar \
    digitsum \
    isvowel \
    liftoff \
    oddeven \
    powertab

# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined

#CC = gccx
#gcc -I..booklib  -o prog   prog.c  ../booklib/cslib.a
CC = gcc -I../booklib

CFLAGS = 

# ***************************************************************
# Entry to bring the package up to date

all: $(PROGRAMS)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    scratch -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

# ***************************************************************
# C compilations

addlist.o: addlist.c
	$(CC) $(CFLAGS) -c addlist.c

average3.o: average3.c
	$(CC) $(CFLAGS) -c average3.c

calendar.o: calendar.c
	$(CC) $(CFLAGS) -c calendar.c

digitsum.o: digitsum.c
	$(CC) $(CFLAGS) -c digitsum.c

isvowel.o: isvowel.c
	$(CC) $(CFLAGS) -c isvowel.c

liftoff.o: liftoff.c
	$(CC) $(CFLAGS) -c liftoff.c

oddeven.o: oddeven.c
	$(CC) $(CFLAGS) -c oddeven.c

powertab.o: powertab.c
	$(CC) $(CFLAGS) -c powertab.c


# ***************************************************************
# Executable programs

addlist: addlist.o
	$(CC) $(CFLAGS) -o addlist addlist.o ../booklib/cslib.a

average3: average3.o
	$(CC) $(CFLAGS) -o average3 average3.o  ../booklib/cslib.a

calendar: calendar.o
	$(CC) $(CFLAGS) -o calendar calendar.o  ../booklib/cslib.a

digitsum: digitsum.o
	$(CC) $(CFLAGS) -o digitsum digitsum.o  ../booklib/cslib.a

isvowel: isvowel.o
	$(CC) $(CFLAGS) -o isvowel isvowel.o  ../booklib/cslib.a


liftoff: liftoff.o
	$(CC) $(CFLAGS) -o liftoff liftoff.o  ../booklib/cslib.a

oddeven: oddeven.o
	$(CC) $(CFLAGS) -o oddeven oddeven.o  ../booklib/cslib.a

powertab: powertab.o
	$(CC) $(CFLAGS) -o powertab powertab.o

