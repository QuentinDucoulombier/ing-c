/**
 * @file fonctions.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief ensemble des appel de fonctions du fichier fonctions.c
 * 
 */
#ifndef __fonctions_h_
#define __fonctions_h_
#define M 20
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

/**
 * @fn void affichage(int tint_tab[M])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief Affiche un tableau de taille M
 * 
 * @param tint_tab 
 */
void affichage(int tint_tab[M]);

/**
 * @fn void inversion(int tint_tab[M])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief Inverse un tableau d'entier
 * 
 * @param tint_tab 
 */
void inversion(int tint_tab[M]);

/**
 * @fn void somme(int tin_tab1[M], int tin_tab2[M], int tin_tabSortie[M])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief calcul la somme de deux tableaux d'entier et le ressort dans un tableauSortie
 * 
 * @param tin_tab1 
 * @param tin_tab2 
 * @param tin_tabSortie 
 */
void somme(int tin_tab1[M], int tin_tab2[M], int tin_tabSortie[M]);

/**
 * @fn int tranversable(int tint_tab[M])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief verifie si un tableau est transversable
 * 
 * @param tint_tab 
 * @return un booléen => 1 si transversable, 0 sinon
 */
int tranversable(int tint_tab[M]);

/**
 * @fn int palindrome(char str_chaine[M])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief verifie si c'est un string est un palindrome
 * 
 * @param str_mot 
 * @return un booléen => 1 si palindrome, 0 sinon
 */
int palindrome(char str_chaine[M]);

/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief permet de saisir un entier
 * 
 * @return l'entier
 */
int saisieEntier(void);

#endif