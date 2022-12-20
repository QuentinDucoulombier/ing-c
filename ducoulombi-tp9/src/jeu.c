/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * @todo debug la fonction melanger
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

void AjouterDebut(paquet* l, carte element)
{
    carte* m;

    m = malloc(sizeof(carte));
    m -> chiffre = element.chiffre;
    m -> couleur = element.couleur;
    m -> valeur = element.valeur;
    m -> suivant = (*l);
    (*l) = m;

}

carte supprimerDebut(paquet* l)
{
    paquet temp = (*l);
    carte eltsuppr;
    eltsuppr.chiffre = temp -> chiffre;
    eltsuppr.couleur = temp -> couleur;
    eltsuppr.valeur = temp -> valeur;
    (*l) = temp -> suivant;
    return eltsuppr;
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
        supprimerDebut(p);
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
        int carreau = 0;
        int coeur = 0;
        int trefle = 0;
        int pique = 0;
        while (temp != NULL)
        {
            //printf("couleur: %d et chiffre:%d\n", temp->couleur, temp->chiffre);
            switch (temp->couleur)
            {
            case 0:
                printf("%d couleur: carreau et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                carreau++;
                break; 
            case 1:
                printf("%d couleur: coeur et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                coeur++;
                break;
            case 2:
                printf("%d couleur: trefle et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                trefle++;
                break;
            case 3:
                printf("%d couleur: pique et chiffre:%d, valeur %d\n",i, temp->chiffre, temp->valeur);
                pique++;
                break;
            default:
                printf("Couleur inconnue\n");
                break;
            }
            temp = temp -> suivant;
            i++;
        }
        printf("carr %d, coeur %d, trefle %d, pique %d\n", carreau, coeur, trefle, pique);
    }
    else
    {
        printf("Le paquet est vide !\n");
    }
    
}

/*verifier ces fonctions*/
void SupprimerFin(paquet* l)
{
    paquet temp = (*l);


    if (temp != NULL)
    {
        while (temp -> suivant -> suivant != NULL)
        {
            temp = temp -> suivant;

        }
        temp -> suivant = NULL;
    }
    else
    {
        temp = NULL;
    }
}

void donneCarte(paquet *p, joueur* joueur)
{
    
    AjouterDebut(&(joueur -> carte), supprimerDebut(p));
    /*while (joueur -> carte -> suivant != NULL)
    {
        SupprimerFin(&joueur->carte);
    }
    
    SupprimerDebut(p);*/
}


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
        exit(EXIT_FAILURE);
    }
}

void creationJoueur(joueur* croupier, joueur* vraiJoueur)
{
    /*Initialisation du croupier*/
    strcpy(croupier->nom, "croupier");
    strcpy(croupier->prenom, "michel");
    croupier->argent = -1; //bank
    /*Initialisation du joueur*/
    printf("\nVeuillez saisir votre nom: ");
    scanf("%s", vraiJoueur->nom);
    printf("\nVeuillez saisir votre prenom: ");
    scanf("%s", vraiJoueur->prenom);
    printf("\nVeuillez saisir votre mise total: ");
    vraiJoueur->argent = saisieEntier();
}


int verifJeu(joueur* joueur, int etat)
{
    joueur->somme += joueur->carte->valeur;
    printf("Somme %d\n", joueur->somme);
    if(!etat)
    {
        if (joueur->somme > 21)
        {
            /*transformer 1 en 11*/
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
    
}


void tourDeJeu(joueur* croupier, joueur* joueur, paquet p)
{
    int out;
    int etat = 0;
    donneCarte(&p, joueur);
    donneCarte(&p, croupier);
    donneCarte(&p, joueur);
    donneCarte(&p, croupier);
    printf("Carte du joueur\n");
    AfficherP(joueur->carte);
    printf("Carte du croupier\n");
    AfficherP(croupier->carte);
    //AfficherP(p);

    //AfficherP(croupier->carte);
    
   /*
    while (verifJeu(joueur, etat))
    {
        printf("0.Distribuer\n");
        printf("1.Rester\n");
        scanf("%d", &out);
        if(out)
        {
            donneCarte(&p, joueur);
        }

    }
    printf("\nout\n");*/
    
}
