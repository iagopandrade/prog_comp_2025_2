#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(void);

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf(" Seja bem vindo ao melhor encriptador de mensagens.\n\n");
	printf(" Menu inicial\\\n");
	printf("  Opções disponíveis\n");
	printf("  0: Criptografar mensagens\n");
	printf("  1: Descriptografar mensagens\n");
	printf("  3: Sair do programa\n");

	int option;
	while(1)
	{
		printf(" Selecione uma opção digitando um número: ");
		scanf(" %c", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		    case '0': encrypt(); break;
			case '1': printf("Opção indisponível\n", option); break;
			case '3': exit(0);
			default: printf("'%c' opção inválida.\n", option);
		}
	}
	return 0;
}

void encrypt(void)
{
	printf(" Criptografia\\\n");
	printf("  Digite uma mensagem para criptografar: ");

	char message[100];
	scanf(" %100[^\n]s", message);
	setbuf(stdin, NULL);
	
	printf("  Agora digite o nome do arquivo: ");

	char file_name[32];
	scanf(" %32[^\n]s", file_name);
	setbuf(stdin, NULL);
	
    FILE *file = fopen(file_name, "w+");

	int i=0;
	while(message[i]!='\0')
	{
		if(isspace(message[i])) fprintf(file, " ", message[i]);
		
		else
		{
			fprintf(file, "%d", toupper(message[i]-64));
			if(i!=strlen(message)-1) fprintf(file, "_", message[i]);
		}
		i++;
	}

	if(fclose(file) == 0)
    {
//    	printf(" '%s'", message);
		printf(" '%s'", file_name);
		printf(" Foi criptografada com sucesso.\n");
		printf("------------------------------------------\n");
	}
	return;
}

