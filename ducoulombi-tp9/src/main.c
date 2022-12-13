/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief 
 * 
 */
#include "jeu.h"

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-13
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    paquet p = NULL;
    initialiserPaquet(&p);
    Compter(p);
    melangerPaquet(&p);
    Compter(p);
    AfficherP(p);
    joueur joueur1;
    joueur* croupier = &joueur1;
    joueur joueur2;
    joueur* joueur = &joueur2;
    creationJoueur(croupier, joueur);
    /*donneCarte(&p, joueur);
    //printf("nom %s\nprenom %s\nargent %d\ncarte: couleur %d, chiffre %d, valeur: %d\n", croupier->nom, croupier->prenom, croupier->argent, croupier->carte->couleur, croupier->carte->chiffre, croupier->carte->valeur);
    //AfficherP(p);
    donneCarte(&p, croupier);
    //printf("nom %s\nprenom %s\nargent %d\ncarte: couleur %d, chiffre %d, valeur: %d\n", joueur->nom, joueur->prenom, joueur->argent, joueur->carte->couleur, joueur->carte->chiffre, joueur->carte->valeur);
    //AfficherP(p);
    donneCarte(&p, joueur);
    donneCarte(&p, croupier);*/
    
    tourDeJeu(croupier, joueur, p);
    
    return (0);
}
