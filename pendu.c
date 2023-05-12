#include "mot.h"


void affiche_pendu() //Ascii des pendus
{
	switch(fail)
	{
		case 0:
			printf(" ---------\n |  	 |\n	 |\n	 |\n 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 1:
			printf(" ---------\n |  	 |\n 0	 |\n	 |\n 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 2:
			printf(" ---------\n |  	 |\n 0	 |\n-	 |\n 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 3 :
			printf(" ---------\n |  	 |\n 0	 |\n-|	 |\n 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 4 :
			printf(" ---------\n |  	 |\n 0	 |\n-|-	 |\n 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 5 :
			printf(" ---------\n |  	 |\n 0	 |\n-|-	 |\n/ 	 |\n 	 |\n 	 |\n  -------|\n");
			break;

		case 6 :
			printf(" ---------\n |  	 |\n 0	 |\n-|-	 |\n// 	 |\n 	 |\n 	 |\n  -------|\n");
			break;
	}
}

void main()
{
	char mainMot[25] = {0};
	char tabFauxChar[6] = {0};
	char *mainMotCache = NULL;
	int win = 1, loose = 1;;

	affiche_pendu();
	saisieMot(mainMot);
	initialisationMotMasque(mainMot, &mainMotCache);

	do
	{
		saisieChar(mainMot, &mainMotCache, tabFauxChar);
		viderBuffer();
		affiche_pendu();
		winCon(mainMot, &mainMotCache, &win, &loose);
	}while(win != 0 && loose != 0);

	free(mainMotCache);
}
