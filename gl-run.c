#include "gl.h"

int main(void) {
  gl_grid grid;

  gl_grid_init(&grid);

  gl_grid_print(&grid);
  gl_grid_generation(&grid);
  gl_grid_print(&grid);
}
