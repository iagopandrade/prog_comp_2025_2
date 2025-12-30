#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#include "aricd.h"
#include "ario.h"

void menu(void)

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf(" Seja bem vindo ao melhor encriptador de mensagens.\n\n");

	menu();
	return 0;
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