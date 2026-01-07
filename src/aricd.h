 #ifndef ARICD_H
#define ARICD_H
int encrypt(char *file_name, char *message)
{
    FILE *file = fopen(file_name, "w");

	int i;
	for (i=0; message[i] != '\0'; i++)
	{
		if (isspace(message[i]))
			fprintf(file, " ");
		else
		{
			if (isalpha(message[i])!=0)
			{
				fprintf(file, "%d", toupper(message[i]) - 64);
				
                if (strlen(message)-1 > i)
					if (!isspace(message[i+1]) && message[i+1] != '\0')
					    fprintf(file, "_");
			}
		}
	}
	
	if(fclose(file) == 0) 
        return 1;
    else
        perror("");
    return 0;
}
int decrypt(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("");
        return 0;
    }

    FILE *file_temp = fopen("temp.txt", "w");
    if (file_temp == NULL)
    {
        perror("");
        fclose(file);
        return 0;
    }

    char message[101];
    if (fgets(message, sizeof(message), file) == NULL)
    {
        fclose(file);
        fclose(file_temp);
        return 0;
    }

    char *tok = strtok(message, "_");

    while (tok != NULL)
    {
//        trata possíveis espaços dentro do token */
        char *p = tok;

        while (*p)
        {
            if (isspace(*p))
            {
                fputc(' ', file_temp);
                p++;
                continue;
            }

            int num = atoi(p);
            if (num >= 1 && num <= 26)
                fputc(num + 64, file_temp);

//            avança até sair do número
            while (isdigit(*p))
                p++;
        }

        tok = strtok(NULL, "_");
    }

    fclose(file);
    fclose(file_temp);

    remove(file_name);
    rename("temp.txt", file_name);

    return 1;
}
#endif
