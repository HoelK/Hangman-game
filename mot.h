#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxFails = 6;
int fail = 0;
int tailleMot = 0;

void saisieMot(char motAtrouver[])
{
	//Saisie du mot
	do
	{
		printf("Votre mot à deviner : ");
		fgets(motAtrouver, 25, stdin);
		if(strlen(motAtrouver) >= 25)
			printf("Veuillez à saisir un mot, pas le contenu d'un dictionnaire !");
	}while(strlen(motAtrouver) >= 25);

	//On efface le mot de la console pour pas que le second joueur puisse le voir
	for(int i = 0; i < 10000; i++)
	{
		printf("\n");
	}
}

void initialisationMotMasque(char motAtrouver[], char **motMasqueUnderscore)
{
	//Récupération de la taille du mot
	tailleMot = strlen(motAtrouver);
	
	//Création du tableau qui contient les "_" qui va être affiché pendant la partie
	*motMasqueUnderscore = malloc(tailleMot * sizeof(char));

	//Vérification de l'allocation
	if(motMasqueUnderscore == NULL)
		exit(0);

	//Remplissage du tableau
	for(int i = 0; i < tailleMot-1; i ++)
	{
		(*motMasqueUnderscore)[i] = '_';
	}
	printf("%s\n", *motMasqueUnderscore);
}

void saisieChar(char motAtrouver[], char **motMasqueUnderscore, char tabFauxChar[])
{
	//Saisie du caractere
	char caractere = 0;
	int lsPosi[5] = {0};
	int x = 0, posi = 0, charFound = 1, fauxChar = 0;

	//Saisir la lettre
	printf("Veuillez saisir un charactère : ");
	scanf("%c", &caractere);

	//Cherche si le char saisie est dans le mot et note sa position
	for(int i = 0; i < tailleMot; i++)
	{
		if(motAtrouver[i] == caractere)
		{
			lsPosi[x] = i;
			x++;
			charFound = 0;
		}
	}

	//Si oui alors les '_' correspondant aux positions sont remplacés
	if(charFound == 0)
		for(int i = 0; i < x; i++)
		{
			posi = lsPosi[i];
			(*motMasqueUnderscore)[posi] = caractere;
		}
	else //Si non alors mettre la lettre dans un tableau des mauvaises lettres
	{
		fauxChar = fail;
		tabFauxChar[fauxChar] = caractere;
		fail++;
	}

	printf("Liste des mauvaises lettres déjà essayés : ");
	//Affichage du tableau des mauvaises lettres
	for(int i = 0; i < fauxChar+1; i++)
	{
			printf("%c, ", tabFauxChar[i]);
	}
	printf("\nMot à trouver : %s\n", *motMasqueUnderscore);
}

void winCon(char motAtrouver[], char **motMasqueUnderscore, int *win, int *loose)
{
	if(fail == maxFails)
	{
		printf("Oh non vous avez perdu !\n");
		*loose = 0;
	}

	if(memcmp(motAtrouver, *motMasqueUnderscore, tailleMot-1) == 0)
	{
		*win = 0;
		printf("Félicitation, vous avez gagné !\n");
	}
}

void viderBuffer()
{
	int c = 0;

	while(c != '\n' && c != EOF)
	{
		c = getchar();
	}
}