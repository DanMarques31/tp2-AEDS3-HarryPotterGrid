#include <stdio.h>
#include "grid.h"
#define INF 1000000000

void monta_grid(FILE* entrada, int R, int C, int **grid) {
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fscanf(entrada, "%d", &grid[i][j]);
        }
    }
}

void monta_gridPD(int R, int C, int **pd) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            pd[i][j] = INF;
        }
    }

}

//função utilizada só para verificar a leitura dos dados.
void imprime_grid(int R, int C, int **grid) {
    for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                printf("%d ", grid[j][k]);
            }
            printf("\n");
        }
}

