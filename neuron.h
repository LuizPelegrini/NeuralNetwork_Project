#ifndef NEURON_H
#define NEURON_H

#include "numberLayout.h"

#define TAX_APRENDIZAGEM 1
// Var to count how many eras is needed to solve the problem
int era;

// Flag
int weightMatrixChanged;

char generateOutput(char** input, char** weight, char b, char wBias);
char activationFunction(int result);
void changeWeights(char** input, char** weight, char output, char desiredOutput);

#endif // NEURON_H
