#ifndef NUMBERLAYOUT_H
#define NUMBERLAYOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 5
#define ARRAY_SIZE 6

typedef struct digitNode{
    char** matrix;
    char* desiredOutput;
    struct digitNode* next;
}DigitNode;

typedef struct controller{
    DigitNode* initial;
    DigitNode* ending;
}Controller;

typedef struct weightMatrix{
    char **weightMatrix;
    char weightBias;
    struct weightMatrix* next;
}WeightMatrix;

typedef struct weightMatrixController{
    WeightMatrix *first;
    int numElements;
}WeightMatrixController;

Controller *controller;                     // Controller to help find the last node and the first node
WeightMatrixController *weightController;

char bias;

void createDigitNode(int number);
void createMatrixZero(char** matrix);
void createMatrixOne(char** matrix);
void createMatrixTwo(char** matrix);
void createMatrixThree(char** matrix);
void createMatrixFour(char** matrix);
void createMatrixFive(char** matrix);
void createWeightMatrix(int randomInit);
void insertNode(DigitNode* digitNode);
void printWeightValues();
void cleanMemory();
int isEmpty();
int initialize();


#endif
