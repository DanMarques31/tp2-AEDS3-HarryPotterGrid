#include <stdio.h>
#include "file.h"

FILE* entrada, *saida;

//Função para abertura do arquivo de entrada para leitura, e de saída para escrita.
void abre_arquivo(char argv[]) {
    entrada = fopen(argv, "r");
    saida = fopen("saida.txt", "w");

    //Se o arquivo estiver vazio retorna erro.
    if (entrada == NULL) {
        printf("Falha na abertura do arquivo.\n");
    }
}

//Simplesmente escreve no arquivo de saída, a utilizamos para impressão dos resultados em um arquivo texto de saída.
void escreve_arquivo(FILE* saida, int resultado) {
    fprintf(saida, "%d\n", resultado);
}

//Função para o fechamento dos arquivos.
void fecha_arquivo() {
    fclose(entrada);
    fclose(saida);
}

//Função para a leitura do arquivo.
int scan_arquivo(FILE* entrada) {
    int x;
    fscanf(entrada, "%d", &x);
    return x;
}