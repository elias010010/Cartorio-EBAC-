#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //bilbioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar dos string

int registro()
{	
	//inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/strings

	
	printf("Digita o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Criar o arquivo 
	file = fopen(arquivo, "w"); //Criar o arquivo/ "w" significa escrever
	fprintf(file,cpf); //Salvar o valor da variavel
	fclose(file); //Fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");  //Definindo a linguagem 
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	 
 	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}

int main()
	{
	int opcao=0;  //Definindo variaveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "portuguese");  //Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("Op��o:"); //Final do menu 
	
		scanf("%d" , &opcao);  //Armazenando informa��es(escolha do usuario)
	
		system("cls");//responsavel por limpar a tela
	
		switch(opcao) //inicio da sele��o do menu
		{
		
		case 1:
		registro(); // chameda de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Esta op��o n�o estar disponivel!");
		system("pause");
		break;
	
		}
	}
}
