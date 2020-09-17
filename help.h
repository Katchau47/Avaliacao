//arquivo onde serão declaradas as bibliotecas e protótipos de função
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define NULL 0

typedef struct  {
   char nome[25];
   char sobrenome[25];
   char telefone [15];
   char sexo;
   int idade;
   char cpf[14];
   int ativo;
} cliente ;

FILE *hos;

char menu ();

char busca_cliente(char *cpf);

void cadastra_cliente();

void imprime_cliente(cliente c);

void atualiza_cliente();

void remove_cliente();
