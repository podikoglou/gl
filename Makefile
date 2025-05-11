CC = gcc
CFLAGS = -O3 -Wall -Wextra -pedantic

all: gl-run gl-bench

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

gl-run: gl.c gl-run.c
gl-bench: gl.c gl-bench.c

clean:
	rm gl-bench gl-run
