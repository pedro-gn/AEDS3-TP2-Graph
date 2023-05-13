#include "graph.h"





Vertice *createVerticesArr(int **matrix, int nrows, int ncols){
    Vertice *vertices;

    vertices = (Vertice*)malloc(ncols * nrows * sizeof(Vertice));

    int count=0;

    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            vertices[count].value = matrix[i][j];
            vertices[count].row = i;
            vertices[count].col = j;
            count++;
        }
    }

    return vertices;
}

int **createAdjMatrix(int **matrix, int nrows, int ncols, Vertice *vertices){
    int adjMatrixSize = ncols * nrows;

    int **adjMatrix = (int **)malloc(adjMatrixSize * sizeof(int*));



    for(int i = 0; i < adjMatrixSize; i++){
        adjMatrix[i] = (int *)malloc(adjMatrixSize * sizeof(int));
    } 
    
    for(int i = 0; i < adjMatrixSize; i++){
        for(int j = 0; j < adjMatrixSize; j++){
            
            if((vertices[i].col + 1  == vertices[j].col && vertices[i].row  == vertices[j].row ) || (vertices[i].row + 1  == vertices[j].row && vertices[i].col == vertices[j].col)){
                adjMatrix[i][j] = vertices[j].value;
            }else{
                adjMatrix[i][j] = INT_MAX;
            }
        }
    }

    return adjMatrix;

}