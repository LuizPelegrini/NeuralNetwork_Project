#ifndef NUMBERLAYOUT_H
#define NUMBERLAYOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 5
#define ARRAY_SIZE 4

typedef struct digitNode{
    char** matrix;
    struct digitNode* next;
}DigitNode;

typedef struct controller{
    DigitNode* initial;
    DigitNode* ending;
}Controller;

 Controller *controller;        // Controller to help find the last node and the first node
 DigitNode *last;               // Points to the last node to be computed

char** m_weightMatrix;
char* m_resultArray;
char bias;
char weightBias;

char** createNumberMatrix(int number);
char** createWeightMatrix(int number, int randomInit);


#endif
