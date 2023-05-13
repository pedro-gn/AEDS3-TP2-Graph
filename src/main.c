#include <stdio.h>
#include <stdlib.h>
#include "fileHandler.h"
#include "graph.h"

int main(int argc, char *argv[]){
    FILE *inputFile;
    int strategy;

    int numberOfTests;
    int nrows=0, ncols=0;
    int **testMatrix;


    if(argc == 3){
        strategy = atoi(argv[1]);
        inputFile = fopen(argv[2], "r");
    }else{
        printf("Argumentos Faltando ou Sobrando!");
        exit(1);
    }


    // Resolução 

    // Numero de casos de testes no arquivo de entrada
    numberOfTests = getNumberOfTests(inputFile);

    // A cada iteração temos o numero de colunas, linhas e a matriz do teste
    for(int i = 0; i < numberOfTests; i++){

        readMatrix(inputFile, &nrows, &ncols, &testMatrix);

        Vertice *vertices = createVerticesArr(testMatrix, nrows, ncols);

        int **adjMatrix = createAdjMatrix(testMatrix, nrows, ncols, vertices);


        if(strategy == 1){
            // Algoritmo 1
        }else if(strategy == 2){
            // Algoritmo 2
        }


        
        free(vertices);
    }



    fclose(inputFile);
    return 0;
}