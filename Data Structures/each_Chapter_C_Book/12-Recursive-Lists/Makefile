# Makefile for programs in directory 12-Recursive-Lists
# ***************************************************************

PROGRAMS = \
    bigfact \
    listtest

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

bigfact.o: bigfact.c bigint.h
	$(CC) $(CFLAGS) -c bigfact.c

bigint.o: bigint.c bigint.h
	$(CC) $(CFLAGS) -c bigint.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

listtest.o: listtest.c list.h scanadt.h
	$(CC) $(CFLAGS) -c listtest.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c


# ***************************************************************
# Executable programs

bigfact: bigfact.o bigint.o
	$(CC) $(CFLAGS) -o bigfact bigfact.o bigint.o  ../booklib/cslib.a

listtest: listtest.o list.o scanadt.o
	$(CC) $(CFLAGS) -o listtest listtest.o list.o scanadt.o  ../booklib/cslib.a

