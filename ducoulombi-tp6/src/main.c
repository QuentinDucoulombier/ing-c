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
 * 
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





/*int palindrome(char str[]) {
  int i, length = 0, flag = 0;

  //Find the length of string
  for (i = 0; str[i] != '\0'; i++) {
    length++;
  }
  printf("%d", length);

  for (i = 0; i < length; i++) {
    printf("debut %c\n", str[i]);
    printf("fin %c\n", str[length - i - 1]);
    if (str[i] != str[length - i - 1]) {
      flag = 1;
      break;
    }
  }

  if (flag) {
    return 0;
  } else {
    return 1;
  }
}
*/

int main() {
  caseMenu(affichageMenu());
  /*char str[100];

  printf("Enter a string\n");
  scanf("%s", str); //changer fonctions

  if (palindrome(str)) {
    printf("%s is a palindrome\n", str);
  } else {
    printf("%s is not a palindrome\n", str);
  }*/

  return 0;
}
