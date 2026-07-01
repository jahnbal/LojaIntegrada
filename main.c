#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "utilidades.h"
#include "menu.h"
#include "produtos.h"
#include "clientes.h"
#include "vendas.h"

// --- DEFINIÇÃO DAS VARIÁVEIS GLOBAIS ---
// Elas são declaradas como 'extern' no produtos.h e clientes.h, 
// então precisa criar elas de verdade aqui na main para alocar memória.
Produto produtos[MAX_PRODUTOS];
int quantidadeProdutos = 0;
Cliente clientes[MAX_CLIENTES];
int quantidadeClientes = 0;

int main(void)
{
    int escolha_principal;

    do {
        limpar_tela();
        exibir_menu(&escolha_principal);

        switch (escolha_principal) {
            case 1:
                menuCadastroProdutos();
                break;

            case 2:
                menuCadastroClientes();
                break;

            case 3:
                realizarVenda();
                break;

            case 4:
                printf("\nSaindo do sistema. Ate logo!\n");
                break;

            default:
                break;
        }
    } while (escolha_principal != 4);

    return 0;
}