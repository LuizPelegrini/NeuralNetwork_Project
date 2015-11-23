#include <stdio.h>
#include <stdlib.h>
#include "numberLayout.h"
#include "neuron.h"

int main()
{
    /*
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
    */

    DigitNode *aux, *dirty;
    char *result;
    int clean = 0;
    int i, j;

    initialize(0);
    createDigitNode(0);
    createDigitNode(1);

    aux = controller->initial;
    dirty = controller->ending;

    // Verify the remaining nodes
    do{
        result = generateOutput(aux->matrix, m_weightMatrix, bias, weightBias, 1);

        printf("result[0] = %d\n", result[0]);
        printf("aux->desiredOutput[3] = %d\n", aux->desiredOutput[3]);

        if(result[0] != aux->desiredOutput[3]){
            changeWeights(aux->matrix, m_weightMatrix, result[0], aux->desiredOutput[3]);
            dirty = aux;
            aux = aux->next;
        }else{
            if(aux == dirty)
                clean = 1;
            aux = aux->next;
        }
    }while(!clean);


    // Result Weight Matrix
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            printf("%d | ", m_weightMatrix[i][j]);
        }
        printf("\n");
    }
    printf("Weight Bias = %d\n", weightBias);
    printf("\n");

    return 0;
}
