#include "gl.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  srand(time(NULL));

  gl_grid grid;

  gl_grid_init_rand(&grid);

  for (;;) {
    printf("\x1B[2J");
    gl_grid_print(&grid);
    gl_grid_generation(&grid);

    usleep(1000000);
  }
}
