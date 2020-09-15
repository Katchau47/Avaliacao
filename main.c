#include "help.h"

#define NULL 0

int main(){
char opc, cpf[14];
cliente c;
char b;
opc=menu();
do{
    switch (opc)
    {
    case '1':
        printf("\n\ndigite o cpf do cliente\n\n");
        scanf("%s",&cpf);
        b=busca_cliente(cpf);
        if(b==NULL)
            printf("\n\nCliente naum encontrado\n\n");
        else
            printf("\n\nCliente encontrado\n\n");
    break;

    case '2':
        printf("\nChamar funcao cadastro...\n\n");
        cadastra_cliente (c);

    break;

    case '3':
        printf("\nChamar funcao att...\n\n");

    break;

    case '4':
        printf("\nChamar funcao remove...\n\n");

    break;

    case '5':
        printf("\nChamar funcao imprime...\n\n");

    break;

    case '6':
        printf("\nChamar funcao lista...\n\n");

    break;

    case '9':
    break;

    default:
    printf("\nOpcao invalida!\n\n");
    break;
  }
  opc=menu();
}while (opc!='9');
return 0;
}


char menu (){
char op;
printf("// ----- // ----- // CADASTRO HOSPEDE // ----- // ----- // \n\n[1] - Buscar por cadastro \n[2] - Cadastrar novo\n[3] - Atualizar cadastro\n[4] - Remover cadastro\n[5] - Imprimir todos cadastrados\n[6] - Gerar relatorio\n[9] - Finalizar \n-------------------------------\nEntre com a sua opcao: ");
scanf("\n%c",&op);
return (op);
}

char busca_cliente(char cpf){
 cliente comp;
 int i;
if ((hos = fopen("hospede.dat", "r+")) == NULL)
    printf("Nao foi possivel abrir o arquivo!\n");
else {
    while (!feof(hos))
    {
        for (i=0;i < 200; i++)
        {
            fscanf(hos, "%s ", &comp.cpf);
            if (cpf==comp.cpf)
            {
                printf("cliente encontrado");
                return (cpf);
            }

            else
            {
                return NULL;
            }


        };
    };
};
fclose(hos);
}

void cadastra_cliente(cliente c){
printf("Cpf ");
scanf("%s", c.cpf);
int val=busca_cliente(c.cpf);
if (val==0)
{
    printf("Nome: ");
    scanf("%s", c.nome);
    printf("Sobrenome: ");
    scanf("%s", c.sobrenome);
    printf("Telefone: ");
    scanf("%s", c.telefone);
    printf("Sexo: ");
    scanf("%s", c.sexo);
    printf("Idade: ");
    scanf("%d", c.idade);
}
hos = fopen("hospede.dat", "w");
if (hos == NULL) {
puts("Nao foi possivel abrir o arquivo!\n");
exit(1);
}
fprintf(hos, "%d ", c); // escreve o numero no arquivo
 fclose(hos);
}


//int valida_cpf(char cpf, char ccpf){
   // int i;
   // for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
        //assim que uma letra seja diferente
       // if (str1[i] != str2[i]){
            //retorna -1 se a primeira for menor ou 1 caso contrário
           // return str1[i] < str2[i] ? -1 : 1;
       // }
    //}
    //Se as duas acabaram, são iguais e retorna 0. Se a str1 acabou e str2 não
    //retorna um valor negativo. Se str2 acabou e a str1 retorna um valor positivo
    //return str1[i] - str2[i];
//}





