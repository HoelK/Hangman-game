#include <stdio.h>

void displaygame(int fail, char hidenword[], char wrongchar[])
{
	//Ascii of the hangman
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
	//Words
	printf("Word : %s\nList of wrong char tried : %s\n", hidenword, wrongchar);
}
