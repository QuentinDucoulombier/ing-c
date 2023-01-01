/**
 * @file listes.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief Fichier d'appel de l'ensemble de fonctions qui permet l'utilisation des listes
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
 * @brief procedure qui permet d'ajouter une carte a une certaine position dans une liste (paquet)
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
 * @brief procedure qui permet d'ajouter une carte au debut d'une liste (paquet)
 * 
 * @param l 
 * @param element 
 */
void ajouterDebut(paquet* l, carte element);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief fonction qui permet de supprimer une carte a la fin d'une liste (paquet)
 * 
 * @param l 
 * @return la carte supprimer
 */
carte supprimerDebut(paquet* l);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief procedure qui compte le nombre de carte dans le paquet
 * 
 * @param p 
 */
void compter(paquet p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-24
 * 
 * @brief procedure qui permet d'ajouter une carte a la fin d'une liste (paquet)
 * 
 */
void ajouterFin(paquet* l, carte element);

#endif