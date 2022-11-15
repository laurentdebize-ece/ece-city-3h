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

void afficherToolBoxe( Color Toolboxes ){
    DrawRectangleLines(1100/2 + 100, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5+100, 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 +100, 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5 +100, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2 +100, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 + 5+100, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90 +100, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5+100, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100, 300, 80, 80, Toolboxes);
    DrawText("maison", 1100 / 2 + 5+100, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90 +100, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5+100, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100, 400, 80, 80, Toolboxes);
    DrawText("elec", 1100 / 2+100 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90+100, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 +100 +5, 400, 20, Toolboxes);


}

void aggrandirRectangle( int x, int y,Color Toolboxes){

    x = GetMouseX();
    y = GetMouseY();

    if ( x > 1100/2 +100 && x < 1100/2 + 80 +100 && y > 100 && y < 180){
        DrawRectangleLines(1100/2 +100- 1,100-1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 100 && y < 180){
        DrawRectangleLines(1100/2 +100+90 - 1,100 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +100 && x < 1100/2 + 80 +100 && y > 200 && y < 280 ){
        DrawRectangleLines(1100/2 +100- 1,200 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 200 && y < 280 ){
        DrawRectangleLines(1100/2 +100+90 - 1,200 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +100 && x < 1100/2 + 80 +100 && y > 300 && y < 380 ){
        DrawRectangleLines(1100/2 +100- 1,300 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 300 && y < 380){
        DrawRectangleLines(1100/2 +100+90 - 1,300 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +100 && x < 1100/2 + 80 +100 && y > 400 && y < 480 ){
        DrawRectangleLines(1100/2 +100- 1,400 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 400 && y < 480 ){
        DrawRectangleLines(1100/2 +100+90 - 1,400 -1 , 80+2, 80+2, Toolboxes);
    }
}


int clickNiveauUn(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 +100 && x < 1100 / 2 + 80 +100 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauDeux(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 +100 && x < 1100 / 2 + 160 +100 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauZero(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2  +100 && x < 1100/2 + 80 +100 && y > 200 && y < 280 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauBack(int x,int y){
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 200 && y < 280 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseMaison(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 +100 && x < 1100 / 2 + 80 +100 && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseRoute(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 +90 +100 && x < 1100/2 + 160 +100 && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseElec(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 +100 && x < 1100/2 + 80+100  && y > 400 && y < 480 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseEau(int x,int y){
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100/2 +90 +100  && x < 1100/2 + 160+100  && y > 400 && y < 480) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

void afficherNiveau1( Color Toolboxes){
    DrawRectangleLines(1100/2+100, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2+100 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +100+90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +100+90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2+100, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 +100+ 5, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 +100+ 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 +100+ 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2+100, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2+100 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 +100+ 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2+100, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2 +100+ 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100 +90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 +100+ 90 + 5, 400, 20, Toolboxes);
}

void afficherNiveau2(Color Toolboxes){
    DrawRectangleLines(1100/2+100, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +100+90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +100+90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2+100, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 +100+ 5, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 +100+ 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 +100+ 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2+100, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2 +100+ 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 +100+ 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2+100, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2+100 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 +100+ 90 + 5, 400, 20, Toolboxes);
}

void afficherNiveau0(Color Toolboxes){
    DrawRectangleLines(1100/2+100, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +100+5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +100+90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +100+90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2+100, 200, 80, 80, Toolboxes);
    DrawText("0", 1100 / 2 +100+ 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2+100 + 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2 +100 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 +100+ 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2+100, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2 +100+ 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 +100+ 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 +100+ 90 + 5, 400, 20, Toolboxes);
}


void affichageCercleAchat(Color noir, Color blanc){
    DrawText("Voulez-vous acheter? ", 1100 / 2 + 95, 520, 20, noir);

    DrawCircle(1100 / 2 + 140, 580, 40, noir);
    DrawText("OUI ", 1100 / 2 + 120, 570, 20, blanc);

    DrawCircle(1100 / 2 + 240, 580, 40, noir);
    DrawText("NON ", 1100 / 2 + 220, 570, 20, blanc);
}

void achat(city* c,Color noir, Color blanc){
    affichageCercleAchat(noir, blanc);
    // si il clique sur oui
    if ((GetMouseX() - (1100 / 2 + 140)) * (GetMouseX() - (1100 / 2 + 140)) + (GetMouseY() - 580) * (GetMouseY() - 580) < 40 * 40 && IsMouseButtonPressed(1)){
        // qu'il a assez d'argent
        if (c->tableau_element[c->joueur1.element_choisie].prix <= c->ece_flouz) {
            c->ece_flouz = c->ece_flouz - c->tableau_element[c->joueur1.element_choisie].prix;
            // s'il achete une centrale elec
        }
    }
}