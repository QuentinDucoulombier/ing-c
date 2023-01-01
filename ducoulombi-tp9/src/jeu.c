/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * TODO:
 *  x- Verifier si le blackjack marche (oui)
 *  - Ne pas melanger mettre juste a la fin de la liste
 *  x- Modifier le truc de blackjack ligne 570 (c'est bon)
 *  x- Rajouter le fait de split les fonctions: assurance, blackjack...
 *  x- Le joueur ne peut pas faire de mise <=0
 *  x- Cree une fonction verifbinaire 
 *   - Verifier que le fait d'avoir un as modifie bien la valeur
 *   - Debug la fonction melanger
 *   - Verifier sur ubuntu que ca met bien en bold
 *  x- Ajouer les scores
 *   - Bug supprimer debut (tres bizarre)
 * 
 * @brief 
 * 
 */

#include "jeu.h"
#include "listes.h"

/*---------------------------------------------------*/
/*                Ensemble de fonctions local        */
/*---------------------------------------------------*/

/**
 * @fn int menuBin(int type)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief fonction local qui permet de laisser l'utilisateur saisir son choix a l'aide d'un petit menu binaire
 * 
 * @param type 
 * @return le choix de l'utilisateur
 */
int menuBin(int type)
{
    int resultat = 1;
    do
    {
        if(resultat>2 || resultat<1)
        {
            printf("Veuillez saisir un nombre entre 1 et 2\n");
        }
        if(type == 1)
        {
            printf("1- Oui\n");
            printf("2- Non\n");
        }
        else if (type == 2)
        {
            printf("1- Distribuer\n");
            printf("2- Rester\n");
        }
        
        
        resultat = saisieEntier();
    } while (resultat>2 || resultat<1);
    
    resultat -= 1;
    return(resultat);

}


/**
 * @fn void doubler(joueur* joueur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief procedure local qui permet de doubler la mise
 * 
 * @param joueur 
 */
void doubler(joueur* joueur)
{
    printf("Doubler votre mise ?\n");
    
    int bool_double = menuBin(1);
    if(!bool_double)
    {
        joueur->mise += joueur->mise;
        printf("Vous doublez votre mise !\nMise actuelle %d\n\n", joueur->mise);
    }

}

/**
 * @fn void assurance(joueur* croupier, joueur* joueur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief procedure locale qui permet au joueur de gerer l'assurance
 * 
 * @param croupier 
 * @param joueur 
 */
void assurance(joueur* croupier, joueur* joueur)
{
    if(croupier -> carte -> chiffre == AS)
    {
        croupier -> assurance = TRUE;
        printf("Le joueur peut choisir une assurance\n");
        printf("            --------------Explication-------------\n");
        printf("Pour cela, le joueur paye la moitié de sa mise initiale. Si le croupier fait Blackjack, le joueur perd sa mise mais se voit payer l assurance en double (donc bénéfice 0, perte 0). Si le croupier ne fait pas Blackjack, deux situations sont possibles : Premièrement, le joueur gagne ; il perd son assurance mais empoche l équivalent de sa mise initiale (bénéfice net 1/2 fois la mise initiale). Deuxièmement, le joueur perd ; il perd alors l assurance ainsi que sa mise (perte 1,5 fois la mise initiale).\n");
        printf("\nVoulez vous choisir une assurance ?\n");
        int reponse = menuBin(1);
        if(!reponse)
        {
            joueur->assurance = joueur->mise/2; //passe a true car >0
            joueur->argent -= joueur->assurance;
        }
    }
}

/**
 * @fn void blackJack(joueur* croupier, joueur* joueur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief procedure local qui permet de detecter un blackjack
 * 
 * @param croupier 
 * @param joueur 
 */
void blackJack(joueur* croupier, joueur* joueur)
{
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
}

/**
 * @fn void saisieArgent(joueur* joueur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2023-01-01
 * 
 * @brief precudure local qui permet de laisser l'utilisateur saisir une somme
 * 
 * @param joueur 
 */
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
        if(joueur->mise <= 0)
        {
            printf("Vous etes obligez de misez qql de chose de positif\n");
        }

    } while (joueur->mise > joueur->argent || joueur->mise <= 0);
}



/*---------------------------------------------------*/
/*        Ensemble de fonctions non local            */
/*---------------------------------------------------*/


void initialiserPaquet(paquet *p)
{
    // On crée un tableau contenant toutes les cartes du paquet
    chiffreCarte chiffres[] = {AS, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET, DAME, ROI};
    eCouleur couleurs[] = {carreau, coeur, trefle, pique};

    // On parcourt le tableau des cartes et on crée un objet carte pour chaque combinaison possible de chiffre et de couleur
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
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
    //carte temp = supprimerDebut(p);
    ajouterDebut(&(joueur -> carte), supprimerDebut(p));
    //ajouterFin(p, temp);
    /*Compte le nombre d'as dans le paquet du joueur*/
    if(joueur->carte->chiffre == AS)
    {
        joueur->as ++;
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
    do
    {
        vraiJoueur->argent = saisieEntier();
        if(vraiJoueur->argent <= 0)
        {
            printf("Veuillez saisir une valeure postive: ");
        }
    } while (vraiJoueur->argent <= 0);
    
    
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
                printf("Vous avez un as donc la somme devient");//Faire le cas ou ca tombe sur 21 et le cas ou il y a 2 as
                joueur->somme -= 10;
                //printf("as -> %d\n", joueur->as);
                joueur->as --; //Normalement ca marche
                //printf("as -> %d\n", joueur->as);
                printf("%d\n", joueur->somme);
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
    //printf("out fonction \n");
    return FALSE;
    
}




void aGagne(joueur* croupier, joueur* joueur, paquet p)
{
    int etat = 0;
    int out;
    if(joueur->blackjack && !croupier->blackjack)
    {
        joueur->argent += joueur->mise + joueur->mise/2;
        printf("\n\e[1mLe joueur gagne\e[m\n");
        joueur->score++;
    }
    else if (croupier->blackjack && !joueur->blackjack)
    {
        if(!joueur->assurance)
        {
            joueur->argent -= joueur->mise;
            printf("\n\e[1mLe croupier gagne\e[m\n");
            
        }
        else
        {
            joueur->argent += joueur->assurance;
            printf("Grace a votre assurance vous ne perdez rien\n");
        }
        croupier->score++;
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
            out = menuBin(2);
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
            printf("\n\e[1mLe croupier gagne\e[m\n");
            croupier->score++;
        }
        /*joueur gagne*/
        else if ((croupier -> somme < joueur -> somme && joueur -> etat == TRUE && croupier -> etat == TRUE) || (joueur -> etat == TRUE && croupier -> etat == FALSE))
        {
            if(!joueur->assurance)
            {
                joueur->argent += joueur->mise;
                printf("\n\e[1mLe joueur gagne\e[m\n");
                joueur->score++;
            }
            else
            {
                printf("Le joueur gagne mais perd son assurance\n");
                joueur->argent += joueur->mise;
                joueur->score++;
            }
            
            
        }
        else
        {
            printf("Egalité\n");
        }
    }
}


void tourDeJeu(joueur* croupier, joueur* joueur, paquet p)
{
    /*Variable et initialisation*/
    joueur -> as = FALSE;
    croupier -> as = FALSE;

    /*-------- On distribue les cartes --------*/
    //Premiere carte du joueur
    donneCarte(&p, joueur);
    joueur->somme += joueur->carte->valeur;

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
    /*On verifie s'il y a blackjack*/
    blackJack(croupier, joueur);
    /*Et on regarde qui gagne la partie*/
    aGagne(croupier,joueur, p);
}





void debutDuJeu(joueur* croupier, joueur* joueur, paquet p)
{
    /*On cree le joueur avec son nom, prenom, argent ...*/
    creationJoueur(croupier, joueur);

    /*On initialise toutes les variables*/
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
    joueur -> score = 0;
    croupier -> score = 0;
    
    /*Gere la mise*/
    saisieArgent(joueur);

    /*Lance la partie*/
    tourDeJeu(croupier, joueur, p);

    /*Propose au joueur de rejouer*/
    int resultat = 1;    
    //AfficherP(p);
    printf("Voulez vous rejouez ?\n");
    resultat = menuBin(1);
    /*Recommence la partie*/
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
        printf("Nouvelle partie !\n");
        printf("Score:\n- Joueur = %d\n- Croupier = %d\n\n", joueur->score, croupier->score);
        saisieArgent(joueur);
        tourDeJeu(croupier, joueur, p);
        printf("Voulez vous rejouez ?\n");
        resultat = menuBin(1);
    }
    /*Fin de la partie*/
    printf("Score:\n- Joueur = %d\n- Croupier = %d\n\n", joueur->score, croupier->score);
    printf("Merci d'avoir joué %s %s :), vous repartez avec %d €\n", joueur->prenom, joueur->nom, joueur->argent);
}