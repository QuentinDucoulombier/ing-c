/**
 * @file menu.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier qui contient l'ensemble des appels des fonctions et procedure a l'affiche, la saisie et le resultat du menu
 * 
 */
#ifndef __menu_h_
#define __menu_h_

/**
 * @fn int affichageMenu(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief affiche et permet de choisir le menu
 * 
 * @return le choix de l'utilisateur
 */
int affichageMenu(void);

/**
 * @fn void caseMenu(int int_choix, int* tableau, int taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fonction qui affiche le resultat en fonction du choix de l'utilisateur
 * 
 * @param int_choix 
 * @param tableau 
 * @param taille 
 */
void caseMenu(int int_choix, int* tableau, int taille);

#endif