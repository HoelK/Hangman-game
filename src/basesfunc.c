#include <stdio.h>
#include <string.h>

void emptybuffer()
{
	int c = 0;

	while(c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int wincon(int fail, int maxfails, int wordlen, char mainword[], char hidenword[])
{
	if(fail == maxfails)
	{
		printf("You lost !\n");
		return 0;
	}
	else if(memcmp(mainword, hidenword, wordlen) == 0)
	{
		printf("Congrats, you won !\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
