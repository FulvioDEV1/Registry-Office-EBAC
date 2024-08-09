#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//Biblioteca de string(conjunto de vari�veis)

int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema
{
	    setlocale(LC_ALL, "Portuguese");//Definindo a linguaguem
	
	char arquivo[40];//in�cio da cria��o das vari�veis
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];//fim de cria��o das vari�veis
        
        printf("Digite o cpf a ser cadastrado: ");
		scanf("%s", cpf);  
		
		strcpy(arquivo, cpf);//responsavel pro copiar valores das strings
		
		FILE *file;//cria o arquivo
		file = fopen(arquivo, "w");//abre o arquivo
		fprintf(file, cpf);//salva a informa��o no arquivo
		fclose(file);//fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado:");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ".");
		fclose(file);
		
		system("pause");//pause a tela ap�s as a��es
	
		
}

int consulta()//fun��o respons�vel por consultar os usu�rios do sistema
{
        setlocale(LC_ALL, "Portuguese");//definindo linguaguem
   
    char cpf[40];//criando vari�veis
    char conteudo[200];
            
        printf("Digite o CPF a ser consultado: ");
        scanf("%s", cpf);
    
        FILE *file;//abrindo arquivo
        file = fopen(cpf, "r");
        
    if(file == NULL)
    {
        printf("n�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
	}
	
    while(fgets(conteudo, 200, file) != NULL)
	{
	    printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");	
	}	
    
	    system("pause");
	    fclose(file);//fechando arquivo
	    
	          
}

int deletar()// fun��o respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];
	   
	   printf("Digite o CPF do usu�rio a ser deletado: ");
	   scanf("%s", cpf);
	   
	   remove(cpf);
	   
	   FILE *file;
	   file = fopen(cpf, "r");
	   fclose(file);
	   
   	if(file == NULL)
    {
	   	printf("O usu�rio n�o se encontra no sistema!.\n");
	   	system("pause");
    }
   
	   
	   
}

int main()// Menu principal vem primeiro
    {
	int opcao=0;//Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	    system("cls");//Limpar Tela
	
	    setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");//In�cio do Menu
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar  nomes\n");
    	printf("\t3 - Deletar  nomes\n\n");//Fim do Menu
    	printf("op��o:");

        scanf("%d", &opcao);

        system("cls");//Limpar Tela
    
    
    
    switch(opcao)
	{
    	case 1:
        registro();
        break;
        
        case 2:
		consulta();
        break;
        
        case 3:
        deletar();
        break;
        
        
        default:
		printf("\n essa op��o est� indispon�vel\n\n");
        system("pause");
        break;
        
	}


}
}//Usando o Switch case
