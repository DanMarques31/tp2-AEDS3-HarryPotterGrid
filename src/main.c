#include <stdlib.h>
#include "file.h"
#include "AlgGuloso.h"

int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Erro: nenhum arquivo de entrada fornecido.\n");
        return 1;
    }

    abre_arquivo(argv[1]);

    int qtd_casos = scan_arquivo();
    int linhas, colunas, **matriz;
    entrada = fopen(argv[1], "r");
        
        if (entrada == NULL) {
            printf("Falha na abertura do arquivo.\n");
            return 1;
        }

        for (int i = 0; i < qtd_casos; i++) {
            linhas = scan_arquivo();
            colunas = scan_arquivo();

            // Aloca a matriz dinamicamente
            matriz = (int **)malloc(linhas * sizeof(int *));
            for (int j = 0; j < linhas; j++) {
                matriz[j] = (int *)malloc(colunas * sizeof(int));
            }

            monta_matriz(entrada, linhas, colunas, matriz);

            // Libera a memória da matriz
            for (int j = 0; j < linhas; j++) {
                free(matriz[j]);
            }
            free(matriz);
        }

        fecha_arquivo();

        return 0;
}