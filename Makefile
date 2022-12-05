CC=clang
CFLAGS=-Wall -ggdb

BINS=brainfuck

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(BINS)
