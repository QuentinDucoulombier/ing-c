#ifndef __fonctions_h_
#define __fonctions_h_

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Fonction pour les tableau*/

/**
 * @fn int* allouer(int int_taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @param int_taille 
 * @return int* 
 */
int* allouer(int int_taille);

/**
 * @fn void initialisation(int int_taille, int* pint_tab)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @param int_taille 
 * @param pint_tab 
 */
void initialisation(int int_taille, int* pint_tab);

/**
 * @fn void Affichage(int int_taille, int* pint_tab)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @param int_taille 
 * @param pint_tab 
 */
void affichage(int int_taille, int* pint_tab);

/**
 * void Liberer(int* pint_tab)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @param pint_tab 
 */
void liberer(int* pint_tab);




/*Reste des fonctions*/
/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-01
 * 
 * @brief 
 * 
 * @return int 
 */
int saisieEntier(void);

#endif