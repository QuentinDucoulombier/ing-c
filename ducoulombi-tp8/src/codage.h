/**
 * @file codage.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-20
 * 
 * @brief ensemble des fonctions pour encoder des chaine de caractere
 * 
 */

#ifndef __codage_h_
#define __codage_h_


/**
 * @fn char *codeCesar(char *str, int decalage)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief fonction pour encrypté selon le code cesar
 * 
 * @param str 
 * @param decalage 
 * @return la chaine encrypté
 */
char *codeCesar(char *str, int decalage);

/**
 * @fn char* codeDeVigenere(char* str, char* key)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief fonction pour encrypté selon le code de vigenere
 * 
 * @param str 
 * @param key 
 * @return la chaine encrypté
 */
char* codeDeVigenere(char* str, char* key);

/**
 * @fn char* codeDeScytale(char* message)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-20
 * 
 * @brief fonction pour encrypté selon le codage de scytale
 * 
 * @param message 
 * @return la chaine encrypté
 */
char* codeDeScytale(char* message);

#endif