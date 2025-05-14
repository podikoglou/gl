CC = gcc
CFLAGS = -O3 -Wall -Wextra -pedantic -lm

all: gl-run gl-bench nn-train

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

gl-run: gl.c gl-run.c
gl-bench: gl.c gl-bench.c
nn-train: gl.c nn.c nn_math.c nn-train.c

clean:
	rm gl-bench gl-run nn-train
