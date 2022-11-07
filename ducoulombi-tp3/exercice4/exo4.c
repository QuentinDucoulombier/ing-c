/**
 * @file exo4.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fichier pour l'ensemble de fonctions pour l'exercie 'Programme un peu plus grand'
 * 
 */
#include <stdio.h>
#include <stdlib.h> 

/**
 * @fn int saisieEntier(void)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 2
 * @date 2022-11-07
 * 
 * @brief fonction de saisie d'entier
 * 
 * @return le nombre saisie si pas d'erreur, on quitte le programme avec exit dans le cas inverse
 */
int saisieEntier(void)
{
    int int_n = 0;
    int int_outScan = scanf("%d", &int_n);
    if(int_outScan)
    {
        return(int_n);
    }
    else
    {
        fprintf(stderr, "Entree incorrecte\n");
        //On nous a expliqué que l'on pouvait aussi utilisé exit Failure
        exit(EXIT_FAILURE);
    }
}

/**
 * @fn void triangle(int int_taille)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction qui affiche un triangle
 * 
 * @param int_taille 
 */
void triangle(int int_taille)
{

    int int_espace;
    int int_nb;


    for (int j = 1; j <= (int_taille*2)-1; j = j+2)
    {
        int_nb=1;
        int_espace=int_taille-j+(int_taille-2);
        while (int_espace>0)
        {
            printf(" ");
            int_espace=int_espace-2;
        }
        while (int_nb<=j)
        {
            printf("*");
            int_nb=int_nb+1;
        }
        printf(" \n");
    }

}

/**
 * @fn void tableMultiplication(int int_table)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction qui affiche une table de multiplication saisie de 1 a 10
 * 
 * @param int_table 
 */
void tableMultiplication(int int_table)
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d * %d = %d\n", i, int_table, i*int_table);
    }
    
}

/**
 * @fn void estAmstrong(int int_amstrong)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction qui verifie que c'est un nombre d'Amstrong
 * 
 * @param int_amstrong 
 */
void estAmstrong(int int_amstrong)
{

    int sauvegarde = int_amstrong;
    int somme = 0;
    while (sauvegarde > 0)
    {
        int chiffre = sauvegarde % 10;
        somme = somme + chiffre * chiffre * chiffre;
        sauvegarde = sauvegarde /10;

    }
    
    if (somme == int_amstrong)
    {
        printf("%d est un nombre d'Amstrong\n", int_amstrong);
    }

    else
    {
        printf("%d n'est pas un nombre d'Amstrong\n", int_amstrong);
    }
}

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction main, qui permet de choisir une fonction a effectué a l'aide d'un menu
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    int int_retour; /* Valeur de retour */
	int int_choix;  /* Choix de l'utilisateur */
	
	/* Affichage du menu */
	printf ("1 - Faire un triangle\n");
	printf ("2 - Faire une table de multiplication\n");
	printf ("3 - Verifier si un nombre est un nombre d'Armstrong\n");

	/* Demande du choix a l'utilisateur */
	printf ("Quel est votre choix : ");
	int_retour = scanf ("%d", &int_choix);

	/* Verification de l'entree */
	if (int_retour == 0) {
		fprintf(stderr, "Entree incorrecte\n");
		exit (EXIT_FAILURE);
	}

    int int_taille;
    int int_table;
    int int_amstrong;

	/* Affichage du message en fonction du choix */
	switch (int_choix) 
    {
        case 1 : 
            
            printf("Veuillez saisir la taille du triangle: ");
            int_taille = saisieEntier();
            triangle(int_taille);
            break;
        case 2 :
            
            printf("Veuillez saisir la table de mutliplication: ");
            int_table = saisieEntier();
            tableMultiplication(int_table);        
            break;
        case 3 :
            
            printf("Veuilez saisir votre nombre afin de verifier si c'est un nombre d'Amstrong: ");
            int_amstrong = saisieEntier();
            estAmstrong(int_amstrong);
            break;
        default :
            break;
	}

    return (0);
}
