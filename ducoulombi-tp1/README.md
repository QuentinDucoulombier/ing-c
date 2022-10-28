# TD1 : Le Hello wolrd Francais :chicken:

---

Auteur: Quentin Ducoulombier  
date: 19/10/2022  
email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

Pour compiler il suffit de se mettre dans le repertoire courant du fichier helloWorld.c
```
>>gcc -Wall helloWorld.c -o exe
>>./exe
```

## Comment generer Doxygen ?

Pour generer doxygen il existe deux solutions : 
La premiere manière
```
>>doxygen -g
>>doxygen Doxyfile
```
ou sinon 
```
>> doxywizard
```

## A quoi servent les séquences d’échappement ?

Une séquence d'échappement est une combinaison de caractères qui a une signification autre que les caractères littéraux qu'elle contient 
Elle est marquée par un ou plusieurs caractères précédents  
(source : https://en.wikipedia.org/wiki/Escape_sequence)

Exemple :
- \\' apostrophe
- \\" guillemet. Valeur hexadécimale : 0x22 ;
- \\? point d'interrogation. Valeur hexadécimale : 0x3f ;
- \\ Barre oblique inversée. Valeur hexadécimale : 0x5c ;
- \\0 caractère nul. Valeur hexadécimale : 0x00 ;
- \\a Caractère d'appel audible. Valeur hexadécimale : 0x07 ;
- \\b retour arrière (backspace). Valeur hexadécimale : 0x08 ;
- \\f nouvelle page. Valeur hexadécimale : 0x0c ;
- \\n nouvelle ligne. Valeur hexadécimale : 0x0a ;
- \\r retour chariot. Valeur hexadécimale : 0x0d ;
