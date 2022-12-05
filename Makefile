CC=clang
CFLAGS=-Wall -ggdb

BINS=brainfuck

OBJ=brainfuck.o stack.o

all: $(BINS)

brainfuck.o: brainfuck.c
	$(CC) $(CFLAGS) -c -o $@ $<

stack.o: stack.c
	$(CC) $(CFLAGS) -c -o $@ $<

brainfuck: brainfuck.o stack.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm $(BINS) *.o
