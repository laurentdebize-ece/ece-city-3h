#include "../structure et macros/STRUCTURE.h"

void calcul(city * c){
    c->nb_habitant=0;
    c->nb_electricite=0;
    c->nb_eau=0;

    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c->nb_habitant += c->tableau_element[c->plateau[i][j].numero].nb_habitants;
            if(c->plateau[i][j].numero == 8){
                c->nb_electricite += 5000;
            }
            if(c->plateau[i][j].numero == 9){
                c->nb_eau += 5000;
            }

        }
    }
}
