#ifndef GL_H
#define GL_H

#include "opts.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct gl_grid {
  bool grid[GRID_HEIGHT][GRID_WIDTH];
} gl_grid;

void gl_grid_init(gl_grid *grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      grid->grid[y][x] = false;
    }
  }
}

int gl_grid_compute_alive_neighbours(gl_grid *grid, int y, int x) {
  int counter = 0;

  for (int dy = dy - 1; dy < dy + 1; dy++) {
    for (int dx = dx - 1; dx < dx + 1; dy++) {
      // ignore center clel
      if (dy == y || dx == x)
        continue;

      // ensure dy and dx are within the grid bounds
      if (dy > 0 && dy < GRID_WIDTH && dx > 0 && dx < GRID_HEIGHT) {

        if (grid->grid[dy][dx])
          counter++;
      }
    }
  }

  return counter;
}

void gl_grid_generation(gl_grid *grid) {
  int neighbours[GRID_HEIGHT][GRID_WIDTH];

  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      int alive_neighbours = gl_grid_compute_alive_neighbours(grid, y, x);

      neighbours[y][x] = alive_neighbours;
    }
  }

  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      bool alive = grid->grid[y][x];
      int alive_neighbours = neighbours[y][x];

      bool new_state;

      if (alive) {
        new_state = alive_neighbours == 2 || alive_neighbours == 3;
      } else {
        new_state = alive_neighbours == 3;
      }

      neighbours[y][x] = new_state;
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

#endif
