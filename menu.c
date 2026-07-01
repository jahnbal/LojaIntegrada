#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"

void exibir_menu(int *ptr_opcao)
{
    printf("\n===========================================================\n");
    printf("                   * Sistema de Vendas *");
    printf("\n===========================================================\n");
    printf("1. Cadastro de Produtos\n");
    printf("2. Cadastro de Clientes\n");
    printf("3. Venda\n");
    printf("4. Sair do sistema\n");
    printf("\nDigite sua opcao: ");

    // Tenta ler a opcao. Em caso de falha, define 0 e limpa o buffer.
    if (scanf("%d", ptr_opcao) != 1) {
        *ptr_opcao = 0;
        limpar_buffer_teclado();
    }
}
