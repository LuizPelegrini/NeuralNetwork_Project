#include "neuron.h"

char generateOutput(char** input, char** weight, char b, char wBias){
    int result = 0;
    int i, j;

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            result += (input[i][j]*weight[i][j]);
        }
    }

    // Include Bias
    result += (b*wBias);

    return activationFunction(result);
}

char activationFunction(int result){
    if(result > 0)
        return 1;
    else
        return 0;
}

void changeWeights(char** input, char** weight, char output, char desiredOutput){
    int i, j;
    int error;



    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            error = desiredOutput - output;
            weight[i][j] = (char)(weight[i][j] + (error * TAX_APRENDIZAGEM * input[i][j]));
        }
    }

    weightBias = (char)(weightBias + (error * TAX_APRENDIZAGEM * bias));

    weightMatrixChanged = 1;
}
