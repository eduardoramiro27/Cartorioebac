#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo, cpf);//respons�vel por copiar o valor das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //cria o arquivo, "w" = escrever
	fprintf(file, "CPF: ");
	fprintf(file, cpf); //salva o valor da vari�vel
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
	
	printf("Cadastro conclu�do com sucesso\n\n");
	
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
		printf("O arquivo n�o foi localizado.\n\n");
	}
	else
	{

	system("cls");
	
	printf("Essas s�o as informa��es do usu�rio: \n\n");
	
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
		printf("Usu�rio n�o encontrado!\n\n");
	}
	else
	{
		remove(cpf);
	    system("cls");
	    printf("Usu�rio deletado com sucesso!\n\n");
    }
    
    system("pause");
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");//respons�vel po limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo as linguagens

		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
	    printf("Escolha op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    
	    switch(opcao)//in�cio da sele��o do menu
	    {
	    	case 1:
	    	registro();//chamda de fun��es
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;
		} //fim da sele��o
	
	}
}
