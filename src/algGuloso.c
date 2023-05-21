#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "algGuloso.h"

//Funcao auxiliar para retorno do menor valor.
int minValor(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

//Funcao auxiliar para retorno do maior valor.
int maxValor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int guloso(int R, int C, int **grid) {

    //Energia minima.
    int minEnerg = 1;

    //Energia acomulada.
    int energia = 1;

    // Percorre toda matriz.
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // Atualiza o valor de energia a cada posição grid(i,j).
            energia += grid[i][j];

            // Verifica se a energia acumulada não é suficiente.
            if (energia <= 0) {
                // Atualiza a energia mínima apenas se ela for maior do que a energia atual + 1.
                minEnerg = maxValor(minEnerg, abs(energia) + 1);
            }

            // Atualiza a energia para no mínimo 1.
            energia = maxValor(1, energia);
        }
    }

    //Impressão e retorno do resultado.
    printf("%d\n", minEnerg);
    return minEnerg;
}