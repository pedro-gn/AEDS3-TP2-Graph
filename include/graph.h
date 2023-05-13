#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// O vertice do grafo tera a posição dele dentro do tabuleiro e seu valor
typedef struct{
    int value;
    int row,col;
}Vertice;

int **createAdjMatrix(int **matrix, int nrows, int ncols, Vertice *vertices);


Vertice *createVerticesArr(int **matrix, int nrows, int ncols);




#endif