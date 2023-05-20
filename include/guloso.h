#ifndef GULOSO_H
#define GULOSO_H

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int energia_harry (int* caminho, int indice_caminho);
int guloso (Graph *graph, int nrows, int ncols);

#endif