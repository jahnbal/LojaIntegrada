#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "utilidades.h"
#include "estruturas.h"
#include "menu.h"
#include "menuProdutos.h"

//Retorna o índice do vetor se achar, ou -1 se não achar
int buscarProdutoPorCodigo(int codigo_procurado) {
    for (int i = 0; i < quantidadeProdutos; i++) {
        //Verifica se o produto está ativo antes de retornar
        if (produtos[i].ativo == 1 && produtos[i].codigo == codigo_procurado) {
            return i;
        }
    }
    return -1;
}

void cadastrarProduto() {
    int codigo;
    if (quantidadeProdutos >= MAX_PRODUTOS) {
        printf("ERRO: Limite de armazenamento de produtos atingido.\n");
        mensagem_espera_enter();
        return;
    }
    limpar_tela();
    printf("\nCADASTRAR PRODUTO\n");

    //Loop para garantir código único
    do {
        printf("Digite o codigo do produto: ");
        codigo = ler_inteiro(); //Nao permite letras

        if (buscarProdutoPorCodigo(codigo) != -1) {
            printf("ERRO: Esse codigo ja existe! Tente outro.\n");
        } else {
            break;
        }
    } while (1);

    produtos[quantidadeProdutos].codigo = codigo; //Grava o codigo

    printf("Descricao do produto: ");
    ler_string(produtos[quantidadeProdutos].descricao, TAM_DESCRICAO);

    printf("Preco do produto (R$): ");
    produtos[quantidadeProdutos].preco = ler_float_positivo(); 
    produtos[quantidadeProdutos].ativo = 1; //Define como ativo
    quantidadeProdutos++;
    
    printf("\nProduto cadastrado com sucesso!");
    mensagem_espera_enter();
}

void listarProduto() {
    limpar_tela();
    printf("\nLISTA DE PRODUTOS\n");
    //Verifica se tem produtos (considera se há excluidos)
    int tem_produto = 0;
    for(int i =0 ; i < quantidadeProdutos; i++) {
        if(produtos[i].ativo == 1) {
            tem_produto = 1;
        }
    }
    if (tem_produto == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("%-10s | %-30s | %s\n", "CODIGO", "DESCRICAO", "PRECO");
        printf("----------------------------------------------------------\n");
        
        for (int i = 0; i < quantidadeProdutos; i++) {
            if (produtos[i].ativo == 1) { //Só mostra os ativos
                printf("%-10d | %-30s | RS %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].preco);
            }
        }
    }
    limpar_buffer_teclado();
    mensagem_espera_enter();
}

void alterarProduto() {
    int codigo, indice;

    limpar_tela();
    printf("\nALTERAR PRODUTO\n");
    printf("Digite o codigo do produto a ser alterado: ");
    codigo = ler_inteiro();

    indice = buscarProdutoPorCodigo(codigo);

    if (indice != -1) {
        printf("Produto encontrado: %s (R$ %.2f)\n", produtos[indice].descricao, produtos[indice].preco);
        
        printf("\nNova descricao (Deixe em branco para manter a atual): ");
        char novaDescricao[TAM_DESCRICAO];
        ler_string(novaDescricao, TAM_DESCRICAO);
        
        if (strlen(novaDescricao) > 0) {
            strcpy(produtos[indice].descricao, novaDescricao);
        }

        printf("Novo preco (Digite 0 para manter o atual R$ %.2f): ", produtos[indice].preco);
        float novoPreco = ler_float_positivo();
        
        if (novoPreco > 0) {
            produtos[indice].preco = novoPreco;
        }

        printf("\nProduto atualizado com sucesso!\n");
    } else {
        printf("ERRO: Produto nao encontrado.\n");
    }
    mensagem_espera_enter();
}

void excluirProduto() {
    int codigo, indice;
    char confirmacao;

    limpar_tela();
    printf("\nEXCLUIR PRODUTO\n");
    printf("Digite o codigo do produto a ser excluido: ");
    codigo = ler_inteiro();

    indice = buscarProdutoPorCodigo(codigo);

    //Confirmacao do usuario
    if (indice != -1) {
        printf("Produto: %s (R$ %.2f)\n", produtos[indice].descricao, produtos[indice].preco);
        printf("Esta operação não poderá ser desfeita. Confirma (s/n): ");
        scanf(" %c", &confirmacao);
        limpar_buffer_teclado();

        if (confirmacao == 'S' || confirmacao == 's') {
            produtos[indice].ativo = 0; //Exclusão
            printf("\nProduto excluido com sucesso\n");
        } else {
            printf("Operacao cancelada.\n");
        }
    } else {
        printf("ERRO: Produto nao encontrado.\n");
    }
    mensagem_espera_enter();
}

void menuCadastroProdutos() {
    int opcao;
    do {
        tela_cadastro_produtos(&opcao);
        
        switch (opcao) {
            case 1:
            cadastrarProduto(); 
            break;

            case 2: 
            excluirProduto(); 
            break;

            case 3: 
            alterarProduto(); 
            break;

            case 4: 
            listarProduto();
            break;

            case 5: 
            break;

            default: 
                printf("Opcao invalida!\n");
                mensagem_espera_enter();
        }
    } while (opcao != 5);
}