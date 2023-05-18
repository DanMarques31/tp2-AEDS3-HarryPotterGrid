#include <stdio.h>
#include <stdlib.h>
#include "algGuloso.h"

void guloso(int R, int C, int **grid) {

    int *aux_pos = (int *)malloc(R * C * sizeof(int));
    int *aux_neg = (int *)malloc(R * C * sizeof(int));
    int posCont = 0, negCont = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] > 0) {
                aux_pos[posCont++] = grid[i][j];
            } else if (grid[i][j] < 0) {
                aux_neg[negCont++] = grid[i][j];
            }
        }
    }

    int soma_pos = 0, soma_neg = 0;
    for (int i = 0; i < posCont; i++) {
        soma_pos += aux_pos[i];
    }

    for (int i = 0; i < negCont; i++) {
        soma_neg += aux_neg[i];
    }

    int result = soma_pos - soma_neg + 1;

    printf("%d\n", result);

    free(aux_pos);
    free(aux_neg);

}
