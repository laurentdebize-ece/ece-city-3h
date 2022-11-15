
#include "../structure et macros/include.h"

void evolution(c_element tab[colones][ligne]) {
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (tab[i][j].temps < GetTime() && tab[i][j].temps != 0 && tab[i][j].numero >= 3 ){
                tab[i][j].numero ++;
                if(tab[i][j].numero == 7){
                    tab[i][j].temps = 0;
                }
                else{
                    tab[i][j].temps = GetTime() + 15;
                }
            }
        }
    }
}