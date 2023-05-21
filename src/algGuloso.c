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

    //Percorre toda matriz.
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            //Atualiza o valor de energia a cada posicao grid(i,j).
            energia += grid[i][j];

            //Se a energia acumulada não for suficiente, atualiza ela com 1 e atualiza a energia mínima.
            if (energia <= 0) {
                //Retorna o maior valor entre minEnerg e o valor de energia + 1. (abs() retorna o valor do número sem seu sinal).
                minEnerg = maxValor(minEnerg, abs(energia) + 1);
                energia = 1;
            }
        }
    }

    //Impressão e retorno do resultado.
    printf("%d\n", minEnerg);
    return minEnerg;
}