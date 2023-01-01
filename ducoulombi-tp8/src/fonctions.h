/**
 * @file fonctions.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief ensemble des appels de fonctions des fichiers de fonction
 * 
 */
#ifndef __fonctions_h_
#define __fonctions_h_

/*Toutes les bibliotheques necessaire*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "codage.h"

/**
 * @fn long verifConversion(char* chaine)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief permet de verifier si la conversion est bien passé
 * 
 * @param chaine 
 * @return une erreur si la conversion ne marche pas, sinon la conversion 
 */
long verifConversion(char* chaine);

/**
 * @fn void liberer(char* str)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-20
 * 
 * @brief fonction pour liberer la chaine de caractere
 * 
 * @param str 
 */
void liberer(char* str);

/**
 * @fn char* get_input()
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief Get the input object
 * 
 * @return char* 
 */
char* get_input();



/**
 * @fn long saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief permet de saisir un long
 * 
 * @return long 
 */
long saisieEntier(void);

#endif