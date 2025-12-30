#ifndef ARICD_H
#define ARICD_H
void encrypt(void)
{
	printf(" Criptografia\\\n");
	printf("  Digite uma mensagem para criptografar: ");

	char message[101];
	scanf(" %100[^\n]", message);
	setbuf(stdin, NULL);

	printf("  Agora digite o nome do arquivo: ");

	char file_name[32];
	scanf(" %31[^\n]", file_name);

    FILE *file = fopen(file_name, "w+");

	int i;
	for (i=0; message[i] != '\0'; i++)
	{
		if (isspace(message[i])) fprintf(file, " ", message[i]);

		else
		{
			if (isalpha(message[i])!=0)
			{
				fprintf(file, "%d", toupper(message[i])-64);
				if (i!=strlen(message)-1)
				{
					if(!isspace(message[i+1]) && message[i+1] != '\0')
						fprintf(file, "_", message[i]);
				}
			}
		}	
	}
	
	if (fclose(file) == 0)
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
#endif