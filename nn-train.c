#include "gl.h"
#include "nn.h"
#include "opts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  /* setup */
  srand(time(NULL));

  /* init network */
  nn nn;
  nn_init(&nn);

  gl_grid grid;

  /* init grid */
  for (int epoch = 0; epoch < 5; epoch++) {

    /* reset grid */
    gl_grid_init_rand(&grid);

    printf("[nn]: starting epoch %d\n", epoch);

    for (int i = 0; i < GRID_HEIGHT; i++) {
      for (int j = 0; j < GRID_WIDTH; j++) {
        float neighbours[9];
        int pos = 0;

        int alive_neighbours = 0;

        float actual_y, pred_y;

        /* iterate through all cells */
        for (int dy = i - 1; dy <= i + 1; dy++) {
          for (int dx = j - 1; dx <= j + 1; dx++) {

            /* ensure dy and dx are within the grid bounds */
            if (dy >= 0 && dy < GRID_HEIGHT && dx >= 0 && dx < GRID_WIDTH) {

              bool alive = grid.grid[dy][dx];

              /* put state in neighbours array */
              neighbours[pos++] = alive ? 1 : 0;

              /* increase alive neighbours counter (used to compute actual y) */
              if (alive)
                alive_neighbours++;
            }
          }
        }

        /* calculate actual y */
        /* TODO: use function from gl.h (and, well, make the function) */
        bool next_state = grid.grid[i][j]
                              ? (alive_neighbours == 2 || alive_neighbours == 3)
                              : alive_neighbours == 3;

        actual_y = next_state ? 1.0 : 0.0;

        /* forward */
        pred_y = nn_forward(&nn, neighbours);

        printf("actual: %f, predicted: %f\n", actual_y, pred_y);

        /* TODO: backpropagination */
      }
    }
  }
}
