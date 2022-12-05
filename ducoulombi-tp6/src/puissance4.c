/**
 * @file puissance4.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief 
 * 
 */

#include "puissance4.h"
#include "fonctions.h"


void initialisation(int tint_tab[LIGNES][COLONNES])
{
    for (int i = 0; i < LIGNES; i++)
    {
        for (int j = 0; j < COLONNES; j++)
        {
            tint_tab[i][j]=-1;
        }
        
    }
}



void affichageP4 (int tint_tab[LIGNES][COLONNES])
{
    for (int i = 0; i < LIGNES; i++)
    {
        printf("| ");
        for (int j = 0; j < COLONNES; j++)
        {
            if (tint_tab[i][j]==-1)
            printf("  | ");
            if (tint_tab[i][j]==1)  
            printf("\033[0;31mX\033[0m | ");
            if (tint_tab[i][j]==2)
            printf("\033[0;34mO\033[0m | ");
        }
        printf("\n");
    }
    
}



int choixJoueur(void)
{
    int joueur = -1;
    do
    {
        printf("Quel joueur commence ? (1 ou 2): \n");
        joueur = saisieEntier();
    } while ((joueur < 1) || (joueur > 2));

    return(joueur);
}

void affichageDebut(int joueur)
{
    if (joueur == 1)
    {
        printf("Le joueur 1 commence !, son symbole sera X");
    }
    else
    {
        printf("Le joueur 2 commence !, son symbole sera O");
    }
    printf("\n\n");


    printf("-------------------------------------\n");
    printf("-------------Debut du jeu------------\n");
    printf("-------------------------------------\n\n");
}


int aGagne(int tint_tab[LIGNES][COLONNES])
{
    
    int gagnant = -1;


    /*LIGNES*/
    for (int i = 0; i < LIGNES; i++)
    {
        for (int j = 0; j < COLONNES-3; j++)
        {
            if ((tint_tab[i][j] != -1) && (tint_tab[i][j] == tint_tab[i][j+1]) && (tint_tab[i][j] == tint_tab[i][j+2]) && (tint_tab[i][j] == tint_tab[i][j+3]))
            {
                gagnant = tint_tab[i][j];
            }
        }       
    }


    /*COLONNES*/
    for (int j = 0; j < COLONNES; j++)
    {
        for (int i = 0; i < LIGNES-3; i++)
        {
            if ((tint_tab[i][j] != -1) && (tint_tab[i][j] == tint_tab[i+1][j]) && (tint_tab[i][j] == tint_tab[i+2][j]) && (tint_tab[i][j] == tint_tab[i+3][j]))
            {
                gagnant = tint_tab[i][j];
            }
        } 
    }

    /*Diagonale 1*/

    for (int i = 0; i < LIGNES-3; i++)
    {
        for (int j = 0; j < COLONNES-3; j++)
        {
            if ((tint_tab[i][j] != -1) && (tint_tab[i][j] == tint_tab[i+1][j+1]) && (tint_tab[i][j] == tint_tab[i+2][j+2]) && (tint_tab[i][j] == tint_tab[i+3][j+3]))
            {
                gagnant = tint_tab[i][j];
            } 
        }

    }

    /*Diagonale 2*/

    for (int i = 0; i < LIGNES-3; i++)
    {
        for (int j = 0; j < COLONNES; j++)
        {
            if ((tint_tab[i][j] != -1) && (tint_tab[i][j] == tint_tab[i+1][j-1]) && (tint_tab[i][j] == tint_tab[i+2][j-2]) && (tint_tab[i][j] == tint_tab[i+3][j-3]))
            {
                gagnant = tint_tab[i][j];
            }
        }

    }
    
    if ((gagnant == 1) || (gagnant == 2))
    {
        printf("le gagnant est le joueur %d\n", gagnant);
    }



    return(gagnant);

}

void tourDeJeu(int tint_tab[LIGNES][COLONNES], int gagnant, int joueur)
{

    int max=LIGNES*COLONNES;
    printf("max %d\n", max);
    int compteur = 0;
    
    

    while ((gagnant == -1) || (compteur == max))
    {
        aGagne(tint_tab);
        printf("---------------------------------------\n\n");
        if (joueur == 1)
        {
            printf("C'est au tour du joueur 2\n\n");
            jouer(tint_tab, 2);
            gagnant = aGagne(tint_tab);
            printf("---------------------------------------\n\n");
            printf("C'est au tour du joueur %d\n\n", joueur);
            jouer(tint_tab, joueur);
            gagnant = aGagne(tint_tab);
            
        }
        else
        {
            printf("C'est au tour du joueur 1\n\n");
            jouer(tint_tab, 1);
            gagnant = aGagne(tint_tab);
            printf("---------------------------------------\n\n");
            printf("C'est au tour du joueur %d\n\n", joueur);
            jouer(tint_tab, joueur);
            gagnant = aGagne(tint_tab);
        }
        compteur+=2;

    }

    if(compteur == max)
    {
        printf("il y a match nul\n");
    }
    

}

int jouer(int tint_plateau[LIGNES][COLONNES], int joueur)
{
    int ligneLocal;
    int colonneLocal;
    int chiffreRetourner = 0;
   
    affichageP4(tint_plateau);
    printf("\n");
    
    printf("Veuillez saisir la colonne : ");
    colonneLocal = saisieEntier();
    while ((colonneLocal < 0) || (colonneLocal > COLONNES-1)){
        printf("Colonne invalide : ");
        colonneLocal = saisieEntier();
    }
    printf("\n");

    ligneLocal = LIGNES-1;

    if (tint_plateau[0][colonneLocal] != -1)
    {
        printf ("Cette colonne est pleine (tu passes donc ton tour !)\n");
        chiffreRetourner = 0;
    }
    else
    {
        while ((tint_plateau[ligneLocal][colonneLocal] == 1) || (tint_plateau[ligneLocal][colonneLocal] == 2))
        {
            if (ligneLocal >= 0)
            {
                ligneLocal = ligneLocal-1;
            }
        }
        tint_plateau[ligneLocal][colonneLocal]= joueur;
        chiffreRetourner = 1;
    
    }
    
    return(chiffreRetourner);
}