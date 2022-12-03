#!/bin/bash

echo "veuillez saisir le numero du td"
read y;


mkdir -p ducoulombi-tp$y

mkdir ducoulombi-tp$y/src
mkdir ducoulombi-tp$y/bin
mkdir ducoulombi-tp$y/doc
mkdir ducoulombi-tp$y/save

touch ducoulombi-tp$y/src/main.c
touch ducoulombi-tp$y/README.md 
touch ducoulombi-tp$y/Makefile
echo -e "#include <stdio.h> \n\nint main(int argc, char *argv[])\n{\n\n    return (0);\n}" > ducoulombi-tp$y/src/main.c
echo -e "# \n 
---

Auteur: Quentin Ducoulombier  
Date: `date +"%d/%m/%y"`  
Email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

### Pour compiler il suffit de se mettre dans le répertoire courant du dossier ducoulombi-tp7.b

> make  
> ./exe

### Pour nettoyer les fichiers:

Pour les fichiers de compilation:  
> make clean  

Pour les fichiers de compilation et l'exécutable:
> make mrpoper  

Pour supprimer tous les fichiers précédents et les fichiers générés par doxygen:    
> make cleanAll  

## Comment générer Doxygen ?

### Pour générer doxygen si le fichier Doxyfile existe déjà **(cas normal)**:

> make doc  

Si vous voulez directement lancer la documentation vous pouvez utiliser:  
> make firefoxDoc  
> make operaDoc

### Si le fichier Doxyfile n'existe pas: 

> doxygen -g  
> doxygen Doxyfile

**Attention**: Le fichier Doxyfile de base est different du fichier générer avec doxygen -g. Il faut utilisé cette commande que si le fichier Doxyfile **n'existe pas**.  
En effet le fichier Doxyfile depend du dossier [dataForDoxyfile](../dataForDoxyfile/) a ne **PAS** supprimer. (voir [ici](https://jothepro.github.io/doxygen-awesome-css/md_docs_extensions.html) pour plus d'information sur le css)
" > ducoulombi-tp$y/README.md
cp Doxyfile ducoulombi-tp$y/
cp -R dataForDoxyfile ducoulombi-tp$y/doc
cp Makefile ducoulombi-tp$y


