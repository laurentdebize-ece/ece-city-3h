
#include "../structure et macros/include.h"

void evolution(c_element tab[colones][ligne], city *c) {
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (tab[i][j].temps < (GetTime()-c->temps) && tab[i][j].temps != 0 && tab[i][j].numero >= 3) {
                c->ece_flouz += c->tableau_element[c->plateau[i][j].numero].nb_habitants * 10;
                if (tab[i][j].numero != 7) {
                    tab[i][j].numero++;
                }
                tab[i][j].temps = (GetTime()-c->temps) + 15;
            }
        }
    }
}


