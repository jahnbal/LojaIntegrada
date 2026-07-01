#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "estruturas.h"

extern Cliente clientes[MAX_CLIENTES];
extern int quantidadeClientes;

int buscarClientePorCodigo(int codigoProcurado);
void cadastrarCliente();
void listarClientes();
void alterarCliente();
void excluirCliente();
void menuCadastroClientes();

#endif // CLIENTES_H_INCLUDED