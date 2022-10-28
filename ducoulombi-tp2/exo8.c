/**
 * @file exo8.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fichier pour faire un compte a rebours
 * 
 */
#include <stdio.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fonction Main, qui fait un compte a rebours (avec un for)
 * 
 * @param argc 
 * @param argv 
 * @return return 0 si aucun probleme
 */
int main(int argc, char *argv[])
{
    int n = 0;
    printf("Veuillez votre valeur du debut du compte a rebours\n");
    int verif = scanf("%d", &n);
    if(verif)
    {
        printf("\n");
        for (int i = n; i >= 0; i--) 
        {
            printf("%d\n", i);
        }
    }
    else
    {
        printf("Erreur de saisie\n");
    }
    return (0);
    
}