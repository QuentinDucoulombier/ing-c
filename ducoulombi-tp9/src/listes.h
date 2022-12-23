/**
 * @file listes.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 */

#ifndef __LISTES_H_
#define __LISTES_H_

#include "jeu.h"
#include "affichage.h"

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param l 
 * @param valeur 
 * @param chiffreC 
 * @param coul 
 * @param pos 
 */
void ajouterPos(paquet* l, int valeur, chiffreCarte chiffreC, eCouleur coul, int pos);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param l 
 * @param element 
 */
void AjouterDebut(paquet* l, carte element);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param l 
 * @return carte 
 */
carte supprimerDebut(paquet* l);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param p 
 */
void Compter(paquet p);

#endif