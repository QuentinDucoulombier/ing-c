/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * TODO:
 *  - Verifier si le blackjack marche (oui)
 *  - Ne pas melanger mettre juste a la fin de la liste
 *  - Modifier le truc de blackjack ligne 570 (c'est bon)
 * 
 * @brief 
 * @todo debug la fonction melanger
 * 
 */

#include "jeu.h"
#include "listes.h"


void initialiserPaquet(paquet *p)
{
    // On crée un tableau contenant toutes les cartes du paquet
    chiffreCarte chiffres[] = {AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI};
    eCouleur couleurs[] = {carreau, coeur, trefle, pique};

    // On parcourt le tableau des cartes et on crée un objet carte pour chaque combinaison possible
    // de chiffre et de couleur
    int test = 1;
    /*for (int i = 0; i < 3; i++)*///Pour test les as
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
                else if (c->chiffre == AS)
                {
                    c->valeur = 11;
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

void donneCarte(paquet *p, joueur* joueur)
{
    AjouterDebut(&(joueur -> carte), supprimerDebut(p));
    //printf("\nCarte %d\n", joueur->carte->chiffre);
    //afficheCarte(joueur->carte->couleur, joueur->carte->chiffre, joueur->carte->valeur);
    /*Compte le nombre d'as dans le paquet du joueur*/
    if(joueur->carte->chiffre == AS)
    {
        joueur->as ++;
        //printf("as -> %d\n", joueur->as);
    }
    
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


void AfficherP(paquet p)
{
    if (p != NULL)
    {
        paquet temp = p;
        int i = 1;
        /*int carreau = 0;
        int coeur = 0;
        int trefle = 0;
        int pique = 0;*/
        while (temp != NULL)
        {
            //printf("couleur: %d et chiffre:%d\n", temp->couleur, temp->chiffre);
            printf("%d: ", i);
            afficheCarte(temp->couleur, temp->chiffre, temp->valeur);
            i++;
            temp = temp -> suivant;
        }
        //printf("carr %d, coeur %d, trefle %d, pique %d\n", carreau, coeur, trefle, pique);
    }
    else
    {
        printf("Le paquet est vide !\n");
    }
    
}

void creationJoueur(joueur* croupier, joueur* vraiJoueur)
{
    /*Initialisation du croupier*/
    strcpy(croupier->nom, "croupier");
    strcpy(croupier->prenom, "michel");
    croupier->argent = -1; //bank ilimité
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
    if(!etat) //etat == 0
    {
        joueur->somme += joueur->carte->valeur;
        printf("Somme: %d\n", joueur->somme);
        if (joueur->somme > 21)
        {
            
            /*transforme As avec une valeur de 11 en 1*/
            /*Joueur->as compte le nombre d'as dans le paquet de carte du joueur si >0 => VRAI sinon si 0 => FAUX*/
            if(joueur->as)
            {
                printf("Vous avez un as donc la somme devient\n");//Faire le cas ou ca tombe sur 21 et le cas ou il y a 2 as
                joueur->somme -= 10;
                printf("as -> %d\n", joueur->as);
                joueur->as --; //Normalement ca marche
                printf("as -> %d\n", joueur->as);
                printf("Somme la %d\n", joueur->somme);
                return TRUE;
            }
            else
            {
                printf("Vous avez perdu\n");
                joueur->etat = FALSE;
                return FALSE;
            }
        }
        else
        {
            return TRUE;
        }
    }
    printf("out fonction \n");
    return FALSE;
    
}

void doubler(joueur* joueur)
{
    printf("Doubler votre mise ?\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    
    int bool_double = saisieEntier() - 1;
    if(!bool_double)
    {
        joueur->mise += joueur->mise;
        printf("Vous doublez votre mise !\nMise actuelle %d\n\n", joueur->mise);
    }

}


void assurance(joueur* croupier, joueur* joueur)
{
    if(croupier -> carte -> chiffre == AS)
    {
        croupier -> assurance = TRUE;
        printf("Le joueur peut choisir une assurance\n");
        printf("          --------------Explication-------------\n");
        printf("Pour cela, le joueur paye la moitié de sa mise initiale. Si le croupier fait Blackjack, le joueur perd sa mise mais se voit payer l assurance en double (donc bénéfice 0, perte 0). Si le croupier ne fait pas Blackjack, deux situations sont possibles : Premièrement, le joueur gagne ; il perd son assurance mais empoche l équivalent de sa mise initiale (bénéfice net 1/2 fois la mise initiale). Deuxièmement, le joueur perd ; il perd alors l assurance ainsi que sa mise (perte 1,5 fois la mise initiale).\n");
        printf("\nVoulez vous choisir une assurance ?\n");
        printf("1- Oui\n");
        printf("2- Non\n");
        int reponse = saisieEntier() - 1;
        if(!reponse)
        {
            joueur->assurance = joueur->mise/2; //passe a true
            joueur->argent -= joueur->assurance;
        }
    }
}

/*Debuger aaaaaaaaah*/
void tourDeJeu(joueur* croupier, joueur* joueur, paquet p)
{
    /*Variable et initialisation*/
    int out;
    int etat = 0;
    joueur -> as = FALSE;
    croupier -> as = FALSE;

    /*-------- On distribue les cartes --------*/
    //Premiere carte du joueur
    donneCarte(&p, joueur);
    joueur->somme += joueur->carte->valeur;
    /*test
    carte test;
    test.couleur = 0;
    test.chiffre = 1;
    test.valeur = 11;
    AjouterDebut(&(croupier -> carte), test);*/
    //Premiere carte du croupier
    donneCarte(&p, croupier);
    croupier->somme += croupier->carte->valeur;
    printf("Premiere carte du croupier\n");
    AfficherP(croupier->carte);
    
    /*Si c'est un as on propose l'assurance au joueur*/
    assurance(croupier, joueur);

    //Deuxieme carte du joueur
    donneCarte(&p, joueur);
    joueur->somme += joueur->carte->valeur;
    //Deuxieme carte du croupier
    donneCarte(&p, croupier);
    /*carte test2;
    test2.couleur = 0;
    test2.chiffre = 10;
    test2.valeur = 10;
    AjouterDebut(&(croupier -> carte), test2);*/
    croupier->somme += croupier->carte->valeur;
    /*--------- On affiche les cartes du joueur ---------*/
    printf("Carte du joueur\n");
    AfficherP(joueur->carte);
    //On affiche la somme
    printf("somme: %d\n", joueur->somme);
    /*On propose au joueur si c'est possible de doubler sa mise*/
    if(joueur->argent > joueur->mise*2)
    {
        doubler(joueur);
    }
    else
    {
        printf("Vous n'avez pas assez d'argent pour doubler\n");
    }


    /*gere le cas du blackjack*/
    /*transformer en fonction*/
    if(joueur->somme == 21)
    {
        printf("Felicitation vous avez fait blackjack\n");
        joueur -> blackjack = TRUE;
    }
    else if(croupier->somme == 21)
    {
        printf("Le croupier a fait blackjack\n");
        AfficherP(croupier->carte);
        croupier -> blackjack = TRUE;
    }
    /*Alors effectivement comme ca, ca n'a pas de sens ^^*/
    /*Verifie le cas du blackjack*/
    if(joueur->blackjack && !croupier->blackjack)
    {
        joueur->argent += joueur->mise + joueur->mise/2;
        printf("Le joueur gagne\n");
    }
    else if (croupier->blackjack && !joueur->blackjack)
    {
        if(!joueur->assurance)
        {
            joueur->argent -= joueur->mise;
            printf("Le croupier gagne\n");
        }
        else
        {
            joueur->argent += joueur->assurance;
            printf("Grace a votre assurance vous ne perdez rien\n");
        }
    }
    else if (croupier->blackjack && joueur->blackjack)
    {
        printf("egalité");
    }
    /*Tous les autres cas*/
    else
    {
        /*Joueur 1*/
        printf("Au tour du joueur\n");
        printf("somme: %d\n", joueur->somme);
        do
        {
            printf("0.Distribuer\n");
            printf("1.Rester\n");
            scanf("%d", &out); //rajouter le entrée entier et limité que a 0 et 1
            if(!out) //out == 1
            {
                donneCarte(&p, joueur);
                printf("Carte du joueur\n");
                AfficherP(joueur->carte);
                etat = 0;
            }
            else
            {
                etat = 1;
            }
        }while(verifJeu(joueur, etat));
        printf("Au tour du croupier\n");
        printf("Carte du croupier\n");
        AfficherP(croupier->carte);
        printf("somme: %d\n", croupier->somme);
        /*Croupier*/
        if(joueur -> etat == TRUE)
        {
            etat = 0;
            do
            {
                if(croupier -> somme <= 16)
                {
                    donneCarte(&p, croupier);
                    printf("Carte du croupier\n");
                    AfficherP(croupier->carte);
                    etat = 0;
                }
                else
                {
                    etat = 1;
                }
            }while(verifJeu(croupier, etat));
        }
        /*croupier gagne*/
        if((croupier -> somme > joueur -> somme && joueur -> etat == TRUE && croupier -> etat == TRUE) || (joueur -> etat == FALSE && croupier -> etat == TRUE))//croupier -> etat == TRUE
        {
            joueur->argent -= joueur->mise;
            printf("Le croupier gagne\n");
        }
        /*joueur gagne*/
        else if ((croupier -> somme < joueur -> somme && joueur -> etat == TRUE && croupier -> etat == TRUE) || (joueur -> etat == TRUE && croupier -> etat == FALSE))
        {
            if(!joueur->assurance)
            {
                joueur->argent += joueur->mise;
                printf("Le joueur gagne\n");
            }
            else
            {
                printf("Le joueur gagne mais perd son assurance\n");
                joueur->argent += joueur->mise;
            }
            
            
        }
        else
        {
            printf("Egalité\n");
        }
    }
    
    //AfficherP(p);
}




void saisieArgent(joueur* joueur)
{
    do
    {
        printf("Vous avez %d argents\n", joueur->argent);
        printf("Quelle est votre mise pour cette partie: ");
        joueur->mise = saisieEntier();
        printf("\n");
        if(joueur->mise > joueur->argent)
        {
            printf("Erreur vous avez misez plus que votre argent\n");
        }

    } while (joueur->mise > joueur->argent);
}

void debutDuJeu(joueur* croupier, joueur* joueur, paquet p)
{
    creationJoueur(croupier, joueur);
    croupier -> carte = NULL;
    joueur -> carte = NULL;
    joueur -> somme = 0;
    croupier -> somme = 0;
    joueur -> etat = TRUE;
    croupier -> etat = TRUE;
    joueur -> mise = 0;
    croupier -> mise = -1; 
    /*Gerer blackJack*/
    joueur -> blackjack = FALSE;
    croupier -> blackjack = FALSE;
    croupier -> assurance = FALSE;
    joueur -> assurance = FALSE;
    /*logique que ca marche pas verifier joueur->somme*/

    saisieArgent(joueur);
    tourDeJeu(croupier, joueur, p);
    int resultat = 1;    
    printf("Voulez vous rejouez ?\n");
    printf("1- Oui\n");
    printf("2- Non\n");
    resultat = saisieEntier() - 1;
    while (!resultat)
    {
        /*refaire le menu*/
        /*ne pas melanger mettre juste a la fin de la liste*/
        melangerPaquet(&p);
        joueur -> somme = 0;
        croupier -> somme = 0;
        croupier -> carte = NULL;
        joueur -> carte = NULL;
        joueur -> etat = TRUE;
        croupier -> etat = TRUE;
        joueur -> mise = 0;
        croupier -> mise = -1; 
        /*Gerer blackJack*/
        joueur -> blackjack = FALSE;
        croupier -> blackjack = FALSE;
        saisieArgent(joueur);
        tourDeJeu(croupier, joueur, p);
        printf("Voulez vous rejouez ?\n");
        printf("1- Oui\n");
        printf("2- Non\n");
        resultat = saisieEntier() - 1;
    }
    printf("Merci d'avoir joué :), vous repartez avec %d €\n", joueur->argent);
}