/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief fichier main
 * 
 */
#include "jeu.h"
#include "affichage.h"
#include "listes.h"

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief fonction main
 * 
 * @param argc 
 * @param argv 
 * @return 0 pas d'erreur 
 */
int main(int argc, char *argv[])
{
    /*Initialisation du paquet*/
    paquet p = NULL;
    initialiserPaquet(&p);
    //compter(p);
    melangerPaquet(&p);
    //compter(p);
    /*Pour afficher le paquet de carte enlever le commentaire sur //AfficherP(p)*/
    //AfficherP(p);

    /*Initialisation des joueurs*/
    joueur joueur1;
    joueur* croupier = &joueur1;
    joueur joueur2;
    joueur* joueur = &joueur2;

    /*Commence le jeu*/
    debutDuJeu(croupier, joueur, p);
    
    return (0);
}
