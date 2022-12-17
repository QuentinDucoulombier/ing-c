/**
 * @file codeCesar.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief 
 * 
 */

#ifndef __codeCesar_h_
#define __codeCesar_h_


/**
 * @fn char *codeCesar(char *str, int decalage)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief 
 * 
 * @param str 
 * @param decalage 
 * @return char* 
 */
char *codeCesar(char *str, int decalage);

/**
 * @fn char* codeDeVigenere(char* str, char* key)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief 
 * 
 * @param str 
 * @param key 
 * @return char* 
 */
char* codeDeVigenere(char* str, char* key);

/**
 * @fn char* codeDeScytale(char* message)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-17
 * 
 * @brief 
 * 
 */
char* codeDeScytale(char* message);

#endif