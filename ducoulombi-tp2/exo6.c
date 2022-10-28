/**
 * @file exo6.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fichier qui contient la fonction qui permet de verifier si le produit est negatif ou positif
 * 
 */
#include <stdio.h>


/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fonction qui verifie si le produit est negatif ou positif
 * 
 * @param argc 
 * @param argv 
 * @return retourne 0 si erreur, 1 sinon
 */
int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;
    int outA = 0;
    int outB = 0;
    printf("Veuillez rentrer votre premier nombre: \n");
    outA =  scanf("%d", &a);
    printf("Veuillez rentrer votre second nombre: \n");
    outB = scanf("%d", &b);
    
    if ((outA) && (outB))
    {
        if ((a>0 && b>0) || (a<0 && b<0))
        {
            printf("Le produit est positif\n");
        }
        else
        {
            printf("Le produit est négatif\n");
        }       
    }
    else
    {
        printf("Il y a une erreur de saisie\n");
    }
    return (0);
}