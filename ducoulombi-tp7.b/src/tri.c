#include "tri.h"
#include "fonctions.h"


/*-----------------*/
/*Tri par insertion*/
/*-----------------*/
void triInsertion(int* pint_tab, int int_taille)
{
    int int_elementInsere;

    int j;
    for (int i = 1; i < int_taille; i++)
    {
        int_elementInsere = pint_tab[i];

        for (j = i; j > 0 && pint_tab[j - 1] > int_elementInsere; j--)
        {
            pint_tab[j] = pint_tab[j - 1];
        }
        pint_tab[j] = int_elementInsere;
    }
}


/*----------*/
/*Tri fusion*/
/*----------*/

int* copierSousTableau(int* src, int debut, int fin)
{
    int* tabDest;
    tabDest = allouer(fin - debut);
    for (int i = debut; i < fin ; i++)
    {
        tabDest[debut - i] = src[i];
    }
    return tabDest;    
}

void fusion(int* tab1, int taille1, int* tab2, int taille2, int* tabRes)
{

}