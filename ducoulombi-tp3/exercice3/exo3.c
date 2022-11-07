/**
 * @file exo3.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fichier pour voir le probleme d'appel de fonction
 * 
 */
#include <stdio.h> 

/**
 * @fn void echange(int int_nb1, int int_nb2)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction qui echange deux variables
 * 
 * @param int_nb1 
 * @param int_nb2 
 */
void echange(int int_nb1, int int_nb2)
{
    int int_tmp = 0;
    printf("Avant echange\nNb1 = %d\nNb2 = %d\n", int_nb1, int_nb2);
    int_tmp = int_nb1;
    int_nb1 = int_nb2;
    int_nb2 = int_tmp;
    //l'echange fonctionne correctement
    printf("Apres echange\nNb1 = %d\nNb2 = %d\n", int_nb1, int_nb2);
}


/**
 * @fn int main(int argc, char *argv[])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @brief fonction Main qui appel la fonction echange et qui met en evidence le probleme d'appel de fonction
 * 
 * @param argc 
 * @param argv 
 * @return 0 si pas d'erreur
 */
int main(int argc, char *argv[])
{
    int int_nb1;
    int int_nb2;
    int_nb1 = 5;
    int_nb2 = 7;
    printf("Avant appel de la fonction\nNb1 = %d\nNb2 = %d\n", int_nb1, int_nb2);
    printf("Appel de la fonction échange\n");
    echange(int_nb1, int_nb2);
    //L'echange ne marche pas car ce n'est pas des pointeurs
    printf("Apres appel de la fonction\nNb1 = %d\nNb2 = %d\n", int_nb1, int_nb2);
    return (0);
}
