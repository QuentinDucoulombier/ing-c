/**
 * @file pi.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief 
 * 
 */
#ifndef __pi_h_
#define __pi_h_

/**
 * @fn float disqueQuadrillage(int nbrPoint);
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief fonction qui permet d'approximer pi grace a l'aire d'un disque par quadrillage 
 * 
 * @param nbrPoint 
 * @return pi 
 */
float disqueQuadrillage(int nbrPoint);

/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 3
 * @date 2022-11-16
 * 
 * @brief fonction qui permet de saisir un entier
 * 
 */
int saisieEntier(void);

/**
 * @fn float piSangamagrama(int nbrIteration)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief fonction qui fait l'approximation de pi par la technique de Madhava de Sangamagrama
 * 
 * @param nbrIteration 
 * @return pi
 */
float piSangamagrama(int nbrIteration);

/**
 * @fn float piWallis(int nbrIteration)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief fonction qui fait l'approximation de pi par la technique de John Wallis
 * 
 * @param nbrIteration 
 * @return pi
 */
float piWallis(int nbrIteration);


#endif