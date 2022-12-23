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
    debutDuJeu(croupier, joueur, p);
    
    return (0);
}
