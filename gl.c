#include "gl.h"
#include "opts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gl_grid_init_zero(gl_grid *grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      grid->grid[y][x] = false;
    }
  }
}

void gl_grid_init_rand(gl_grid *grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      grid->grid[y][x] = rand() & 1;
    }
  }
}

int gl_grid_compute_alive_neighbours(gl_grid *grid, int y, int x) {
  int counter = 0;

  for (int dy = y - 1; dy <= y + 1; dy++) {
    for (int dx = x - 1; dx <= x + 1; dx++) {

      // ignore center cell
      if (dy == y && dx == x)
        continue;

      // ensure dy and dx are within the grid bounds
      if (dy >= 0 && dy < GRID_HEIGHT && dx >= 0 && dx < GRID_WIDTH) {

        if (grid->grid[dy][dx])
          counter++;
      }
    }
  }

  return counter;
}

void gl_grid_generation(gl_grid *grid) {
  gl_grid *copy;
  memcpy(&copy, &grid, sizeof(grid));

  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      bool alive = copy->grid[y][x];
      int alive_neighbours = gl_grid_compute_alive_neighbours(copy, y, x);

      bool new_state = alive ? (alive_neighbours == 2 || alive_neighbours == 3)
                             : alive_neighbours == 3;

      grid->grid[y][x] = new_state;
    }
  }
}

void gl_grid_print(gl_grid *grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      bool alive = grid->grid[y][x];

      printf(alive ? "1" : " ");
    }

    printf("\n");
  }
}
