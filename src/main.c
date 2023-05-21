#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "file.h"
#include "grid.h"
#include "algDinamica.h"
#include "algGuloso.h"

int main(int argc, char *argv[]) {
    
    //Cria a struct e a variável para o uso da função 'getrusage' .
    struct rusage usage;
    double user_time, system_time;

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

        //Executa a 2ª estratégia, o algoritmo de Programação Dinâmica.
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
            int result = dinamica(linhas, colunas, gridPD, grid);

            //Imprime em um arquivo o resultado.
            escreve_arquivo(saida, result);
            
            //Libera a memória do grid.
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
                free(gridPD[i]);
            }
            free(grid);
            free(gridPD);
        } 
        
        //Executa a 2ª estratégia, o algoritmo Guloso.
        else if (atoi(argv[1]) == 2) {
            
            //Aloca o grid dinâmicamente.
            grid = (int **)malloc(linhas * sizeof(int *));
            for (int i = 0; i < linhas; i++) {
                grid[i] = (int *)malloc(colunas * sizeof(int));
            }

            //Chamada da função que preenche o grid.
            monta_grid(entrada, linhas, colunas, grid);

            //Chamada da função que executa a solução Gulosa.
            int result = guloso(linhas, colunas, grid);
            
            //Imprime em um arquivo texto o resultado.
            escreve_arquivo(saida, result);

            //Libera a memória do grid.
            for (int i = 0; i < linhas; i++) {
                free(grid[i]);
            }
            free(grid);
        }
    }
    
    //Uso da função 'getrusage'.

    getrusage(RUSAGE_SELF, &usage);

    //Conversão dos tempos para segundos.
    user_time = (double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0;
    system_time = (double) usage.ru_stime.tv_sec + (double) usage.ru_stime.tv_usec / 1000000.0;
    
    //Impressão dos tempos de execução.
    printf("Tempo de usuário: %f segundos\n", user_time);
    printf("Tempo de sistema: %f segundos\n", system_time);

    fecha_arquivo();
    return 0;
}
