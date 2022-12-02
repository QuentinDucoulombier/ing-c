/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief 
 * 
 */


#include "fonctions.h"
#include "puissance4.h"
#include "menu.h"


/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    /*srand( time(NULL));
    int tint_tab1[M];
    //int tint_tab2[M];
    //int tint_tabS[M];
    //char str_nom[M];
    for (int i = 0; i < M; i++)
    {
        tint_tab1[i] = 0;
        //tint_tab1[i] = rand() % 101;
        //tint_tab2[i] = rand() % 101;
    }
    tint_tab1[0] = 10;
    tint_tab1[1] = -2;
    tint_tab1[2] = 12;
    affichage(tint_tab1);
    //affichage(tint_tab2);
    //inversion(tint_tab1);
    //affichage(tint_tab1);
    //somme(tint_tab1, tint_tab2, tint_tabS);
    //affichage(tint_tabS);
    printf("trasversale : %d\n", tranversable(tint_tab1));
    //saisieChar(str_nom);
    //printf("chaine %s\n", str_nom);
    //inversionChaine(str_nom);
    //printf("chaine inverse %s\n", str_nom);*/

    /*Puissance 4*/
    /*INITIALISATION DES VARIABLES*/
    /*int joueur;
    int pionPlace;
    int gagner;
    int matriceP[LIGNES][COLONNES];

    joueur = choixJoueur();
    affichageDebut(joueur);
    initialisation(matriceP);
    pionPlace = jouer(matriceP, joueur);
    gagner = aGagne(matriceP);
    tourDeJeu(matriceP, gagner, joueur);
    affichageP4(matriceP);*/

    caseMenu(affichageMenu());

    return (0);
   
}
