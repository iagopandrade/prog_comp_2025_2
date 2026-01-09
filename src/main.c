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
	printf("Digite 'C' para	Criptografar mensagens\n");
	printf("Digite 'D' para	Descriptografar mensagens\n");
	printf("Digite 'V' para	Visualizar mensagens\n");
	printf("Digite 'E' para Encerrar programa\n");
	printf("Digite 'L' para	Limpar o terminal\n");
	printf("Digite 'A' para	Exibir os comandos do programa\n");
	printf("_______________________________________________________________________\n");
	printf("Comandos disponíveis\t\n");
	printf("Escreva \"_cancelar\" para sair do modo atual e retornar ao menu principal\n");
	printf("\n=======================================================================\n");
}

int criptografar(void)
{
    char message[101];

	printf("_______________________________________________________________________\n");
	printf("Opção 'Criptografar' foi escolhida\n");

    while (1) // Laço para verificar se a string está correta
    {
    	printf("Informe a mensagem\n");
        printf("ARI\\criptografia>");
       	// printf("\n_______________________________________________________________________\n");
        
		fgets(message, sizeof(message), stdin);
        
        message[strcspn(message, "\n")] = '\0'; // Remove o newline '\n' para evitar erros na comparação

        if (strlen(message) == 0) // Verifica se a mensagem está vazia (usuário apenas pressionou 'ENTER')
        {
            printf("Mensagem vazia\n");
            printf("_______________________________________________________________________\n");
            continue;
        }

        if (strcmp(message, "_cancelar") == 0)
        {
            printf("Operação cancelada\n");
            printf("_______________________________________________________________________\n");
            return 0;
        }
      
//		Sinalizadores
        int i, alpha = 0, digit = 0, special_symbol = 0;

        for (i = 0; message[i] != '\0'; i++) // Laço para verificar os caracteres da string
        {
            if (isalpha(message[i]))
                alpha++;
            else if (isdigit(message[i])) 
                digit++; 
            else if (!isspace(message[i])) // * Se não for espaço, nem letra, nem número. Então é caractere especial
                special_symbol++;
        }
        
        if (special_symbol > 0)
        {
            printf("A mensagem não pode conter caracteres especiais\n");
            printf("_______________________________________________________________________\n");
            continue;
        }
        
        if (digit > 0)
        {
            printf("A mensagem não pode possuir dígitos\n");
            printf("_______________________________________________________________________\n");
            continue;
        }
        
        if (alpha == 0)
        {
            printf("A mensagem não pode ser composta apenas por espaços\n");
            printf("_______________________________________________________________________\n");
            continue;
        }
        
        break;
    }

    char file_name[32];
    printf("_______________________________________________________________________\n");
    printf("Informe o nome do arquivo\n");
    printf("ARI\\criptografia>");
    fgets(file_name, sizeof(file_name), stdin);
    
    file_name[strcspn(file_name, "\n")] = '\0'; // Remove o newline '\n' para evitar erros na comparação

    if (strcmp(file_name, "_cancelar") == 0)
    {
        printf("Operação cancelada\n");
        return 0;
    }

    if (encrypt(file_name, message))
	{
	    printf("_______________________________________________________________________\n");
	    printf("Mensagem criptografada e arquivo salvo\n\n");
	
	    // Menu após salvar a mensagem
	    char choice;
	    do
	    {
	        printf("Escolha uma opção:\n");
	        printf("C - Criptografar nova mensagem\n");
	        printf("V - Voltar ao menu principal\n");
	        printf("E - Encerrar programa\n");
	        printf("ARI\\criptografia>");
	
	        scanf(" %c", &choice);
	        fflush(stdin);
	        
	        choice = toupper(choice); // Converte para maiúsculo para evitar case-sensitive
	
	        if (choice == 'C')
	        {
	           	//printf("Opção criptografar foi escolhida\n");
	            return criptografar();
	        }
	        else if (choice == 'V')
	        {
	            printf("_______________________________________________________________________\n");
	            printf("Opção voltar ao menu principal foi escolhida\n");
				printf("Digite o novo caractere correspondente ao menu\n");	    
	            return 0;
	        }
	        else if (choice == 'E')
	        {
	            printf("_______________________________________________________________________\n");
	            printf("Opção 'Encerrar' programa foi escolhida\n");
	            printf("Programa finalizado!\n");
	            exit(0);
	        }
	        else
	        {
	            printf("Opção inválida\n");
	        }

	    } while (1);
	}
}

int main(void)
{
	setlocale(LC_ALL, "ptb");
	printf("\n=======================================================================");
    printf("\n          ARI - SISTEMA DE CRIPTOGRAFIA DE MENSAGENS              ");
    printf("\n=======================================================================\n");

	ari_commands(); // Imprime as opções do programa

	while (1) // Laço principal: só sai quando o usuário escolhe 'E'
	{
		printf("ARI>");
		char option;
	    scanf(" %c", &option);
	    fflush(stdin);

		option = toupper(option); // Converte para maiúsculo para evitar case-sensitive
		
		switch(option)
		{
			case EXIT:
			{
				printf("_______________________________________________________________________\n");
				printf("Opção 'Encerrar' foi escolhida\n");
				exit(0);
			}

			case LIMPAR:
			{			
				system("cls");
				printf("Opção 'Limpar' foi escolhida\n");
				printf("Digite o novo caractere correspondente ao menu\n");	 
				printf("_______________________________________________________________________\n");
				break;
			}

			case AJUDA:
			{	
				printf("_______________________________________________________________________\n");
				printf("Opção 'Ajuda' foi escolhida\n");
				printf("_______________________________________________________________________\n");	
				ari_commands();
				break;
			}

		    case ENCRIPT:
		    {
				criptografar();
				break;
			}

			case DECRYPT:
			{	
				printf("_______________________________________________________________________\n");
			    printf("Opção 'Descriptografar' foi escolhida\n");
			    printf("Informe o nome de um arquivo\n");
			
			    printf("ARI\\descriptografar>");
			    char input[32];
			    fgets(input, sizeof(input), stdin);
			    
			    input[strcspn(input, "\n")] = '\0'; // Remove o newline '\n' para evitar erros na comparação
			
			    if (strcmp(input, "_cancelar") == 0)
			        break;
			
			    if (decrypt(input))
			    {
			        printf("\nArquivo descriptografado com sucesso!\n");
			        printf("Conteúdo descriptografado:\n\n");
			
			        FILE *file = fopen(input, "r"); 
			        if (file == NULL)
			        {
			            perror("");
			            break;
			        }
			
			        char buffer[101];
			        while (fgets(buffer, sizeof(buffer), file) != NULL)
			        {
			            printf("%s", buffer);
			        }
			
			        fclose(file);			
			        printf("\n_______________________________________________________________________\n");
			        printf("Digite o novo caractere correspondente ao menu\n");
			    	break;
				}
			}

			case VIEWER:
			{	
				printf("_______________________________________________________________________\n");
				printf("Opção 'Visualizar' foi escolhida\n");
				printf("Informe o nome do arquivo\n");
				
				printf("ARI\\visualizar>");
				char input[32];
				fgets(input, sizeof(input), stdin);
				
				input[strcspn(input, "\n")] = '\0'; // Remove o newline '\n' para evitar erros na comparação

				if (strcmp(input, "_cancelar") == 0)
				{
					printf("Operação cancelada\n");
            		printf("_______________________________________________________________________\n");
					break;
				}
				
				FILE *file = fopen(input, "r");
				if (file == NULL)
				{
			        perror("");
			        break;
			    }
				
				char message[101];
				fscanf(file, "%100[^\n]", message);
				printf("%s: %s\n", input, message);
				
				fclose(file);
				break;
			}

			default: printf("'%c' Opção inválida\n", option);
		}
	}
	return 0;
}
