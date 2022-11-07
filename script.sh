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

Pour generer doxygen si le fichier Doxyfile existe deja (cas normal):

> doxygen Doxyfile

Si le fichier Doxyfile n'existe pas

> doxygen -g  
> doxygen Doxyfile

**Attention**: Le fichier Doxyfile de base est different du fichier générer avec doxygen -g. Il faut utilisé cette commande que si le fichier Doxyfile **n'existe pas**.  
En effet le fichier Doxyfile depend du dossier [dataForDoxyfile](../dataForDoxyfile/) a ne **PAS** suprrimer. (voir [ici](https://jothepro.github.io/doxygen-awesome-css/md_docs_extensions.html) pour plus d'information sur le css)
" > ducoulombi-tp$y/exercice$i/README.md
cp Doxyfile ducoulombi-tp$y/exercice$i 
cp -R dataForDoxyfile ducoulombi-tp$y
done