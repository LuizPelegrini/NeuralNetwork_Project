#include <stdio.h>
#include <stdlib.h>
#include "numberLayout.h"
#include "neuron.h"

int main()
{

    int op, count;

    do{
        printf("Qual exercicio?\n");
        printf("1. Exercicio 1\n");
        printf("2. Exercicio 2\n");
        printf("3. Exercicio 3\n");
        printf("4. EXIT\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:         // 1 Neuron
                count = 1;
                initialize();                           // Initialize my data structures

                createWeightMatrix(0);                  // Weight matrix for neuron 1

                createDigitNode(0);                     // Create digit 0
                createDigitNode(1);                     // Create digit 1

                findNeuronWeightValues(count);          // Find the weight values for each matrix
                printWeightValues();                    // Print the results

                cleanMemory();                          // Clean memory leftovers
                break;
            case 2:         // 2 Neurons
                count = 0;
                initialize();                           // Initialize my data structures

                createWeightMatrix(0);                  // Weight matrix for neuron 1
                createWeightMatrix(0);                  // Weight matrix for neuron 2

                createDigitNode(0);                     // Create digit 0
                createDigitNode(1);                     // Create digit 1

                findNeuronWeightValues(count);          // Find the weight values for each matrix
                printWeightValues();                    // Print the results

                cleanMemory();                          // Clean memory leftovers
                break;
            default:
                break;
        }
    }while(op!=4);
    return 0;
}
