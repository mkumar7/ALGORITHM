all: mytarget run checkmem clean

mytarget: bst.c program6.c
	gcc -c bst.c  program6.c
	gcc -o program6 bst.o program6.o

run: program6
	./program6

checkmem: 
	valgrind ./program6

clean:
	rm -i program6 

