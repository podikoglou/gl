#include "gl.h"

#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));

  gl_grid grid;

  gl_grid_init_rand(&grid);

  gl_grid_print(&grid);
  gl_grid_generation(&grid);
  gl_grid_print(&grid);
}
