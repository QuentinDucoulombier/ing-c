/**
 * @file exo5.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief 
 * @todo verifier si c'est un int ou un float !!
 * 
 */
#include <stdio.h>


/**
 * @fn int main(int argc, char *argv)
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
    int d = 1;
    int outDeno = 0;
    int outNum = 0;
    printf("Veuillez saisir le numérateur: \n");
    outNum = scanf("%d", &n);
    printf("Veuillez saisir le denominateur: \n");
    outDeno = scanf("%d", &d);
    printf("Num: %d Deno %d\n", outNum, outDeno);
    if((outNum) && (outDeno))
    {
        if(d != 0)
        {
            printf("%d / %d = %f\n", n, d, (float)n/d);
        }
        else
        {
            printf("Division impossible\n");
        }
    }
    else
    {
        printf("Erreur de saisie\n");
    }
    return (0);
}