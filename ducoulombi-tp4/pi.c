/**
 * @file pi.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief 
 * 
 */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>


/// @brief fonction qui permet de rentrer un entier
/// @return le nombre saisie
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



/// @brief fonction disqueQuadrillage qui calcul pi
/// @param nbrPoint 
/// @return pi
float disqueQuadrillage(int nbrPoint)
{
    float x = 0;
    float y = 0;
    float resultat = 0;
    float cpt = 0;
    float cpt2 = 0;
    srand(time(NULL));
    for (int i = 0; i <= nbrPoint; i++)
    {
        x = (float)rand()/RAND_MAX;
        y = (float)rand()/RAND_MAX;
        resultat = sqrt(powf(x, 2)+powf(y, 2));

        if (resultat <= 1)
        {
            cpt++;
        }
        else
        {
            cpt2++;
        }
    }
    
    float pi = 0;
    pi = 4*(cpt/(cpt2+cpt));
    return(pi);
}

/// @brief fonction qui fait l'approximation de pi par la technique de Madhava de Sangamagrama
/// @param nbrIteration 
/// @return pi
float piSangamagrama(int nbrIteration)
{
    float f_pi = 0;
    float f_somme = 0;
    for (int i = 0; i <= nbrIteration; i++)
    {
        f_somme = f_somme + powf(-1, i)/(float)(2*i+1);
    }
    f_pi = 4 * f_somme;
    return (f_pi);   
}

/// @brief fonction qui fait l'approximation de pi par la technique de John Wallis
/// @param nbrIteration 
/// @return pi
float piWallis(int nbrIteration)
{
    float f_pi = 0;
    float f_multi = 1;
    for (int i = 1; i <= nbrIteration; i++)
    {
        f_multi = f_multi * (powf(2*i, 2) / (float)(powf(2*i, 2) - 1));
    }
    
    f_pi = 2 * f_multi;
    return (f_pi);
}