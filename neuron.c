#include "neuron.h"

char* generateOutput(char** input, char** weight, char b, char wBias, int neuronQuantity){
    int result;
    int i, j, k;
    char* resultArray;

    resultArray = (char*)malloc(neuronQuantity*sizeof(char));

    for(k=0;k<neuronQuantity;k++){
        result = 0;

        for(i=0;i<ROWS;i++){
            for(j=0;j<COLUMNS;j++){
                result += (input[i][j]*weight[i][j]);
            }
        }

        // Include Bias
        result += (b*wBias);

        resultArray[k] = activationFunction(result);
    }

    return resultArray;
}

char activationFunction(int result){
    if(result > 0)
        return 1;
    return 0;
}

void changeWeights(char** input, char** weight, char output, char desiredOutput){
    int i, j;
    int error;

    error = desiredOutput - output;

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            weight[i][j] = (char)(weight[i][j] + (error * TAX_APRENDIZAGEM * input[i][j]));
        }
    }

    weightBias = (char)(weightBias + (error * TAX_APRENDIZAGEM * bias));
}
