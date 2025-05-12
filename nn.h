#ifndef NN_H
#define NN_H

typedef struct nn {
  float weights_1[9][4];
  float biases_1[4];

  float weights_2[4][1];
  float biases_2[1];
} nn;

void nn_init(nn *nn);
float nn_forward(nn *nn, float x[9]);

#endif
