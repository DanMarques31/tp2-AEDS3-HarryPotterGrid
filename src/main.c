#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "file.h"
#include "grid.h"
#include "algDinamica.h"
#include "algGuloso.h"

int main(int argc, char *argv[]) {
    
    //Cria as structs para o uso das funções 'gettimeofday' e 'getrusage' respectivamente.
    struct timeval start, end;
    struct rusage usage;

    //Inicio da função 'gettimeofday'.
    gettimeofday(&start, NULL);

    //Caso n° de argumentos no terminal seja < 3 significa que não foi passado nenhum arquivo.
    if (argc < 3) {
        printf("Erro: Não foi fornecido um arquivo de texto.\n");
        return 1;
    }

    //Abre o arquivo, lê o "T" que representa a quantidade de casos e instância as variáveis.
    abre_arquivo(argv[2]);

    int qtd_casos = scan_arquivo(entrada);
    int linhas, colunas, **grid, **gridPD;

    //Lê o número de linhas e colunas da próxima matriz.
    for (int i = 0; i < qtd_casos; i++) {
        linhas = scan_arquivo(entrada);
        colunas = scan_arquivo(entrada);

        //Executa o 2° argumento, o algoritmo de Programação Dinâmica.
        if (atoi(argv[1]) == 1) {
            
            //Aloca o grid dinâmicamente.
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                grid[i] = (int *)malloc(colunas * sizeof(int));
            }

            //Alocação matriz pd (Programação Dinâmica).
            gridPD = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                gridPD[i] = (int *)malloc(colunas * sizeof(int));
            }

            //Chamada das funções que preenchem as matrizes.
            monta_grid(entrada, linhas, colunas, grid);
            monta_gridPD(linhas, colunas, gridPD);

            //Chamada da função que executa a solução de programação dinâmica.
            dinamica(linhas, colunas, gridPD, grid);
            
            //Libera a memória do grid.
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
                free(gridPD[i]);
            }
            free(grid);
            free(gridPD);
        } 
        
        //Executa o 3° argumento, o algoritmo Guloso.
        else if (atoi(argv[1]) == 2) {
            
            //Aloca o grid dinâmicamente.
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                grid[i] = (int *)malloc(colunas * sizeof(int));
            }

            //Chamada da função que preenche o grid.
            monta_grid(entrada, linhas, colunas, grid);

            //Chamada da função que executa a solução Gulosa.
            guloso(linhas, colunas, grid);

            //Libera a memória do grid
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
            }
            free(grid);
        }
    }
    
    //Fim da função 'gettimeofday' e uso da função 'getrusage'.

    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    //Impressão dos tempos de execução.

    printf("Tempo de execução: %ld microsegundos\n", (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec)));
    printf("Tempo de usuário: %ld microsegundos\n", usage.ru_utime.tv_usec);
    printf("Tempo de sistema: %ld microsegundos\n", usage.ru_stime.tv_usec);

    fecha_arquivo();
    return 0;
}
