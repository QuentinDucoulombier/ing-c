/**
 * @file racine2.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief ensemble de fonctions pour approximer racine de 2
 * 
 */
#ifndef __racine2_h_
#define __racine2_h_

/**
 * @fn float racineNewton(int nbrIteration);
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief approximation de la racine de 2 par la methode d'Isaac Newton
 * 
 * @param nbrIteration 
 * @return racine de 2 
 */
float racineNewton(int nbrIteration);


float racineHalley(int nbrIteration);


float racineSmyrne(int nbrIteration);

#endif