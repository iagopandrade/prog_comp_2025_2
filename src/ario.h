#ifndef ARIO_H
#define ARIO_H
void ari_printf(void)
{
	printf(" Visualizar mensagens\\\n");
	printf("  Opções disponíveis\n");
	printf("  0: Visualizar mensagem\n");
	printf("  1: Voltar\n");
	
	int option;
	while(1)
	{
		printf(" Selecione uma opções digitando um nï¿½mero: ");
		scanf(" %c", &option);
		setbuf(stdin, NULL);

		switch(option)
		{
		    case '0':
			{
				printf("Digite o nome do arquivo: ");
				char file_name[32];
				scanf(" %[^\n]", file_name);
				
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
#endif