#include "gl.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void print_usage(char *bin) { printf("usage: %s <generations>\n", bin); }

int main(int argc, char **argv) {
  /* read args */

  if (argc <= 1) {
    print_usage(argv[0]);
    return 1;
  }

  char *generations_raw = argv[1];
  int generations = atoi(generations_raw);

  if (generations == 0) {
    print_usage(argv[0]);
    return 1;
  }

  /* setup */
  srand(time(NULL));

  gl_grid grid;
  gl_grid_init_rand(&grid);

  clock_t start, end;

  /* start timer and compute generations  */
  start = clock();

  for (int i = 0; i < generations; i++)
    gl_grid_generation(&grid);

  end = clock();

  /* calculate elapsed time */
  double elapsed = 1000.0 * (end - start) / CLOCKS_PER_SEC;

  printf("took %f ms to compute %d generations\n", elapsed, generations);
}
