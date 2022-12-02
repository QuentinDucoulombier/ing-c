/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 */
#include "tri.h"
#include "fonctions.h"

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    int taille;
    int* tabMain;

    /*Saisie de la taille*/
    taille = saisieEntier();

    /*Initialisation...*/
    tabMain = allouer(taille);
    initialisation(taille, tabMain);

    /*Affichage du tableau orignal*/
    printf("tableau original\n");
    affichage(taille, tabMain);

    /*Affichage du tableau trié par insertion*/
    //triInsertion(tabMain, taille);
    //triFusion(tabMain, taille);
    triDenombrement(tabMain, taille);
    printf("\n tri par denombrement\n");
    affichage(taille, tabMain);

    /*liberer le tableau*/
    
    liberer(tabMain);

    return (0);
}
