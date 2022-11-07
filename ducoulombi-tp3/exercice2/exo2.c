/**
 * @file exo2.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fichier pour l'exo Portée d'une variable
 * 
 */
#include <stdio.h> 
#include <stdlib.h>

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
 * @fn void bidon(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction bidon qui permet juste de comparer avec le main
 * 
 */
void bidon(void)
{
    //pas initialisé volontairement (donc warning)
    int int_n; 
    printf("n bidon avant: %d\n", int_n);
    int_n = saisieEntier();
    printf("n bidon apres: %d\n", int_n);
}

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction main qui permet de comparer la difference entre une fonction et le main dans les nom de variable
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    //pas initialisé volontairement (donc warning)
    int int_n;
    printf("n main avant: %d\n", int_n);
    int_n = saisieEntier();
    printf("n main apres: %d\n", int_n);
    bidon();
     //"n main apres bidon" est egale "n main apres" car meme "int_n"
    printf("n main apres bidon: %d\n", int_n);
    return (0);
}
