/**
 * @file fonctions.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief 
 * 
 */


#include "fonctions.h"


long verifConversion(char* chaine)
{
    char* endPtr;
    long taille = strtol(chaine, &endPtr, 10);
    if(endPtr == chaine)
    {
        fprintf(stderr, "Mauvais format: %s -- Valeur %ld\n", endPtr, taille);
        exit(EXIT_FAILURE);
    }
    else
    {
        return(taille);
    }
}