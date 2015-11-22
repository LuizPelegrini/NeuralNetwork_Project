#include <stdio.h>
#include <stdlib.h>
#include "numberLayout.h"
#include "neuron.h"

int main()
{
    char** numberZeroMatrix;                                        // Matrix to represent the digit 0
    char** numberOneMatrix;                                         // Matrix to represent the digit 1
    char** weightMatrix;
    char result;

    numberZeroMatrix = createNumberMatrix(0);
    numberOneMatrix = createNumberMatrix(1);
    weightMatrix = createWeightMatrix(0, 0);

    // The Weight matrix has not changed yet
    weightMatrixChanged = 0;

    result = generateOutput(numberZeroMatrix, weightMatrix, bias, weightBias);


    while(weightMatrixChanged == 1 || !NAO_CHGOU_NO_FINAL){

    }

    printf("result: %d\n", result);

    return 0;
}
