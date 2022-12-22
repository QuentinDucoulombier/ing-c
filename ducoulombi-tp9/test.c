#include <stdio.h>

// Enumération des valeurs possibles des cartes
typedef enum {
  AS, // As
  DEUX, // Deux
  TROIS, // Trois
  QUATRE, // Quatre
  CINQ, // Cinq
  SIX, // Six
  SEPT, // Sept
  HUIT, // Huit
  NEUF, // Neuf
  DIX, // Dix
  VALET, // Valet
  DAME, // Dame
  ROI // Roi
} valeur_t;

// Enumération des couleurs possibles des cartes
typedef enum {
  PIQUE, // Pique
  COEUR, // Coeur
  CARREAU, // Carreau
  TREFLE // Trèfle
} couleur_t;

// Structure représentant une carte
typedef struct {
  valeur_t valeur;
  couleur_t couleur;
} carte_t;

// Fonction pour afficher une carte en ASCII art
void afficher_carte(carte_t carte) {
  // On commence par afficher la bordure supérieure de la carte
  printf("+---------+\n");

  // Ensuite, on affiche la valeur de la carte
  switch (carte.valeur) {
    case AS:
      printf("|A       A|\n");
      break;
    case DEUX:
      printf("|2       2|\n");
      break;
    case TROIS:
      printf("|3       3|\n");
      break;
    case QUATRE:
      printf("|4       4|\n");
      break;
    case CINQ:
      printf("|5       5|\n");
      break;
    case SIX:
      printf("|6       6|\n");
      break;
    case SEPT:
      printf("|7       7|\n");
      break;
    case HUIT:
      printf("|8       8|\n");
      break;
    case NEUF:
      printf("|9       9|\n");
      break;
    case DIX:
      printf("|10     10|\n");
      break;
    case VALET:
      printf("|J       J|\n");
      break;
    case DAME:
      printf("|Q       Q|\n");
      break;
    case ROI:
      printf("|K       K|\n");
      break;
  }

  // On affiche ensuite la couleur de la carte
  switch (carte.couleur) {
    case PIQUE:
      printf("|   PIK   |\n");
      break;
    case COEUR:
      printf("|   COE   |\n");
      break;
    case CARREAU:
      printf("|   CAR   |\n");
     
    case TREFLE:
        printf("|   TRE   |\n");
    break;
    }

    // On affiche finalement la bordure inférieure de la carte
    printf("+---------+\n");
}

int main() {
    // On crée une carte de test
    carte_t carte;
    carte.valeur = DAME;
    carte.couleur = COEUR;

    // On affiche la carte
    afficher_carte(carte);

    return 0;
}
