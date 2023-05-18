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

// O grafo tera o array de vertices, a matrix de adjacencia e quantos vertices possui
typedef struct{
    Vertice *vertices;
    int nvertices;
    int **adjMatrix;
}Graph;

void createGraph(Graph *graph, int **matrix, int nrows, int ncols);

void negateGraph(Graph *graph);

void bellmanford(Graph graph, int start, int **pred);



#endif