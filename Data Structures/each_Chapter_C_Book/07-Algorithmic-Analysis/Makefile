# Makefile for programs in directory 07-Algorithmic-Analysis
# ***************************************************************

PROGRAMS = \
    testssort \
    testmsort \
    testqsort

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

msort.o: msort.c
	$(CC) $(CFLAGS) -c msort.c

qsort.o: qsort.c
	$(CC) $(CFLAGS) -c qsort.c

ssort.o: ssort.c
	$(CC) $(CFLAGS) -c ssort.c

testsort.o: testsort.c
	$(CC) $(CFLAGS) -c testsort.c


# ***************************************************************
# Executable programs

testssort: testsort.o ssort.o
	$(CC) $(CFLAGS) -o testssort testsort.o ssort.o  ../booklib/cslib.a

testmsort: testsort.o msort.o
	$(CC) $(CFLAGS) -o testmsort testsort.o msort.o  ../booklib/cslib.a

testqsort: testsort.o qsort.o
	$(CC) $(CFLAGS) -o testqsort testsort.o qsort.o  ../booklib/cslib.a
