/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief 
 * 
 */
#include "fonctions.h"
#include "codeCesar.h"

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    if(argc != 7)
    {
        fprintf(stderr, "Il manque %d arguments\n", 7 - argc);
        exit(EXIT_FAILURE);
    }
    else
    {
        if(strcmp(argv[2],"cesar") == 0)
        {
            /*Affichage de la chaine inital*/
            printf("Chaine intial: %s\n", argv[6]);
            /*Calcul du decalage*/
            long decalage = verifConversion(argv[4]);
            /*Affichage de la chaine final*/
            printf("Chaine final: %s\n", codeCesar(argv[6], decalage));
        }
        else if (strcmp(argv[2],"vigenere") == 0)
        {
            printf("Chaine intial: %s\n", argv[6]);
            printf("Chaine final: %s\n", codeDeVigenere(argv[6], argv[4]));
        }
    }

    return(0);
} 
