//
// Created by leque on 04/11/2022.
//

#include "../structure et macros/include.h"

void affichage(city c, int x, int y, Color couleurMaison) {
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
                DrawTexture(c.tableau_element[c.plateau[i][j].numero].texture, j * espacement + positionFenetre,
                            i * espacement + positionFenetre, WHITE);
            }
        }
    }

    EndDrawing();

}

void afficherSurLaSouris(city c, Color couleurMaison, int x, int y) {
    int i = 0;
    int j = 0;
    DrawTexture(c.tableau_element[c.plateau[i][j].numero].texture, x,
                y, couleurMaison);

}

void afficherToolBoxe(city c, Color Toolboxes, Color couleurMaison1) {
    DrawRectangleLines(1100 / 2 + 100, 100, 80, 80, BLACK);
    DrawText("-1", 1100 / 2 + 5 + 100, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90 + 100, 100, 80, 80, BLACK);
    DrawText("-2", 1100 / 2 + 90 + 5 + 100, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 100, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 + 5 + 100, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90 + 100, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5 + 100, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 100, 300, 80, 80, Toolboxes);
    DrawText("maison", 1100 / 2 + 5 + 100, 300, 20, Toolboxes);
    DrawTexture(c.tableau_element[3].texture, 1100 / 2 + 100 + 20, 300 + 20, couleurMaison1);


    DrawRectangleLines(1100 / 2 + 90 + 100, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5 + 100, 300, 20, Toolboxes);
    DrawTexture(c.tableau_element[1].texture, 1100 / 2 + 100 + 90 + 25, 300 + 30, couleurMaison1);


    DrawRectangleLines(1100 / 2 + 100, 400, 80, 80, Toolboxes);
    DrawText("elec", 1100 / 2 + 100 + 5, 400, 20, Toolboxes);
    DrawTexture(c.tableau_element[8].texture, 1100 / 2 + 100 + 20, 400 + 20, couleurMaison1);

    DrawRectangleLines(1100 / 2 + 90 + 100, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 + 100 + 5, 400, 20, Toolboxes);
    DrawTexture(c.tableau_element[9].texture, 1100 / 2 + 100 + 90 + 20, 400 + 20, couleurMaison1);


}

void aggrandirRectangle(int x, int y, Color Toolboxes) {

    x = GetMouseX();
    y = GetMouseY();

    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 100 && y < 180) {
        DrawRectangleLines(1100 / 2 + 100 - 1, 100 - 1, 80 + 2, 80 + 2, BLACK);
    }
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 100 && y < 180) {
        DrawRectangleLines(1100 / 2 + 100 + 90 - 1, 100 - 1, 80 + 2, 80 + 2, BLACK);
    }
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 200 && y < 280) {
        DrawRectangleLines(1100 / 2 + 100 - 1, 200 - 1, 80 + 2, 80 + 2, BLACK);
    }
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 200 && y < 280) {
        DrawRectangleLines(1100 / 2 + 100 + 90 - 1, 200 - 1, 80 + 2, 80 + 2, Toolboxes);
    }
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 300 && y < 380) {
        DrawRectangleLines(1100 / 2 + 100 - 1, 300 - 1, 80 + 2, 80 + 2, Toolboxes);
    }
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 300 && y < 380) {
        DrawRectangleLines(1100 / 2 + 100 + 90 - 1, 300 - 1, 80 + 2, 80 + 2, Toolboxes);
    }
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 400 && y < 480) {
        DrawRectangleLines(1100 / 2 + 100 - 1, 400 - 1, 80 + 2, 80 + 2, Toolboxes);
    }
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 400 && y < 480) {
        DrawRectangleLines(1100 / 2 + 100 + 90 - 1, 400 - 1, 80 + 2, 80 + 2, Toolboxes);
    }
}


int clickNiveauUn(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickNiveauDeux(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickNiveauZero(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 200 && y < 280) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickNiveauBack(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 200 && y < 280) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickCaseMaison(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickPlateau(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x < espacement * ligne + positionFenetre && x > positionFenetre && y < colones * espacement + positionFenetre &&
        y > positionFenetre) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickCaseRoute(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickCaseElec(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 100 && x < 1100 / 2 + 80 + 100 && y > 400 && y < 480) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}

int clickCaseEau(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 + 100 && x < 1100 / 2 + 160 + 100 && y > 400 && y < 480) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
    return 0;
}


void afficherEmplacementMaison(Color rond, Color rond1, Color rond2, Color rond3, int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    DrawRectangleLines(x, y, espacement * 3, espacement * 3, rond);
    DrawRectangleLines(x, y, espacement, espacement, rond1);
    DrawRectangleLines(x, y, espacement * 2, espacement * 2, rond2);
    DrawRectangleLines(x, y, espacement * 2, espacement * 2, rond3);
}

void
cliqueMenuGeneral(city* c, int x, int y, int a, Color *Toolboxes, Color *couleurMaison1, Color *couleurMaison, Color *rond,
                  Color *rond1, Color *rond2, Color *rond3) {
    x = GetMouseX();
    y = GetMouseY();

    if (clickNiveauUn(x, y) == 1) {

        *Toolboxes = BLANK;
        *couleurMaison1 = BLANK;
    }
    if (clickNiveauDeux(x, y) == 1) {

        *Toolboxes = BLANK;
        *couleurMaison1 = BLANK;

    }

    if (clickNiveauZero(x, y) == 1) {

        *Toolboxes = BLACK;
        *couleurMaison1 = WHITE;

    }

    if (clickNiveauBack(x, y) == 1) {

        *rond = BLANK;
        *rond1 = BLANK;
        *rond2 = BLANK;
        *rond3 = BLANK;

    }
    if (clickCaseMaison(x, y) == 1) {
        int i = 0;
        int j = 0;
        *couleurMaison = WHITE;
        *rond = BLACK;
        DrawRectangleLines(x, y, espacement * 3, espacement * 3, *rond);
        c->plateau[i][j].numero = 0;
        DrawTexture(c->tableau_element[c->plateau[i][j].numero].texture, x, y, *couleurMaison);
        c->joueur1.element_choisie = 3;
        a = 0;
    }
    if (clickCaseRoute(x, y) == 1) {
        int i = 0;
        int j = 0;
        *rond1 = RED;
        *couleurMaison = WHITE;
        DrawRectangleLines(x, y, espacement * 1, espacement * 1, *rond1);
        c->plateau[i][j].numero = 0;
        DrawTexture(c->tableau_element[c->plateau[i][j].numero].texture, x, y, *couleurMaison);
        c->joueur1.element_choisie = 1;
        a = 1;

    }
    if (clickCaseElec(x, y) == 1) {
        int i = 0;
        int j = 0;
        *couleurMaison = WHITE;
        *rond2 = DARKBROWN;
        DrawRectangleLines(x, y, espacement * 2, espacement * 2, *rond2);
        c->plateau[i][j].numero = 0;
        DrawTexture(c->tableau_element[c->plateau[i][j].numero].texture, x, y, *couleurMaison);
        c->joueur1.element_choisie = 8;
        a = 1;


    }
    if (clickCaseEau(x, y) == 1) {
        int i = 0;
        int j = 0;
        *couleurMaison = WHITE;
        *rond3 = DARKBLUE;
        DrawRectangleLines(x, y, espacement * 2, espacement * 2, *rond3);
        c->plateau[i][j].numero = 0;
        DrawTexture(c->tableau_element[c->plateau[i][j].numero].texture, x, y, *couleurMaison);
        c->joueur1.element_choisie = 9;

        a = 1;


    }
    if (clickPlateau(x, y) == 1 && c->joueur1.element_choisie != -1) {

        *rond = BLANK;
        *rond1 = BLANK;
        *rond2 = BLANK;
        *rond3 = BLANK;

        int j = (-100 + x) / 15;
        int i = (-100 + y) / 15;
        if (a == 1) {
            c->plateau[i][j].numero = 0;
        }
        if (a == 0) {
            c->plateau[i][j].temps = GetTime() + 15;
        }

        c->plateau[i][j].numero = c->joueur1.element_choisie;
        c->joueur1.element_choisie = -1;
        *couleurMaison = BLANK;
    }

}
