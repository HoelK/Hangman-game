#ifndef WORD_H
#define WORD_H

void inputmainword(char mainword[]);											//Ask the first to choose the word then erease it
void inithidenword(int wordlen, char hidenword[]);								//Initialise the word that the second player see
void inputchar(int *fail, char wrongchar[], char mainword[],char hidenword[]);	//Ask the second player a char and compare it with the main word

#endif
