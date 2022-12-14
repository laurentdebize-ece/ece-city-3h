#include "../structure et macros/include.h"

void evolution(c_element tab[colones][ligne], city *c) {
    // parcourt de toutes les cases
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (tab[i][j].temps < (GetTime() - c->temps) && tab[i][j].temps != 0 && tab[i][j].numero >= 3) {
                // impot de 10 ECE_Flouz par habitant
                c->ece_flouz += c->tableau_element[c->plateau[i][j].numero].nb_habitants * 10;
                if (tab[i][j].numero != 7) {
                    // on incremente de 1 le numero puisqu'il y a évolution
                    int numero = tab[i][j].numero + 1;

                    // si la case est négative, il y a quelque chose dessus
                    for (int i2 = 0; i2 <= c->tableau_element[numero].espacement_x - 1; i2++) {
                        for (int j2 = 0; j2 <= c->tableau_element[numero].espacement_y - 1; j2++) {
                            c->plateau[i + i2][j + j2].numero = -numero;
                        }
                    }
                    tab[i][j].numero = numero;
                }
                // evolution toutes les 15 secondes
                tab[i][j].temps = (GetTime() - c->temps)+ 15;

            }

        }
    }
}




