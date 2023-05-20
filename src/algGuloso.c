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

void guloso(int R, int C, int **grid) {

    //Energia minima.
    int minEnerg = 1;

    //Energia acomulada.
    int energia = 1;

    //Percorre toda matriz.
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            //Atualiza o valor de energia a cada posicao grid(i,j).
            energia += grid[i][j];

            //Se a energia acomulada não for suficiente, atualiza ela com 1 e atualiza a energia minima.
            if (energia <= 0) {
                minEnerg = maxValor(minEnerg, abs(energia) + 1);
                energia = 1;
            }
        }
    }

    printf("%d\n", minEnerg); 
}