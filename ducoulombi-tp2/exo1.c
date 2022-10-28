/**
 * @file exo1.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fichier de l'exo1 du TP2
 * 
 */
#include <stdio.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief main du programme qui permet a l'utilisateur de rentrer puis d'afficher un entier
 * 
 * @param argc 
 * @param argv 
 * @return afficher l'entier saisis par l'utilisateur
 */
int main(int argc, char *argv[])
{
    int entier = 0;
    printf("Veuillez saisir un nombre\n");
    int out = scanf("%d", &entier);
    if (out) //verifie le scanf
    {
        printf("le nombre saisis est: %d\n", entier);
    }
    else
    {
        printf("Il y a une erreur de saisie\n");
    }
    return (0);
}