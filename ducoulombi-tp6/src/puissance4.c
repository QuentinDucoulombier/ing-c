/**
 * @file puissance4.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief fichier avec les fonctions pour le puissance 4
 * 
 */

#include "puissance4.h"

void init(int ttint_plateau[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            ttint_plateau[i][j] = -1;
        }
    }
}

void affichageP4(int ttint_plateau[N][N])
{
    for(int i=0; i<N; i++)
    {
        printf("| ");
        for(int j=0; j<N; j++)
        {
            if(ttint_plateau[i][j] == -1)
            {
                printf("  | ");
            }
            else if(ttint_plateau[i][j] == 0)
            {
                printf("\033[0;31mX\033[0m | ");
            }
            else if(ttint_plateau[i][j] == 1)
            {
                printf("\033[0;34mO\033[0m | ");
            }
        }
        printf("\n");
    }
}

int jouer(int ttint_plateau[N][N], int int_joueur, int int_x )
{
    int i = N;
    while((ttint_plateau[i][int_x] != -1) && (i>-1))
    {
        i--;
    }
    if(i == -1)
    {
        printf("Erreur, colonne pleine\n");
        return 0;
    }
    else
    {
        ttint_plateau[i][int_x] = int_joueur;
        return 1;
    }
}

int aGagne(int ttint_plateau[N][N])
{
    /*LIGNES*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N-3; j++)
        {
            if ((ttint_plateau[i][j] != -1) && (ttint_plateau[i][j] == ttint_plateau[i][j+1]) && (ttint_plateau[i][j] == ttint_plateau[i][j+2]) && (ttint_plateau[i][j] == ttint_plateau[i][j+3]))
            {
                return(ttint_plateau[i][j]);
            }
        }       
    }


    /*COLONNES*/
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N-3; i++)
        {
            if ((ttint_plateau[i][j] != -1) && (ttint_plateau[i][j] == ttint_plateau[i+1][j]) && (ttint_plateau[i][j] == ttint_plateau[i+2][j]) && (ttint_plateau[i][j] == ttint_plateau[i+3][j]))
            {
                return(ttint_plateau[i][j]);
            }
        } 
    }

    /*Diagonale 1*/
    for (int i = 0; i < N-3; i++)
    {
        for (int j = 0; j < N-3; j++)
        {
            if ((ttint_plateau[i][j] != -1) && (ttint_plateau[i][j] == ttint_plateau[i+1][j+1]) && (ttint_plateau[i][j] == ttint_plateau[i+2][j+2]) && (ttint_plateau[i][j] == ttint_plateau[i+3][j+3]))
            {
                return(ttint_plateau[i][j]);
            } 
        }

    }

    /*Diagonale 2*/
    for (int i = 0; i < N-3; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            if ((ttint_plateau[i][j] != -1) && (ttint_plateau[i][j] == ttint_plateau[i+1][j-1]) && (ttint_plateau[i][j] == ttint_plateau[i+2][j-2]) && (ttint_plateau[i][j] == ttint_plateau[i+3][j-3]))
            {
                return(ttint_plateau[i][j]);
            }
        }

    }
    for(int k = 0; k < N; k++)
    {
        for(int l = 0; l < N; l++)
        {
            if(ttint_plateau[k][l] == -1)
            {
                return -1;
            }
        }
    }
    return -2;
}

/*
void rotation_gravite(int ttint_plateau[N][N])
{
    int ttint_plateau_rotation[N][N];
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            ttint_plateau_rotation[i][j] = ttint_plateau[N-j-1][i];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            ttint_plateau[i][j] = ttint_plateau_rotation[i][j];
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(ttint_plateau[i][j] != -1)
            {
                int k = i;
                while(ttint_plateau[k+1][j] == -1 && k<N-1)
                {
                    ttint_plateau[k+1][j] = ttint_plateau[k][j];
                    ttint_plateau[k][j] = -1;
                    k++;
                }
            }
        }
    }
}*/

void tourDeJeu_rotation(int ttint_plateau[N][N])
{
    int int_joueur = 0;
    int int_x;
    int int_gagne;
    //int int_rotation;
    while(aGagne(ttint_plateau) == -1)
    {
        affichageP4(ttint_plateau);
        printf("Joueur %d, entrez une colonne : ", int_joueur+1);
        int_x = saisieEntier();
        while ((int_x <0) || (int_x > N - 1))
        {
            printf("\033[0;31mColonne invalide !\033[0m\n");
            printf("Joueur %d, entrez une colonne : ", int_joueur+1);
            int_x = saisieEntier();
        }
        while((jouer(ttint_plateau, int_joueur, int_x) == 0))
        {
            printf("Joueur %d, entrez une colonne : ", int_joueur+1);
            int_x = saisieEntier();
        }
        /*Cas ou on veut la rotation*/
        /*printf("Joueur %d, entrez le nombre de rotation : ", int_joueur+1);
        int_rotation = saisieEntier();
        for(int i=0; i<int_rotation; i++)
        {
            rotation_gravite(ttint_plateau);
        }*/
        int_joueur = (int_joueur+1)%2;
    }
    affichageP4(ttint_plateau);
    int_gagne = aGagne(ttint_plateau);
    if(int_gagne == -2)
    {
        printf("Match nul\n");
    }
    else
    {
        printf("Le joueur %d a gagne\n", int_gagne+1);
    }
}
