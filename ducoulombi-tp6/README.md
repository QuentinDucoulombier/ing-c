# TP6: tableaux statiques
 
---

Auteur: Quentin Ducoulombier  
Date: 30/11/22  
Email: ducoulombi@cy-tech.fr

---

## Comment compiler ?

Pour compiler il suffit de se mettre dans le repertoire courant du dossier ducoulombi-tp6

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

