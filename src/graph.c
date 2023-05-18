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



// Algoritmo de bellmanford.
// Acha o menor caminho em um grafo ponderado podendo conter pesos negativos
void bellmanford(Graph graph, int start, int **pred) {
    int i, j, k;
    int dist[graph.nvertices];
    *pred = malloc(graph.nvertices * sizeof(int));

    // Inicializa as distâncias de todos os vértices como "infinito"
    for (i = 0; i < graph.nvertices; i++) {
        dist[i] = INT_MAX;
        (*pred)[i] = -1;
    }
    // A distância do vértice de início para ele mesmo é 0
    dist[start] = 0;

    // Relaxa as arestas repetidamente
    for (i = 0; i < graph.nvertices - 1; i++) {
        for (j = 0; j < graph.nvertices; j++) {
            for (k = 0; k < graph.nvertices; k++) {
                if (graph.adjMatrix[j][k] != INT_MIN) {
                    if (dist[j] != INT_MAX && dist[j] + graph.adjMatrix[j][k] < dist[k]) {
                        dist[k] = dist[j] + graph.adjMatrix[j][k];
                        (*pred)[k] = j;
                    }
                }
            }
        }
    }

    // Verifica se há ciclos negativos
    for (j = 0; j < graph.nvertices; j++) {
        for (k = 0; k < graph.nvertices; k++) {
            if (graph.adjMatrix[j][k] != INT_MIN) {
                if (dist[j] != INT_MAX && dist[j] + graph.adjMatrix[j][k] < dist[k]) {
                    printf("O grafo contém um ciclo negativo\n");
                    return;
                }
            }
        }
    }   
}

// Nega o grafo tranformando pesos negativos em positivos e vice-versa
void negateGraph(Graph *graph){
    
    for(int i = 0; i < graph->nvertices; i++){
        for(int j = 0; j < graph->nvertices; j++){
            if(graph->adjMatrix[i][j] != INT_MIN){
                graph->adjMatrix[i][j] = ~graph->adjMatrix[i][j] + 1;
            }
        }
    }

}

void freeGraph(Graph *graph){
    
    free(graph->vertices);
    for(int i = 0; i < graph->nvertices; i++){
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    
}


