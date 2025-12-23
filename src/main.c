#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(void);
void decrypt(void);
void menu(void);
void ari_printf(void);

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf(" Seja bem vindo ao melhor encriptador de mensagens.\n\n");

	menu();
	return 0;
}

void ari_printf(void)
{
	printf(" Visualizar mensagens\\\n");
	printf("  Opções disponíveis\n");
	printf("  0: Visualizar mensagem\n");
	printf("  1: Voltar\n");
	
	int option;
	while(1)
	{
		printf(" Selecione uma opções digitando um número: ");
		scanf(" %c", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		    case '0':
			{
				printf("Digite o nome do arquivo: ");
				char file_name[32];
				scanf(" %[^\n]32s", file_name);
				setbuf(stdin, NULL);
				
				FILE *file = fopen(file_name, "r");
				
				if(file == NULL)
				{
					perror("");
					fclose(file);
					break;
				}
				
				char ch;
				printf("Conteúdo do arquivo:\n");
				while((ch = fgetc(file)) != EOF)
				{
					putchar(ch);
				}
				
				printf("\n");
				
				fclose(file);				
				break;	
			}
			case '1': return;
			 default: printf("'%c' opção inválida.\n", option);
		}
	}
	return;
}

void encrypt(void)
{
	printf(" Criptografia\\\n");
	printf("  Digite uma mensagem para criptografar: ");

	char message[100];
	scanf(" %[^\n]100s", message);
	setbuf(stdin, NULL);

	printf("  Agora digite o nome do arquivo: ");

	char file_name[32];
	scanf(" %[^\n]32s", file_name);
	setbuf(stdin, NULL);

    FILE *file = fopen(file_name, "w+");

	int i;
	for(i=0; message[i] != '\0'; i++)
	{
		if(isspace(message[i])) fprintf(file, " ", message[i]);

		else
		{
			if(isalpha(message[i])!=0)
			{
				fprintf(file, "%d", toupper(message[i])-64);
				if(i!=strlen(message)-1)
				{
					if(!isspace(message[i+1]) && message[i]+1!='\0')
						fprintf(file, "_", message[i]);
				}
			}
		}	
	}//for
	
	if(fclose(file) == 0)
	{
		printf(" Sua mensagem foi criptografada com sucesso.\n");
		printf("_____%s_____________________________________\n", file_name);
		fopen(file_name, "r");
		char ch;
		while((ch = fgetc(file)) != EOF)
		{
        	putchar(ch);
    	}
		fclose(file);
		printf("\n__________________________________________\n");
		printf("\n------------------------------------------\n");
	}
	
	int option;
	while(1)
	{
		printf(" Criptografia\\\n");
		printf("  Opções disponíveis\n");
		printf("  0: Criptografar outra mensagem\n");
		printf("  1: Sair dessa seção\n");
		printf(" Selecione uma opção digitando um número: ");
		scanf(" %c", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		    case '0': encrypt(); break;
			case '1': main();	 break;	
			 default: printf("'%c' opção inválida.\n", option);
		}
	}
	return;
}

void menu(void)
{
	printf(" Menu inicial\\\n");
	printf("  Opções disponíveis\n");
	printf("  0: Criptografar mensagens\n");
	printf("  1: Descriptografar mensagens\n");
	printf("  2: Visualizar mensagens\n");
	printf("  3: Encerrar programa\n");
	
	int option;
	while(1)
	{
		printf(" Selecione uma opções digitando um número: ");
		scanf(" %c", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		    case '0': encrypt(); break;
			case '1': printf("Opção indisponível\n", option); break;
			case '2': ari_printf(); break;
			case '3': exit(0);
			 default: printf("'%c' opção inválida.\n", option);
		}
	}
}

