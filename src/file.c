#include <stdio.h>
#include "file.h"

FILE* entrada;

//Função para abertura do arquivo.
void abre_arquivo(char argv[]) {
    entrada = fopen(argv, "r");

    if (entrada == NULL) {
        printf("Falha na abertura do arquivo.\n");
    }
}

//Função para o fechamento do arquivo.
void fecha_arquivo() {
    fclose(entrada);
}

//Função para a leitura do arquivo.
int scan_arquivo(FILE* entrada) {
    int x;
    fscanf(entrada, "%d", &x);
    return x;
}