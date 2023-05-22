#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomInput(int qtd_casos) {
    srand(time(NULL));
    
    FILE* entrada = fopen("input.txt", "w");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    fprintf(entrada, "%d\n", qtd_casos);

    for (int i = 0; i < qtd_casos; i++) {
        int linhas = rand() % 901 + 100; // Valores entre 100 e 1000
        int colunas = rand() % 901 + 100;

        fprintf(entrada, "%d %d\n", linhas, colunas);

        for (int j = 0; j < linhas; j++) {
            for (int k = 0; k < colunas; k++) {
                int valor;
                if (j == 0 && k == 0) {
                    valor = 0;
                } else if (j == linhas - 1 && k == colunas - 1) {
                    valor = 0;
                } else {
                    valor = rand() % 11001 - 1000; // Valores entre -1000 e 1000
                }
                fprintf(entrada, "%d ", valor);
            }
            fprintf(entrada, "\n");
        }
    }

    fclose(entrada);
}


int main() {

    int qtd_casos = 500; //Quantidade de casos de teste
    generateRandomInput(qtd_casos);

    return 0;
}
