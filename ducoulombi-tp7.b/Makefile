# Commande non recursive
CC := gcc -Wall
#Copie pour save
CP := cp -t
#Supression pour clean
RM := rm -f

# Initialisation des dossiers
SRCDIR = ./src/
BINDIR = ./bin/
SAVEDIR = ./save/
DOCDIR = ./doc/

# Initialisation des fichier
RESTE = *.vscode *.bak *.old *~						#Ensemble des fichiers poubelle
SRC = $(wildcard $(SRCDIR)*.c) 						#Ensemble des fichiers c dans le dossier SRC
OBJ = $(subst $(SRCDIR), $(BINDIR), $(SRC:.c=.o))	#Ensemble des fichiers o dans le dossier BIN
HEAD = $(wildcard $(SRCDIR)*.h)						#Ensemble des fichiers h dans le dossier SRC
PROG := exe											#L'executable

# Pour compiler les fichiers c du dossier src
all: $(PROG)

$(PROG) : $(OBJ)
	$(CC) $^ -o $@

$(BINDIR)%.o : $(SRCDIR)%.c 
	$(CC) -c $^ -o $@

.PHONY : clean save	doc							#Effectue les commande meme si un fichier du meme nom existe

# Clean les .o et les fichiers poubelles
clean:
	$(RM) $(OBJ) $(PROG)
	$(RM) $(RESTE)
mrproper: clean
	$(RM) *.exe
cleanAll: mrproper
	$(RM) -r $(DOCDIR)/*

# Copie les fichiers dans la save
save:
	$(CP) $(SAVEDIR) $(SRC) $(HEAD)

restore:
	$(CP) $(SRCDIR) $(SAVEDIR)/*

doc:
	@doxygen Doxyfile
	@echo "la documentation à était crée"
	
firefoxDoc: doc
	@firefox $(DOCDIR)/html/index.html

operaDoc: doc
	@opera $(DOCDIR)/html/index.html