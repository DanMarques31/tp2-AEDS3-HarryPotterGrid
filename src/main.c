#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "grid.h"
#include "algDinamica.h"
#include "algGuloso.h"

int main(int argc, char *argv[]) {
    
    if (argc < 3) {
        printf("Erro: número incorreto de argumentos fornecidos.\n");
        return 1;
    }

    abre_arquivo(argv[2]);

    int qtd_casos = scan_arquivo(entrada);
    int linhas, colunas, **grid, **gridPD;

    for (int i = 0; i < qtd_casos; i++) {
        linhas = scan_arquivo(entrada);
        colunas = scan_arquivo(entrada);

        // Algoritmo de Programação Dinâmica
        if (atoi(argv[1]) == 1) {
            

            // Aloca o grid dinamicamente
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                grid[i] = (int *)malloc(colunas * sizeof(int));
            }

            // Alocação matriz pd (Programação Dinâmica)
            gridPD = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                gridPD[i] = (int *)malloc(colunas * sizeof(int));
            }

            monta_grid(entrada, linhas, colunas, grid);
            monta_gridPD(linhas, colunas, gridPD);
            dinamica(linhas, colunas, gridPD, grid);
            
            // Libera a memória do grid
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
                free(gridPD[i]);
            }
            free(grid);
            free(gridPD);
        } 
        
        // Algoritmo Guloso
        else if (atoi(argv[1]) == 2) {
            

            // Aloca o grid dinamicamente
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                grid[i] = (int *)malloc(colunas * sizeof(int));
            }

            monta_grid(entrada, linhas, colunas, grid);
            guloso(linhas, colunas, grid);

            // Libera a memória do grid
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
            }
            free(grid);
        }
    }
    
    fecha_arquivo();
    return 0;
}
