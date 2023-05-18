#include "../include/solution1.h"

int solution1(Graph graph, int nrows, int ncols){
    int *pred;
    // Nega o grafo transformando as arestas positivas em negativas e vice versa
    negateGraph(&graph);
    // Aplica o algoritmo de bellmanford para achar o 
    // Menor caminho no grafo negado que é igual ao "maior" no graficpo normal ou seja o caminho que perde menos vida e ganha mais
    // Isso é possivel pois o grago é um DAG
    bellmanford(graph, 0, &pred);
    // Nega o grafo novamente para voltar ao normal
    negateGraph(&graph);
    // Acha a energia minima para o caminho mais "longo"
    lowestEnergy(graph, pred, nrows, ncols);    
}


int lowestEnergy(Graph graph, int *pred, int nrows, int ncols){
    int beginE = 1; // energia minima de comeco
    int currE = 1;
    int count;
    int path[(nrows+ncols-1)]; // Caminho do primeiro vertice ao ultimo


    // Ordena o caminho para começar da primeira casa no grid

    // Vertice de destino que é sempre o ultimo
    int v = graph.nvertices - 1;
    
    count = (nrows+ncols-2);

    while (v != 0) {
        path[count] = v;
        count--;
        v = pred[v];
    }

    path[0] = 0;


    // Acha a energia minima
    for( int i = 1; i < (nrows+ncols-1); i++){
        int vertex = path[i];

        if(currE + graph.vertices[vertex].value >= 1){
            currE += graph.vertices[vertex].value;
        }else{
            beginE += abs(currE + graph.vertices[vertex].value - 1);
            currE = 1;
        }

    }

    
    return beginE;

}