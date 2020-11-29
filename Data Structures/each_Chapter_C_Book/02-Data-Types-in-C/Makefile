# Makefile for programs in directory 02-Data-Types-in-C
# ***************************************************************

PROGRAMS = \
    employee \
    gymjudge \
    quadeq

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

employee.o: employee.c
	$(CC) $(CFLAGS) -c employee.c

gymjudge.o: gymjudge.c
	$(CC) $(CFLAGS) -c gymjudge.c

quadeq.o: quadeq.c
	$(CC) $(CFLAGS) -c quadeq.c


# ***************************************************************
# Executable programs

employee: employee.o
	$(CC) $(CFLAGS) -o employee employee.o ../booklib/cslib.a 

gymjudge: gymjudge.o
	$(CC) $(CFLAGS) -o gymjudge gymjudge.o ../booklib/cslib.a 

quadeq: quadeq.o
	$(CC) $(CFLAGS) -o quadeq quadeq.o ../booklib/cslib.a -lm

