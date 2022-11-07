/**
 * @file exo1.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fichier de saisie d'entier
 * 
 */
#include <stdio.h> 
#include <stdlib.h> //pour utiliser exit

/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction de saisie d'entier
 * 
 * @return le nombre saisie si pas d'erreur, on quitte le programme avec exit dans le cas inverse
 */
int saisieEntier(void)
{
    int int_n = 0;
    printf("Veuillez saisir un entier: ");
    int int_outScan = scanf("%d", &int_n);
    if(int_outScan)
    {
        return(int_n);
    }
    else
    {
        fprintf(stderr, "Entree incorrecte\n");
        //On nous a expliqué que l'on pouvait aussi utilisé exit Failure
        exit(EXIT_FAILURE);
    }
}

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction main qui appel et affiche la saise d'entier
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    int int_nb = saisieEntier();
    printf("%d\n", int_nb);
    return (0);
}
