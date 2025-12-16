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
	printf(" Menu\\Opções disponíveis\n");
	printf("  0: Criptografar mensagens\n");
	printf("  1: Descriptografar mensagens\n");
	printf("  3: Sair do programa\n");

	int option;
	while(1)
	{
		printf("  Selecione uma opção digitando um número: ");
		scanf(" %c", &option);

		switch(option)
		{
		    case '0': encrypt(); break;
			case '1': printf("Opção indisponível\n",option); break;
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
	
    FILE *file = fopen("MensagemCriptografada.txt", "a+");
    
    if(file == NULL)
    {
        perror("");
    }

    fprintf(file, "%s", message);   

	if(fclose(file) == 0)
    {
    	printf(" '%s'", message);
		printf(" Foi criptografada com sucesso.\n");
		printf("------------------------------------------\n");
	}
	return;
}

