
#include "../structure et macros/include.h"

void evolution(c_element tab[colones][ligne], city *c) {
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {

            if (tab[i][j].temps < GetTime() && tab[i][j].temps != 0 && tab[i][j].numero >= 3) {
                c->ece_flouz += c->tableau_element[c->plateau[i][j].numero].nb_habitants * 10;
                if (tab[i][j].numero != 7) {
                    tab[i][j].numero++;
                }

                    if (c->plateau[i][j].numero == 3 ) {
                        if(c->nb_electricite > c->nb_habitant && c->plateau[i][j].temps==0) {
                            tab[i][j].temps = GetTime() + 15;
                        }
                    }
                    else {
                        tab[i][j].temps = GetTime() + 15;
                    }


            }
        }
    }
}


