all: mytarget run checkmem clean

mytarget: tournament.c program4.c
	gcc -c tournament.c program4.c
	gcc -o program4 tournament.o program4.o

run: program4
	./program4

checkmem: 
	valgrind ./program4

clean:
	rm -i program4 tournament.o program4.o

