#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#include "aricd.h"
#include "ario.h"

#define EXIT		'E'
#define ENCRIPT		'C'

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf(" Seja bem vindo ao melhor encriptador de mensagens.\n\n");

	while(1)
	{
		printf("ARI>");
		char op;
	    scanf(" %c", &op);
	    fflush(stdin);
		
		op = toupper(op);
		switch(op)
		{
			case EXIT: exit(0);
			
		    case ENCRIPT:
		    {
				printf("Informe a mensagem\n");
				
				printf("ARI\\criptografia>");
				char message[101];
				scanf(" %100[^\n]", message);
								
				printf("Informe o nome do arquivo\n");
				
				printf("ARI\\criptografia>");
				char file_name[32];
				scanf(" %31[^\n]", file_name);
							
		    	if (encrypt(file_name, message))
					printf("Mensagem criptografada\n");
				break;
			}

			default: printf("'%c' opção inválida\n", op);
		}
	}
	return 0;
}