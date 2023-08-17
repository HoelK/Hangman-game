#include <string.h>

#include "basesfunc.h"
#include "display.h"
#include "word.h"

void main()
{
	const int maxfails = 6;
	int end = 1, fail = 0, wordlen = 0, nbwrongchar = 0;
	char mainword[27] = {0}, hidenword[27] = {0}, wrongchar[7] = {0};

	int *ptrfail = &fail;

	inputmainword(mainword);
	wordlen = (strlen(mainword))- 1;
	inithidenword(wordlen, hidenword);

	do
	{
		inputchar(ptrfail, wrongchar, mainword, hidenword);
		emptybuffer();
		displaygame(fail, hidenword, wrongchar);
		end = wincon(fail, maxfails, wordlen, mainword, hidenword);
	}while(end);
}

