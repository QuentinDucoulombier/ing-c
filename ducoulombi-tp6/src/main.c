/**
 * @file main.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-02
 * 
 * @brief 
 * 
 */


#include "fonctions.h"
#include "puissance4.h"
#include "menu.h"


/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-30
 * 
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
  //caseMenu(affichageMenu());
    char str_mot[M];

    printf("Entrez une chaine: ");
    scanf("%s", str_mot); //changer fonctions

    if (palindrome(str_mot)) 
    {
        printf("%s est un palindrome\n", str_mot);
    } 
    else 
    {
        printf("%s n'est pas un palindrome\n", str_mot);
    }

    return 0;
}
