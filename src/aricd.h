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
				
                if (i != strlen(message) - 1)
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
#endif