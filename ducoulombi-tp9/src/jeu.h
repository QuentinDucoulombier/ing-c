/**
 * @file jeu.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief fichier de l'ensemble des appels de fonctions pour le bon fonctionnement du jeu
 * 
 */
#ifndef __jeu_h_
#define __jeu_h_

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "affichage.h"

/**
 * @enum typedef enum eCouleur
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief enumeration de toutes les couleurs d'un jeu de cartes
 * 
 */
typedef enum eCouleur
{
    carreau,
    coeur,
    trefle,
    pique
}eCouleur;

/**
 * @enum typedef enum chiffreCarte
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief enumeration de tous les cartes possibles
 * 
 */
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

/**
 * @struct typedef struct carte
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief structure de la carte
 * 
 */
typedef struct carte
{
    chiffreCarte chiffre;
    int valeur;
    eCouleur couleur;
    struct carte* suivant;
}carte;

/**
 * @typedef typedef carte* paquet
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief creation du typedef paquet qui correspond au pointeur de la structure carte
 * 
 */
typedef carte* paquet;

/**
 * @struct typedef struct joueur
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief creation de la structure du joueur
 * 
 */
typedef struct joueur
{
    int argent;
    int mise;
    int blackjack;
    paquet carte;
    int assurance;
    int somme;
    int etat;
    int as;
    int score;
    char nom[30];
    char prenom[30];
}joueur;


/**
 * @fn void initialiserPaquet(paquet *p)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief procedure pour initialiser le paquet de cartes
 * 
 * @param p 
 */
void initialiserPaquet(paquet *p);

/**
 * @fn void melangerPaquet(paquet *p)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief procedure pour melanger le paquet de carte
 * 
 * @param p 
 */
void melangerPaquet(paquet *p);



/**
 * @fn void donneCarte(paquet *paquet, joueur* joueur)
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
 * @fn void creationJoueur(joueur* croupier, joueur* vraiJoueur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief procedure pour crée le joueur et le faire saisir ses infos
 * 
 */
void creationJoueur(joueur* croupier, joueur* vraiJoueur);

/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-12
 * 
 * @brief fonction pour saisir un entier
 * 
 * @return l'entier saisis par l'utilisateur
 */
int saisieEntier(void);


/**
 * @fn int verifJeu(joueur* joueur, int etat)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief fonction qui verifie que le joueur ne depasse pas 21
 * 
 * @param joueur 
 * @param etat 
 * @return l'etat du joueur (peut encore jouer(true), il a perdu (false))
 */
int verifJeu(joueur* joueur, int etat);


/**
 * @fn void tourDeJeu(joueur* croupier, joueur* joueur, paquet p)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief procedure qui permet de gerer une partie
 * 
 * @param croupier 
 * @param joueur 
 * @param p 
 */
void tourDeJeu(joueur* croupier, joueur* joueur, paquet p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-22
 * 
 * @brief procedure qui initialise le debut d'une partie
 * 
 * @param croupier 
 * @param joueur 
 * @param p 
 */
void debutDuJeu(joueur* croupier, joueur* joueur, paquet p);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief procedure qui afficher les cartes
 * 
 * @param p 
 */
void AfficherP(paquet p);

#endif
