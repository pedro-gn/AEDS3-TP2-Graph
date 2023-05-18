#include <stdio.h>
#include <stdlib.h>

#include "fileHandler.h"
#include "graph.h"
#include "solution1.h"


int main(int argc, char *argv[]){
    FILE *inputFile;
    int strategy;

    int numberOfTests;
    int nrows=0, ncols=0;
    int **testMatrix;
    Graph graph;


    if(argc == 3){
        strategy = atoi(argv[1]);
        inputFile = fopen(argv[2], "r");
    }else{
        printf("Argumentos Faltando ou Sobrando!");
        exit(1);
    }

    // Numero de casos de testes no arquivo de entrada
    numberOfTests = getNumberOfTests(inputFile);
    int results[numberOfTests];

    // Um dos testes por iteração
    for(int i = 0; i < numberOfTests; i++){

        // Le a matriz de testes e o numero de linhas e colunas
        readMatrix(inputFile, &nrows, &ncols, &testMatrix);

        // Cria o grafo
        createGraph(&graph, testMatrix, nrows, ncols);
        

        if(strategy == 1){
            // Algoritmo 1
            results[i] = solution1(graph, nrows, ncols);
            
        }else if(strategy == 2){
            // Algoritmo 2
        }
        freeMatrix(testMatrix, nrows);
        freeGraph(&graph);
    }

    // Escreve o resultado no arquivo
    writeFile(results, numberOfTests);
    
    fclose(inputFile);
    return 0;
}