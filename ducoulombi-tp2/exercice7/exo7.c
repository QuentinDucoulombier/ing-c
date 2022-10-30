/**
 * @file exo7.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fichier qui verifie la saisie d'une date puis ajoute + 1 jours
 * 
 */
#include <stdio.h>

/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-10-28
 * 
 * @brief fonction Main qui verifie la saisie d'une date puis ajoute + 1 jours
 * 
 * @param argc 
 * @param argv 
 * @return retourne 1 si erreur 0 sinon
 */
int main(int argc, char *argv[])
{
    int verifBissextile = 0; //initialisé a faux
    int annee = 0;
    int mois = 0;
    int jour = 0;
    int bon = 1; //initialisé a vrai
    int groupeMois = -1;


/*---------------------------Année---------------------------*/
    
    printf("Veuillez saisir une annee\n");
    int verifAnnee = scanf("%d", &annee);
    //verifie si l'année est bien un reel
    if(!verifAnnee)
    {
        printf("Erreur, veuillez rentrer l'année en reel\n");
        //retourne une erreur
        return (1);
    }
    else
    {
        if (((annee%4)==0) && (((annee%100)!=0) || ((annee%400)==0)))
        {
            verifBissextile = 1; //passe l'année bissextile en vrai
        }
    }


   
    

/*---------------------------Mois---------------------------*/
    do
    {
        printf("Veuillez saisir un mois\n");
        int verifMois = scanf("%d", &mois);
        //verifie si le jour est bien un reel
        if(!verifMois) 
        {
            printf("Erreur, veuillez rentrer le mois en reel\n"); 
            //retourne une erreur
            return (1);
        }
    } while ((mois<1) || (mois>12)); //verifie que le mois est un mois possible


//Creation de different groupe de mois en fonctions des differents cas possible
    if ((mois==4) || (mois==6) || (mois==9) || (mois==11))
    {
        groupeMois = 1; //groupe de mois qui contient seulement 30 jours
    }
    else if ((mois == 2) && (verifBissextile))
    {
        groupeMois = 2; //groupe de mois qui contient 29 jours
    }
    else if ((mois == 2) && (!verifBissextile))
    {
        groupeMois = 3; //groupe de mois qui contient 28 jours
    }
    else if (mois == 12)
    {
        groupeMois = 4; //groupe de mois qui contient decembre
    }
    else
    {
        groupeMois = 5; //groupe qui contient 31 jours sans decembre
    }
    

/*---------------------------Jour---------------------------*/
    do
    {
        printf("Veuillez saisir un jour\n");
        int verifJour = scanf("%d", &jour);
        if(!verifJour)
        {
            printf("Erreur, veuillez saisir le jour en reel\n");
            return (1);
        }
    } while ((jour<1) || (jour>31));


/*---------------------------Verification de la saisie---------------------------*/
    //cas années bissextile => donc 29 jour disponible en fevrier
    if ((verifBissextile) && (jour>29) && (mois == 2)) 
    {
        printf("\nIl y a une erreur de saisie (jour trop grand 28 max)\n");
        bon = 0;
    }
    //cas mois de fevrier non bissextile
    else if ((!verifBissextile) && (mois == 2) && (jour>28)) 
    {
        printf("\nIl y a une erreur de saisie (jour trop grand 29 max)\n");
        bon = 0;
    }
    //cas pour les mois de 30 jours
    else if (((mois==4) || (mois==6) || (mois==9) || (mois==11)) && (jour>30)) 
    {
        printf("\nIl y a une erreur de saisie (jour trop grand 30 max)\n");
        bon = 0;
    }

/*---------------------------Calcul du jour suivant---------------------------*/
    if (bon)
    {
        printf("\nIl n'y pas d'erreur de saisie\n");
        printf("Le jour suivant sera le: ");
        //cas ou nous sommes le dernier jour du mois
        if(((jour == 30) && (groupeMois == 1)) || ((jour == 31 ) && (groupeMois == 5)) || ((jour == 29) && (groupeMois == 2)) || ((jour == 28) || (groupeMois == 3)))
        {
            printf("%d / %d / %d\n", 1, mois+1, annee);
        }
        //cas ou nous sommes le dernier jour de l'année
        else if ((jour == 31) && (groupeMois == 4)) 
        {
            printf("%d / %d / %d\n", 1, 1, annee+1);
        }
        //tous les autres cas
        else
        {
            printf("%d / %d / %d\n", jour+1, mois, annee);
        }
        
    }

    return 0;
    
}