# Makefile for programs in directory 11-Symbol-Tables
# ***************************************************************

PROGRAMS = \
    cmddisp \
    dumpfreq \
    mapfreq \
    plot \
    sorttest \
    symtest \
    wordfreq

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

cmddisp.o: cmddisp.c symtab.h
	$(CC) $(CFLAGS) -c cmddisp.c

cmpfn.o: cmpfn.c cmpfn.h
	$(CC) $(CFLAGS) -c cmpfn.c

dumpfreq.o: dumpfreq.c scanadt.h symtab.h
	$(CC) $(CFLAGS) -c dumpfreq.c

iterator.o: iterator.c iterator.h symtab.h
	$(CC) $(CFLAGS) -c iterator.c

mapfreq.o: mapfreq.c scanadt.h symtab.h
	$(CC) $(CFLAGS) -c mapfreq.c

plot.o: plot.c
	$(CC) $(CFLAGS) -c plot.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c

sorttest.o: sorttest.c cmpfn.h
	$(CC) $(CFLAGS) -c sorttest.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

symtest.o: symtest.c scanadt.h symtab.h
	$(CC) $(CFLAGS) -c symtest.c

wordfreq.o: wordfreq.c iterator.h scanadt.h symtab.h
	$(CC) $(CFLAGS) -c wordfreq.c


# ***************************************************************
# Executable programs

cmddisp: cmddisp.o symtab.o
	$(CC) $(CFLAGS) -o cmddisp cmddisp.o symtab.o ../booklib/cslib.a

dumpfreq: dumpfreq.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o dumpfreq dumpfreq.o scanadt.o symtab.o  ../booklib/cslib.a

mapfreq: mapfreq.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o mapfreq mapfreq.o scanadt.o symtab.o  ../booklib/cslib.a

plot: plot.o
	$(CC) $(CFLAGS) -o plot plot.o  ../booklib/cslib.a -lm

sorttest: sorttest.o cmpfn.o
	$(CC) $(CFLAGS) -o sorttest sorttest.o cmpfn.o  ../booklib/cslib.a

symtest: symtest.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o symtest symtest.o scanadt.o symtab.o  ../booklib/cslib.a

wordfreq: wordfreq.o iterator.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o wordfreq wordfreq.o iterator.o scanadt.o symtab.o  ../booklib/cslib.a

