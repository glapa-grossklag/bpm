CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2

bpm: bpm.o
	$(CC) $^ -o $@

bpm.o: bpm.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean
clean:
	rm -f bpm bpm.o
