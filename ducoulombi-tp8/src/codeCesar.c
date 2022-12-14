/**
 * @file codeCesar.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-06
 * 
 * @brief 
 * 
 */

#include "codeCesar.h"
#include "fonctions.h"

/*char* codeCesar(char* str)
{
    return void;
}*/

/*
void codeCesar(long taille, char* chaine, char chaineSortie[strlen(chaine)])
{
    long j = 0; 
    int k = 0;
    //cas ou l'encrement est superieur a 26
    if(taille > 26)
    {
        //on fait le modulo
        taille = taille % 26;
    }

    for (int i = 0; i < strlen(chaine); i++)
    {
        j = 0;
        while (toupper(chaine[i]) != STR[j])
        {
            j++;
        }
        chaineSortie[k] = STR[j + taille];
        k++;
    }
    printf("chaine final fonction: %s\n", chaineSortie);
}
*/

char *codeCesar(char *str, int decalage) 
{
    if(decalage > 26)
    {
        //on fait le modulo
        decalage = decalage % 26;
    }
    char *strCrypte = malloc(strlen(str) + 1);
    int i;
    for (i = 0; i < strlen(str); i++) {
        int codeAscii = str[i];
        if (codeAscii >= 65 && codeAscii <= 90) {
            codeAscii += decalage;
            if (codeAscii > 90) {
                codeAscii -= 26;
            }
        } else if (codeAscii >= 97 && codeAscii <= 122) {
            codeAscii += decalage;
            if (codeAscii > 122) {
                codeAscii -= 26;
            }
        }
        strCrypte[i] = codeAscii;
    }
    strCrypte[i] = '\0';
    return strCrypte;
}

char* codeDeVigenere(char* str)
{
    
}
