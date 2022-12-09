/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 */

#include "jeu.h"

void melange(carte *paquet)
{
    int i, j;
    carte temp;
    srand(time(NULL));
    for(i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = paquet[i];
        paquet[i] = paquet[j];
        paquet[j] = temp;
    }
}

void donneCarte(carte *paquet, joueur* joueur)
{
    joueur->carte = paquet[0];
    paquet++;
}