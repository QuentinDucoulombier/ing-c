/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief fichier main
 * 
 */
#include "fonctions.h"
#include "puissance4.h"
#include "menu.h"


/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief fonction main
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    caseMenu(affichageMenu());

    return(0);
}
