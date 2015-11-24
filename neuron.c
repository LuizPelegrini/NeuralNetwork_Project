#include "neuron.h"

char generateOutput(char** input, char** weight, char b, char wBias){
    int result;
    int i, j;


    result = 0;

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
    return 0;
}

void changeWeights(char** input, WeightMatrix* weightElement, char output, char desiredOutput){
    int i, j;
    int error;

    error = desiredOutput - output;

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            weightElement->weightMatrix[i][j] = (char)(weightElement->weightMatrix[i][j] + (error * TAX_APRENDIZAGEM * input[i][j]));
        }
    }

    weightElement->weightBias = (char)(weightElement->weightBias + (error * TAX_APRENDIZAGEM * bias));
}

void findNeuronWeightValues(int count){
    DigitNode *aux, *dirty;
    WeightMatrix *aux2;
    char result;
    int clean;

    aux2 = weightController->first;

    do{
        aux = controller->initial;
        dirty = controller->ending;
        clean = 0;

        ///CORE
        do{
            result = generateOutput(aux->matrix, aux2->weightMatrix, bias, aux2->weightBias);

            if(result != aux->desiredOutput[count]){
                changeWeights(aux->matrix, aux2, result, aux->desiredOutput[count]);
                dirty = aux;
                aux = aux->next;
            }else{
                if(aux == dirty)
                    clean = 1;
                aux = aux->next;
            }

        }while(!clean);
        ///END_CORE


        count++;

    }while((aux2 = aux2->next) != NULL);

}
