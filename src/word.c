#include <stdio.h>
#include <string.h>
#include <stddef.h>

void inputmainword(char mainword[])
{
	//Input of the word
	do
	{
		printf("Worrd to gess (25 char max): ");
		fgets(mainword, 27, stdin);
		mainword[*strchr(mainword, '\n')] = '\0';

		//Secure input
		if(strlen(mainword) > 26)
			printf("Please, don't go upper 25 chars\n");
	}while(strlen(mainword) > 26);

	//Erease the word from the terminal to hide it
	for(int i = 0; i < 10000; i++)
	{
		printf("\n");
	}
}

void inithidenword(int wordlen, char hidenword[])
{
	for(int i = 0; i < wordlen; i++)
	{
		hidenword[i] = '_';
	}
	hidenword[wordlen] = '\0';
}

void inputchar(int *ptrfail, char wrongchar[], char mainword[],char hidenword[])
{
	int posichar = 0;
	char inputchar = 0;
	
	//Input the char
	printf("Veuillez saisir un charactère : ");
	scanf("%c", &inputchar);

	//If the char isn't in the word, add a fail
	if(strchr(mainword, inputchar) == NULL)
	{
		wrongchar[*ptrfail] = inputchar;
		*ptrfail += 1;
	}
	else //Else add the letter to the word the 2nd player see
	{
		for(int i = 0; i < (strlen(mainword)) - 1; i++)
		{
			if(mainword[i] == inputchar)
			{
				hidenword[i] =inputchar;	
			}
		}
	}
}
