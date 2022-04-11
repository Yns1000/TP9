#include "pile.h"

void initPile(T_Pile *P)
{
    P->nbElts = 0;
}

int pilepleine(const T_Pile *P)
{
    if (P->nbElts == MAX)
        return 1;

    else
        return 0;
}

int pilevide(const T_Pile *P)
{
    if (P->nbElts == 0)
        return 1;

    else
        return 0;
}

int empiler(T_Pile *P, T_Elt e) // renvoie 0 si pile pleine, sinon 1
{
    if (pilepleine(P) != 1)
    {
        affecterElt(&(P->Elts[P->nbElts]), &e);
        P->nbElts = P->nbElts + 1;
        return 1;
    }
    else
        printf("\nVotre pile est pleine, cet element ne sera pas ajouté (Rappel : Taille max = %d)\n", MAX);

    return 0;
}

int depiler(T_Pile *P, T_Elt *pelt) // renvoie 0 si pile vide, sinon 1
{
    if (pilevide(P) != 1)
    {
        *pelt = P->Elts[P->nbElts - 1];
        P->nbElts = P->nbElts - 1;
        return 1;
    }
    return 0;
}

T_Elt sommet(const T_Pile *P)
{
    return (P->Elts[P->nbElts - 1]);
}

int hauteur(const T_Pile *P)
{
    return P->nbElts;
}

void afficherPile(T_Pile *P)
{
    T_Pile tmp;
    T_Elt elt;
    initPile(&tmp);

    if (pilevide(P) != 1)
    {
        do
        {
            depiler(P, &elt);
            afficherElt(&elt);
            empiler(&tmp, elt);

        } while (pilevide(P) != 1);

        do
        {
            depiler(&tmp, &elt);
            empiler(P, elt);

        } while (pilevide(&tmp) != 1);
    }

    else
        printf("\n ** Votre pile est vide !!!\n");
}

int permutation(T_Pile *P, char *ch)
{
    initPile(P);

    int j, i = 0;
    T_Elt E;
    int taille = strlen(ch);

    do
    {
        while (valide(P) == 1)
        {
            if (noeudTerminal(P, taille))
            {
                printf("\n\n");

                j = -1;

                do
                {
                    printf("%c", ch[P->Elts[j] - 1]);
                    j++;

                } while (j <= P->nbElts);

                i++;

                break;
            }
            else
            {
                passerAuPremierFils(P, 1);
            }
        }

        while ((rechercheTerminee(P) == 0) && naPlusDeFrere(P, taille))
        {
            remonterAuPere(P, &E);
        }

        if (rechercheTerminee(P) == 0)
        {
            passerAuFrereSuivant(P, &E);
        }

    } while (rechercheTerminee(P) == 0);

    return i;
}

int valide(T_Pile *P)
{
    int j, i = 0;

    do
    {
        for (j = i + 1; j < P->nbElts; j++)
        {
            if (P->Elts[i] == P->Elts[j])
            {
                return 0;
            }
        }

        i++;
    } while (i < P->nbElts);

    return 1;
}

int echiquier(T_Pile *P, int dim)
{
    initPile(P);

    int i = 0;
    T_Elt E;

    do
    {
        while (valideECH(P) == 1 && valide(P) == 1)
        {
            if (noeudTerminal(P, dim))
            {
                printf("\n\n");

                afficherPile(P);

                i++;

                break;
            }
            else
            {
                passerAuPremierFils(P, 1);
            }
        }

        while ((rechercheTerminee(P) == 0) && naPlusDeFrere(P, dim))
        {
            remonterAuPere(P, &E);
        }

        if (rechercheTerminee(P) == 0)
        {
            passerAuFrereSuivant(P, &E);
        }

    } while (rechercheTerminee(P) == 0);

    return i;
}

int valideECH(T_Pile *P)
{

    int j, i = P->nbElts - 1, k;

    do
    {
        for (j = i - 1; j >= 0; j--)
        {
            k = i - j;
            if (P->Elts[i] == P->Elts[j] - k || P->Elts[i] == P->Elts[j] + k)
            {
                return 0;
            }
        }

        i--;
    } while (i > 0);

    return 1;
}