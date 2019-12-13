compile: list.c profile.c program5.c queue.c stack.c vector.c
	gcc -std=c11 -Wall *.c -o program5

all: compile

run: compile
	./program5

memcheck: compile
	valgrind --leak-check=yes ./program5

clean:
	rm -i program5
