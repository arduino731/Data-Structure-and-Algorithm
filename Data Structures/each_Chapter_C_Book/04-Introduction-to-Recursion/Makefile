# Makefile for programs in directory 04-Introduction-to-Recursion
# ***************************************************************

PROGRAMS = \
    bsearch \
    fact \
    fastfib \
    fib \
    ifact \
    oddeven \
    palin \
    palin2

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

bsearch.o: bsearch.c
	$(CC) $(CFLAGS) -c bsearch.c

fact.o: fact.c
	$(CC) $(CFLAGS) -c fact.c

fastfib.o: fastfib.c
	$(CC) $(CFLAGS) -c fastfib.c

fib.o: fib.c
	$(CC) $(CFLAGS) -c fib.c

ifact.o: ifact.c
	$(CC) $(CFLAGS) -c ifact.c

oddeven.o: oddeven.c
	$(CC) $(CFLAGS) -c oddeven.c

palin.o: palin.c
	$(CC) $(CFLAGS) -c palin.c

palin2.o: palin2.c
	$(CC) $(CFLAGS) -c palin2.c


# ***************************************************************
# Executable programs

bsearch: bsearch.o
	$(CC) $(CFLAGS) -o bsearch bsearch.o ../booklib/cslib.a

fact: fact.o
	$(CC) $(CFLAGS) -o fact fact.o  ../booklib/cslib.a

fastfib: fastfib.o
	$(CC) $(CFLAGS) -o fastfib fastfib.o  ../booklib/cslib.a

fib: fib.o
	$(CC) $(CFLAGS) -o fib fib.o ../booklib/cslib.a

ifact: ifact.o
	$(CC) $(CFLAGS) -o ifact ifact.o ../booklib/cslib.a

oddeven: oddeven.o
	$(CC) $(CFLAGS) -o oddeven oddeven.o  ../booklib/cslib.a

palin: palin.o
	$(CC) $(CFLAGS) -o palin palin.o  ../booklib/cslib.a

palin2: palin2.o
	$(CC) $(CFLAGS) -o palin2 palin2.o  ../booklib/cslib.a

