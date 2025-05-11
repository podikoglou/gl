all: gl-run gl-bench

gl-run: gl.c gl-run.c
gl-bench: gl.c gl-bench.c

clean:
	rm gl-bench gl-run
