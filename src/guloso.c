#include "guloso.h"

int energia_harry (int* caminho, int indice_caminho) {

    int energia_inicial = 1;
    int energia = 1;

    for (int i = 0; i < indice_caminho; i++) {
        energia = energia + caminho[i];
        while(energia < 1) {
            energia++;
            energia_inicial++;
        }
    }

    return energia_inicial;
}


int guloso (Graph *graph, int nrows, int ncols) {

    int* caminho = (int*)malloc(graph->nvertices * sizeof(int));
    int indice_caminho = 0;
    int indice_vertices = 0; 
    int melhor_vertice = 0;

    caminho[indice_caminho] = graph->vertices[0].value;
    indice_caminho++;
    while (indice_vertices+1 < graph->nvertices) {
        int maior_aresta = INT_MIN, nova_aresta = INT_MIN;
        for(int i = 0; i < graph->nvertices; i++) {
            nova_aresta = graph->adjMatrix[indice_vertices][i];  
            if (nova_aresta > maior_aresta) {
                maior_aresta = nova_aresta;
                melhor_vertice = i;
            }
        }

        caminho[indice_caminho] = graph->vertices[melhor_vertice].value;
        indice_caminho++;
        indice_vertices = melhor_vertice;
    }
    int energia = energia_harry(caminho, indice_caminho);
    free(caminho);
    return energia;
}
