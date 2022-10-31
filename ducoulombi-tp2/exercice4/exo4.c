/**
 * @file exo4.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fichier qui contient l'ensemble des fonctions pour la saisie d'une personne
 * 
 */
#include <stdio.h>
#include <strings.h>


/*------------------------------------------------*/
/*--------------Saisie du prénom -----------------*/
/*------------------------------------------------*/

/**
 * @fn int saisiePrenom(char prenom[30])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fonction qui permet a l'utilisateur de saisir son prénom
 * 
 * @param prenom 
 * @return la sortie en booléen du scanf (s'il y a une erreur ou non)
 */
int saisiePrenom(char prenom[30])
{
    int outPrenom = 0;
    printf("Veuillez saisir un prenom\n");
    outPrenom = scanf("%s", prenom);
    return outPrenom;
}


/*------------------------------------------------*/
/*----------------Saisie du nom ------------------*/
/*------------------------------------------------*/

/**
 * @fn int saisieNom(char nom[30])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fonction qui permet a l'utilisateur de saisir son nom
 * 
 * @param nom 
 * @return la sortie en booléen du scanf (s'il y a une erreur ou non) 
 */
int saisieNom(char nom[30])
{
    int outNom = 0;
    printf("Veuillez saisir un nom\n");
    outNom = scanf("%s", nom);
    return outNom;
}


/*-----------------------------------------------*/
/*--Ensemble de fonctions et struc pour la date--*/
/*-----------------------------------------------*/
/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief structure de la date
 * 
 */
typedef struct date
{
    char mois[30];
    int annee;
    int jour;
    int outMois; //verification du scanf pour saisir le mois
    int outJour; //verification du scanf pour saisir le jour
    int outAnnee;//verification du scanf pour saisir l'année

}date;

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief typedef renomme date* en DATE (transforme la struct en pointeur)
 * 
 */
typedef date* DATE;



/**
 * @fn int verifDate(DATE date)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief Fonction qui verifie si la date n'est PAS l'un des mois de l'année 
 * @brief Cette fonction est utilisé dans la saisie du mois (dans la fonction saisieDate)
 * 
 * @param date 
 * @return un booléen (0 si faux et 1 si vrai)
 */
int verifDate(DATE date)
{
    return (strcasecmp(date->mois, "janvier") != 0) && (strcasecmp(date->mois, "fevrier") != 0) && (strcasecmp(date->mois, "mars") != 0) && (strcasecmp(date->mois, "avril") != 0) && (strcasecmp(date->mois, "mai") != 0) && (strcasecmp(date->mois, "juin") != 0) && (strcasecmp(date->mois, "juillet") != 0) && (strcasecmp(date->mois, "aout") != 0) && (strcasecmp(date->mois, "septembre") != 0) && (strcasecmp(date->mois, "octobre") != 0) && (strcasecmp(date->mois, "novembre") != 0) && (strcasecmp(date->mois, "decembre"));
}


/**
 * @fn int saisieDate(DATE date)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fonction qui permet de saisir une date
 * @brief Je sais qu'il n'etait pas demandé de verifier si le mois etait bon cependant je trouvé ca + propre
 * 
 * @param date 
 * @return 1 si une erreur de saisie sinon 0
 */
int saisieDate(DATE date)
{  
    //initialiser tt les variables de verification du scanf a "FAUX" (0 en c)
    date->outMois = 0; 
    date->outJour = 0;
    date->outAnnee = 0;
    
    /*------------- Partie pour saisir le jour -------------*/
    printf("Veuillez saisir un jour\n");
    date->outJour = scanf("%d", &date->jour); 
    //Verifie si la saisie est valide
    if(!date->outJour)
    {
        printf("Il y a une erreur de saisie sur le jour (entier)\n");
        //Sortie de la fonction si la saisie est mauvaise
        return (1);
    }

    /*------------- Partie pour saisir le mois -------------*/
    do
    {
        printf("Veuillez saisir un mois\n");
        date->outMois = scanf("%s", date->mois);
        //Verifie si la saisie n'est PAS l'un des mois de l'année (voir la fonction verifDate) ou si la saisie est invalide 
        if (verifDate(date) || (!date->outMois))
        {
            //renvoie une erreur
            printf("il y a une erreur de saisie sur le mois (chaine de caractere)\n");
            //Il n'y a pas de return (1) car ici il y a une boucle do...while
        }
        
    } 
    //Recommence la saisie si le mois n'est pas compatible
    while (verifDate(date));


    /*------------- Partie pour saisir l'année -------------*/
    printf("Veuillez saisir une année\n");
    date->outAnnee = scanf("%d", &date->annee);
    //verifie si la saisie est valide
    if(!date->outAnnee)
    {
        printf("Il y a une erreur de saisie sur l'année (entier)\n");
        //Sortie de la fonction si la saisie est mauvaise
        return (1);
    }

    //Retourne 0 si tt les parties ont bien fonctionnées
    return (0); 
}



/*------------------------------------------------*/
/*-------------------Affichage--------------------*/
/*------------------------------------------------*/
/**
 * @fn void affichage(DATE date, int verifScanNom, int verifScanPrenom, char nom[30], char prenom[30])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief procédure qui affiche le resultat de l'utilisateur
 * 
 * @param date 
 * @param verifScanNom 
 * @param verifScanPrenom 
 * @param nom 
 * @param prenom 
 */
void affichage(DATE date, int verifScanNom, int verifScanPrenom, char nom[30], char prenom[30])
{
    printf("\n\nVoici ce que vous avez entré: \n");
    if (verifScanNom) //Verifie la saisie du Nom
    {
        printf("Nom: %s\n", nom);
    }
    else
    {
        printf("il y a une erreur de saisie sur le nom (chaine de caractere)\n");
    }

    if (verifScanPrenom) //Verifie la saisie du Prenom
    {
        printf("Prenom: %s\n", prenom);
    }
    else
    {
        printf("il y a une erreur de saisie sur le prenom (chaine de caractere)\n");
    }
    
    if((date->outAnnee) && (date->outJour) && (date->outMois)) //verifie la saisie de la date
    {
        printf("Date:  %d %s %d\n", date->jour, date->mois, date->annee);
    }//pas besoin d'ecrire un message d'erreur, il existe deja dans la fonction saisieDate
}




/*------------------------------------------------*/
/*---------------------Main-----------------------*/
/*------------------------------------------------*/
/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-26
 * 
 * @brief fonction Main qui permet a l'utilisateur de saisir des infos et de verifier puis d'afficher ces infos
 * 
 * @param argc 
 * @param argv 
 * @return 1 si erreur 0 sinon
 */
int main(int argc, char *argv[])
{
    /* Affectation des variables */
    char nom[30];               //initialisation du nom
    char prenom[30];            //initialisation du préno
    date dateBase;              //creation de la struct date
    DATE date = &dateBase;      //initalisation du pointeur de la struct date
    int verifScanNom = 0;       //initialisation de la verification du scan Nom a Faux
    int verifScanPrenom = 0;    //initialisation de la verification du can prenom a faux
    //Appel de la fonction saisieNom
    verifScanNom = saisieNom(nom);
    //Appel de la fonction saisiePrenom
    verifScanPrenom = saisiePrenom(prenom);
    //Appel de la fonction saisieDate
    saisieDate(date);

    /* Fonction pour faire l'affichage */
    affichage(date, verifScanNom, verifScanPrenom, nom, prenom);
   
    return (0);
}