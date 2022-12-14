/*! \file Programmation/2007-2008/Cours/Cours9/split.c
 *  \author Florent Devin <florent.devin@eisti.fr>
 *  \version 0.1
 *  \date Mon Dec  3 18:54:31 2007
 *
 *  \brief Démonstration de strtok
 *
 *
 */


// Inclusion des entêtes de librairie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// Définition de constantes
/*! \def PROG_OK
 *	Constante pour définir une terminaison correcte
 */
#define PROG_OK 0


/*! \def ERREUR_SYS
 *  Constante pour définir une terminaison par erreur
 *  système
 */
#define ERREUR_SYS -1
 

/*! \fn int main (int argc, char** argv)
 *  \author Florent Devin <florent.devin@eisti.fr>
 *  \version 0.1
 *  \date Mon Dec  3 18:54:53 2007
 *
 *  \brief Fonction principale
 *
 *
 * \param argc : Nombre d'argument
 * \param argv : Tableau des arguments
 * \return 0 : le programme doit se terminer normalement
 *
 * \remarks 
 */

int main (int argc, char** argv) {
	char str_path[255]; // Chemin à splitter
	char* str_token; // Token pour chaque spli

	// Initialisation de la chaîne 
	strcpy (str_path, "/home/devinf/Enseignement/Ing1/Programmation/2007-2008/Cours/Cours9");
	// Si la copie a échouée
	if (str_path == NULL) {
		// On affiche un message
		fprintf (stderr, "Problème lors de la copie : %s\n", strerror (errno));
		// Et on quitte
		exit (ERREUR_SYS);
	}

	// On commence à diviser la chaîne
	str_token = strtok (str_path, "/");
	// S'il n'y a pas de token, pas la peine de continuer
	if (str_token != NULL) {
		// Repeter tant que le Token n'est pas nul
		do {
			// Affichage du token
			printf ("%s\n", str_token);
			// Demande d'un nouveau token
			// Notez l'appel de strtok
			str_token = strtok (NULL, "/");
		} while (str_token != NULL);
	}
	
	//Fin du programme, Il se termine normalement, et donc retourne 0
	return (PROG_OK);
}
