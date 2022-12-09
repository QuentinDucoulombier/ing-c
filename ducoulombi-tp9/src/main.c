#include "jeu.h"

int main(int argc, char *argv[])
{
    /*carte test;
    test.valeur = ROI;
    test.couleur = trefle;
    printf("valeur: %d, couleur %d\n", test.valeur, test.couleur);*/

    carte paquet[52];
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 13; j++)
        {
            paquet[i * 13 + j].couleur = i;
            paquet[i * 13 + j].valeur = j + 1;
        }
    }
    melange(paquet);
    /*for(i = 0; i < 52; i++)
    {

        switch (paquet[i].couleur)
        {
        case 0:
            printf("couleur: carreau et valeur:%d\n", paquet[i].valeur);
            break; 
        case 1:
            printf("couleur: coeur et valeur:%d\n", paquet[i].valeur);
            break;
        case 2:
            printf("couleur: trefle et valeur:%d\n", paquet[i].valeur);
            break;
        case 3:
            printf("couleur: pique et valeur:%d\n", paquet[i].valeur);
            break;
        
        default:
            break;
        }
        //printf("couleur: %d et valeur:%d\n", paquet[i].couleur, paquet[i].valeur);
        }*/
    
    //regarder td2
    joueur joueur1;
    joueur* croupier = &joueur1;
    /*printf("Veuillez saisir votre nom\n");
    scanf("%s", croupier->nom);
    printf("Veuillez saisir votre prenom\n");
    scanf("%s", croupier->prenom);*/
    strcpy(croupier->nom, "croupier");
    strcpy(croupier->prenom, "michel");
    croupier->argent = 2000;
    donneCarte(paquet, croupier);
    //rajouter couleur et valeur pour carte
    printf("nom %s\nprenom %s\nargent%d\ncarte%d\n", croupier->nom, croupier->prenom, croupier->argent, croupier->carte.couleur);


    

    return (0);
}
