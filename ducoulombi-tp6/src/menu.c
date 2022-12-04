/**
 * @file menu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief 
 * 
 */


#include "menu.h"
#include "fonctions.h"
#include "puissance4.h"



int affichageMenu(void)
{
    int int_choix = -1;
	printf ("1 - Inverser un tableau\n");
	printf ("2 - Faure la somme de deux tableau\n");
	printf ("3 - Approximation de John Wallis\n");
    printf ("\n");
    printf("------ Fonction pour approximer racine de 2 ------\n");
    printf ("4 - Approximation de Isaac Newton\n");
	printf ("5 - Approximation de Edmund Halley\n");
	printf ("6 - Approximation par la methode de Théon de Smyrne\n");
    	/* Demande du choix a l'utilisateur */
	printf ("Quel est votre choix : ");
    int_choix = saisieEntier();
    return(int_choix);
}

void caseMenu(int int_choix)
{
    int tint_tab1[M];
    int tint_tab2[M];
    int tint_tabS[M];


    int joueur;
    int pionPlace;
    int gagner;
    int matriceP[LIGNES][COLONNES];
    srand(time(NULL));
    switch (int_choix) 
    {
        case 1 : 
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = rand() % 101;
            }
            affichage(tint_tab1);
            inversion(tint_tab1);
            affichage(tint_tab1);
            break;
        case 2 :
            
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = rand() % 101;
                tint_tab2[i] = rand() % 101;
            } 
            somme(tint_tab1, tint_tab2, tint_tabS);
            affichage(tint_tab1);
            affichage(tint_tab2);
            affichage(tint_tabS);
            break;
        case 3 :
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = 0;
            }
            tint_tab1[0] = 10;
            tint_tab1[1] = -2;
            tint_tab1[2] = 12;
            printf("trasversale : %d\n", tranversable(tint_tab1));
            break;
        case 4 : 

            joueur = choixJoueur();
            affichageDebut(joueur);
            initialisation(matriceP);
            pionPlace = jouer(matriceP, joueur);
            gagner = aGagne(matriceP);
            tourDeJeu(matriceP, gagner, joueur);
            affichageP4(matriceP);

            break;
        default :
            break;
	}
}


