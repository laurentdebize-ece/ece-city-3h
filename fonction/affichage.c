//
// Created by leque on 04/11/2022.
//

#include <math.h>
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

void cliqueMenuGeneral(city* c, int x, int y, int a, Color *Toolboxes, Color *couleurMaison1, Color *couleurMaison, Color *rond,
                  Color *rond1, Color *rond2, Color *rond3, Color noir, Color blanc) {
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
        blanc = WHITE;
        noir = BLACK;
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
        blanc = WHITE;
        noir = BLACK;
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
        blanc = WHITE;
        noir = BLACK;
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
        blanc = WHITE;
        noir = BLACK;
        DrawRectangleLines(x, y, espacement * 2, espacement * 2, *rond3);
        c->plateau[i][j].numero = 0;
        DrawTexture(c->tableau_element[c->plateau[i][j].numero].texture, x, y, *couleurMaison);
        c->joueur1.element_choisie = 9;

        a = 1;
    }

    if((GetMouseX() - (1100 / 2 + 240)) * (GetMouseX() - (1100 / 2 + 240)) + (GetMouseY() - 580) * (GetMouseY() - 580) < 40 * 40 && IsMouseButtonDown(1)){
        DrawText("Achat  ", 1100 / 2 + 95, 500, 20, noir);
        noir = BLANK;
        blanc= BLANK;
    }


    if (c->tableau_element[c->joueur1.element_choisie].prix > c->ece_flouz){
        DrawText("Vous ne pouvez pas acheter, ", 1100 / 2 + 95, 500, 20, noir);
        DrawText("par manque de moyens.", 1100 / 2 + 95, 520, 20, noir);
        noir = BLANK;
        blanc = BLANK;
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

void afficherToolBoxe3d(city c, Camera3D camera, city *c_adresse) {
    bool fin = false;
    char texte[15] = {0};
    int i = 0;
    int element = 1;
    Color color = WHITE;
    Texture2D fleche = LoadTexture("../image/fleche.png");
    Texture2D piece = LoadTexture("../image/piece.png");
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.position = (Vector3) {30.0f, 30.0f, 30.0f};
    while (!fin) {
        color = WHITE;
        i++;
        if (i > 1000) {
            i = 0;
        }
        if (WindowShouldClose()) {
            fin = true;
        }
        if (GetMouseX() > 500 && GetMouseX() < 700 && GetMouseY() > 600 && GetMouseY() < 650) {
            color = GREEN;
        }


        if (IsMouseButtonPressed(1)) {
            if (GetMouseX() > 1000 && GetMouseX() < 1159 && GetMouseY() > 250 && GetMouseY() < 409) {
                switch (element) {
                    case 1 :
                        element = 3;
                        break;
                    case 3 :
                        element = 8;
                        break;
                    case 8 :
                        element = 9;
                        break;
                    case 9 :
                        element = 1;
                        break;
                    default:
                        break;
                }

            }
            if (GetMouseX() > 49 && GetMouseX() < 200 && GetMouseY() > 250 && GetMouseY() < 409) {
                switch (element) {
                    case 1 :
                        element = 9;
                        break;
                    case 3 :
                        element = 1;
                        break;
                    case 8 :
                        element = 3;
                        break;
                    case 9 :
                        element = 8;
                        break;
                    default:
                        break;
                }

            }
            if (GetMouseX() > 500 && GetMouseX() < 700 && GetMouseY() > 600 && GetMouseY() < 650) {
                c_adresse->joueur1.element_choisie = element;
                fin = true;
            }
        }
        BeginDrawing();

        ClearBackground(BLACK);
        BeginMode3D(camera);
        DrawModel(c.tableau_element[element].model,
                  (Vector3) {0, 0, 0},
                  c.tableau_element[element].scale, WHITE);
        camera.position = (Vector3) {30.0f * cos(i * (2 * PI / 1000)), 30.0f, 30.0f * sin(i * (2 * PI / 1000))};
        EndMode3D();
        DrawTexture(fleche, 1000, 250, WHITE);
        DrawRectangleRounded((Rectangle) {500, 600, 200, 50}, 5, 5, color);
        DrawTexture(piece, 655, 605, WHITE);
        sprintf(texte, "%d", c.tableau_element[element].prix);
        DrawText(texte, 520, 610, 30, BLUE);
        DrawTextureEx(fleche, (Vector2) {200, 409}, 180, 1, WHITE);
        EndDrawing();

    }
    UnloadTexture(fleche);
    UnloadTexture(piece);
}

void poser_element(city *c, Camera3D camera, city *c_adresse) {
    Ray ray = {0};
    RayCollision collision = {0};
    bool clique_accepter = false;

    ray = GetMouseRay(GetMousePosition(), camera);
    collision = GetRayCollisionBox(ray, (BoundingBox) {(Vector3) {-45, 0, -35}, (Vector3) {45, 0, 35}});
    int x = collision.point.x / 2 + 23;
    int z = collision.point.z / 2 + 18;
    if(0 <= x && x <=45 && 0<=z && z<=33) {
        if (c->joueur1.element_choisie != 0) {
            c->plateau[x][z].numero = c->joueur1.element_choisie;
            if (IsMouseButtonPressed(1)) {
                if (c->joueur1.element_choisie != 1) {
                    for (int i = 0; i <= c_adresse->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                        for (int j = 0;
                             j <= c_adresse->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                            if (c_adresse->plateau[x + i][z - 1].numero == 1 ||
                                c_adresse->plateau[x + i][z +
                                                          c_adresse->tableau_element[c->joueur1.element_choisie].espacement_y].numero ==
                                1
                                || c_adresse->plateau[x - 1][z + j].numero == 1 ||
                                c_adresse->plateau[x + c->tableau_element[c->joueur1.element_choisie].espacement_x][z +
                                                                                                                    j].numero ==
                                1) {

                                clique_accepter = true;
                            }
                        }
                    }
                } else {
                    clique_accepter = true;
                }
                for (int i = 0; i <= c->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                    for (int j = 0; j <= c->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                        if (c_adresse->plateau[x + i][z + j].numero != 0) {
                            clique_accepter = false;

                        }
                    }
                }
            }

            if (clique_accepter) {
                if (c->joueur1.element_choisie == 3) {
                    c_adresse->plateau[x][z].
                            temps = GetTime() + 15;
                }
                for (int i = 0; i <= c->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                    for (int j = 0; j <= c->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                        c_adresse->plateau[x + i][z + j].numero = -c->joueur1.element_choisie;
                    }
                }
                c_adresse->plateau[x][z].numero = c->joueur1.element_choisie;
            }
        }
    }

}

void affichage3d(city c, Camera3D camera, city *c_adresse) {
    poser_element(&c, camera, c_adresse);

    BeginDrawing();

    ClearBackground(SKYBLUE);
    BeginMode3D(camera);
    DrawGrid(46, 2);
    for (int i = -colones - 1; i <= colones + 1; i += 2) {
        for (int j = -ligne - 1; j <= ligne + 1; j += 2) {
            DrawModel(c.tableau_element[0].model, (Vector3) {i, -0.1, j}, 1, WHITE);
        }
    }

    int i2 = 0;
    int j2 = 0;
    for (int i = 0; i <= (colones - 1) * 2; i += 2) {
        i2 = (i) / 2;
        for (int j = 0; j <= (ligne - 1) * 2; j += 2) {
            j2 = (j) / 2;
            if (c.plateau[i2][j2].numero >0) {
                if (c.plateau[i2][j2].numero == 1) {
                    //affichage_route(c, i, j, i2, j2);
                    affichageNiveauMoinsUn(c,i,j,i2,j2);
                } else {
                    if (c.plateau[i2][j2].numero == 9) {
                        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                                  (Vector3) {(float) 4 + (float) i +
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                             (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                                  (Vector3) {(float) 8 + (float) i +
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                             (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                                  (Vector3) {(float) 4 + (float) i +
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                             4 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                                  (Vector3) {(float) 8 + (float) i +
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                             4 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                                  (Vector3) {(float) i +
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                             4 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                    }
                    DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                              (Vector3) {(float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                         c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                         (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                              c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
                }
            }
        }
    }

    EndMode3D();
    DrawTexture(c.tableau_texture[0], 60, 20, WHITE);
    DrawTexture(c.tableau_texture[1], 260, 20, WHITE);
    DrawTexture(c.tableau_texture[2], 460, 20, WHITE);
    DrawTexture(c.tableau_texture[3], 660, 20, WHITE);
    DrawTexture(c.tableau_texture[4], 860, 20, WHITE);
    if (c.joueur1.element_choisie == 0){
        DrawTexture(c.tableau_texture[5], 1060, 5, WHITE);
    }
    else{
        if (GetMouseX() > 1060 && GetMouseX() < 1360 && GetMouseY() > 20 && GetMouseY() < 100) {
            DrawTexture(c.tableau_texture[7], 1060, 5, WHITE);
        }
        else{
            DrawTexture(c.tableau_texture[6], 1060, 5, WHITE);
        }
    }


    char texte[15] = {0};
    double temps = GetTime() - c.temps;
    sprintf(texte, "%.2lf",temps);
    DrawText(texte, 100, 25, 20, BLUE);
    sprintf(texte, "%d", c.ece_flouz);
    DrawText(texte, 300, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_habitant);
    DrawText(texte, 500, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_electricite);
    DrawText(texte, 700, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_eau);
    DrawText(texte, 900, 25, 20, BLUE);

    EndDrawing();
}

void affichage_route(city c, int i, int j, int i2, int j2) {
    int compteur = 0;
    if (c.plateau[i2 + 1][j2].numero == 1) {
        compteur++;
    }
    if (c.plateau[i2 - 1][j2].numero == 1) {
        compteur++;
    }
    if (c.plateau[i2][j2 + 1].numero == 1) {
        compteur++;
    }
    if (c.plateau[i2][j2 - 1].numero == 1) {
        compteur++;
    }
    if (compteur >= 3) {
        DrawModel(c.model_route[0],
                  (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                             -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
    } else if (c.plateau[i2 + 1][j2].numero == 1 && c.plateau[i2][j2 + 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-0.48f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -2.0f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 0, 0},
                    0,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    WHITE);
    } else if (c.plateau[i2 + 1][j2].numero == 1 && c.plateau[i2][j2 - 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-2.5f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -4.1f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    90,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    WHITE);
    } else if (c.plateau[i2 - 1][j2].numero == 1 && c.plateau[i2][j2 - 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-4.62f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -2.0f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    180,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    WHITE);

    } else if (c.plateau[i2 - 1][j2].numero == 1 && c.plateau[i2][j2 + 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-2.58f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               +0.1f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    -90,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    WHITE);

    } else if (c.plateau[i2 + 1][j2].numero == 1 || c.plateau[i2 - 1][j2].numero == 1) {
        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                  (Vector3) {(float) -2 + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                             -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                  c.tableau_element[c.plateau[i2][j2].numero].scale, WHITE);
    } else {
        DrawModelEx(c.tableau_element[c.plateau[i2][j2].numero].model,
                    (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -2.55f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    90,
                    (Vector3) {c.tableau_element[c.plateau[i2][j2].numero].scale,
                               c.tableau_element[c.plateau[i2][j2].numero].scale,
                               c.tableau_element[c.plateau[i2][j2].numero].scale},
                    WHITE);
    }
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

    if ((GetMouseX() - (1100 / 2 + 140)) * (GetMouseX() - (1100 / 2 + 140)) + (GetMouseY() - 580) * (GetMouseY() - 580) < 40 * 40 && IsMouseButtonPressed(1)){
        if (c->tableau_element[c->joueur1.element_choisie].prix <= c->ece_flouz) {
            c->ece_flouz = c->ece_flouz - c->tableau_element[c->joueur1.element_choisie].prix;
        }
    }
}
void affichageNiveauMoinsUn(city c,int i,int j,int i2,int j2) {
    Vector3 cubePosition = (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                      c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                      -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z };
    DrawCube(cubePosition, 2.0f, 0.5f, 1.8f, YELLOW);
}

/*
void relierMaisonChateau(maison m,chateauEau eau,int var,int var1){
    var =3;
    var1 =5;
    //initialiser mon tableau

    int ch[5]= {1,2,3,4,5};
    int ch1[5]= {5,6,7,8,9};

    for(int i=0;i<5;i++) {
        ch[i] = var + i;
        //printf("%d",ch[i]);
    }
    for(int i=0;i<5;i++) {
        ch1[i] = var1 + i;
        //printf("%d",ch1[i]);
    }
    int chemin=0;
    if (ch[0] < ch1[0]){
        if (){
            ch[0] = chemin;
            printf("oui");
        }

    }
    else {
        ch1[0] = chemin;
        printf("non");
    }
}
*/