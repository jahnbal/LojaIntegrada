#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"



void tela_cadastro_clientes(int *ptr_opcao)
{
    limpar_tela();

    printf("\nExecutando: Cadastro de Clientes\n");
    printf("1. Incluir Cliente\n");
    printf("2. Excluir Cliente\n");
    printf("3. Alterar Cliente\n");
    printf("4. Mostrar Cadastro de Clienes\n");
    printf("5. Retornar\n");
    printf("\nDigite sua opcao: ");

    //Tenta ler a opcao. Em caso de falha, define 0 e limpa o buffer.
    if (scanf("%d", ptr_opcao) != 1) {
        *ptr_opcao = 0;
        limpar_buffer_teclado();
    }
}
