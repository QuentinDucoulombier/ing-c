/**
 * @file jeu.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 */
#ifndef __jeu_h_
#define __jeu_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum eCouleur
{
    carreau,
    coeur,
    trefle,
    pique
}eCouleur;

typedef enum chiffreCarte
{
    AS = 1,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    SIX,
    SEPT,
    HUIT,
    NEUF,
    DIX,
    VALET,
    DAME,
    ROI
}chiffreCarte;

typedef struct carte
{
    chiffreCarte chiffre;
    int valeur;
    eCouleur couleur;
    struct carte* suivant;
}carte;

typedef carte* paquet;

typedef struct joueur
{
    int argent;
    paquet carte;
    int somme;
    char nom[30];
    char prenom[30];
}joueur;

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 * @param p 
 */
void initialiserPaquet(paquet *p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * @todo debugger la fonction
 * 
 * @param p 
 */
void melangerPaquet(paquet *p);



/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 * @param paquet 
 * @param joueur 
 */
void donneCarte(paquet *paquet, joueur* joueur);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 */
void changementValeur(carte* paquet);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 */
void AfficherP(paquet p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 * @param p 
 */
void Compter (paquet p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 */
void creationJoueur(joueur* croupier, joueur* vraiJoueur);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief 
 * 
 * @return int 
 */
int saisieEntier(void);


/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief 
 * 
 * @param joueur 
 * @param etat 
 * @return int 
 */
int verifJeu(joueur* joueur, int etat);


/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief 
 * 
 */
void tourDeJeu(joueur* croupier, joueur* joueur, paquet p);


#endif
