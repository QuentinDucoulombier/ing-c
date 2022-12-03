/**
 * @file fonctions.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier fonctions qui contient l'appel de l'ensemble des fonctions pour le tableau dynamique et pour saisir un entier
 * 
 */
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
 * @brief alloue le tableau
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
 * @brief initialise le tableau avec des valeurs random
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
 * @brief affiche le tableau
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
 * @brief libere le tableau
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
 * @brief fonction qui permet de rentrer un entier
 * 
 * @return int 
 */
int saisieEntier(void);

#endif