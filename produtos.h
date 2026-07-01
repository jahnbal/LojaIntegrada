#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include "estruturas.h"

extern Produto produtos[MAX_PRODUTOS];
extern int quantidadeProdutos;

void cadastrarProduto();
void listarProduto();
void alterarProduto();
void excluirProduto();
void menuCadastroProdutos(); 
int buscarProdutoPorCodigo(int codigo_procurado);

#endif // PRODUTOS_H_INCLUDED