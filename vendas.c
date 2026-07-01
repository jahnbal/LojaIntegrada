#include <stdio.h>
#include <stdlib.h> 
#include "vendas.h"
#include "estruturas.h"
#include "utilidades.h"

extern Produto produtos[];
extern int quantidadeProdutos;
extern Cliente clientes[];
extern int quantidadeClientes;

void cabecalho_venda()
{
    limpar_tela();
    printf("===========================================================\n");
    printf("*                     Venda de Produtos                   *\n");
    printf("===========================================================\n\n");
}

void cabecalho_nota_fiscal()
{
    limpar_tela();
    printf("===========================================================\n");
    printf("*                      Dados da Venda                     *\n");
    printf("===========================================================\n\n");
}

void realizarVenda() 
{
    cabecalho_venda();
    printf("Iniciando nova venda...\n\n");

    //Verificações Iniciais: Existência de Produtos e Clientes
    if (quantidadeProdutos == 0) {
        printf("Sem produtos cadastrados.\n");
        
    }
    
    if (quantidadeClientes == 0) {
        printf("Sem clientes cadastrados.\n");
        
    }

    if (quantidadeProdutos == 0 || quantidadeClientes == 0) {
        mensagem_espera_enter();

    }

    printf("%-10s | %-30s\n", "CODIGO", "NOME");
        printf("--------------------------------------------\n");
        for (int i = 0; i < quantidadeClientes; i++) {
            if (clientes[i].ativo == 1) { //Só mostra os ativos
                printf("%-10d | %-30s\n", clientes[i].codigo, clientes[i].nome);
            }
        }
    printf("\n");
        

    int codcliente, pos_cliente = -1;
    //Loop para garantir cliente válido
    while(pos_cliente == -1) {
        printf("Codigo do Cliente (ou -1 para sair): ");
        codcliente = ler_inteiro();

        if (codcliente == -1) {
            printf("Venda cancelada.\n");
            return;
        }
        for (int i = 0; i < quantidadeClientes; i++) {
            if (clientes[i].codigo == codcliente && clientes[i].ativo == 1) {
                pos_cliente = i;
                break;
            }
        }
        if (pos_cliente == -1) {
            printf("ERRO: Cliente nao encontrado! Tente novamente.\n");
        }
    }

    cabecalho_venda();
    printf("Codigo do cliente: %d - %s\n\n", codcliente, clientes[pos_cliente].nome);
    printf("Produtos\n");
    printf("========\n");

    //Carrinho de Compras - Vetores Temporários
    int carrinho_codigos[50];     
    int carrinho_quantidades[50]; 
    int itens_carrinho = 0;       

    printf("%-10s | %-30s | %s\n", "CODIGO", "DESCRICAO", "PRECO");
        printf("----------------------------------------------------------\n");
        
        for (int i = 0; i < quantidadeProdutos; i++) {
            if (produtos[i].ativo == 1) { //Só mostra os ativos
                printf("%-10d | %-30s | RS %.2f\n", produtos[i].codigo, produtos[i].descricao, produtos[i].preco);
            }
        }
    printf("\n");

    while (1) {
        int cod, qtd;
        int pos_prod = -1; //Inicializa como não encontrado

        printf("\nCodigo do Produto %d (digite -1 para finalizar): ", itens_carrinho + 1);
        cod = ler_inteiro();

        //Condição de saída
        if (cod == -1) {
            if(itens_carrinho == 0) {
                printf("Venda cancelada (carrinho vazio).\n");
                mensagem_espera_enter();
                return; //Sai da funcao quando nao ha itens
            }
            break; 
        }

        //Busca o produto e muda pos_prod se achar
        for (int i = 0; i < quantidadeProdutos; i++) {
            if (produtos[i].codigo == cod && produtos[i].ativo == 1) {
                pos_prod = i;
                break;
            }
        }

        if (pos_prod == -1) {
            printf("Produto nao encontrado!\n");
        } else {
            printf("Produto: %s\n", produtos[pos_prod].descricao);
            
            printf("Quantidade: ");
            qtd = ler_inteiro();
            //Validacao de quantidade
            if (qtd > 0) {
                carrinho_codigos[itens_carrinho] = cod;
                carrinho_quantidades[itens_carrinho] = qtd;
                itens_carrinho++;
                printf("Item adicionado.\n");
            } else {
                printf("Quantidade invalida.\n");
            }
        }
    }

    cabecalho_nota_fiscal();
    printf("Cliente: %d - %s\n\n", clientes[pos_cliente].codigo, clientes[pos_cliente].nome);
    printf("Produtos Adquiridos\n\n");
    //Cabecalho da tabela
    printf("%-8s %-25s %-15s %-12s %-15s\n", "Codigo", "Descricao", "Preco Unit", "Quantidade", "Total Item");

    float total_compra = 0.0;
    //Loop para mostrar itens e calcular total
    for (int i = 0; i < itens_carrinho; i++) {
        int cod_atual = carrinho_codigos[i];
        int qtd_atual = carrinho_quantidades[i];
        
        //Busca o produto pelo código
        int posicao_produto = -1;
        for(int j = 0; j < quantidadeProdutos; j++) {
            if(produtos[j].codigo == cod_atual) {
                posicao_produto = j;
                break;
            }
        }
        //Se encontrou, calcula e imprime
        if(posicao_produto != -1) {
            float total_item = produtos[posicao_produto].preco * qtd_atual;
            total_compra += total_item;
            printf("%-8d %-25s RS %-12.2f %-12d RS %-12.2f\n", produtos[posicao_produto].codigo, produtos[posicao_produto].descricao, produtos[posicao_produto].preco, qtd_atual, total_item);
        }
    }
    //Pagamento e Troco
    printf("\nTotal da Compra: RS %.2f\n\n", total_compra);
    float valor_pago, troco;
    do {
        printf("Valor Pago: RS ");
        valor_pago = ler_float_positivo();

        if (valor_pago < total_compra) {
            printf("Valor insuficiente! Faltam RS %.2f\n", total_compra - valor_pago);
        }
    } while (valor_pago < total_compra);
    troco = valor_pago - total_compra;
    printf("\nTroco: RS %.2f\n", troco);
    printf("\n\nVenda finalizada com sucesso!\n");
    mensagem_espera_enter();
}