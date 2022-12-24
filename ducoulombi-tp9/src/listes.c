/**
 * @file listes.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 */

#include "listes.h"

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
void ajouterPos(paquet* l, int valeur, chiffreCarte chiffreC, eCouleur coul, int pos)
{
    carte* m = malloc(sizeof(carte));
    carte* mTemp = malloc(sizeof(carte));
    paquet temp = (*l);
    int i = 0;

    m -> valeur = valeur;
    m -> chiffre = chiffreC;
    m -> couleur = coul;
    m -> suivant = NULL;

    while (temp -> suivant != NULL && i != (pos - 1))
    {
        temp = temp -> suivant;
        i++;
    }

    mTemp = temp -> suivant;
    m -> suivant = mTemp;
    temp -> suivant = m;
}

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
void AjouterDebut(paquet* l, carte element)
{
    carte* m;

    m = malloc(sizeof(carte));
    m -> chiffre = element.chiffre;
    m -> couleur = element.couleur;
    m -> valeur = element.valeur;
    m -> suivant = (*l);
    (*l) = m;

}

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
carte supprimerDebut(paquet* l)
{
    paquet temp = (*l);
    carte eltsuppr;
    eltsuppr.chiffre = temp -> chiffre;
    eltsuppr.couleur = temp -> couleur;
    eltsuppr.valeur = temp -> valeur;
    (*l) = temp -> suivant;
    return eltsuppr;
}

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
void Compter(paquet p)
{
    int res = 0;


    if (p != NULL)
    {
        paquet temp = p;
        while (temp != NULL)
        {
            res++;
            //printf("\n"); test a faire
            temp = temp -> suivant;
        }
    }
    printf("res -> %d\n", res);
}


void ajouterFin(paquet* l, carte element)
{

    carte* m;
    paquet temp;

    m = malloc(sizeof(carte));
    m -> chiffre = element.chiffre;
    m -> couleur = element.couleur;
    m -> valeur = element.valeur;
    temp = (*l);

    if (temp != NULL)
    {
        while (temp -> suivant != NULL)
        {
            temp = temp -> suivant;
        }
        temp -> suivant = m;
    }
    else
    {
        temp = m;
    }
}