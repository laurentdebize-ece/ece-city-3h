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

void cliqueMenuGeneral(city *c, int x, int y, int a, Color *Toolboxes, Color *couleurMaison1, Color *couleurMaison,
                       Color *rond,
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

    if ((GetMouseX() - (1100 / 2 + 240)) * (GetMouseX() - (1100 / 2 + 240)) +
        (GetMouseY() - 580) * (GetMouseY() - 580) < 40 * 40 && IsMouseButtonDown(1)) {
        DrawText("Achat  ", 1100 / 2 + 95, 500, 20, noir);
        noir = BLANK;
        blanc = BLANK;
    }


    if (c->tableau_element[c->joueur1.element_choisie].prix > c->ece_flouz) {
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
    if (0 <= x && x <= 45 && 0 <= z && z <= 33) {
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
                            temps = (GetTime()-c->temps) + 15;
                }
                for (int i = 0; i <= c->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                    for (int j = 0; j <= c->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                        c_adresse->plateau[x + i][z + j].numero = -c->joueur1.element_choisie;
                        c_adresse->plateau[x + i][z + j].reference_x = x;
                        c_adresse->plateau[x + i][z + j].reference_y = z;
                    }
                }
                c_adresse->plateau[x][z].numero = c->joueur1.element_choisie;
                achat(c_adresse);
            }
        }
    }

}
#define LETTER_BOUNDRY_SIZE     0.25f
#define TEXT_MAX_LAYERS         32
#define LETTER_BOUNDRY_COLOR    VIOLET
static Vector3 MeasureText3D(Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing)
{
    int len = TextLength(text);
    int tempLen = 0;                // Used to count longer text line num chars
    int lenCounter = 0;

    float tempTextWidth = 0.0f;     // Used to count longer text line width

    float scale = fontSize/(float)font.baseSize;
    float textHeight = scale;
    float textWidth = 0.0f;

    int letter = 0;                 // Current character
    int index = 0;                  // Index position in sprite font

    for (int i = 0; i < len; i++)
    {
        lenCounter++;

        int next = 0;
        letter = GetCodepoint(&text[i], &next);
        index = GetGlyphIndex(font, letter);

        // NOTE: normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all of the bad bytes using the '?' symbol so to not skip any we set next = 1
        if (letter == 0x3f) next = 1;
        i += next - 1;

        if (letter != '\n')
        {
            if (font.glyphs[index].advanceX != 0) textWidth += (font.glyphs[index].advanceX+fontSpacing)/(float)font.baseSize*scale;
            else textWidth += (font.recs[index].width + font.glyphs[index].offsetX)/(float)font.baseSize*scale;
        }
        else
        {
            if (tempTextWidth < textWidth) tempTextWidth = textWidth;
            lenCounter = 0;
            textWidth = 0.0f;
            textHeight += scale + lineSpacing/(float)font.baseSize*scale;
        }

        if (tempLen < lenCounter) tempLen = lenCounter;
    }

    if (tempTextWidth < textWidth) tempTextWidth = textWidth;

    Vector3 vec = { 0 };
    vec.x = tempTextWidth + (float)((tempLen - 1)*fontSpacing/(float)font.baseSize*scale); // Adds chars spacing to measure
    vec.y = 0.25f;
    vec.z = textHeight;

    return vec;
}

static void DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint)
{
    // Character index position in sprite font
    // NOTE: In case a codepoint is not available in the font, index returned points to '?'
    int index = GetGlyphIndex(font, codepoint);
    float scale = fontSize/(float)font.baseSize;

    // Character destination rectangle on screen
    // NOTE: We consider charsPadding on drawing
    position.x += (float)(font.glyphs[index].offsetX - font.glyphPadding)/(float)font.baseSize*scale;
    position.z += (float)(font.glyphs[index].offsetY - font.glyphPadding)/(float)font.baseSize*scale;

    // Character source rectangle from font texture atlas
    // NOTE: We consider chars padding when drawing, it could be required for outline/glow shader effects
    Rectangle srcRec = { font.recs[index].x - (float)font.glyphPadding, font.recs[index].y - (float)font.glyphPadding,
                         font.recs[index].width + 2.0f*font.glyphPadding, font.recs[index].height + 2.0f*font.glyphPadding };

    float width = (float)(font.recs[index].width + 2.0f*font.glyphPadding)/(float)font.baseSize*scale;
    float height = (float)(font.recs[index].height + 2.0f*font.glyphPadding)/(float)font.baseSize*scale;

    if (font.texture.id > 0)
    {
        const float x = 0.0f;
        const float y = 0.0f;
        const float z = 0.0f;

        // normalized texture coordinates of the glyph inside the font texture (0.0f -> 1.0f)
        const float tx = srcRec.x/font.texture.width;
        const float ty = srcRec.y/font.texture.height;
        const float tw = (srcRec.x+srcRec.width)/font.texture.width;
        const float th = (srcRec.y+srcRec.height)/font.texture.height;

        if (false) DrawCubeWiresV((Vector3){ position.x + width/2, position.y, position.z + height/2}, (Vector3){ width, LETTER_BOUNDRY_SIZE, height }, LETTER_BOUNDRY_COLOR);

        rlCheckRenderBatchLimit(4 + 4*backface);
        rlSetTexture(font.texture.id);

        rlPushMatrix();
        rlTranslatef(position.x, position.y, position.z);

        rlBegin(RL_QUADS);
        rlColor4ub(tint.r, tint.g, tint.b, tint.a);

        // Front Face
        rlNormal3f(0.0f, 1.0f, 0.0f);                                   // Normal Pointing Up
        rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);              // Top Left Of The Texture and Quad
        rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height);     // Bottom Left Of The Texture and Quad
        rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height);     // Bottom Right Of The Texture and Quad
        rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);              // Top Right Of The Texture and Quad

        if (backface)
        {
            // Back Face
            rlNormal3f(0.0f, -1.0f, 0.0f);                              // Normal Pointing Down
            rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);          // Top Right Of The Texture and Quad
            rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);          // Top Left Of The Texture and Quad
            rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height); // Bottom Left Of The Texture and Quad
            rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height); // Bottom Right Of The Texture and Quad
        }
        rlEnd();
        rlPopMatrix();

        rlSetTexture(0);
    }
}

// Draw a 2D text in 3D space
static void DrawText3D(Font font, const char *text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint)
{
    int length = TextLength(text);          // Total length in bytes of the text, scanned by codepoints in loop

    float textOffsetY = 0.0f;               // Offset between lines (on line break '\n')
    float textOffsetX = 0.0f;               // Offset X to next character to draw

    float scale = fontSize/(float)font.baseSize;

    for (int i = 0; i < length;)
    {
        // Get next codepoint from byte string and glyph index in font
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        // NOTE: Normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all of the bad bytes using the '?' symbol moving one byte
        if (codepoint == 0x3f) codepointByteCount = 1;

        if (codepoint == '\n')
        {
            // NOTE: Fixed line spacing of 1.5 line-height
            // TODO: Support custom line spacing defined by user
            textOffsetY += scale + lineSpacing/(float)font.baseSize*scale;
            textOffsetX = 0.0f;
        }
        else
        {
            if ((codepoint != ' ') && (codepoint != '\t'))
            {
                DrawTextCodepoint3D(font, codepoint, (Vector3){ position.x + textOffsetX, position.y, position.z + textOffsetY }, fontSize, backface, tint);
            }

            if (font.glyphs[index].advanceX == 0) textOffsetX += (float)(font.recs[index].width + fontSpacing)/(float)font.baseSize*scale;
            else textOffsetX += (float)(font.glyphs[index].advanceX + fontSpacing)/(float)font.baseSize*scale;
        }

        i += codepointByteCount;   // Move text bytes counter to next codepoint
    }
}

void affichage3d(city c, Camera3D camera, city *c_adresse,Color couleur,Color couleur1) {
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

    int x= GetMouseX();
    int y=GetMouseY();
    int i2 = 0;
    int j2 = 0;
    for (int i = 0; i <= (colones - 1) * 2; i += 2) {
        i2 = (i) / 2;
        for (int j = 0; j <= (ligne - 1) * 2; j += 2) {
            j2 = (j) / 2;

            if (c.plateau[i2][j2].numero > 0) {
                if (c.plateau[i2][j2].numero == 1) {
                    affichageNiveauMoinsUn(c, i, j, i2, j2, couleur);
                    affichage_route(c, i, j, i2, j2,couleur1);
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

    afficherCapaciteCE(&c.chateauEau);

    EndMode3D();
    DrawTexture(c.tableau_texture[0], 60, 20, WHITE);
    DrawTexture(c.tableau_texture[1], 260, 20, WHITE);
    DrawTexture(c.tableau_texture[2], 460, 20, WHITE);
    DrawTexture(c.tableau_texture[3], 660, 20, WHITE);
    DrawTexture(c.tableau_texture[4], 860, 20, WHITE);
    if (c.joueur1.element_choisie == 0) {
        DrawTexture(c.tableau_texture[5], 1060, 5, WHITE);
    } else {
        if (GetMouseX() > 1060 && GetMouseX() < 1360 && GetMouseY() > 20 && GetMouseY() < 100) {
            DrawTexture(c.tableau_texture[7], 1060, 5, WHITE);
        } else {
            DrawTexture(c.tableau_texture[6], 1060, 5, WHITE);
        }
    }


    char texte[15] = {0};
    double temps = GetTime() - c.temps;
    sprintf(texte, "%.2lf", temps);
    DrawText(texte, 100, 25, 20, BLUE);
    sprintf(texte, "%d", c.ece_flouz);
    DrawText(texte, 300, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_habitant);
    DrawText(texte, 500, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_electricite);
    DrawText(texte, 700, 25, 20, BLUE);
    sprintf(texte, "%d", c.nb_eau);
    DrawText(texte, 900, 25, 20, BLUE);

    NiveauZeroUnDeux();
    EndDrawing();
}

void affichage_route(city c, int i, int j, int i2, int j2,Color couleur1) {
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
                    couleur1);
    } else if (c.plateau[i2 + 1][j2].numero == 1 && c.plateau[i2][j2 - 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-2.5f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -4.1f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    90,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    couleur1);
    } else if (c.plateau[i2 - 1][j2].numero == 1 && c.plateau[i2][j2 - 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-4.62f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               -2.0f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    180,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    couleur1);

    } else if (c.plateau[i2 - 1][j2].numero == 1 && c.plateau[i2][j2 + 1].numero == 1) {
        DrawModelEx(c.model_route[1],
                    (Vector3) {-2.58f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                               c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                               +0.1f + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                    (Vector3) {0, 1, 0},
                    -90,
                    (Vector3) {0.25f, 0.25f, 0.25f},
                    couleur1);

    } else if (c.plateau[i2 + 1][j2].numero == 1 || c.plateau[i2 - 1][j2].numero == 1) {
        DrawModel(c.tableau_element[c.plateau[i2][j2].numero].model,
                  (Vector3) {(float) -2 + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                             -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                  c.tableau_element[c.plateau[i2][j2].numero].scale, couleur1);
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
                    couleur1);
    }
}

void achat(city *c) {
    if (c->tableau_element[c->joueur1.element_choisie].prix <= c->ece_flouz) {
        c->ece_flouz = c->ece_flouz - c->tableau_element[c->joueur1.element_choisie].prix;
    }
}
void affichageNiveauMoinsUn(city c,int i,int j,int i2,int j2,Color couleur) {
    Vector3 cubePosition = (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                      c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                      -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z };
    DrawCube(cubePosition, 2.0f, 0.5f, 2.0f, couleur);
}

void NiveauZeroUnDeux() {

    DrawCircleLines(100, 150, 50, WHITE);
    DrawText("0", 93, 135, 30, WHITE);
    DrawCircleLines(100, 300, 50, WHITE);
    DrawText("-1", 85, 285, 30, WHITE);
    DrawCircleLines(100, 450, 50, WHITE);
    DrawText("-2", 85, 435, 30, WHITE);

    int x = GetMouseX();
    int y = GetMouseY();


    if ((x - 100) * (x - 100) + (y - 150) * (y - 150) < 50 * 50) {
        DrawCircleLines(100, 150, 51, WHITE);
    }
    if ((x - 100) * (x - 100) + (y - 300) * (y - 300) < 50 * 50) {
        DrawCircleLines(100, 300, 51, WHITE);

    }
    if ((x - 100) * (x - 100) + (y - 450) * (y - 450) < 50 * 50) {
        DrawCircleLines(100, 450, 51, WHITE);
    }
}
void afficherCapaciteCE(chateauEau** listeChateauEau){
    if(*listeChateauEau != NULL){
        for(chateauEau* pChateau= *listeChateauEau; pChateau != NULL; pChateau = pChateau->chateauEau) {

            char texte[20] = {0};
            sprintf(texte, "%d/%d", pChateau->capacite, EAUMAX);

            rlPushMatrix();
            rlRotatef(90.0f, 1.0f, 0.0f, 0.0f);
            Vector3 m = MeasureText3D(GetFontDefault(), texte, 10.0f, 0.5f, 0.0f);
            Vector3 pos = (Vector3){((float)pChateau->position_x*2 - colones) + 2, ((float)pChateau->position_y*2 - ligne)+2, -10.0f};
            DrawText3D(GetFontDefault(), texte, pos, 10.0f, 0.5f, 0.0f, false, DARKBLUE);
            rlPopMatrix();
        }
    }
}







