# Makefile for programs in directory 05-Recursive-Procedures
# ***************************************************************

PROGRAMS = \
    archway \
    hanoi \
    koch \
    mondrian \
    permute

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

archway.o: archway.c
	$(CC) $(CFLAGS) -c archway.c

hanoi.o: hanoi.c
	$(CC) $(CFLAGS) -c hanoi.c

koch.o: koch.c
	$(CC) $(CFLAGS) -c koch.c

mondrian.o: mondrian.c
	$(CC) $(CFLAGS) -c mondrian.c

permute.o: permute.c
	$(CC) $(CFLAGS) -c permute.c


# ***************************************************************
# Executable programs

archway: archway.o
	$(CC) $(CFLAGS) -o archway archway.o  ../booklib/cslib.a -lm

hanoi: hanoi.o
	$(CC) $(CFLAGS) -o hanoi hanoi.o  ../booklib/cslib.a

koch: koch.o
	$(CC) $(CFLAGS) -o koch koch.o  ../booklib/cslib.a -lm

mondrian: mondrian.o
	$(CC) $(CFLAGS) -o mondrian mondrian.o  ../booklib/cslib.a -lm

permute: permute.o
	$(CC) $(CFLAGS) -o permute permute.o  ../booklib/cslib.a

