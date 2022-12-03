/**
 * @file fonctions.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier fonctions qui contient l'ensemble des fonctions pour le tableau dynamique et pour saisir un entier
 * 
 */
#include "fonctions.h"

/// @brief alloue le tableau
/// @param int_taille 
/// @return le tableau alloué
int* allouer(int int_taille)
{
    int* pint_tab;
    pint_tab = malloc(int_taille *sizeof(int));
    if (pint_tab == NULL)
    {
        fprintf(stderr, "Erreur d'initialisation\n");
        exit(EXIT_FAILURE);
    }
    return pint_tab;
}

/// @brief initialise le tableau de facon random
/// @param int_taille 
/// @param pint_tab 
void initialisation(int int_taille, int* pint_tab)
{
    srand(time(NULL));
    for (int i = 0; i < int_taille; i++)
    {
        pint_tab[i]=rand() % 100;
    }
    
}

/// @brief affiche le tableau
/// @param int_taille 
/// @param pint_tab 
void affichage(int int_taille, int* pint_tab)
{
    for (int i = 0; i < int_taille; i++)
    {
        printf(" | %d",pint_tab[i]);
    }
    printf(" |\n");

}

/// @brief libere le tableau
/// @param pint_tab 
void liberer(int* pint_tab)
{

    free(pint_tab);
    pint_tab = NULL;
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