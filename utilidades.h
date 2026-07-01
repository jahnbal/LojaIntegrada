#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

//Controle de Tela
void limpar_tela();
void limpar_buffer_teclado();
void mensagem_espera_enter();

//Entradas de Dados Seguras
void ler_string(char *buffer, int tamanho);
int ler_inteiro();
float ler_float_positivo();

#endif // UTILIDADES_H_INCLUDED