/**
 * @file menu.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief ensemble d'appel de fonctions pour le menu
 * 
 */
#ifndef __menu_h_
#define __menu_h_

/**
 * @fn int affichageMenu(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief fonction qui affiche le menu et retourne le choix
 * 
 * @return retourne le choix de l'utilisateur
 */
int affichageMenu(void);

/**
 * @fn void caseMenu(int int_choix)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief effectue le menu en fonction du choix
 * 
 * @param int_choix 
 */
void caseMenu(int int_choix);


#endif
