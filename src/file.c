#include <stdio.h>
#include "file.h"

FILE* entrada, *saida;

//Função para abertura do arquivo.
void abre_arquivo(char argv[]) {
    entrada = fopen(argv, "r");
    saida = fopen("resultado.txt", "w");


    if (entrada == NULL) {
        printf("Falha na abertura do arquivo.\n");
    }
}

void escreve_arquivo(FILE* saida, int resultado) {
    fprintf(saida, "%d\n", resultado);
}

//Função para o fechamento do arquivo.
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