#ifndef GL_H
#define GL_H

#include "opts.h"
#include <stdbool.h>

typedef struct gl_grid {
  bool grid[GRID_HEIGHT][GRID_WIDTH];
} gl_grid;

void gl_grid_init_zero(gl_grid *grid);
void gl_grid_init_rand(gl_grid *grid);

int gl_grid_compute_alive_neighbours(gl_grid *grid, int y, int x);
void gl_grid_generation(gl_grid *grid);
void gl_grid_print(gl_grid *grid);

#endif
