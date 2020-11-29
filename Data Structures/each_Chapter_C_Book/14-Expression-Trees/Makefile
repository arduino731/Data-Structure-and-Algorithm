# Makefile for programs in directory 14-Expression-Trees
# ***************************************************************

PROGRAMS = \
    interp

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

eval.o: eval.c eval.h exp.h symtab.h
	$(CC) $(CFLAGS) -c eval.c

exp.o: exp.c exp.h
	$(CC) $(CFLAGS) -c exp.c

interp.o: interp.c eval.h exp.h parser.h scanadt.h
	$(CC) $(CFLAGS) -c interp.c

iverson.o: iverson.c exp.h parser.h scanadt.h
	$(CC) $(CFLAGS) -c iverson.c

parser.o: parser.c exp.h parser.h scanadt.h
	$(CC) $(CFLAGS) -c parser.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c


# ***************************************************************
# Executable programs

interp: interp.o eval.o exp.o parser.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o interp interp.o eval.o exp.o parser.o \
                                  scanadt.o symtab.o  ../booklib/cslib.a

