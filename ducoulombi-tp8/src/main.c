/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief fichier de la fonction main
 * 
 */
#include "fonctions.h"
#include "codage.h"

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief fonction main
 * 
 * @param argc 
 * @param argv 
 * @return  si pas d'erreur
 */
int main(int argc, char *argv[])
{
    if((argc != 7) && ((strcmp(argv[2],"scytale") != 0)))
    {
        fprintf(stderr, "Il manque %d arguments\n", 7 - argc);
        printf("--------Exemple de formule---------\n");
        printf("Pour le code cesar: ./exe -c cesar -d 5 \"Bonjour les tekiens\"\n");
        printf("Pour le code de vigenere: ./exe -c vigenere -k \"cle\" -m \"message\"\n");
        printf("Pour le codage de scytale: ./exe -c scytale -m \"message a encrypte\"\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        char* chaineCoder = NULL;
        if(strcmp(argv[2],"cesar") == 0)
        {
            /*Affichage de la chaine inital*/
            printf("Chaine intial: %s\n", argv[6]);
            /*Calcul du decalage*/
            long decalage = verifConversion(argv[4]);
            /*Affichage de la chaine final*/
            chaineCoder = codeCesar(argv[6], decalage);
            printf("Chaine final: %s\n", chaineCoder);
            liberer(chaineCoder);
        }
        else if (strcmp(argv[2],"vigenere") == 0)
        {
            printf("Chaine intial: %s\n", argv[6]);
            chaineCoder = codeDeVigenere(argv[6], argv[4]);
            printf("Chaine final: %s\n", chaineCoder);
            liberer(chaineCoder);
        }
        else if (strcmp(argv[2],"scytale") == 0)
        {
            printf("Chaine intial: %s\n", argv[4]);
            chaineCoder = codeDeScytale(argv[4]);
            printf("Chaine final: %s\n", chaineCoder);
            liberer(chaineCoder);
        }
    }
    return(0);
} 
