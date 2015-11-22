#include "numberLayout.h"


int initialize(int randomInit){
    // Initialize the contoller
    controller = (Controller*)malloc(sizeof(Controller));
    controller->initial = NULL;
    controller->ending = NULL;

    // Initialize the weight matrix
    createWeightMatrix(randomInit);

    // Initialize the result array
    m_resultArray = (char*)malloc(ARRAY_SIZE*sizeof(char));

    // Initialize bias and the its corresponding weight
    bias = 1;
    weightBias = 0;
}

int isEmpty(){
    if(controller->initial==NULL)
        return 1;
    return 0;
}

void createDigitNode(int number){
    int i, j;                           // iterators
    char** matrix;                      // matrix, according to the chosen digit
    DigitNode* digitNode;               // node


    matrix = (char**)malloc(ROWS*sizeof(char*));

    for(i=0;i<ROWS;i++){
        matrix[j] = (char*)malloc(COLUMNS*sizeof(char));
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
            m_resultArray[0] = 0;
            m_resultArray[1] = 0;
            m_resultArray[2] = 0;
            m_resultArray[3] = 0;
            break;
        case 1:
            // Represent the digit 1 in the matrix
            createMatrixOne(matrix);

            // Define the desired output
            m_resultArray[0] = 0;
            m_resultArray[1] = 0;
            m_resultArray[2] = 0;
            m_resultArray[3] = 1;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            printf("Digit not supported!\n");
            break;
    }


    if(isEmpty()){

        digitNode = (DigitNode*)malloc(sizeof(DigitNode));
        digitNode->matrix = matrix;
        digitNode->next = NULL;

        controller->initial = digitNode;
        controller->ending = digitNode;

        //free(matrix);                                 // <<<<<<<<<<<<<<<<<<<<< try this later
    }
    else{
        // Create new node
        digitNode = (DigitNode*)malloc(sizeof(DigitNode));

        // Feed the matrix of the node
        digitNode->matrix = matrix;

        // Circular list
        digitNode->next = controller->initial;

        // Updates the pointer of the last node in the list
        controller->ending->next = digitNode;

        // Updates the ending pointer of the list, to the recently created node
        controller->ending = digitNode;

        // the last node to be tested will be the last node of the list
        last = controller->ending;
    }

    /*for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            printf("%d | ", m_numberMatrix[i][j]);
        }
        printf("\n");
    }*/
}

void createWeightMatrix(int randomInit){
    int i, j;

    m_weightMatrix = (char**)malloc(ROWS*sizeof(char*));

    for(i=0;i<ROWS;i++){
        m_weightMatrix[i] = (char*)malloc(COLUMNS*sizeof(char));
    }

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            m_weightMatrix[i][j] = 0;
        }
    }


    // If the user wants random initialization, do it
    // Else, let it as it is
    if(randomInit){
        // Random initialization between 0 and 10
        srand((unsigned)time(NULL));

        switch(number){
            case 0:
                m_weightMatrix[0][1] = rand()%10;
                m_weightMatrix[0][2] = rand()%10;
                m_weightMatrix[0][3] = rand()%10;
                m_weightMatrix[1][0] = rand()%10;
                m_weightMatrix[2][0] = rand()%10;
                m_weightMatrix[3][0] = rand()%10;
                m_weightMatrix[4][0] = rand()%10;
                m_weightMatrix[1][4] = rand()%10;
                m_weightMatrix[2][4] = rand()%10;
                m_weightMatrix[3][4] = rand()%10;
                m_weightMatrix[4][4] = rand()%10;
                m_weightMatrix[5][1] = rand()%10;
                m_weightMatrix[5][2] = rand()%10;
                m_weightMatrix[5][3] = rand()%10;

                weightBias = rand()%10;
                break;
            case 1:
                m_weightMatrix[0][2] = rand()%10;
                m_weightMatrix[1][2] = rand()%10;
                m_weightMatrix[2][2] = rand()%10;
                m_weightMatrix[3][2] = rand()%10;
                m_weightMatrix[4][2] = rand()%10;
                m_weightMatrix[5][2] = rand()%10;
                m_weightMatrix[5][0] = rand()%10;
                m_weightMatrix[5][1] = rand()%10;
                m_weightMatrix[5][3] = rand()%10;
                m_weightMatrix[5][4] = rand()%10;
                m_weightMatrix[1][1] = rand()%10;

                weightBias = rand()%10;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
        }
    }

    /*for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            printf("%d | ", m_weightMatrix[i][j]);
        }
        printf("\n");
    }*/
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
