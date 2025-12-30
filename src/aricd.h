#ifndef ARICD_H
#define ARICD_H  
int encrypt(char *file_name, char *message)
{
    FILE *file = fopen(file_name, "w");

	int i;
	for (i=0; message[i] != '\0'; i++)
	{
		if (isspace((unsigned char)message[i]) )
			fprintf(file, " ");
		else
		{
			if (isalpha((unsigned char)message[i]) != 0)
			{
				fprintf(file, "%d", toupper(message[i]) - ('A' - 1));
				
                if (i != strlen(message)-1)
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
		int num = atoi(tok);

		if (isspace((unsigned char)num))
		{
			fputc(' ', file_temp);
			continue;
		}
			
        fputc(num + 'A' - 1, file_temp);
        tok = strtok(NULL, "_");
    }
    
    fclose(file);
    fclose(file_temp);

    remove(file_name);
    rename("temp.txt", file_name);
    return 1;
}
#endif