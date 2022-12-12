/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 */

#include "jeu.h"


void initialiserPaquet(paquet *p)
{
    // On crée un tableau contenant toutes les cartes du paquet
    chiffreCarte chiffres[] = {AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI};
    eCouleur couleurs[] = {carreau, coeur, trefle, pique};

    // On parcourt le tableau des cartes et on crée un objet carte pour chaque combinaison possible
    // de chiffre et de couleur
    int test = 1;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            test++;
            carte* c = malloc(sizeof(carte));
            if(c != NULL)
            {
                c->chiffre = chiffres[i];
                if(c->chiffre > DIX)
                {
                    c->valeur = 10;
                }
                else
                {
                    c->valeur = (int) chiffres[i];
                }
                c->couleur = couleurs[j];
                c->suivant = *p;  // On fait pointer la nouvelle carte vers le début de la pile
                *p = c;          // On met à jour le début de la pile
            }
        }
    }
    printf("test -> %d\n", test);
}


void ajouterPos(paquet* l, int valeur, chiffreCarte chiffreC, eCouleur coul, int pos)
{
    carte* m = malloc(sizeof(carte));
    carte* mTemp = malloc(sizeof(carte));
    paquet temp = (*l);
    int i = 0;

    m -> valeur = valeur;
    m -> chiffre = chiffreC;
    m -> couleur = coul;
    m -> suivant = NULL;

    while (temp -> suivant != NULL && i != (pos - 1))
    {
        temp = temp -> suivant;
        i++;
    }

    mTemp = temp -> suivant;
    m -> suivant = mTemp;
    temp -> suivant = m;
}


void SupprimerDebut(paquet* l)
{
    paquet temp = (*l);
    (*l) = temp -> suivant;
}

void Compter (paquet p)
{
    int res = 0;


    if (p != NULL)
    {
        paquet temp = p;
        while (temp != NULL)
        {
            res++;
            temp = temp -> suivant;
        }
    }
    printf("res -> %d\n", res);
}



void melangerPaquet(paquet *p)
{
    srand(time(NULL));  

    for (int i = 0; i < 52; i++)
    {
        int pos = rand() % 52; 
        SupprimerDebut(p);
        int valeur = (*p) ->valeur;
        chiffreCarte chiffre = (*p)->chiffre;
        eCouleur couleur = (*p)->couleur;
        ajouterPos(p, valeur, chiffre, couleur, pos); 
    }
}


void AfficherP(paquet p)
{
    if (p != NULL)
    {
        paquet temp = p;
        int i = 1;
        while (temp != NULL)
        {
            //printf("couleur: %d et chiffre:%d\n", temp->couleur, temp->chiffre);
            switch (temp->couleur)
            {
            case 0:
                printf("%d couleur: carreau, chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                break; 
            case 1:
                printf("%d couleur: coeur et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                break;
            case 2:
                printf("%d couleur: trefle et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                break;
            case 3:
                printf("%d couleur: pique et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                break;
            default:
                printf("Couleur inconnue\n");
                break;
            }
            temp = temp -> suivant;
            i++;
        }
    }
    else
    {
        printf("Le paquet est vide !\n");
    }
    
}

void donneCarte(carte *paquet, joueur* joueur)
{
    joueur->carte[0]= paquet[0];
    paquet++;
}

void changementValeur(carte* paquet)
{
    for (int i = 0; i < 52; i++)
    {
        if (paquet[i].chiffre > DIX)
        {
            paquet[i].valeur = DIX;
        }
        else
        {
            paquet[i].valeur = paquet[i].chiffre;
        }
        
    }
}