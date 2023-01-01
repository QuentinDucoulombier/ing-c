# TP8 - Chaine de caractere
 
---

Auteur: Quentin Ducoulombier  
Date: 06/12/22  
Email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

### Pour compiler il suffit de se mettre dans le répertoire courant du dossier ducoulombi-tp7.b

> make  
> ./exe (avec la liste des arguments -> voir ./exe)
```bash
--------Exemple de formule---------
Pour le code cesar: ./exe -c cesar -d 5 -m "Bonjour les tekiens"
Pour le code de vigenere: ./exe -c vigenere -k "cle" -m "message"
Pour le codage de scytale: ./exe -c scytale -m "message a encrypte"
OU
Pour le code cesar: ./exe -c cesar
Pour le code de vigenere: ./exe -c vigenere
Pour le codage de scytale: ./exe -c scytale
```

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

