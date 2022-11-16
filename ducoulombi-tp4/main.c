/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief fichier main qui contient un menu permettant de selectionner une fonction
 * 
 */
#include <stdio.h> 
#include <stdlib.h>
#include "pi.h"
#include "racine2.h"

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-16
 * 
 * @brief fonction main qui fonction avec un menu
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{

    /*------ Affichage du menu -------*/
    int int_retour; /* Valeur de retour */
	int int_choix;  /* Choix de l'utilisateur */
	
	/* Affichage du menu */
    printf("------ Fonction pour approximer pi ------\n");
	printf ("1 - Approximation par aire d'un disque par quadrillage\n");
	printf ("2 - Approximation de Madhava de Sangamagrama\n");
	printf ("3 - Approximation de John Wallis\n");
    printf ("\n");
    printf("------ Fonction pour approximer racine de 2 ------\n");
    printf ("4 - Approximation de Isaac Newton\n");
	printf ("5 - Approximation de Edmund Halley\n");
	printf ("6 - Approximation par la methode de Théon de Smyrne\n");

	/* Demande du choix a l'utilisateur */
	printf ("Quel est votre choix : ");
	int_retour = scanf ("%d", &int_choix);

	/* Verification de l'entree */
	if (int_retour == 0) {
		fprintf(stderr, "Entree incorrecte\n");
		exit (EXIT_FAILURE);
	}

    /*-------- Affectation des variables ---------*/
    int nbrOccurence = 0;
    float float_racine2 = 0;
    float float_pi = 0;

    /*-------- Switch pour choisir le programme  --------*/
    switch (int_choix) 
    {
        case 1 : 
            
            nbrOccurence = saisieEntier();
            float_pi = disqueQuadrillage(nbrOccurence);
            printf("%f\n", float_pi);

            break;
        case 2 :

            nbrOccurence = saisieEntier();  
            float_pi = piSangamagrama(nbrOccurence);
            printf("%f\n", float_pi);      
            break;
        case 3 :
            nbrOccurence = saisieEntier();  
            float_pi = piWallis(nbrOccurence);
            printf("%f\n", float_pi);
            break;
        case 4 : 
               
            nbrOccurence = saisieEntier();
            float_racine2 = racineNewton(nbrOccurence);
            printf("%f\n", float_racine2);

            break;
        case 5 :

            nbrOccurence = saisieEntier();        
            float_racine2 = racineHalley(nbrOccurence);
            printf("%f\n", float_racine2);    
            break;
        case 6 :
            
            nbrOccurence = saisieEntier();
            float_racine2 = racineSmyrne(nbrOccurence);
            printf("%f\n", float_racine2);
            break;
        default :
            break;
	}

    return (0);

}
