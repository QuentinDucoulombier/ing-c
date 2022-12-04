/**
 * @file fonctions.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief 
 * 
 */
#ifndef __fonctions_h_
#define __fonctions_h_
#define M 20
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

void affichage(int tint_tab[M]);
void inversion(int tint_tab[M]);
void somme(int tin_tab1[M], int tin_tab2[M], int tin_tabSortie[M]);
int tranversable(int tint_tab[M]);
void saisieChar(char str_nom[M]);
int palindrome(char str_mot[M]);
void inversionChaine(char str_mot[M]);
int palindrome(char str[M]);
int saisieEntier(void);

#endif