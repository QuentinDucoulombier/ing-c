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

/**
 * @fn float racineSmyrne(int nbrIteration);
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief approximation de la racine de 2 par la methode d'Edmund Halley
 * 
 * @param nbrIteration 
 * @return racine de 2
 */
float racineHalley(int nbrIteration);

/**
 * @fn float racineSmyrne(int nbrIteration);
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief approximation de la racine de 2 par la methode de Théon de Smyrne
 * 
 * @param nbrIteration 
 * @return float 
 */
float racineSmyrne(int nbrIteration);

#endif