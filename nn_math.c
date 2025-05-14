#include "nn_math.h"
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
