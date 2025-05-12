#include "nn.h"
#include <math.h>
#include <stdlib.h>

float nn_random_weight_xavier() {
  return (rand() / (float)RAND_MAX - 0.5f) * 2.0f * sqrt(2.0f / (9 + 1));
}

void nn_init(nn *nn) {
  /* initialize first layer */

  /* weights */
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 4; j++) {
      nn->weights_1[i][j] = nn_random_weight_xavier();
    }
  }

  /* biases */
  for (int i = 0; i < 4; i++) {
    nn->biases_1[i] = 0.0;
  }

  /* initialize second layer */

  /* weights */
  for (int i = 0; i < 4; i++) {
    nn->weights_2[i][0] = nn_random_weight_xavier();
  }

  /* biases */
  nn->biases_2[0] = 0.0;
}

float nn_forward(nn *nn, float x[9]) { return 0.0; }
