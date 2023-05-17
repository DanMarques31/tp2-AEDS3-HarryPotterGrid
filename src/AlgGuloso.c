#include <stdio.h>
#include "AlgGuloso.h"

void monta_matriz(FILE* entrada, int qtd_casos, int R, int C, int **matriz) {
    for (int casos_teste = 0; casos_teste < qtd_casos; casos_teste++) {
        fscanf(entrada, "%d %d", &R, &C);

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                fscanf(entrada, "%d", &matriz[i][j]);
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

/*void alg_guloso (int qtd_casos, int R, int C, int pos_aux, int neg_aux) {


    
}*/