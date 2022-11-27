#include "../structure et macros/STRUCTURE.h"
#include "../structure et macros/include.h"


void calcul(city * c){
    //initialisation a 0 du nb d'habitant, d'elec et d'eau
    c->nb_habitant=0;
    c->nb_electricite=0;
    c->nb_eau=0;

    // on parcours toutes les cases
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            // si l'element choisi est compris entre 3 et 8,
            // il s'agit d'une cabane, ou d'une maison, ou d'un immmeuble, ou d'un gratte-ciel
            if(c->plateau[i][j].numero > 3 && c->plateau[i][j].numero < 8){
                // on incremente au nb d'habitant total, le nb d'habitant dans la construction
                c->nb_habitant += c->tableau_element[c->plateau[i][j].numero].nb_habitants;
            }
            // si l'element choisi est une central electrique
            if(c->plateau[i][j].numero == 8){
                // on ajoute au nb d'elec total, la capacité maximale d'une centrale
                c->nb_electricite += 5000;
            }
            // si l'element choisi est un chateau d'eau
            if(c->plateau[i][j].numero == 9){
                // on augmente le nb d'eau total du jeu
                c->nb_eau += 5000;
            }

        }
    }
}

