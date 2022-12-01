#include "fonctions.h"


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

void initialisation(int int_taille, int* pint_tab)
{
    srand(time(NULL));
    for (int i = 0; i < int_taille; i++)
    {
        pint_tab[i]=rand() % 100;
    }
    
}

void affichage(int int_taille, int* pint_tab)
{
    for (int i = 0; i < int_taille; i++)
    {
        printf(" | %d",pint_tab[i]);
    }
    printf(" |\n");

}

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
    printf("Veuillez saisir un entier: ");
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