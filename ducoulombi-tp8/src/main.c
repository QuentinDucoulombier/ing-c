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

int main(int argc, char *argv[])
{
    if(argc != 7)
    {
        fprintf(stderr, "Il manque %d arguments\n", 7 - argc);
        exit(EXIT_FAILURE);
    }
    else
    {
        /*for (int i = 0; i < argc; i++)
        {
            printf("%d -> %s\n", i, argv[i]);
        }
        */

        if(strcmp(argv[2],"cesar") == 0)
        {
            /*Affichage de la chaine inital*/
            printf("Chaine intial: %s\n", argv[6]);
            /*Calcul du decalage*/
            long decalage = verifConversion(argv[4]);

            /*Initialisation de la chaine final
            //char chaineFinal[strlen(argv[6])];
            Lancement du codeCesar
            //codeCesar(decalage, argv[6], chaineFinal);*/

            /*Affichage de la chaine encryptée*/
            //printf("chaine final: %s\n", chaineFinal);
            printf("Chaine final: %s\n", codeCesar(argv[6], decalage));
        }
        else if (strcmp(argv[2],"cesar") == 0)
        {
            /* code */
            
        }
        
    }


    /*
    printf("%s\n", argv[1]);
    char* line;
    size_t nb1;
    int nb2;

    printf("%d \n", (int)nb1);
    line = NULL;
    nb2 = getline(&line, &nb1, stdin);
    printf("%d \t %d \t %s \n", (int)nb1, nb2, line);*/
    
    return(0);
} 
