// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"
#include <sys/time.h> //Necessaire pour utiliser la fonction gettimeofday
#include <time.h>
#include <stdlib.h>

T_File mafile;
T_Pile mapile;
int chx, chx2, chx3;
int taillefile = 0, taillepile = 0;
int i = 0, j = 0;
T_Elt eltfile, eltpile;

int taille;
char chaine[20];

int menu();
int menu2();
int menu3();

int main2();
int main3();

struct timeval debut, fin;
long duree;

time_t debut_sec, fin_sec, duree_sec; // En secondes...
int z = 0;

////////////////////////////

///////////////////////////////////////////////

int main()
{

	do
	{
		chx = menu();
		switch (chx)
		{
		case 1:

			system("clear"); // Soigner le terminal

			initPile(&mapile);
			printf("\n Combien de valeurs voulez-vous ajouter ? (MAX = %d) ", MAX);
			scanf("%d", &taillepile);
			if (taillepile > 0 && taillepile <= MAX)
			{
				main2();
			}
			else
			{
				printf("\n\nVous n'avez pas respectez les conditions, retour au menu principal.\n\n");
				break;
			}
			taillepile = 0;
			initPile(&mapile);
			break;
		case 2:

			system("clear"); // Soigner le terminal

			initFile(&mafile);
			printf("\n Combien de valeurs voulez-vous ajouter ? ");
			scanf("%d", &taillefile);

			if (taillefile > 0 && taillefile <= MAX)
			{
				main3();
			}
			else
			{
				printf("\n\nVous n'avez pas respectez les conditions, retour au menu principal.\n\n");
				break;
			}
			taillefile = 0;
			initFile(&mafile);
			break;
		case 3:

			system("clear"); // Soigner le terminal

			printf("\n\nDe quel mots voulez-vous consulter les permutations possibles (Taille =  %d caractère MAX) ? ", MAX);
			scanf("%s", chaine); // une chaine de longueur <=MAX

			if (strlen(chaine) <= MAX)
			{
				gettimeofday(&debut, NULL); // En us

				debut_sec = time(NULL); // En sec

				printf("\n\n *** Nombre de permutations possibles avec le mot \"%s\" : %d", chaine, permutation(&mapile, chaine));

				gettimeofday(&fin, NULL); // Date de fin de la recherche
				fin_sec = time(NULL);

				duree_sec = fin_sec - debut_sec;
				z = duree_sec;

				duree = (fin.tv_sec * 1000000 + fin.tv_usec) - (debut.tv_sec * 1000000 + debut.tv_usec);
				printf("\n\n *** La permutation de ce mot a prit %ld us soit environ %d secondes !!! \n", duree, z);
			}
			else
				printf("\n\nVotre chaine est trop longue !!!\n\n");

			break;

		case 4:

			system("clear"); // Soigner le terminal

			printf("\n\n **Dimension max = %d \n\n Dimension de l'échiquier sur lequel \n vous voulez travailler (Exemple : 4 -> 4x4) : ", MAX);
			scanf("%d", &taille); // taille echiquier <=MAX

			if (0 < taille && taille <= MAX)
			{
				gettimeofday(&debut, NULL); // En us

				debut_sec = time(NULL); // En sec

				printf("\n\n **Il y a %d moyens de mettre %d reines sur votre échiquier de %d*%d !!!", echiquier(&mapile, taille), taille, taille, taille);

				gettimeofday(&fin, NULL); // Date de fin de la recherche

				fin_sec = time(NULL);

				duree_sec = fin_sec - debut_sec;
				z = duree_sec;

				duree = (fin.tv_sec * 1000000 + fin.tv_usec) - (debut.tv_sec * 1000000 + debut.tv_usec);

				printf("\n\n ***La recherche de placement des reines a prit %ld us soit environ %d secondes !!! \n", duree, z);
			}
			else
				printf("\n\n **Votre echiquier de %d*%d ne respecte pas les conditions !!!\n\n", taille, taille);

			break;
		}
	} while (chx != 0);

	printf("\nau plaisir de vous revoir ...\n");
	return 0;
}

int menu() // Menu principal
{

	int choix;
	printf("\n\n\n SDA1 TP9");
	printf("\n\n BY YOUNES BOUGHRIET & VALENTIN NOËL & ADELYZA DESUMEUR");

	printf("\n\n\n 1 : tester mon fichier pile.c");
	printf("\n 2 : tester mon fichier file.c");
	printf("\n 3 : afficher et compter les permutations d'une chaine **AJOUTÉ HORS TP** ");
	printf("\n 4 : afficher et compter les solutions pour un échiquier **AJOUTÉ HORS TP**");

	printf("\n\n 0 :  QUITTER  ");

	printf("\n\n votre choix ?  ");
	scanf("%d", &choix);
	printf("\n********************************************************\n\n");
	return choix;
}

///////////////////////////

int menu2() // Menu pile
{

	int choix2;
	printf("\n\n\n ***Sous-Menu Pile");
	printf("\n\n\n 1 : Afficher la pile");
	printf("\n 2 : Dépiler");
	printf("\n 3 : Caractéristiques de la pile");
	printf("\n 4 : Empiler un element");

	printf("\n\n 0 :  Revenir au menu principal  ");
	printf("\n\n votre choix ?  ");

	scanf("%d", &choix2);

	printf("\n********************************************************\n\n");

	return choix2;
}

/////////////////////

int menu3() // Menu file
{

	int choix3;
	printf("\n\n\n ***Sous-Menu File");
	printf("\n\n\n 1 : Afficher la file");
	printf("\n 2 : Défiler");
	printf("\n 3 : Caractéristiques de la file");
	printf("\n 4 : Enfiler un element");

	printf("\n\n 0 :  Revenir au menu principal  ");
	printf("\n\n votre choix ?  ");

	scanf("%d", &choix3);

	printf("\n********************************************************\n\n");

	return choix3;
}

int main2() // Fonction pour la pile
{
	int tmp = 0;
	j = 0;

	do
	{
		printf(" \n **Element #%d de la pile ? ", j);
		scanf("%d", &eltpile);
		if (empiler(&mapile, eltpile) == 0)
			printf("Imposible d'ajouter cet element, la pile est pleine");

		j++;
	} while (j <= taillepile - 1);

	do
	{
		chx2 = menu2();
		switch (chx2)
		{
		case 1:
			afficherPile(&mapile);
			break;

		case 2:
			eltpile = hauteur(&mapile);
			depiler(&mapile, &eltpile);
			afficherPile(&mapile);

			break;

		case 3:

			printf("\n -- Nombre d'elements : %d\n", hauteur(&mapile));
			if (pilevide(&mapile) == 1)
			{
				printf("\n -- La pile est vide\n");
			}
			if (pilepleine(&mapile) == 1)
			{
				printf("\n -- La pile est pleine\n");
			}
			if (pilepleine(&mapile) == 0 && pilevide(&mapile) == 0)
			{
				printf("\n -- La pile n'est ni vide, ni pleine. \n");
			}

			printf("\n -- Le sommet de votre pile est : %d\n", sommet(&mapile));
			printf("\n -- Votre pile contient : %d elements \n", hauteur(&mapile));

			// testez toutes vos fonctions par un jeu de test de votre choix
			// testPile(&mapile); //TP9 partie 1 : à ecrire

			break;

		case 4:

			printf("\n Valeur à empiler : ");
			scanf("%d", &tmp);
			empiler(&mapile, tmp);
			break;
		}

	} while (chx2 != 0);
	return 0;
}

int main3() // Fonction pour la file
{
	T_Elt tmp = 0;
	T_Elt ll = 0;

	j = 0;

	do
	{
		printf(" \n **Element #%d de la file ? ", j);
		scanf("%d", &eltfile);
		if (ajouter(&mafile, &eltfile) == 0)
			printf("Imposible d'ajouter cet element, la file est pleine");

		j++;
	} while (j <= taillefile - 1);

	do
	{
		chx3 = menu3();
		switch (chx3)
		{
		case 1:
			afficherFile(&mafile);
			break;

		case 2:
			retirer(&mafile, &ll);
			afficherFile(&mafile);

			break;

		case 3:

			// printf("\n -- Nombre d'elements : %d\n", hauteur(&mapile));
			if (fileVide(&mafile) == 1)
			{
				printf("\n -- La file est vide\n");
			}
			if (filePleine(&mafile) == 1)
			{
				printf("\n -- La file est pleine\n");
			}
			if (filePleine(&mafile) == 0 && fileVide(&mafile) == 0)
			{
				printf("\n -- La file n'est ni vide, ni pleine. \n");
			}

			if (!fileVide(&mafile))
			{
				printf("\n -- Le premier element de votre file est :");
			}

			premier(&mafile);

			// testez toutes vos fonctions par un jeu de test de votre choix
			// testPile(&mapile); //TP9 partie 1 : à ecrire*/

			break;

		case 4:

			printf("\n Valeur à emfiler : ");
			scanf("%d", &tmp);
			ajouter(&mafile, &tmp);
			break;
		}

	} while (chx3 != 0);
	return 0;
}