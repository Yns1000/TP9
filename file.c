#include "file.h"

void initFile(T_File *ptrF) // mettre Tete et Queue à -1
{
    ptrF->Tete = -1;
    ptrF->Queue = -1;
}

int retirer(T_File *ptrF, T_Elt *ptrE) // si pas vide, en tete de file
{
    int a = 0;

    if (!fileVide(ptrF))
    {
        *ptrE = ptrF->Elts[ptrF->Tete];

        a = ptrF->Tete;

        do
        {
            ptrF->Elts[a] = ptrF->Elts[a + 1];
            a++;
        } while (a < ptrF->Queue);

        ptrF->Queue--;
        return 1;
    }
    else
        return 0;
}

int ajouter(T_File *ptrF, T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (ptrF->Queue <= 8)
    {
        affecterElt(&ptrF->Elts[ptrF->Queue], ptrE);
        ptrF->Queue = ptrF->Queue + 1;

        //  printf(" \n --DEBUG : Tete = %d  et queue = %d", ptrF->Tete, ptrF->Queue);

        return 1;
    }
    if (ptrF->Queue == MAX)
    {
        return 0;
    }
    if (filePleine(ptrF))
    {
        printf("\n Votre file est pleine, cet element ne sera pas ajouté (Rappel : Taille max = %d)", MAX);
        return 0;
    }
    return 0;
}

int fileVide(const T_File *ptrF) // qd Tete == 0 et Queue == 0
{
    if (ptrF->Tete == ptrF->Queue)
        return 1;
    else
        return 0;
}

int filePleine(const T_File *ptrF) // qd MAX elts dans la file ///////////////
{
    if (ptrF->Queue == MAX - 1)
        return 1;
    else
        return 0;
}

T_Elt premier(T_File *ptrF) // valeur en tete de file
{
    if (!fileVide(ptrF))
    {
        if (ptrF->Tete == -1)
        {
            afficherElt(&ptrF->Elts[-1]);
            return 1;
        }
        if (ptrF->Tete != -1 && !fileVide(ptrF))
        {
            printf("\n -- Le premier element de votre file est :");
            afficherElt(&ptrF->Elts[ptrF->Tete]);
            return 1;
        }
    }

    return 0;
}

void afficherFile(T_File *ptrF)
{

    int i = ptrF->Tete;

    if (fileVide(ptrF))
    {
        printf("\n --Votre file est vide \n");
    }
    else
    {
        printf("\n --Votre file :\n");
        do
        {

            afficherElt(&ptrF->Elts[i]);

            i++;
        } while (i < ptrF->Queue);
    }
}
