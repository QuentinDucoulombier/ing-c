#!/bin/bash

echo "veuillez saisir le numero du td"
read y;


mkdir -p ducoulombi-tp$y
touch ducoulombi-tp$y/main.c
touch ducoulombi-tp$y/README.md 
touch ducoulombi-tp$y/Makefile
echo -e "#include <stdio.h> \n\nint main(int argc, char *argv[])\n{\n\n    return (0);\n}" > ducoulombi-tp$y/main.c
echo -e "# \n 
---

Auteur: Quentin Ducoulombier  
Date: `date +"%d/%m/%y"`  
Email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

Pour compiler il suffit de se mettre dans le repertoire courant du dossier ducoulombi-tp$y

> make    
> ./exe

Pour effacer tous les fichier de compilation et de doxygen effectuer la commande

> make clean  

## Comment generer Doxygen ?

Pour generer doxygen si le fichier Doxyfile existe deja (cas normal):

> doxygen Doxyfile

Si le fichier Doxyfile n'existe pas

> doxygen -g  
> doxygen Doxyfile

**Attention**: Le fichier Doxyfile de base est different du fichier générer avec doxygen -g. Il faut utilisé cette commande que si le fichier Doxyfile **n'existe pas**.  
En effet le fichier Doxyfile depend du dossier [dataForDoxyfile](../dataForDoxyfile/) a ne **PAS** suprrimer. (voir [ici](https://jothepro.github.io/doxygen-awesome-css/md_docs_extensions.html) pour plus d'information sur le css)
" > ducoulombi-tp$y/README.md
cp Doxyfile ducoulombi-tp$y/
cp -R dataForDoxyfile ducoulombi-tp$y
cp Makefile ducoulombi-tp$y

mkdir ducoulombi-tp$y/src
mkdir ducoulombi-tp$y/bin
mkdir ducoulombi-tp$y/doc
mkdir ducoulombi-tp$y/save
