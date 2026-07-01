#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"




void tela_cadastro_produtos(int *ptr_opcao)
{
    limpar_tela();

    printf("\nExecutando: Cadastro de Produtos\n");
    printf("1. Cadastrar Produto\n");
    printf("2. Excluir Produto\n");
    printf("3. Alterar Produto\n");
    printf("4. Mostrar Cadastro de Produtos\n");
    printf("5. Retornar\n");
    printf("\nDigite sua opcao: ");

    //Tenta ler a opcao. Em caso de falha, define 0 e limpa o buffer.
    if (scanf("%d", ptr_opcao) != 1) {
        *ptr_opcao = 0;
        limpar_buffer_teclado();
    }
}