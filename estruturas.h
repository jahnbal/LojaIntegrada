#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define MAX_CLIENTES 100      //Tamanho máximo do vetor de clientes
#define MAX_PRODUTOS 100      //Tamanho máximo do vetor de produtos
#define TAM_NOME 50           //Tamanho máximo de caracteres para nome do cliente
#define TAM_DESCRICAO 100     //Tamanho máximo para descrição do produto

typedef struct {
    int codigo;
    char descricao[TAM_DESCRICAO];
    float preco;
    int ativo; //1 para ativo e 0 para excluído
} Produto;

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    int ativo; //1 para ativo e 0 para excluído
} Cliente;

#endif // ESTRUTURAS_H_INCLUDED