/**
 * @file fonctions.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief 
 * 
 */

#include "fonctions.h"

void affichage(int tint_tab[M])
{
    for (int i = 0; i < M; i++)
    {
        printf("%d |", tint_tab[i]);
    }
    printf("\n");
}


void inversion(int tint_tab[M])
{
    int temp;
    int i;
    int j;
    for (i = 0,j = M-1; i < j; i++, j--)
    {
        temp = 0;
        temp = tint_tab[i];
        tint_tab[i] = tint_tab[j];
        tint_tab[j] = temp;
    }   
}

/// brief verifier for
/// param tin_tab1 
/// param tin_tab2 
/// param tin_tabSortie 
void somme(int tin_tab1[M], int tin_tab2[M], int tin_tabSortie[M])
{
    for (int i = 0; i <= M; i++)
    {
        tin_tabSortie[i] = tin_tab1[i] + tin_tab2[i];
    }
}

int tranversable(int tint_tab[M])
{
    int somme = 0;
    for (int i = 0; i < M; i++)
    {
        somme = somme + tint_tab[i];
    }
    return (somme == M);
    
}

void saisieChar(char str_nom[M])
{
    printf("Veuillez saisir un string de taille 19: ");
    int int_outScan = scanf("%s", str_nom);
    str_nom[20] = '\0';
    if (!(int_outScan))
    {
        fprintf(stderr, "Entree incorrecte\n");
    }
}

int palindrome(char str_chaine[M]) 
{
    int i;
    int taille = 0;
    int bool = 1; //on initialise a vrai

    for (i = 0; str_chaine[i] != '\0'; i++) 
    {
        taille++;
        if(str_chaine[i] == ' ')
        {
            str_chaine[i] = '_';
        }
    }

    i = 0;

    do
    {
        printf("debut %d, %c\n", i, str_chaine[i]);
        printf("fin %d, %c\n", i, str_chaine[taille - i - 1]);
        if (str_chaine[i] != str_chaine[taille - i - 1]) 
        {
            //si c'est le cas bool passe a faux
            bool = 0;
        }
        i++;
    } while ((i < taille));

    return(bool);
}

/// @brief fonction qui permet de rentrer un entier
/// @return le nombre saisie
int saisieEntier(void)
{
    int int_n = 0;
    int int_outScan = scanf("%d", &int_n);
    if(int_outScan)
    {
        return(int_n);
    }
    else
    {
        fprintf(stderr, "Entree incorrecte\n");
        exit(EXIT_FAILURE);
    }
}