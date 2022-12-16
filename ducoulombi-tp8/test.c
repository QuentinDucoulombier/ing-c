#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* vigenere_encrypt(char* str, char* key) {
  int str_length = strlen(str);
  int key_length = strlen(key);

  // Allouer de l'espace mémoire pour stocker le message chiffré
  char* str_encrypted = malloc(str_length + 1);

  for (int i = 0, j = 0; i < str_length; i++) {
    // Si le caractère n'est pas une lettre, on le laisse inchangé.
    if (!isalpha(str[i])) {
      str_encrypted[i] = str[i];
      continue;
    }

    // On met la clé en minuscule pour faciliter le traitement.
    char k = tolower(key[j % key_length]);

    // On utilise l'opérateur ternaire pour déterminer si le caractère de str est en majuscule ou non.
    // Si c'est le cas, on utilise la formule de chiffrement pour les majuscules.
    // Sinon, on utilise la formule de chiffrement pour les minuscules.
    char c = isupper(str[i]) ? 'A' + (str[i] - 'A' + k - 'a') % 26 : 'a' + (str[i] - 'a' + k - 'a') % 26;

    // On ajoute le caractère chiffré à la chaîne de caractères chiffrée.
    str_encrypted[i] = c;

    // On passe à la lettre suivante de la clé.
    j++;
  }

  // Ajouter le caractère de fin de chaîne à la fin de la chaîne chiffrée
  str_encrypted[str_length] = '\0';

  return str_encrypted;
}

int main(void) {
  char str[] = "Bonjour, comment vas-tu?";
  char key[] = "cle";

  printf("Message original: %s\n", str);
  char* str_encrypted = vigenere_encrypt(str, key);
  printf("Message chiffré: %s\n", str_encrypted);

  // Ne pas oublier de libérer l'espace mémoire alloué pour le message chiffré
  free(str_encrypted);

  return 0;
}
