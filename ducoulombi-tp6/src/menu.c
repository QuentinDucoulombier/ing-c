/**
 * @file menu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief ensemble d'appel de fonctions pour le menu
 * 
 */


#include "menu.h"
#include "fonctions.h"
#include "puissance4.h"


int affichageMenu(void)
{
    int int_choix = -1;
	printf ("1 - Inverser un tableau\n");
	printf ("2 - Faure la somme de deux tableau\n");
	printf ("3 - Verifier si un tableau est transversable\n");
    printf ("4 - Puissance 4\n");
	printf ("5 - Palindrome\n");
    /* Demande du choix a l'utilisateur */
	printf ("Quel est votre choix : ");
    int_choix = saisieEntier();
    return(int_choix);
}

void caseMenu(int int_choix)
{
    int tint_tab1[M];
    int tint_tab2[M];
    int tint_tabS[M];


    
    int matriceP[N][N];
    char str_mot[M];
    srand(time(NULL));
    switch (int_choix) 
    {
        case 1 : 
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = rand() % 101;
            }
            affichage(tint_tab1);
            inversion(tint_tab1);
            affichage(tint_tab1);
            break;
        case 2 :
            
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = rand() % 101;
                tint_tab2[i] = rand() % 101;
            } 
            somme(tint_tab1, tint_tab2, tint_tabS);
            affichage(tint_tab1);
            affichage(tint_tab2);
            affichage(tint_tabS);
            break;
        case 3 :
            for (int i = 0; i < M; i++)
            {
                tint_tab1[i] = 0;
            }
            tint_tab1[0] = 10;
            tint_tab1[1] = -2;
            tint_tab1[2] = 12;
            printf("trasversale : %d\n", tranversable(tint_tab1));
            break;
        case 4 : 
            init(matriceP);
            tourDeJeu_rotation(matriceP);
            break;
        case 5 :
            printf("Entrez une chaine: ");
            scanf("%s", str_mot); //changer fonctions

            if (palindrome(str_mot)) 
            {
                printf("%s est un palindrome\n", str_mot);
            } 
            else 
            {
                printf("%s n'est pas un palindrome\n", str_mot);
            }
            break;
        default :
            break;
	}
}


