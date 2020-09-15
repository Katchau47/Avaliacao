int main(){
char op;
do{
  printf("// ----- // ----- // CADASTRO HOSPEDE // ----- // ----- // \n\n[1] - Buscar por cadastro \n[2] - Cadastrar novo\n[3] - Atualizar cadastro\n[4] - Remover cadastro\n[5] - Imprimir todos cadastrados\n[6] - Gerar relatorio\n[9] - Finalizar \n-------------------------------\nEntre com a sua opcao:");
  scanf("%c",&op);
  switch (op)
  {
    case '1':
        printf("\nChamar funcao busca...\n\n");
        scanf("%c",&op);
    break;

    case '2':
        printf("\nChamar funcao cadastro...\n\n");
        scanf("%c",&op);
    break;

    case '3':
        printf("\nChamar funcao att...\n\n");
        scanf("%c",&op);
    break;

    case '4':
        printf("\nChamar funcao remove...\n\n");
        scanf("%c",&op);
    break;

    case '5':
        printf("\nChamar funcao imprime...\n\n");
        scanf("%c",&op);
    break;

    case '6':
        printf("\nChamar funcao lista...\n\n");
        scanf("%c",&op);
    break;

    case '9':
        op=9;
    break;

    default:
    printf("\nOpcao invalida!\n\n");
    break;
  }
  op=op;
}while (op!=9);
return 0;
}
