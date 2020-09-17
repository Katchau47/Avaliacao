#include "help.h";

int main() {
	setlocale(LC_ALL,"PORTUGUESE");

	int opc;
	char cpf[14];

	cliente c;

	opc=menu();

	do {
		switch (opc) {
			case 1:
				system("cls");
				fflush(stdin);
				printf("// ----- // ----- // BUSCA H�SPEDE // ----- // ----- // \n\n");
				printf("\nDigite o CPF: ");
				gets(cpf);
				busca_cliente(&cpf);
				break;

			case 2:
				cadastra_cliente ();
				break;

			case 3:
				atualiza_cliente();

				break;

			case 4:
				remove_cliente();

				break;

			case 5:
				imprime_cliente(c);
				break;

			case 6:
				gerar_relatorio(c);
				
				break;

			case 9:
				break;

			default:
				printf("\nOp��o Inv�lida!\n\n");
				break;
		}

		opc=menu();

	} while (opc != 9);

	return 0;
}


int menu () {
	int op;
	printf("\n\n// ----- // ----- // CADASTRO H�SPEDE // ----- // ----- // \n\n[1] - Buscar por cadastro \n[2] - Cadastrar novo\n[3] - Atualizar cadastro\n[4] - Remover cadastro\n[5] - Imprimir todos cadastrados\n[6] - Gerar relat�rio\n[9] - Finalizar \n-------------------------------\nEntre com a sua op��o: ");
	scanf("\n%d",&op);
	return (op);
}

char busca_cliente(char *cpf) {

	hos = fopen("hospede.dat", "rb");
	cliente c;
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1) {
			if(strcmp(cpf, c.cpf)==0) {
				system("cls");
				printf("\n// ----- // ----- //// ----- // ----- // \n");
				printf("\n\nCadastro existente encontrado\n\n");
				printf("\n// ----- // ----- //// ----- // ----- // \n");
				system("pause");
				system("cls");
				return c.cpf;
			}else{
				return NULL;
			}
			system("cls");
		};
		fclose(hos);
	}
	system("cls");
	printf("\n// ----- // ----- //// ----- // ----- // \n");
	printf("\n\nCadastro existente n�o encontrado\n\n");
	printf("\n// ----- // ----- //// ----- // ----- // \n");
	system("pause");
	system("cls");
	return NULL;
}

void cadastra_cliente() {
	system("cls");
	printf("// ----- // ----- // CADASTRO H�SPEDE // ----- // ----- // \n\n");
	cliente c;
	char cpf[14];
	hos = fopen("hospede.dat", "ab+");
	fflush(stdin);
	printf("Digite o CPF: ");
	gets(cpf);
	fseek(hos, 0, SEEK_SET);
	fflush(stdin);
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {
		}
		if(strcmp(cpf, c.cpf)==0) {
			system("cls");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\n\nCadastro existente encontrado\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");
			return 0;
		} else
			while(fread(&c, sizeof(cliente), 1, hos)==1 && c.ativo!=NULL) {

			}
		if(!feof(hos)) {
			fseek(hos, -sizeof(cliente), SEEK_CUR);
			fflush(stdin);
			printf("\nDigite o Nome: ");
			gets(c.nome);
			printf("Digite o Sobrenome: ");
			gets(c.sobrenome);
			printf("Digite o Telefone: ");
			gets(c.telefone);
			printf("Digite o Sexo: ");
			scanf("%c", &c.sexo);
			printf("Digite a Idade:");
			scanf("%d", &c.idade);
			c.ativo=1;
			strcpy(c.cpf, cpf);
			fwrite(&c,sizeof (cliente),1, hos);
			fclose(hos);
		} else {
			fseek(hos, 1, SEEK_CUR);
			fflush(stdin);
			printf("Nome: ");
			gets(c.nome);
			printf("Sobrenome: ");
			gets(c.sobrenome);
			printf("Telefone: ");
			gets(c.telefone);
			printf("Sexo: ");
			scanf("%c", &c.sexo);
			printf("Idade:");
			scanf("%d", &c.idade);
			c.ativo=1;
			strcpy(c.cpf, cpf);
			fwrite(&c,sizeof (cliente),1, hos);
			fclose(hos);
			system("cls");
		}
		fclose(hos);
		return 0;
	}
	system("cls");
}

void atualiza_cliente() {
	hos = fopen("hospede.dat", "rb+");
	fseek(hos, 0, SEEK_SET);
	cliente c;
	system("cls");
	char cpf[14], op;
	int val=0;
	fflush(stdin);
	printf("// ----- // ----- // Atualiza Hospede // ----- // ----- // \n\n");
	printf("\nDigite o CPF do cadastro que se� atualizado: ");
	gets(cpf);
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {
		}
		if(strcmp(cpf, c.cpf)==0) {
			system("cls");
			printf("\nOs dados desse cliente são:\n");
			fread(&c, sizeof(cliente), 0, hos);
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nCPF: %s \n", c.cpf);
			printf("Nome: %s \n", c.nome);
			printf("Sobrenome: %s \n", c.sobrenome);
			printf("Telefone: %s \n", c.telefone);
			printf("Sexo: %c \n", c.sexo);
			printf("Idade: %d ", c.idade);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");

			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nOs dados ser�o atualizados...\n\n");
			printf("\nDeseja continuar?\n \n--> SIM (s)<--\n\n\n--> N�o (n) <--\n\n");
			("\n// ----- // ----- //// ----- // ----- // \n");
			fflush(stdin);
			scanf ("%c", &op);


			switch (op) {
				case 's':

					fseek(hos, -sizeof(cliente), SEEK_CUR);
					fflush(stdin);
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					printf("Novo Nome: ");
					gets(c.nome);
					printf("Novo Sobrenome: ");
					gets(c.sobrenome);
					printf("Novo Telefone: ");
					gets(c.telefone);
					printf("Novo Sexo: ");
					scanf("%c", &c.sexo);
					printf("Nova Idade:");
					scanf("%d", &c.idade);
					fwrite(&c ,sizeof (cliente),1, hos);
					fclose(hos);
					system("cls");
					break;

				case 'n':
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\nOpera��o cancelada\n");
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					system("pause");
					system("cls");
					break;

				default:
					printf("\nEntrada desconhecida\n");
					system("pause");
					system("cls");
					break;
			}
		}
	}
	system("cls");
}

void remove_cliente() {
	hos = fopen("hospede.dat", "rb+");
	fseek(hos, 0, SEEK_SET);
	cliente c;
	system("cls");
	char cpf[14], op;
	int val=0;
	fflush(stdin);
	printf("// ----- // ----- // Remove Hospede // ----- // ----- // \n\n");
	printf("\nDigite o CPF do cadastro que ser� Removido: ");
	gets(cpf);
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {
		}
		if(strcmp(cpf, c.cpf)==0) {
			system("cls");
			printf("\nOs dados desse cliente são:\n");
			fread(&c, sizeof(cliente), 0, hos);
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nCPF: %s \n", c.cpf);
			printf("Nome: %s \n", c.nome);
			printf("Sobrenome: %s \n", c.sobrenome);
			printf("Telefone: %s \n", c.telefone);
			printf("Sexo: %c \n", c.sexo);
			printf("Idade: %d ", c.idade);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");

			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nOs dados ser�o Deletados...\n\n");
			printf("\nDeseja continuar?\n \n--> SIM (s)<--\n\n\n--> Não (n) <--\n\n");
			("\n// ----- // ----- //// ----- // ----- // \n");
			fflush(stdin);
			scanf ("%c", &op);

			switch (op) {
				case 's':
					fseek(hos, -sizeof(cliente), SEEK_CUR);
					fflush(stdin);
					system("cls");
					c.ativo=0;
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					printf("Cliente deletado");
					printf("\n\n// ----- // ----- //// ----- // ----- // \n\n");
					fwrite(&c ,sizeof (cliente),1, hos);
					fclose(hos);
					system("pause");
					system("cls");
					break;

				case 'n':
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\nOpera��o cancelada\n");
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					system("pause");
					system("cls");
					break;

				default:
					printf("\nEntrada desconhecida\n");
					system("pause");
					system("cls");
					break;
			}
		}
	}
	system("cls");
}

void imprime_cliente(cliente c) {
	system("cls");
	hos = fopen("hospede.dat", "rb");
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		printf("\n// ----- // ----- // LISTA DE CADASTROS // ----- // ----- // \n");
		while(fread(&c, sizeof(cliente), 1, hos)==1) {
			if(c.ativo!=0) {
				printf("\nCPF: %s \n", c.cpf);
				printf("Nome: %s \n", c.nome);
				printf("Sobrenome: %s \n", c.sobrenome);
				printf("Telefone: %s \n", c.telefone);
				printf("Sexo: %c \n", c.sexo);
				printf("Idade: %d ", c.idade);

				printf("\n// ----- // ----- //// ----- // ----- // \n");
			}

		}
		fclose(hos);
	}
	system("pause");
	system("cls");
}

void gerar_relatorio(cliente c){
	system("cls");
	
	hos = fopen("hospede.dat", "rb");
	rel = fopen("relatorio.txt", "w");
	
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else if(rel != NULL) {
		printf("\n// ----- // ----- //// ----- // ----- // \n");
		printf("\n Gerando Relat�rio...\n\n");
	
		while(fread(&c, sizeof(cliente), 1, hos)==1) {
			if(c.ativo!=0) {
				fprintf(rel, "%s", c.cpf);
				fprintf(rel, "%s", c.nome);
				fprintf(rel, "%s", c.sobrenome);
				fprintf(rel, "%s", c.telefone);
				fprintf(rel, "%c", c.sexo);
				fprintf(rel, "%d", c.idade);

				printf("\n// ----- // ----- Relat�rio GERADO COM SUCESSO ----- // ----- // \n");
			}

		}
	}else{
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	}
	fclose(hos);
	fclose(rel);
	
	system("pause");
	system("cls");
	
}

