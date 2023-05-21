#include <stdio.h>
#include "grid.h"
#define INF 1000000000

//Faz o preenchimento do grid com os dados do arquivo de entrada.
void monta_grid(FILE* entrada, int R, int C, int **grid) {
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fscanf(entrada, "%d", &grid[i][j]);
        }
    }
}

//Faz o preenchimento da matriz de programação dinâmica com os dados do arquivo de entrada.
void monta_gridPD(int R, int C, int **pd) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            pd[i][j] = INF;
        }
    }

}

//Função utilizada só para verificar visualmente a leitura dos dados.
void imprime_grid(int R, int C, int **grid) {

    for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
            printf("%d ", grid[j][k]);
        }
        
        printf("\n");
    }
}

