/**
 * @file menu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier qui contient l'ensemble des fonctions et procedure a l'affiche, la saisie et le resultat du menu
 * 
 */

#include "menu.h"
#include "fonctions.h"
#include "tri.h"

/// @brief affiche et permet de choisir le menu (oui je sais ce n'est pas bien de faire une fonction qui affiche)
/// @return le choix de l'utilisateur
int affichageMenu(void)
{
    int int_choix = -1;
    printf("------ CHOIX DU TRI ------\n");
	printf ("1 - Tri par insertion\n");
	printf ("2 - Tri fusion\n");
	printf ("3 - Tri par dénombrement\n");
    printf ("\n");
    /* Demande du choix a l'utilisateur */
	printf ("Quel est votre choix : ");
    int_choix = saisieEntier();
    return(int_choix);
}

/// @brief fonction qui affiche le resultat en fonction du choix de l'utilisateur
/// @param int_choix 
/// @param tableau 
/// @param taille 
void caseMenu(int int_choix, int* tableau, int taille)
{
    switch (int_choix) 
    {
        case 1 : 
            triInsertion(tableau, taille);
            printf("\n tri par insertion\n");
            affichage(taille, tableau);
            break;
        case 2 :
            triFusion(tableau, taille);
            printf("\n tri fusion\n");
            affichage(taille, tableau);
            break;
        case 3 :
            triDenombrement(tableau, taille);
            printf("\n tri par denombrement\n");
            affichage(taille, tableau);
            break;
        default :
            break;
	}
}
