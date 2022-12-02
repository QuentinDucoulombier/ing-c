/**
 * @file tri.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 */
#ifndef __tri_h_
#define __tri_h_

/**
 * @fn void triInsertion(int* pint_tab, int int_taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param pint_tab 
 * @param int_taille 
 */
void triInsertion(int* pint_tab, int int_taille);

/**
 * @fn int* copierSousTableau(int* src, int debut, int fin)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param src 
 * @param debut 
 * @param fin 
 * @return int* 
 */
int* copierSousTableau(int* src, int debut, int fin);

/**
 * @fn void fusion(int* tab1, int taille1, int* tab2, int taille2, int* tabRes)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param tab1 
 * @param taille1 
 * @param tab2 
 * @param taille2 
 * @param tabRes 
 */
void fusion(int* tab1, int taille1, int* tab2, int taille2, int* tabRes);

/**
 * @fn void triFusion(int* tab, int taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param tab 
 * @param taille 
 */
void triFusion(int* tab, int taille);

/**
 * @fn void minMaxTableau(int* tab, int taille, int* min, int* max)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param tab 
 * @param taille 
 * @param min 
 * @param max 
 */
void minMaxTableau(int* tab, int taille, int* min, int* max);

/**
 * @fn void histogramme(int* tab, int taille, int* histo, int tailleH, int min)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param tab 
 * @param taille 
 * @param histo 
 * @param tailleH 
 * @param min 
 */
void histogramme(int* tab, int taille, int* histo, int tailleH, int min);

/**
 * @fn void triDenombrement(int* tab, int taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief 
 * 
 * @param tab 
 * @param taille 
 */
void triDenombrement(int* tab, int taille);

#endif