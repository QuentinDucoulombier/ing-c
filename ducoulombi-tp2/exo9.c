/**
 * @file exo9.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief 
 * 
 */
#include <stdio.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    int n = 0;
    printf("Veuillez votre valeur du debut du compte a rebours\n");
    int verif = scanf("%d", &n);
    if(verif)
    {
        printf("\n");
        while(n >= 0)
        {
            printf("%d\n", n);
            n--;
        }
    }
    else
    {
        printf("Erreur de saisie\n");
    }
    return (0);
    
}