#include "graph.h"


// Cria o grafo com o array de vertices e a matrix de adjacencia
void createGraph(Graph *graph, int **matrix, int nrows, int ncols){
    graph->nvertices = nrows * ncols;
    graph->vertices = (Vertice*)malloc(graph->nvertices * sizeof(Vertice));

    // Array de vertices 
    int count=0;

    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++){
            graph->vertices[count].value = matrix[i][j];
            graph->vertices[count].row = i;
            graph->vertices[count].col = j;
            count++;
        }
    }

    // Matrix de adjacencia

    graph->adjMatrix = (int **)malloc(graph->nvertices * sizeof(int*));

    for(int i = 0; i < graph->nvertices; i++){
        graph->adjMatrix[i] = (int *)malloc(graph->nvertices * sizeof(int));
    } 
    
    for(int i = 0; i < graph->nvertices; i++){
        for(int j = 0; j < graph->nvertices; j++){
            
            if((graph->vertices[i].col + 1  == graph->vertices[j].col && graph->vertices[i].row  == graph->vertices[j].row ) || (graph->vertices[i].row + 1  == graph->vertices[j].row && graph->vertices[i].col == graph->vertices[j].col)){
                graph->adjMatrix[i][j] = graph->vertices[j].value;
            }else{
                graph->adjMatrix[i][j] = INT_MIN;
            }
        }
    }
}
