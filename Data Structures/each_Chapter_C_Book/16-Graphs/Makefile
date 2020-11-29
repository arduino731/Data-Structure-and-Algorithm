# Makefile for programs in directory 16-Graphs
# ***************************************************************

PROGRAMS = \
    gtest

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

adjmat-graph.o: adjmat-graph.c graph.h
	$(CC) $(CFLAGS) -c adjmat-graph.c

bst.o: bst.c bst.h cmpfn.h
	$(CC) $(CFLAGS) -c bst.c

cmdscan.o: cmdscan.c cmdscan.h scanadt.h symtab.h
	$(CC) $(CFLAGS) -c cmdscan.c

cmpfn.o: cmpfn.c cmpfn.h
	$(CC) $(CFLAGS) -c cmpfn.c

foreach.o: foreach.c foreach.h iterator.h
	$(CC) $(CFLAGS) -c foreach.c

graph.o: graph.c foreach.h graph.h set.h
	$(CC) $(CFLAGS) -c graph.c

gtest.o: gtest.c cmdscan.h cmpfn.h foreach.h graph.h iterator.h \
         scanadt.h set.h symtab.h
	$(CC) $(CFLAGS) -c gtest.c

iterator.o: iterator.c cmpfn.h iterator.h itertype.h
	$(CC) $(CFLAGS) -c iterator.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c

set.o: set.c bst.h set.h
	$(CC) $(CFLAGS) -c set.c

simple-graph.o: simple-graph.c graph.h list.h
	$(CC) $(CFLAGS) -c simple-graph.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c


# ***************************************************************
# Executable programs

gtest: gtest.o bst.o cmdscan.o cmpfn.o foreach.o graph.o iterator.o \
       scanadt.o set.o symtab.o
	$(CC) $(CFLAGS) -o gtest bst.o gtest.o cmdscan.o cmpfn.o foreach.o \
                                 graph.o iterator.o scanadt.o set.o symtab.o  ../booklib/cslib.a

