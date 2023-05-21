#include <stdio.h>
#include <stdlib.h>
#include "algDinamica.h"

int dinamica(int R, int C,int **pd, int **grid) {

    //Caso base, posição final da matriz.
    pd[R-1][C-1] = 1;

    //Preenche pd de cima pra baixo.
    //Linhas e colunas começando das últimas, decrementado ate a primeira.
    for (int i = R-1; i >= 0; i--) {
        for (int j = C-1; j >= 0; j--) {

            //Verifica a posição atual. Se não é a posicao final ele pula para a próxima iteração com o comando continue.
            if (i == R-1 && j == C-1){
                continue;  
            }

            //Escolha do caminho de menor energia partindo da posicao inicial.
            int energMin = INF; //Inicializa energMin com valor suficientemente grande.

            //Atualizacao de energMin com o mínimo entre as posicões abaixo e a direita.
            if (i+1 < R) {
                //Posicao abaixo.
                energMin = pd[i+1][j];
            }

            if (j+1 < C) {
                if (energMin < pd[i][j+1]) {
                //Não faz nada. Mantem o valor atual de energMin.
                } 
                
                else {
                    //Posicao a direita.
                    energMin = pd[i][j+1];
                }
            }
            //Atualização matriz pd.
            if (energMin - grid[i][j] > 0) {
                pd[i][j] = energMin - grid[i][j];
            } 
            //Caso energMin for menor que 0, retorna 1 de energia.
            else {
                pd[i][j] = 1;
            }
        }
    }
    //energMin é exibida em pd[0,0].
    int result = pd[0][0];

    //Impressão e retorno do resultado.
    printf("%d\n", result);
    return result;
}

