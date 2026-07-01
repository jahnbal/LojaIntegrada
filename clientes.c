#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "utilidades.h"
#include "estruturas.h"
#include "menu.h"
#include "menuClientes.h"

//Retorna o índice do vetor se achar, ou -1 se não achar
int buscarClientePorCodigo(int codigoProcurado) {
    for (int i = 0; i < quantidadeClientes; i++) {
        //Verifica se o produto está ativo antes de retornar
        if (clientes[i].ativo == 1 && clientes[i].codigo == codigoProcurado) {
            return i;
        }
    }
    return -1;
}

void cadastrarCliente() {
    int codigo;
    if (quantidadeClientes >= MAX_CLIENTES) {
        printf("ERRO: Limite de clientes atingido.\n");
        mensagem_espera_enter();
        return;
    }
    limpar_tela();
    printf("\nCADASTRAR CLIENTE\n");

    //Loop para garantir código único
    do {
        printf("Digite o codigo do cliente: ");
        codigo = ler_inteiro(); //Nao permite letras
        if (buscarClientePorCodigo(codigo) != -1) {
            printf("ERRO: Esse codigo ja existe! Tente outro.\n");
        } else {
            break;
        }
    } while (1);

    clientes[quantidadeClientes].codigo = codigo; //Grava o codigo

    printf("Nome: ");
    ler_string(clientes[quantidadeClientes].nome, TAM_NOME);
    clientes[quantidadeClientes].ativo = 1; //Define como ativo
    quantidadeClientes++;
    printf("\nCliente cadastrado com sucesso!");
    mensagem_espera_enter();
}

void listarClientes() {
    limpar_tela();
    printf("\nLISTA DE CLIENTES\n");
    //Verifica se tem produtos (considera se há excluidos)
    int tem_cliente = 0;
    for(int i=0; i<quantidadeClientes; i++) {
        if(clientes[i].ativo) {
            tem_cliente=1;
        }
    }

    if (tem_cliente == 0) {
        printf("Nenhum cliente cadastrado.\n");
    } else {
        printf("%-10s | %-30s\n", "CODIGO", "NOME");
        printf("--------------------------------------------\n");
        for (int i = 0; i < quantidadeClientes; i++) {
            if (clientes[i].ativo == 1) { //Só mostra os ativos
                printf("%-10d | %-30s\n", clientes[i].codigo, clientes[i].nome);
            }
        }
    }
    limpar_buffer_teclado();
    mensagem_espera_enter();
}

void alterarCliente() {
    int codigo, indice;

    limpar_tela();
    printf("\nALTERAR CLIENTE\n");
    printf("Digite o codigo do cliente a ser alterado: ");
    codigo = ler_inteiro();

    indice = buscarClientePorCodigo(codigo);

    if (indice != -1) {
        printf("Cliente encontrado: %s\n", clientes[indice].nome);
        
        printf("\nNovo nome (Deixe em branco para manter o atual): ");
        char novoNome[TAM_NOME];
        ler_string(novoNome, TAM_NOME);
        
        if (strlen(novoNome) > 0) {
            strcpy(clientes[indice].nome, novoNome);
        }
        printf("\nCliente atualizado com sucesso!\n");
    } else {
        printf("ERRO: Cliente nao encontrado.\n");
    }
    mensagem_espera_enter();
}

void excluirCliente() {
    int codigo, indice;
    char confirmacao;

    limpar_tela();
    printf("\nEXCLUIR CLIENTE\n");
    printf("Digite o codigo do cliente a ser excluido: ");
    codigo = ler_inteiro();

    indice = buscarClientePorCodigo(codigo);

    //Confirmacao do usuario
    if (indice != -1) {
        printf("Cliente: %s\n", clientes[indice].nome);
        printf("Esta operacao nao podera ser desfeita. Confirma (s/n>): ");
        scanf(" %c", &confirmacao);
        limpar_buffer_teclado();

        if (confirmacao == 'S' || confirmacao == 's') {
            clientes[indice].ativo = 0; //Exclusao
            printf("\nCliente excluido com sucesso\n");
        } else {
            printf("Operacao cancelada.\n");
        }
    } else {
        printf("ERRO: Cliente nao encontrado.\n");
    }
    mensagem_espera_enter();
}

void menuCadastroClientes() {
    int opcao;
    do {
        tela_cadastro_clientes(&opcao);

        switch (opcao) {
            case 1: 
                cadastrarCliente(); 
                break;

            case 2:
                excluirCliente();
                break; 

            case 3:
                alterarCliente();
                break;

            case 4:
                listarClientes(); 
                break;

            case 5:
                break;

            default: 
                printf("Opcao invalida.\n");
                mensagem_espera_enter();
                break;
        }
    } while (opcao != 5);
}