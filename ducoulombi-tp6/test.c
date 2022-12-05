/*
Le jeu de Puissance 4 se joue sur une grille carrée de N × N cases (N défini préalablement). Deux
joueurs s’affrontent. Ils doivent remplir chacun à leur tour une des colonnes de la grille par leur pion.
Les pions seront symbolisés par des lettres : O ou X. La grille est en position verticale, ce qui fait que les pièces "tombent" au plus bas de la grille.

Initialisation
Au tout début du jeu, les cases du plateau seront initialisées à -1, pour signifier qu’aucun joueur n’a joué. Implémenter la méthode d’initialisation :
void init (int ttint_plateau[N][N]);

Affichage
À chaque tour de jeu, le plateau sera affiché afin de visualiser l’avancement de la partie. Implémenter
la méthode affichage qui écrit ’X’ lorsque le joueur 1 a joué sur la case, ’O’ s’il s’agit du joueur 2, ou alors ’ ’ s’il n’y a personne.
void affichage (int ttint_plateau[N][N]);

Jouer
Les joueurs jouent tour à tour. Écrire une méthode jouer qui permet à un joueur donné de jouer dans
une colonne spécifique. Si la colonne est pleine, afficher un message d’erreur. La méthode retournera 1 si tout s’est bien passé, et 0 si une erreur est survenue.
int jouer(int ttint_plateau[N][N], int int_joueur, int int_x );

A gagné
À la fin de chaque tour de jeu, il faut vérifier si l’un des deux joueurs a gagné. Implémenter la fonction aGagne , qui retourne soit le numéro du joueur gagnant, soit 0 si c’est match nul, soit -1 si la partie n’est pas terminée.
int aGagne(int ttint_plateau[N][N]);

Tour de jeu
Écrire la méthode tourDeJeu qui permet de faire jouer les joueurs chacun leur tour, jusqu’à la fin de la partie. Lorsque la partie est finie, la grille complète devra être affichée, ainsi que le vainqueur. Lors d’une erreur de saisie de la part de l’utilisateur, le programme devra demander une nouvelle saisie, jusqu’à ce que l’utilisateur saisisse quelque chose de cohérent.
void tourDeJeu(int ttint_plateau[N][N]);

*/

#include <stdio.h>
#include <stdlib.h>

#define N 7

void init (int ttint_plateau[N][N]);
void affichage (int ttint_plateau[N][N]);
int jouer(int ttint_plateau[N][N], int int_joueur, int int_x );
int aGagne(int ttint_plateau[N][N]);
void tourDeJeu_rotation(int ttint_plateau[N][N]);

int main()
{
    int ttint_plateau[N][N];
    init(ttint_plateau);
    tourDeJeu_rotation(ttint_plateau);
    return 0;
}

void init (int ttint_plateau[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            ttint_plateau[i][j] = -1;
        }
    }
}

void affichage (int ttint_plateau[N][N])
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
    while(ttint_plateau[i][int_x] != -1 && i>-1)
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
    int i, j, k, l;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(ttint_plateau[i][j] != -1)
            {
                if(i<N-3)
                {
                    if(ttint_plateau[i][j] == ttint_plateau[i+1][j] && ttint_plateau[i][j] == ttint_plateau[i+2][j] && ttint_plateau[i][j] == ttint_plateau[i+3][j])
                    {
                        return ttint_plateau[i][j];
                    }
                }
                if(j<N-3)
                {
                    if(ttint_plateau[i][j] == ttint_plateau[i][j+1] && ttint_plateau[i][j] == ttint_plateau[i][j+2] && ttint_plateau[i][j] == ttint_plateau[i][j+3])
                    {
                        return ttint_plateau[i][j];
                    }
                }
                if(i<N-3 && j<N-3)
                {
                    if(ttint_plateau[i][j] == ttint_plateau[i+1][j+1] && ttint_plateau[i][j] == ttint_plateau[i+2][j+2] && ttint_plateau[i][j] == ttint_plateau[i+3][j+3])
                    {
                        return ttint_plateau[i][j];
                    }
                }
                if(i<N-3 && j>2)
                {
                    if(ttint_plateau[i][j] == ttint_plateau[i+1][j-1] && ttint_plateau[i][j] == ttint_plateau[i+2][j-2] && ttint_plateau[i][j] == ttint_plateau[i+3][j-3])
                    {
                        return ttint_plateau[i][j];
                    }
                }
            }
        }
    }
    for(k=0; k<N; k++)
    {
        for(l=0; l<N; l++)
        {
            if(ttint_plateau[k][l] == -1)
            {
                return -1;
            }
        }
    }
    return -2;
}


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
}

void tourDeJeu_rotation(int ttint_plateau[N][N])
{
    int int_joueur = 0;
    int int_x;
    int int_gagne;
    int int_rotation;
    while(aGagne(ttint_plateau) == -1)
    {
        affichage(ttint_plateau);
        printf("Joueur %d, entrez une colonne : ", int_joueur+1);
        scanf("%d", &int_x);
        while(jouer(ttint_plateau, int_joueur, int_x) == 0)
        {
            printf("Joueur %d, entrez une colonne : ", int_joueur+1);
            scanf("%d", &int_x);
        }
        printf("Joueur %d, entrez le nombre de rotation : ", int_joueur+1);
        scanf("%d", &int_rotation);
        for(int i=0; i<int_rotation; i++)
        {
            rotation_gravite(ttint_plateau);
        }
        int_joueur = (int_joueur+1)%2;
    }
    affichage(ttint_plateau);
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

/*
void tourDeJeu(int ttint_plateau[N][N])
{
    int int_joueur = 0;
    int int_x;
    int int_gagne;
    while(aGagne(ttint_plateau) == -1)
    {
        affichage(ttint_plateau);
        printf("Joueur %d, entrez une colonne : ", int_joueur+1);
        scanf("%d", &int_x);
        while(jouer(ttint_plateau, int_joueur, int_x) == 0)
        {
            printf("Joueur %d, entrez une colonne : ", int_joueur+1);
            scanf("%d", &int_x);
        }
        printf("joueur %d\n", int_joueur);
        int_joueur = (int_joueur + 1)%2;
    }
    affichage(ttint_plateau);
    int_gagne = aGagne(ttint_plateau);
    printf("a gagne %d\n", int_gagne);
    if(int_gagne == -2)
    {
        printf("Match nul\n");
    }
    else
    {
        printf("Le joueur %d a gagne\n", int_gagne+1);
    }
}*/