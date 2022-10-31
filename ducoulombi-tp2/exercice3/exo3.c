/**
 * @file exo3.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-30
 * 
 * @brief Copie du fichier exo1.c
 * 
 */
#include <stdio.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 2
 * @date 2022-10-30
 * 
 * @brief main du programme qui permet a l'utilisateur de rentrer puis d'afficher deux entiers
 * 
 * @param argc 
 * @param argv 
  * @return affiche les entiers saisies par l'utilisateur
 */
int main(int argc, char *argv[])
{
    int entier1 = 0;
    int entier2 = 0;
    printf("Veuillez saisir le premier entier\n");
    int out1 = scanf("%d", &entier1);
    printf("Veuillez saisir le deuxieme entier\n");
    int out2 = scanf("%d", &entier2);
    //On verifie le scanf
    if ((out1) && (out2))
    {
        printf("les nombre saisis sont: %d et %d\n", entier1, entier2);
    }
    else
    {
        printf("Il y a une erreur de saisie\n");
    }
    return (0);
}