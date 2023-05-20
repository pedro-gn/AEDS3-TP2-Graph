#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "fileHandler.h"
#include "graph.h"
#include "solution2.h"
#include "guloso.h"

float diffUserTime(struct rusage *start, struct rusage *end);
float diffSystemTime(struct rusage *start, struct rusage *end);


int main(int argc, char *argv[]){

    FILE *inputFile;
    int strategy;


    int numberOfTests;
    int nrows=0, ncols=0;
    int **testMatrix;
    Graph graph;


    // Medir tempo
    struct rusage startC, endC; // Tempo computação
    struct rusage startIO, endIO; // Tempo io
    struct timeval start, end; // Tempo de relgio


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


    gettimeofday(&start, NULL);
    
    // Um dos testes por iteração
    for(int i = 0; i < numberOfTests; i++){

        getrusage(RUSAGE_SELF, &startIO);
        // Le a matriz de testes e o numero de linhas e colunas
        readMatrix(inputFile, &nrows, &ncols, &testMatrix);
        getrusage(RUSAGE_SELF, &endIO);


        // Cria o grafo
        createGraph(&graph, testMatrix, nrows, ncols);
        

        if(strategy == 1){
            // Algoritmo 1
            getrusage(RUSAGE_SELF, &startC);
            results[i] = solution2(graph, nrows, ncols);
            getrusage(RUSAGE_SELF, &endC);

        }else if(strategy == 2){
            // Algoritmo 2
            getrusage(RUSAGE_SELF, &startC);
            results[i] = guloso(&graph, nrows, ncols);
            getrusage(RUSAGE_SELF, &endC);
        }

        printf("Tempo de computacao do teste numero [ %d ] :\n", i+1);
        printf("  CPU time: %.06f seg user, %.06f seg system\n", diffUserTime(&startC, &endC), diffSystemTime(&startC, &endC));
    

        freeMatrix(testMatrix, nrows);
        freeGraph(&graph);
    }

    gettimeofday(&end, NULL);

    printf("Tempo de I/O :\n");
    printf("  CPU time: %.06f seg user, %.06f seg system\n", diffUserTime(&startIO, &endIO), diffSystemTime(&startIO, &endIO));

    printf("Tempo de relogio Total : %f segundos\n",
    1e-6*((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));


    // Escreve o resultado no arquivo
    writeFile(results, numberOfTests);
    
    fclose(inputFile);
    return 0;
}





// Calcula tempo do usuario
float diffUserTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

// Calcula tempo do sistema
float diffSystemTime(struct rusage *start, struct rusage *end)
{
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}