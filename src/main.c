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

int criptografar(void)
{
	printf("Informe a mensagem\n");
	printf("ARI\\criptografia>");
	char message[101];
	fgets(message, sizeof(message), stdin); 
	
	message[strcspn(message, "\n")] = '\0'; // Remove o '\n' do ENTER		
	
	// Verifica se a string é vazia
	if (strlen(message) == 0)
		return printf("Mensagem vazia\n");
	
	if (strcmp(message, "_cancelar") == 0)
	{
		printf("Operação cancelada\n");
		return 0;
	}

	// Sinalizadores		
	int i, space = 0, alpha = 0, digit = 0, special_symbol = 0;
		
	for (i = 0; message[i] != '\0'; i++)
	{
			
		if (isalpha(message[i]) != 0)
			alpha++;
		else if (isdigit(message[i]) != 0)
			digit++;

		// Se não há caractere e nem espaço, automaticamente é um símbolo
		else if (isalpha(message[i]) == 0 && isspace(message[i]) == 0)			
        special_symbol++;
	}

	if (special_symbol > 0 || alpha == 0 || digit > 0)
	{
		if (special_symbol == 0 && alpha == 0 && digit == 0)
		{
			printf("A mensagem não pode ser composta apenas por espacos\n");
			return -1;
		}
		if (special_symbol > 0) 
			printf("A mensagem não pode conter caracteres especiais\n");		
		if (alpha == 0) 
			printf("A mensagem não possui letras\n");
		if (digit > 0) 
			printf("A mensagem não pode possuir dígitos\n");
		return -1;
	}

	printf("Informe o nome do arquivo\n");
	printf("ARI\\criptografia>");
	char file_name[32];
	fgets(file_name, sizeof(file_name), stdin);
	
	file_name[strcspn(file_name, "\n")] = '\0';

	if (strcmp(file_name, "_cancelar") == 0)
	{
		printf("Operação cancelada.");
		return 0;
	}
	
	if (encrypt(file_name, message))			
	{
		printf("Mensagem criptografada\n");
		
		printf("Opções disponíveis\n");
		printf("C	Criptografar uma nova mensagem\n");
		printf("S   	Sair\n");
		
		char encrypt_op;
		do
		{
			printf("ARI\\criptografia>");
			scanf(" %c", &encrypt_op);
			fflush(stdin);
			encrypt_op = toupper(encrypt_op);
		} while(encrypt_op != 'C' && encrypt_op != 'S');
		
		if (encrypt_op == 'C')
		{
			criptografar();
		}
		else
			printf("Você saiu da seção\n");
		return 1;
	}
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
				criptografar();
				break;
			}// fim ENCRIPT

			case DECRYPT:
			{
    			printf("Informe o nome de um arquivo\n");  			
    			
    			printf("ARI\\descriptografar>");
				char in[32];
    			fgets(in, sizeof(in), stdin);
    			
				in[strcspn(in, "\n")] = '\0'; // Remove o '\n' do ENTER
    			
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
				fgets(in, sizeof(in), stdin);
				
				in[strcspn(in, "\n")] = '\0'; // Remove o '\n' do ENTER
				
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
