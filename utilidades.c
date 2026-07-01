#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

//Controle de Tela

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpar_buffer_teclado() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void mensagem_espera_enter() {
    printf("\nPressione ENTER para continuar...");
    char c = getchar();
    if (c != '\n') {
        limpar_buffer_teclado();
    }
}

//Entradas de Dados Seguras

void ler_string(char *buffer, int tamanho) {
    fflush(stdin); 
    if (fgets(buffer, tamanho, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    } else {
        limpar_buffer_teclado();
    }
}

int ler_inteiro() {
    int valor;
    int retorno;
    do {
        retorno = scanf("%d", &valor);
        limpar_buffer_teclado();
        if (retorno == 0) {
            printf("Entrada invalida! Digite apenas numeros inteiros: ");
        }
    } while (retorno == 0);
    return valor;
}

float ler_float_positivo() {
    float valor;
    int retorno;
    do {
        retorno = scanf("%f", &valor);
        limpar_buffer_teclado();
        if (retorno == 0 || valor < 0) {
            printf("Entrada invalida! Digite um valor positivo: ");
        }
    } while (retorno == 0 || valor < 0);
    return valor;
}