CC=g++
FLAG=-c

all:	Main.o VendingMachine.o
	$(CC) Main.o VendingMachine.o -o out
Main.o:
	$(CC) $(FLAG) Main.cpp
VendingMachine.o:
	$(CC) $(FLAG) VendingMachine.cpp VendingMachine.h
clean:
	rm *.o out *.gch	
	
