/**
 * @file tri.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 */
#include "tri.h"
#include "fonctions.h"


/*-----------------*/
/*Tri par insertion*/
/*-----------------*/

/// @brief 
/// @param pint_tab 
/// @param int_taille 
void triInsertion(int* pint_tab, int int_taille)
{
    int int_elementInsere;

    int j;
    for (int i = 1; i < int_taille; i++)
    {
        int_elementInsere = pint_tab[i];

        for (j = i; j > 0 && pint_tab[j - 1] > int_elementInsere; j--)
        {
            pint_tab[j] = pint_tab[j - 1];
        }
        pint_tab[j] = int_elementInsere;
    }
}


/*----------*/
/*Tri fusion*/
/*----------*/

/// @brief 
/// @param src 
/// @param debut 
/// @param fin 
/// @return 
int* copierSousTableau(int* src, int debut, int fin)
{
    int* tabDest;
    tabDest = allouer(fin - debut);
    for (int i = debut; i < fin ; i++)
    {
        tabDest[i - debut] = src[i];
    }
    return tabDest;    
}

/// @brief 
/// @param tab1 
/// @param taille1 
/// @param tab2 
/// @param taille2 
/// @param tabRes 
void fusion(int* tab1, int taille1, int* tab2, int taille2, int* tabRes) 
{
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;
  while (i < taille1 && j < taille2) {
    if (tab1[i] < tab2[j]) {
      tabRes[k++] = tab1[i++];
    } else {
      tabRes[k++] = tab2[j++];
    }
  }
  while (i < taille1) {
    tabRes[k++] = tab1[i++];
  }
  while (j < taille2) {
    tabRes[k++] = tab2[j++];
  }
}

/// @brief 
/// @param tab 
/// @param taille 
void triFusion(int* tab, int taille) 
{
  if (taille <= 1) 
  {
    return;
  }
  int milieu = taille / 2;
  int* tab1 = copierSousTableau(tab, 0, milieu);
  int* tab2 = copierSousTableau(tab, milieu, taille);
  triFusion(tab1, milieu);
  triFusion(tab2, taille - milieu);
  fusion(tab1, milieu, tab2, taille - milieu, tab);
  liberer(tab1);
  liberer(tab2);
}

/// @brief 
/// @param tab 
/// @param taille 
/// @param min 
/// @param max 
void minMaxTableau(int* tab, int taille, int* min, int* max) 
{
  *min = tab[0];
  *max = tab[0];
  for (int i = 1; i < taille; i++) {
    if (tab[i] < *min) {
      *min = tab[i];
    }
    if (tab[i] > *max) {
      *max = tab[i];
    }
  }
}

/// @brief 
/// @param tab 
/// @param taille 
/// @param histo 
/// @param tailleH 
/// @param min 
void histogramme(int* tab, int taille, int* histo, int tailleH, int min) 
{
  for (int i = 0; i < tailleH; i++) {
    histo[i] = 0;
  }
  for (int i = 0; i < taille; i++) {
    histo[tab[i] - min]++;
  }
}

/// @brief 
/// @param tab 
/// @param taille 
void triDenombrement(int* tab, int taille) 
{
  int min, max;
  minMaxTableau(tab, taille, &min, &max);
  int* histo = malloc((max - min + 1) * sizeof(int));
  histogramme(tab, taille, histo, max - min + 1, min);
  int k = 0;
  for (int i = 0; i < max - min + 1; i++) {
    for (int j = 0; j < histo[i]; j++) {
      tab[k] = i + min;
      k++;
    }
  }
  free(histo);
}