/**
 * @file racine2.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// @brief approximation de la racine de 2 par la methode d'Isaac Newton
/// @param nbrIteration 
/// @return racine de 2
float racineNewton(int nbrIteration)
{
    float float_racine = 1;
    for (int i = 0; i <= nbrIteration; i++)
    {
        float_racine = (float_racine / 2.0) + 1 / float_racine;
    }
    return (float_racine);
}

/// @brief 
/// @param nbrIteration 
/// @return 
float racineHalley(int nbrIteration)
{
    float float_racine = 1;
    for (int i = 1; i <= nbrIteration; i++)
    {
        float_racine = float_racine * ((powf(float_racine, 2) + 6.0)/(3 * powf(float_racine, 2) + 2.0));
    }
    return (float_racine);
}

/// @brief 
/// @param nbrIteration 
/// @return 
float racineSmyrne(int nbrIteration)
{
    float float_racine = 1;
    float float_suitep = 1;
    float float_suiteq = 1;
    float float_suitepTemp = 1;
    float float_suiteqTemp = 1;

    for (int i = 1; i <= nbrIteration; i++)
    {
        float_suitepTemp = float_suitep + 2*float_suiteq;
        float_suiteqTemp = float_suiteq + float_suitep;

        float_suitep = float_suitepTemp;
        float_suiteq = float_suiteqTemp;
    }
    float_racine = float_suitep / float_suiteq;
    return(float_racine);
}
