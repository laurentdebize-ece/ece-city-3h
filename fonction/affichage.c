//
// Created by leque on 04/11/2022.
//

#include "../structure et macros/include.h"

void affichage(city c) {
    BeginDrawing();
    ClearBackground(WHITE);

    DrawTexture(c.tableau_texture[0], 60, 20, WHITE);
    DrawTexture(c.tableau_texture[1], 260, 20, WHITE);
    DrawTexture(c.tableau_texture[2], 460, 20, WHITE);
    DrawTexture(c.tableau_texture[3], 660, 20, WHITE);
    DrawTexture(c.tableau_texture[4], 860, 20, WHITE);


    for (int i = positionFenetre; i < (ligne + 1) * espacement + positionFenetre; i += espacement) {
        DrawLine(i, positionFenetre, i, colones * espacement + positionFenetre, BLUE);
    }
    for (int i = positionFenetre; i < (colones + 1) * espacement + positionFenetre; i += espacement) {
        DrawLine(positionFenetre, i, ligne * espacement + positionFenetre, i, BLUE);
    }
    char texte[15] = {0};
    sprintf(texte, "%.2lf", GetTime());
    DrawText(texte, 100, 25, 20, BLUE);
    sprintf(texte, "%d", c.ece_flouz);
    DrawText(texte, 300, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_habitant);
    DrawText(texte, 500, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_electricite);
    DrawText(texte, 700, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_eau);
    DrawText(texte, 900, 25, 20, BLUE);
    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            if (c.plateau[i][j].numero != 0) {
                DrawTexture(c.tableau_element[c.plateau[i][j].numero].texture, i * espacement + positionFenetre,
                            j * espacement + positionFenetre, WHITE);
            }
        }
    }

    EndDrawing();
}