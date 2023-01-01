/**
 * @file affichage.c
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief Fichier de l'ensemble des fonctions pour l'affichage
 * 
 */
#include "affichage.h"
#include "jeu.h"


void afficheCarte(int couleur, int chiffre, int valeur)
{
    /*Ascii art pour valets, rennes et rois https://ascii.co.uk/art/cards*/
    switch (chiffre)
    {
    case 1:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|         |\n|    %s    |\n|         |\n|         |\n|        %d|\n└─────────┘", chiffre, "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 2:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|        %d|\n└─────────┘", chiffre, "♠",  "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 3:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|    %s    |\n|         |\n|    %s    |\n|         |\n|    %s    |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 4:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|         |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 5:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|    %s    |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 6:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break;
    case 7:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 8:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d        |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|        %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 9:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s %d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 10:
        switch (couleur)
        {
        case 0:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦", "♦",chiffre);
            break;
        case 1:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥", "♥",chiffre);
            break;
        case 2:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣", "♣",chiffre);
            break;
        case 3:
            printf("\n┌─────────┐\n|%d%s   %s  |\n|    %s    |\n|  %s   %s  |\n|         |\n|  %s   %s  |\n|    %s    |\n|  %s   %s%d|\n└─────────┘", chiffre, "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠", "♠",chiffre);
            break;
        default:
            printf("erreur");
            break;
        }
        break; 
    case 11:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♦ ( o\\   |\n|  ! \\l   |\n| ^^^Xvvv |\n|   l\\ I  |\n|   \\o ) ♦|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♥ %% *`.  |\n|  %% <~   |\n| %%%% / %%%% |\n|   _> %%  |\n|  `,* %% ♥|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♣ ! -\\   |\n|  \\ -!   |\n|  ',\\\',  |\n|   I- \\  |\n|   \\- I ♣|\n|  ~|__/ V|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|V /~~|_  |\n|♠ | o`,  |\n|  | -|   |\n| =~)+(_= |\n|   |- |  |\n|  `.o | ♠|\n|  ~|__/ V|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    case 12:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♦ |o.o|  |\n|   \\v/   |\n|  XXOXX  |\n|   /^\\   |\n|  |o'o| ♦|\n|  |___| D|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♥ %%*,*%%  |\n|  \\_o_/  |\n|  /~o~\\  |\n|  %%*'*%%  |\n|  |o'o| ♥|\n|  |___| D|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♣ \\- -/  |\n| o |-|   |\n|  I %% I  |\n|   |-| o |\n|  /- -\\ ♣|\n|  |___| D|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|D |~~~|  |\n|♠ /o,o\\  |\n|  \\_-_/  |\n| _-~+_-~ |\n|  /~-~\\  |\n|  \\o`o/ ♠|\n|  |___| D|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    case 13:
        switch (couleur)
            {
            case 0:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♦ |o.o|  |\n|   \\v/   |\n|  XXOXX  |\n|   /^\\   |\n|  |o'o| ♦|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 1:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♥ %%*,*%%  |\n|  \\_o_/  |\n|  /~o~\\  |\n|  %%*'*%%  |\n|  |o'o| ♥|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 2:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♣ \\- -/  |\n| o |-|   |\n|  I %% I  |\n|   |-| o |\n|  /- -\\ ♣|\n|  |\\|/| R|\n└─────────┘");
                break;
            case 3:
                printf("\n┌─────────┐\n|R |/|\\|  |\n|♠ /o,o\\  |\n|  \\_-_/  |\n| _-~+_-~ |\n|  /~-~\\  |\n|  \\o`o/ ♠|\n|  |\\|/| R|\n└─────────┘");
                break;
            default:
                printf("erreur");
                break;
            }
            break;
    default:
        printf("Couleur inconnu\n");
        break;
    }
    printf("\n");
}
