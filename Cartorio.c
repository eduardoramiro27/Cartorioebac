#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//responsável por copiar o valor das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo, "w" = escrever
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//"a" = atualizar
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("cls");
	
	printf("Cadastro concluído com sucesso\n\n");
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		system("cls");
		printf("O arquivo não foi localizado.\n\n");
	}
	else
	{

	system("cls");
	
	printf("Essas são as informações do usuário: \n\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		system("cls");
		printf("Usuário não encontrado!\n\n");
	}
	else
	{
		remove(cpf);
	    system("cls");
	    printf("Usuário deletado com sucesso!\n\n");
    }
    
    system("pause");
}

int main()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//responsável po limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens

		printf("### Cartório da EBAC ###\n\n"); //início do menu
	    printf("Escolha opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d",&opcao); //armazenando a escolha do usuário
	
	    system("cls");
	    
	    
	    switch(opcao)//início da seleção do menu
	    {
	    	case 1:
	    	registro();//chamda de funções
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		} //fim da seleção
	
	}
}
