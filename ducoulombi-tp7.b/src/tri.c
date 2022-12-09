/**
 * @file tri.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-03
 * 
 * @brief fichier qui contient l'ensemble des fonctions/procedures de tri
 * 
 */
#include "tri.h"
#include "fonctions.h"


/*-----------------*/
/*Tri par insertion*/
/*-----------------*/

/// @brief procédure qui permet de trier un tableau d’entier en utilisant la méthode du tri insertion.
/// @param pint_tab 
/// @param int_taille 
void triInsertion(int* pint_tab, int int_taille)
{
	int int_elementInsere;
	int j;
	int i;
	for (i = 1; i < int_taille; i++)
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

/// @brief fonction qui permet de copier dans un tableau dest les valeurs du tableau src allant de l’indice debut à l’indice fin.
/// @param src 
/// @param debut 
/// @param fin 
/// @return la copie du sous tableau
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

/// @brief procédure qui permet de fusionner deux tableaux triés de façon croissante tab1 et tab2 dans un tableau résultat tabRes qui sera lui aussi trié de façon croissante.
/// @param tab1 
/// @param taille1 
/// @param tab2 
/// @param taille2 
/// @param tabRes 
void fusion(int* tab1, int taille1, int* tab2, int taille2, int* tabRes) 
{
	int int_cpt1 = 0;
	int int_cpt2 = 0;
	int int_cpt3 = 0;
	while ((int_cpt1 < taille1) && (int_cpt2 < taille2)) 
	{
		if (tab1[int_cpt1] < tab2[int_cpt2]) 
		{
			tabRes[int_cpt3++] = tab1[int_cpt1++];
		} 
		else 
		{
			tabRes[int_cpt3++] = tab2[int_cpt2++];
		}
	}
	while (int_cpt1 < taille1) 
	{
		tabRes[int_cpt3++] = tab1[int_cpt1++];
	}
	while (int_cpt2 < taille2) 
	{
		tabRes[int_cpt3++] = tab2[int_cpt2++];
	}
}

/// @brief procédure qui trie un tableau de façon croissante grace au fonctions/procedure precedente.
/// @param tab 
/// @param taille 
void triFusion(int* tab, int taille) 
{
	//verifie que la taille est superieur a 1 (dans l'autre cas on ne fais rien)
	if (taille > 1)
	{
		/*Calcul le milieu*/
		int milieu = taille / 2;
		/*Initialise les deux sous tableau*/
		int* tab1 = copierSousTableau(tab, 0, milieu);
		int* tab2 = copierSousTableau(tab, milieu, taille);
		/*Effectue le tri fusion*/
		triFusion(tab1, milieu);
		triFusion(tab2, taille - milieu);
		/*Puis les fusionne*/
		fusion(tab1, milieu, tab2, taille - milieu, tab);
		/*Et enfin libere les tableaux*/
		liberer(tab1);
		liberer(tab2);
	}
}


/*--------------------*/
/*Tri par dénombrement*/
/*--------------------*/

/// @brief fonction qui recherche les valeurs minimum et maximum du tableau tab
/// @param tab 
/// @param taille 
/// @param min 
/// @param max 
void minMaxTableau(int* tab, int taille, int* min, int* max) 
{
	//"*min" et non "min" car affectation de pointeur vers pointeur et non pointeur vers int
	//min et max les premiere valeur du tab
	*min = tab[0];
	*max = tab[0];
	// boucle de 1 a taille et non 0 car deja initialisé a tab[0]  
	for (int i = 1; i < taille; i++) 
	{
		if (tab[i] < *min) 
		{
		*min = tab[i];
		}
		if (tab[i] > *max) 
		{
		*max = tab[i];
		}
	}
}

/// @brief fonction qui permet de déterminer la fréquence d’apparition de chaque élément du tableau tab.
/// @param tab 
/// @param taille 
/// @param histo 
/// @param tailleH 
/// @param min 
void histogramme(int* tab, int taille, int* histo, int tailleH, int min) 
{
	for (int i = 0; i < tailleH; i++) 
	{
		//valeur inbitialisé a 0
		histo[i] = 0; 
	}
	for (int i = 0; i < taille; i++) 
	{
		//incremente
		histo[tab[i] - min]++;
	}
}

/// @brief procédure qui trie un tableau de façon croissante.
/// @param tab 
/// @param taille 
void triDenombrement(int* tab, int taille) 
{
	int min;
	int max;
	int k = 0;

	minMaxTableau(tab, taille, &min, &max);
	int* histo = allouer(max - min + 1);
	histogramme(tab, taille, histo, max - min + 1, min);
	for (int i = 0; i < max - min + 1; i++) 
	{
		for (int j = 0; j < histo[i]; j++) 
		{
			tab[k] = i + min;
			k++;
		}
	}
	liberer(histo);
}