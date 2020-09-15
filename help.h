//arquivo onde serão declaradas as bibliotecas e protótipos de função
#include <stdio.h>

typedef struct {
char nome[80];
int idade;
char sexo;
char cpf[14];
}cliente ;

char busca_cliente(char *cpf);
