# Makefile for programs in directory 15-Sets
# ***************************************************************

PROGRAMS = \
    permute \
    intsettest \
    settest \
    strtest

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

bst.o: bst.c bst.h cmpfn.h
	$(CC) $(CFLAGS) -c bst.c

cmpfn.o: cmpfn.c cmpfn.h
	$(CC) $(CFLAGS) -c cmpfn.c

cvecset.o: cvecset.c cvector.h iterator.h itertype.h set.h
	$(CC) $(CFLAGS) -c cvecset.c

cvector.o: cvector.c cvector.h
	$(CC) $(CFLAGS) -c cvector.c

foreach.o: foreach.c foreach.h iterator.h
	$(CC) $(CFLAGS) -c foreach.c

iterator.o: iterator.c cmpfn.h iterator.h itertype.h
	$(CC) $(CFLAGS) -c iterator.c

permute.o: permute.c cmpfn.h iterator.h set.h
	$(CC) $(CFLAGS) -c permute.c

set.o: set.c bst.h iterator.h itertype.h set.h
	$(CC) $(CFLAGS) -c set.c

settest.o: settest.c iterator.h set.h
	$(CC) $(CFLAGS) -c settest.c

strtest.o: strtest.c iterator.h set.h
	$(CC) $(CFLAGS) -c strtest.c


# ***************************************************************
# Executable programs

permute: permute.o bst.o cmpfn.o iterator.o set.o
	$(CC) $(CFLAGS) -o permute bst.o permute.o cmpfn.o \
                                  iterator.o set.o  ../booklib/cslib.a

intsettest: settest.o cvecset.o cvector.o foreach.o iterator.o
	$(CC) $(CFLAGS) -o intsettest settest.o cvecset.o cvector.o \
                                      foreach.o iterator.o  ../booklib/cslib.a

settest: settest.o bst.o cmpfn.o foreach.o iterator.o set.o
	$(CC) $(CFLAGS) -o settest settest.o bst.o cmpfn.o \
                                  foreach.o iterator.o set.o  ../booklib/cslib.a

strtest: strtest.o bst.o cmpfn.o iterator.o set.o
	$(CC) $(CFLAGS) -o strtest strtest.o bst.o cmpfn.o \
                                  iterator.o set.o  ../booklib/cslib.a
