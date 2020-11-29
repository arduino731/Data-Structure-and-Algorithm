# Makefile for programs in directory 03-Libraries-and-Interfaces
# ***************************************************************

PROGRAMS = \
    copyfile \
    craps \
    flipcoin \
    linecopy \
    pigword1 \
    pigword2 \
    randtest \
    remcom \
    spcount

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

copyfile.o: copyfile.c
	$(CC) $(CFLAGS) -c copyfile.c

craps.o: craps.c random.h
	$(CC) $(CFLAGS) -c craps.c

flipcoin.o: flipcoin.c random.h
	$(CC) $(CFLAGS) -c flipcoin.c

linecopy.o: linecopy.c
	$(CC) $(CFLAGS) -c linecopy.c

pigword1.o: pigword1.c
	$(CC) $(CFLAGS) -c pigword1.c

pigword2.o: pigword2.c
	$(CC) $(CFLAGS) -c pigword2.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

randtest.o: randtest.c
	$(CC) $(CFLAGS) -c randtest.c

remcom.o: remcom.c
	$(CC) $(CFLAGS) -c remcom.c

spcount.o: spcount.c
	$(CC) $(CFLAGS) -c spcount.c


# ***************************************************************
# Executable programs

copyfile: copyfile.o
	$(CC) $(CFLAGS) -o copyfile copyfile.o ../booklib/cslib.a

craps: craps.o random.o
	$(CC) $(CFLAGS) -o craps craps.o random.o ../booklib/cslib.a

flipcoin: flipcoin.o random.o
	$(CC) $(CFLAGS) -o flipcoin flipcoin.o random.o ../booklib/cslib.a

linecopy: linecopy.o
	$(CC) $(CFLAGS) -o linecopy linecopy.o ../booklib/cslib.a

pigword1: pigword1.o
	$(CC) $(CFLAGS) -o pigword1 pigword1.o ../booklib/cslib.a

pigword2: pigword2.o
	$(CC) $(CFLAGS) -o pigword2 pigword2.o ../booklib/cslib.a

randtest: randtest.o
	$(CC) $(CFLAGS) -o randtest randtest.o ../booklib/cslib.a

remcom: remcom.o
	$(CC) $(CFLAGS) -o remcom remcom.o ../booklib/cslib.a

spcount: spcount.o
	$(CC) $(CFLAGS) -o spcount spcount.o ../booklib/cslib.a

