#include "numberLayout.h"


int initialize(){
    // Initialize the controller
    controller = (Controller*)malloc(sizeof(Controller));
    controller->initial = NULL;
    controller->ending = NULL;

    weightController = (WeightMatrixController*)malloc(sizeof(WeightMatrixController));
    weightController->first = NULL;
    weightController->numElements = 0;

    bias = 1;

    return 1;
}

int isEmpty(){
    if(controller->initial==NULL)
        return 1;
    return 0;
}

int weightListIsEmpty(){
    if(weightController->numElements == 0)
        return 1;
    return 0;
}

void createDigitNode(int number){
    int i, j;                           // iterators
    char** matrix;                      // matrix, according to the chosen digit
    char* outputArray;
    DigitNode* digitNode;               // node


    matrix = (char**)malloc(ROWS*sizeof(char*));
    outputArray = (char*)malloc(6*sizeof(char));

    for(i=0;i<ROWS;i++){
        matrix[i] = (char*)malloc(COLUMNS*sizeof(char));
    }

    // Zero full matrix
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            matrix[i][j] = 0;
        }
    }

    // According to the digit, the matrix is filled
    switch(number){
        case 0:
            // Represent the digit 0 in the matrix
            createMatrixZero(matrix);

            // Define the desired output
            outputArray[0] = 1;
            outputArray[1] = 0;
            outputArray[2] = 0;
            outputArray[3] = 0;
            outputArray[4] = 0;
            outputArray[5] = 0;
            break;
        case 1:
            // Represent the digit 1 in the matrix
            createMatrixOne(matrix);

            // Define the desired output
            outputArray[0] = 0;
            outputArray[1] = 1;
            outputArray[2] = 0;
            outputArray[3] = 0;
            outputArray[4] = 0;
            outputArray[5] = 0;
            break;
        case 2:
            // Represent the digit 2 in the matrix
            createMatrixTwo(matrix);

            // Define the desired output
            outputArray[0] = 0;
            outputArray[1] = 0;
            outputArray[2] = 1;
            outputArray[3] = 0;
            outputArray[4] = 0;
            outputArray[5] = 0;
            break;
        case 3:
            // Represent the digit 3 in the matrix
            createMatrixThree(matrix);

            // Define the desired output
            outputArray[0] = 0;
            outputArray[1] = 0;
            outputArray[2] = 0;
            outputArray[3] = 1;
            outputArray[4] = 0;
            outputArray[5] = 0;
            break;
        case 4:
            // Represent the digit 4 in the matrix
            createMatrixFour(matrix);

            // Define the desired output
            outputArray[0] = 0;
            outputArray[1] = 0;
            outputArray[2] = 0;
            outputArray[3] = 0;
            outputArray[4] = 1;
            outputArray[5] = 0;
            break;
        case 5:
            // Represent the digit 5 in the matrix
            createMatrixFive(matrix);

            // Define the desired output
            outputArray[0] = 0;
            outputArray[1] = 0;
            outputArray[2] = 0;
            outputArray[3] = 0;
            outputArray[4] = 0;
            outputArray[5] = 1;
            break;
        default:
            printf("Digit not supported!\n");
            break;
    }


    // Create new node
    digitNode = (DigitNode*)malloc(sizeof(DigitNode));

    // Feed the matrix of the node
    digitNode->matrix = matrix;

    // Feed the desired output array of the node
    digitNode->desiredOutput = outputArray;

    // Insert the new node in the circular list
    insertNode(digitNode);
}

void insertNode(DigitNode* digitNode){

    if(isEmpty()){
        digitNode->next = digitNode;

        controller->initial = digitNode;
        controller->ending = digitNode;
    }
    else{
        // Circular list
        digitNode->next = controller->initial;

        // Updates the pointer of the last node in the list
        controller->ending->next = digitNode;

        // Updates the ending pointer of the list, to the recently created node
        controller->ending = digitNode;
    }

    //free(matrix);                                 // <<<<<<<<<<<<<<<<<<<<< try this later
}

void insertWeightMatrix(WeightMatrix *weightMatrix){
    WeightMatrix *aux;

    if(weightListIsEmpty()){
        weightController->first = weightMatrix;
    }
    else{
        aux = weightController->first;

        while(aux->next != NULL)
            aux = aux->next;

        aux->next = weightMatrix;
    }

    weightController->numElements++;
}

void createWeightMatrix(int randomInit){
    int i, j;
    WeightMatrix *weightMatrix;

    weightMatrix = (WeightMatrix*)malloc(sizeof(WeightMatrix));

    weightMatrix->weightMatrix = (char**)malloc(ROWS*sizeof(char*));

    for(i=0;i<ROWS;i++){
        weightMatrix->weightMatrix[i] = (char*)malloc(COLUMNS*sizeof(char));
    }


    // If the user wants random initialization, do it man!
    // Else, let the zeros rule the world!
    if(randomInit){

        srand((unsigned)time(NULL));

        for(i=0;i<ROWS;i++){
            for(j=0;j<COLUMNS;j++){
                weightMatrix->weightMatrix[i][j] = rand()%10;
            }
        }

        // Initialize bias weight
        weightMatrix->weightBias = rand()%10;
    }else{

        for(i=0;i<ROWS;i++){
            for(j=0;j<COLUMNS;j++){
                weightMatrix->weightMatrix[i][j] = 0;
            }
        }

        // Initialize bias weight
        weightMatrix->weightBias = 0;
    }

    weightMatrix->next = NULL;
    insertWeightMatrix(weightMatrix);
}

void createMatrixZero(char** matrix){
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[1][0] = 1;
    matrix[2][0] = 1;
    matrix[3][0] = 1;
    matrix[4][0] = 1;
    matrix[1][4] = 1;
    matrix[2][4] = 1;
    matrix[3][4] = 1;
    matrix[4][4] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
}

void createMatrixOne(char** matrix){

    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][2] = 1;
    matrix[3][2] = 1;
    matrix[4][2] = 1;
    matrix[5][2] = 1;
    matrix[5][0] = 1;
    matrix[5][1] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;
    matrix[1][1] = 1;
}

void createMatrixTwo(char** matrix){
/*
    Graphic representation

    * 0 0 0 *
    * 0 * 0 *
    * * * 0 *
    * * 0 * *
    * 0 * * *
    0 0 0 0 0
*/

    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[1][1] = 1;
    matrix[1][3] = 1;
    matrix[2][3] = 1;
    matrix[3][2] = 1;
    matrix[4][1] = 1;
    matrix[5][0] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;
}

void createMatrixThree(char** matrix){

    /*
        Graphical Representation

        * 0 0 0 0
        * * * * 0
        * 0 0 0 0
        * * * * 0
        * * * * 0
        * 0 0 0 0
    */

    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[0][4] = 1;
    matrix[1][4] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
    matrix[2][4] = 1;
    matrix[3][4] = 1;
    matrix[4][4] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;
}

void createMatrixFour(char** matrix){

    /*
        Graphical Representation

        0 * * 0 *
        0 * * 0 *
        0 0 0 0 *
        * * * 0 *
        * * * 0 *
        * * * 0 *
    */

    matrix[0][0] = 1;
    matrix[0][3] = 1;
    matrix[1][0] = 1;
    matrix[1][3] = 1;
    matrix[2][0] = 1;
    matrix[2][3] = 1;
    matrix[3][0] = 1;
    matrix[3][1] = 1;
    matrix[3][2] = 1;
    matrix[3][3] = 1;
    matrix[4][3] = 1;
    matrix[5][3] = 1;
}

void createMatrixFive(char** matrix){

    /*
        Graphical Representation

        * 0 0 0 0
        * 0 * * *
        * 0 0 0 0
        * * * * 0
        * * * * 0
        * 0 0 0 0
    */

    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[0][4] = 1;
    matrix[1][1] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
    matrix[2][4] = 1;
    matrix[3][4] = 1;
    matrix[4][4] = 1;
    matrix[5][1] = 1;
    matrix[5][2] = 1;
    matrix[5][3] = 1;
    matrix[5][4] = 1;
}

void printWeightValues(){
    WeightMatrix* aux;
    int i, j, k = 0;

    aux = weightController->first;

    do{
        printf("**************************\n");
        printf("Weight Matrix >> %d <<\n", k++);
        printf("**************************\n");
        for(i=0;i<ROWS;i++){
            for(j=0;j<COLUMNS;j++){
                printf("%d | ", aux->weightMatrix[i][j]);
            }
            printf("\n");
        }

        printf("\n\n");
    }while((aux = aux->next) != NULL);

}

void cleanMemory(){
    int i;

    DigitNode* aux;
    aux = controller->initial->next;
/*
    for(i=0;i<ROWS;i++){
        free(m_weightMatrix[i]);
    }

    free(m_weightMatrix);*/

    while(aux != controller->ending){
        free(controller->initial);
        controller->initial = aux;
        aux = aux->next;
    }

    free(controller->initial);
    free(controller->ending);
    free(controller);

}

