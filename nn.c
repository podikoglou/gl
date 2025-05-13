#include "nn.h"
#include <math.h>
#include <stdlib.h>

#define e 2.71828

float nn_random_weight_xavier() {
  return (rand() / (float)RAND_MAX - 0.5f) * 2.0f * sqrt(2.0f / (9 + 1));
}

float nn_relu(float x) {
  if (x > 0.0)
    return x;
  else
    return 0.0;
}

float nn_sigmoid(float x) { return (1 / (1 + powf(e, -x))); }

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

void forward_layer1(float input[9], float weights[9][4], float biases[4],
                    float output[4]) {
  for (int j = 0; j < 4; j++) {
    output[j] = biases[j];

    for (int i = 0; i < 9; i++) {
      output[j] += input[i] * weights[i][j];
    }

    output[j] = nn_relu(output[j]);
  }
}

float forward_layer2(float input[4], float weights[4][1], float bias) {
  float output = bias;

  for (int i = 0; i < 4; i++) {
    output += input[i] * weights[i][0];
  }

  return nn_sigmoid(output);
}

float nn_forward(nn *nn, float x[9]) {
  float y[4];

  forward_layer1(x, nn->weights_1, nn->biases_1, y);
  return forward_layer2(y, nn->weights_2, nn->biases_2[0]);
}
