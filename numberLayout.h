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
    char* desiredOutput;
    struct digitNode* next;
}DigitNode;

typedef struct controller{
    DigitNode* initial;
    DigitNode* ending;
}Controller;

 Controller *controller;        // Controller to help find the last node and the first node
 DigitNode *last;               // Points to the last node to be computed

char** m_weightMatrix;
char bias;
char weightBias;

void createDigitNode(int number);
void createMatrixZero(char** matrix);
void createMatrixOne(char** matrix);
void createWeightMatrix(int randomInit);
void insertNode(DigitNode* digitNode);
int isEmpty();
int initialize(int randomInit);


#endif
