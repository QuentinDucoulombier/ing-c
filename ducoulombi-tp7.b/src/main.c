/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier main qui permet de presenté l'ensemble des tris
 * 
 */
#include "tri.h"
#include "fonctions.h"
#include "menu.h"

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief fonction main qui presente l'ensemble des tris
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    int taille, choix;
    int* tabMain;

    /*Affiche le menu et permet de saisir le choix*/
    choix = affichageMenu();

    /*Saisie de la taille*/
    printf("Veuillez saisir la taille du tableau: ");
    taille = saisieEntier();

    /*Initialisation du tableau*/
    tabMain = allouer(taille);
    initialisation(taille, tabMain);

    /*Affichage du tableau orignal*/
    printf("tableau original\n");
    affichage(taille, tabMain);

    /*Affichage du tri en fonction du choix du menu*/
    caseMenu(choix, tabMain, taille);

    /*libere le tableau*/
    liberer(tabMain);

    return (0);
}
