#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* chiffrementScytale(char* message) 
{
    int longueur = strlen(message);
    char* strCrypte = malloc(longueur + 1);
    int dimension = ceil(sqrt(longueur));
    char grille[dimension][dimension];

    // Initialisation de la grille avec des espaces
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
        grille[i][j] = '.';
        }
    }

    // Remplissage de la grille avec le message
    int cpt = 0;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
        if (cpt < longueur) {
            grille[i][j] = message[cpt++];
        }
        }
    }

    // Lecture de la grille en colonnes pour obtenir le message crypté
    cpt = 0;
    for (int j = 0; j < dimension; j++) {
        for (int i = 0; i < dimension; i++) {
            if (grille[i][j] != '.') {
                strCrypte[cpt++] = grille[i][j];
            }
        }
    }
    strCrypte[cpt] = '\0';
    return strCrypte;
}

int main() {
  char message[] = "ceci est un message a crypter";
  printf("Message crypté : %s\n", chiffrementScytale(message));

  return 0;
}
