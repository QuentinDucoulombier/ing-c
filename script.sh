#!/bin/bash

echo "veuillez saisir le numero du td"
read y;
echo "veuillez rentrer le nombre d'exos"
read x

for (( i=1; i<=$x; i++ ))
do 
    mkdir -p ducoulombi-tp$y/exercice$i
    touch ducoulombi-tp$y/exercice$i/exo$i.c
    touch ducoulombi-tp$y/exercice$i/README.md 
    touch ducoulombi-tp$y/exercice$i/makefile #>>>> si besoin d'un makefile
    echo -e "#include <stdio.h> \n\nint main(int argc, char *argv[])\n{\n\n    return (0);\n}" > ducoulombi-tp$y/exercice$i/exo$i.c
    echo -e "# \n 
---

Auteur: Quentin Ducoulombier  
Date: `date +"%d/%m/%y"`  
Email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

Pour compiler il suffit de se mettre dans le repertoire courant du fichier helloWorld.c

> gcc -Wall exo$i.c -o exe  
> ./exe


## Comment generer Doxygen ?

Pour generer doxygen il existe deux solutions : 
La premiere manière

> doxygen -g
> doxygen Doxyfile

ou sinon 

> doxywizard
" > ducoulombi-tp$y/exercice$i/README.md
done