#!/bin/bash

echo "veuillez rentrer le nombre d'exos"
read x

for (( i=1; i<=$x; i++ ))
do 
    #rm -r exercice$i >>> pour supprimer les fichier pour le test
    mkdir exercice$i
    touch exercice$i/exo$i.c
    touch exercice$i/README.md 
    #touch exercice$i/makefile >>>> si besoin d'un makefile
    echo -e "#include <stdio.h> \n\nint main(int argc, char *argv[])\n{\n\n    return (0);\n}" > exercice$i/exo$i.c
done