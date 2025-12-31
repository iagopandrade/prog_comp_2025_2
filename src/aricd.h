#ifndef ARICD_H
#define ARICD_H
int encrypt(char *file_name, char *message)
{
    FILE *file = fopen(file_name, "w");

	int i;
	while (message[i] != '\0')
	{
		if (isspace((unsigned char)message[i]))
			fprintf(file, " ");
		else
		{
			if (isalpha((unsigned char)message[i])!=0)
			{
				fprintf(file, "%d", toupper(message[i]) - 64);
				
                if (strlen(message)-1 > i)
					if (!isspace((unsigned char)message[i+1]) && message[i+1] != '\0')
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
        return 0;
    }
	
	char message[101];
	fscanf(file, "%100[^\n]", message);
	
	char *tok = strtok(message, "_");

    while(tok != NULL)
	{
		if (isspace((unsigned char)atoi(tok)))
		{
			fputc(' ', file_temp);
			continue;
		}
			
        fputc(atoi(tok) + 64, file_temp);
        tok = strtok(NULL, "_");
    }
    
    fclose(file);
    fclose(file_temp);

    remove(file_name);
    rename("temp.txt", file_name);
    return 1;
}
#endif
