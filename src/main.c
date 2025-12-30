#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#include "aricd.h"

#define ENCRIPT		'C'
#define DECRYPT		'D'
#define VIEWER	    'V'
#define EXIT		'E'
#define LIMPAR		'L'
#define AJUDA		'A'

void ari_commands(void)
{
	printf("Opções disponíveis\n");
	printf("C	Criptografar mensagens\n");
	printf("D	Descriptografar mensagens\n");
	printf("V   	Visualizar mensagens\n");
	printf("E   	Encerrar programa\n");
	printf("L	Limpa o terminal\n");
	printf("A	Exibe os comandos do programa\n");
	printf("Comandos disponíveis\t\n");
	printf("\"_cancelar\"	Encerra a seção (É necessário estar em seção)\n");
	printf("___________________________________________\n");
}

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf("ARI - O melhor programa de  criptografia.\n");

	ari_commands();

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
			case LIMPAR: system("cls"); break;
			case AJUDA: ari_commands(); break;
			
		    case ENCRIPT:
		    {
				printf("Informe a mensagem\n");
				
				printf("ARI\\criptografia>");
				char message[101];
				scanf(" %100[^\n]", message);

				if (strcmp(message, "_cancelar") == 0)
					break;
								
				printf("Informe o nome do arquivo\n");
				
				printf("ARI\\criptografia>");
				char file_name[32];
				scanf(" %31[^\n]", file_name);

				if (strcmp(file_name, "_cancelar") == 0)
					break;				
							
		    	if (encrypt(file_name, message))
					printf("Mensagem criptografada\n");
				break;
			}

			case DECRYPT:
			{
    			printf("Informe o nome de um arquivo\n");  			
    			
    			printf("ARI\\descriptografar>");
				char in[32];
    			scanf(" %31[^\n]", in);
    			
    			if (strcmp(in, "_cancelar") == 0)
					break;
				
				if (decrypt(in))
					printf("%s foi descriptografado\n", in);
				break;
			}

			case VIEWER:
			{
				printf("Informe o nome do arquivo\n");
				
				printf("ARI\\visualizar>");
				char in[32];
				scanf(" %31[^\n]", in);
				
				if (strcmp(in, "_cancelar") == 0)
					break;
				
				FILE *file = fopen(in, "r");
				if (file == NULL)
				{
			        perror("");
			        break;
			    }
				
				char message[101];	
				fscanf(file, "%100[^\n]", message);
				printf("%s: %s\n", in, message);
				
				fclose(file);
				break;
			}
		
			default: printf("'%c' opção inválida\n", op);
		}
	}
	return 0;
}