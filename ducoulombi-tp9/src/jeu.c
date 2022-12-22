/**
 * @file jeu.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * TODO:
 *  - Verifier si le blackjack marche
 *  - Ne pas melanger mettre juste a la fin de la liste
 *  - Modifier le truc de blackjack ligne 570
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
            //printf("\n"); test a faire
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

void afficheCarte(int couleur, int chiffre, int valeur)
{
    /*Ascii art pour valets, rennes et rois https://ascii.co.uk/art/cards*/
    switch (chiffre)
    {
    case 1:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 2:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♠",  "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 3:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 4:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 5:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 6:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 7:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 8:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 9:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 10:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 11:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♦ ( o\\   |\n|  ! \\l   |\n| ^^^Xvvv |\n|   l\\ I  |\n|   \\o ) ♦|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♥ %% *`.  |\n|  %% <~   |\n| %%%% / %%%% |\n|   _> %%  |\n|  `,* %% ♥|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♣ ! -\\   |\n|  \\ -!   |\n|  ',\\\',  |\n|   I- \\  |\n|   \\- I ♣|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♠ | o`,  |\n|  | -|   |\n| =~)+(_= |\n|   |- |  |\n|  `.o | ♠|\n|  ~|__/ V|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    case 12:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♦ |o.o|  |\n|   \\v/   |\n|  XXOXX  |\n|   /^\\   |\n|  |o'o| ♦|\n|  |___| D|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♥ %%*,*%%  |\n|  \\_o_/  |\n|  /~o~\\  |\n|  %%*'*%%  |\n|  |o'o| ♥|\n|  |___| D|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♣ \\- -/  |\n| o |-|   |\n|  I %% I  |\n|   |-| o |\n|  /- -\\ ♣|\n|  |___| D|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♠ /o,o\\  |\n|  \\_-_/  |\n| _-~+_-~ |\n|  /~-~\\  |\n|  \\o`o/ ♠|\n|  |___| D|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    case 13:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♦ |o.o|  |\n|   \\v/   |\n|  XXOXX  |\n|   /^\\   |\n|  |o'o| ♦|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♥ %%*,*%%  |\n|  \\_o_/  |\n|  /~o~\\  |\n|  %%*'*%%  |\n|  |o'o| ♥|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♣ \\- -/  |\n| o |-|   |\n|  I %% I  |\n|   |-| o |\n|  /- -\\ ♣|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♠ /o,o\\  |\n|  \\_-_/  |\n| _-~+_-~ |\n|  /~-~\\  |\n|  \\o`o/ ♠|\n|  |\\|/| R|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    default:
        printf("Couleur inconnu\n");
        break;
    }
    printf("\n");
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


/*Pas utile
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
}*/

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

/*Debuger aaaaaaaaaaaaaaaah*/
int verifJeu(joueur* joueur, int etat)
{
    /*Faire le cas ou ca tombe direct sur 21*/
    if(!etat) //etat == 0
    {
        joueur->somme += joueur->carte->valeur;
        printf("Somme ici %d\n", joueur->somme);
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

/*Debuger aaaaaaaaah*/
void tourDeJeu(joueur* croupier, joueur* joueur, paquet p)
{
    int out;
    int etat = 0;
    joueur -> as = FALSE;
    croupier -> as = FALSE;
    donneCarte(&p, joueur);
    joueur->somme += joueur->carte->valeur;
    donneCarte(&p, croupier);
    /*Premiere carte du croupier*/
    printf("Premiere carte du croupier\n");
    AfficherP(croupier->carte);
    croupier->somme += croupier->carte->valeur;
    donneCarte(&p, joueur);
    donneCarte(&p, croupier);
    printf("Carte du joueur\n");
    AfficherP(joueur->carte);
    /*Ne pas afficher les cartes du croupier*/
    //printf("Carte du croupier\n");
    //AfficherP(croupier->carte);
    //AfficherP(p);
    /*pas de sens car on fait qu'une seule fois la somme (wtf)*/
    printf("Au tour du joueur\n");
    if(joueur->somme == 21)
    {
        printf("Felicitation vous avez fait blackjack\n");
        joueur -> blackjack = TRUE;
    }
    else if(croupier->somme == 21)
    {
        printf("Le croupier a fait blackjack\n");
        joueur -> blackjack = TRUE;
    }
    
    /*Verifie le cas du blackjack*/
    if(joueur->blackjack && !croupier->blackjack)
    {
        joueur->argent += joueur->mise;
        printf("Le joueur gagne\n");
    }
    else if (croupier->blackjack && !joueur->blackjack)
    {
        joueur->argent -= joueur->mise;
        printf("Le croupier gagne\n");
    }
    else if (croupier->blackjack && joueur->blackjack)
    {
        printf("egalité");
    }
    /*Tous les autres cas*/
    else
    {
        /*Joueur 1*/
        while(verifJeu(joueur, etat))
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
        }
        printf("Au tour du croupier\n");
        printf("Carte du croupier\n");
        AfficherP(croupier->carte);
        /*Croupier*/
        if(joueur -> etat == TRUE)
        {
            etat = 0;
            while(verifJeu(croupier, etat))
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
            }
        }

        if((croupier -> somme > joueur -> somme && joueur -> etat == TRUE && croupier -> etat == TRUE) || (joueur -> etat == FALSE && croupier -> etat == TRUE))//croupier -> etat == TRUE
        {
            joueur->argent -= joueur->mise;
            printf("Le croupier gagne\n");
        }
        else if ((croupier -> somme < joueur -> somme && joueur -> etat == TRUE && croupier -> etat == TRUE) || (joueur -> etat == TRUE && croupier -> etat == FALSE))
        {
            joueur->argent += joueur->mise;
            printf("Le joueur gagne\n");
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
    /*logique que ca marche pas verifier joueur->somme*/

    saisieArgent(joueur);
    tourDeJeu(croupier, joueur, p);
    int resultat = 1;    
    printf("Voulez vous rejouez ?\n");
    printf("1- Non\n");
    printf("2- Oui\n");
    resultat = saisieEntier() - 1;
    while (resultat)
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
        if(joueur->somme == 21)
        {
            printf("Felicitation vous avez fait blackjack\n");
            joueur -> blackjack = TRUE;
        }
        if(croupier->somme == 21)
        {
            printf("Le croupier a fait blackjack\n");
            joueur -> blackjack = TRUE;
        }
        saisieArgent(joueur);
        tourDeJeu(croupier, joueur, p);
        printf("Voulez vous rejouez ?\n");
        printf("1- Non\n");
        printf("2- Oui\n");
        resultat = saisieEntier() - 1;
    }
    printf("Merci d'avoir joué :), vous repartez avec %d €\n", joueur->argent);
}