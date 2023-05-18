#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "grid.h"

int main(int argc, char *argv[]) {
    
    if(argv[1] = 1) {

        if (argc < 2) {
            printf("Erro: nenhum arquivo de entrada fornecido.\n");
            return 1;
        }

        abre_arquivo(argv[2]);

        int qtd_casos = scan_arquivo(entrada);
        int linhas, colunas, **grid, **gridPD;

        for (int i = 0; i < qtd_casos; i++) {

            linhas = scan_arquivo(entrada);
            colunas = scan_arquivo(entrada);

            // Aloca o grid dinamicamente
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int j = 0; j < linhas; j++) {
                grid[j] = (int *)malloc(colunas * sizeof(int));
            }

            // Alocação matriz pd (Programaçao Dinamica)
            gridPD = (int **)malloc(linhas * sizeof(int *));
            for (int j = 0; j < linhas; j++) {
                gridPD[j] = (int *)malloc(colunas * sizeof(int));
            }

            monta_grid(entrada, linhas, colunas, grid);
            monta_gridPD(linhas, colunas, gridPD);
            dinamica(linhas, colunas, gridPD, grid);

            // Libera a memória do grid
            for (int j = 0; j < linhas; j++) {
                free(grid[j]);
                free(gridPD[j]);
            }
            free(grid);
            free(gridPD);
        }
    }
    
    fecha_arquivo();

    return 0;
}
