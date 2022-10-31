/**
 * @file exo5.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fichier qui contient l'ensembles des fonctions pour verifier la compatibilité des variables et effectuer une division euclidienne
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn int verifIntOuFloat(char nombre[50])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-30
 * 
 * @brief fonction qui verifie si c'est un float ou un reel
 * 
 * @param nombre 
 * @return un booleen Vrai si c'est un reel 0 sinon
 */
int verifIntOuFloat(char nombre[50])
{
    int reel = 0; //booléen initialisé a faux
    int i = 0; //compteur
    //parcoure tt le nombre ou s'arrete au point
    while((i < 50) || (nombre[i] != '.')) 
    {
        //verifie si la chaine de caractere(nombre) contient un point
        if (nombre[i] == '.')
        {
            reel = 1;
        }
        i++;
    }
    return reel;
}





/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fonction MAIN qui affiche et verifie la compatibilté de la division euclidienne
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur, 1 sinon
 */
int main(int argc, char *argv[])
{
    //numérateur et denominateur en chaine de caractere pour verifier si c'est un entier ou un reel
    char n[50]; 
    char d[50];
    //sortie du scanf
    int outDeno = 0;
    int outNum = 0;
    printf("Veuillez saisir le numérateur: \n");
    outNum = scanf("%s", n);
    printf("Veuillez saisir le denominateur: \n");
    outDeno = scanf("%s", d);
    //verifie si le scanf n'a pas eu d'erreur et si le nombre rentré est bien un entier
    if((outNum) && (outDeno) && (!verifIntOuFloat(n)) && (!verifIntOuFloat(d)))
    {
        //transforme la chaine de caractere en int grace a la fonction atoi disponible dans la bibliotheque string.h (https://man7.org/linux/man-pages/man3/atoi.3.html)
        int deno = atoi(d); 
        int num = atoi(n);
        //verifie si le denominateur est different de 0
        if(deno != 0)
        {
            printf("%d / %d = %f\n", num, deno, (float)num/deno); //effectue la division et l'affiche
        }
        else
        {
            printf("Division impossible\n"); //sinon affiche une erreur
        }
    }
    else
    {
        printf("Erreur de saisie\n");
    }
    return (0);
}