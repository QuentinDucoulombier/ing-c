/**
 * @file fonctions.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief fichier pour les fonctions
 * 
 */


#include "fonctions.h"


long verifConversion(char* chaine)
{
    char* endPtr;
    /*Convertit la chaine en long*/
    long taille = strtol(chaine, &endPtr, 10);
    /*Verifie le format*/
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


void liberer(char* str)
{

    free(str);
    str = NULL;
}