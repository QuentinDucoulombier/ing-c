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

int verifAlphabet(int codeAscii)
{
    /*Cas de l'alphabet en majuscule*/
    if (codeAscii >= 65 && codeAscii <= 90)
    {
        return(1);   //Retourne vrai
    }
    /*Cas de l'alphabet en minuscule*/
    else if (codeAscii >= 97 && codeAscii <= 122)
    {
        return(2);   //Retourne vrai aussi
    }
    else
    {
        return(0);   //Retourne faux
    }
    
}


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
       
        if (verifAlphabet(codeAscii) == 1)
        {
            codeAscii += decalage;
            if (codeAscii > 90)
            {
                codeAscii -= 26;
            }
        }
        else if (verifAlphabet(codeAscii) == 2)
        {
            codeAscii += decalage;
            if (codeAscii > 122)
            {
                codeAscii -= 26;
            }
        }
        
        strCrypte[i] = codeAscii;
    }
    strCrypte[i] = '\0';
    return(strCrypte);
}


char* codeDeVigenere(char* str, char* key)
{
    int messageLength = strlen(str);
    int keyLength = strlen(key);
    char* strCrypte = malloc(messageLength + 1);

    for (int i = 0; i < messageLength; i++)
    {
        int messageCharType = verifAlphabet((int) str[i]);
        if (messageCharType) //cas > 0 donc true 
        {
            /*Calcul de l'offset à appliquer en fonction de la clé*/
            int offset = (int) key[i % keyLength];
            /*Correspond au "a" en ascii*/
            if (offset >= 97)
            {
                offset -= 97;
            }
            /*Correspond au "A" en ascii*/
            else if (offset >= 65)
            {
                offset -= 65;
            }

            /*Appliquer l'offset au caractère du message*/
            /*Majuscule*/
            if (messageCharType == 1) 
            {
                strCrypte[i] = (char) (((int) str[i] - 65 + offset) % 26 + 65);
            }
            /*Minuscule*/
            else
            {
                strCrypte[i] = (char) (((int) str[i] - 97 + offset) % 26 + 97);
            }
        }
        /*Autre caracteres*/
        else
        {
            strCrypte[i] = str[i];
        }
    }

    // Ajouter le caractère de fin de chaîne
    strCrypte[messageLength] = '\0';
    return(strCrypte);
}

char* codeDeScytale(char* message) 
{
    int longueur = strlen(message);
    char* strCrypte = malloc(longueur + 1);
    int dimension = ceil(sqrt(longueur));
    char grille[dimension][dimension];

    /*Initialisation avec des . (oui des points parce qu'on va quand meme pas encrypté des points ca n'a pas de sens)*/
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++) 
        {
            grille[i][j] = '.';
        }
    }

    /*On remplit la grille avec le message*/
    int cpt = 0;
    for (int i = 0; i < dimension; i++) 
    {
        for (int j = 0; j < dimension; j++) 
        {
            if (cpt < longueur) 
            {
                grille[i][j] = message[cpt++];
            }
        }
    }

    /*On ecrit le message encrypté dans le nouveau string*/
    cpt = 0;
    for (int j = 0; j < dimension; j++) 
    {
        for (int i = 0; i < dimension; i++) 
        {
            if (grille[i][j] != '.') 
            {
                strCrypte[cpt++] = grille[i][j];
            }
        }
    }
    strCrypte[cpt] = '\0';
    return strCrypte;
}