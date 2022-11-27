#include "../structure et macros/include.h"


void afficherToolBoxe3d(city c, Camera3D camera, city *c_adresse) {
    bool fin = false;
    char texte[15] = {0};
    int i = 0;
    int element = 1;
    Color color = WHITE;
    Texture2D fleche = LoadTexture("../image/fleche.png");
    Texture2D piece = LoadTexture("../image/piece.png");
    // Positionnement de la caméra
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
        //Animation en vert quand notre souris est sur la case
        if (GetMouseX() > 500 && GetMouseX() < 700 && GetMouseY() > 600 && GetMouseY() < 650) {
            color = GREEN;
        }

        // Permet d'accéder aux images sur la droite en cliquant sur la flèche
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
            // Permet d'accéder aux images sur la gauche en cliquant sur la flèche
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
        // On peut bouger la caméra avec la souris
        camera.position = (Vector3) {30.0f * cos(i * (2 * PI / 1000)), 30.0f, 30.0f * sin(i * (2 * PI / 1000))};
        EndMode3D();
        // affichage de toutes les données sur l'affichage du plateau comme le temps, l'argent, le nombre de personne, l'électricité et l'eau
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
    // Détecter le clique sur la map en fonction du nombre de ligne et du nombre de colonne et de la position de notre souris
    collision = GetRayCollisionBox(ray, (BoundingBox) {(Vector3) {-45, 0, -35}, (Vector3) {45, 0, 35}});
    int x = collision.point.x / 2 + 23;
    int z = collision.point.z / 2 + 18;
    if (0 <= x && x <= 45 && 0 <= z && z <= 33) {
        if (c->joueur1.element_choisie != 0) {
            c->plateau[x][z].numero = c->joueur1.element_choisie;
            if (IsMouseButtonPressed(1)) {
                // poser tous les éléments sauf la route
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
                }// Poser la route sur le plateau
                else {
                    clique_accepter = true;
                }
                // Actualiser le plateau avec la route qui est posé à l'endroit où l'on a cliqué
                for (int i = 0; i <= c->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                    for (int j = 0; j <= c->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                        if (c_adresse->plateau[x + i][z + j].numero != 0) {
                            clique_accepter = false;

                        }
                    }
                }
            }
            // Lancement du Timer toutes les 15 secondes à l'endroit où l'on a cliqué
            if (clique_accepter) {
                if (c->joueur1.element_choisie == 3) {
                    c_adresse->plateau[x][z].
                            temps = (GetTime()-c->temps) + 15;
                }
                // Actualiser le plateau avec les différents constructions qui évoluent à l'endroit où l'on a cliqué
                for (int i = 0; i <= c->tableau_element[c->joueur1.element_choisie].espacement_x - 1; i++) {
                    for (int j = 0; j <= c->tableau_element[c->joueur1.element_choisie].espacement_y - 1; j++) {
                        c_adresse->plateau[x + i][z + j].numero = -c->joueur1.element_choisie;
                        c_adresse->plateau[x + i][z + j].reference_x = x;
                        c_adresse->plateau[x + i][z + j].reference_y = z;
                    }
                }
                c_adresse->plateau[x][z].numero = c->joueur1.element_choisie;
                // Fonction qui soustrait le cout du batiment à l'argent possédé
                achat(c_adresse);
            }
        }
    }

}

static Vector3 MeasureText3D(Font font, const char* text, float fontSize, float fontSpacing, float lineSpacing)
{
    // fonction du site raylib permettant de mesurer la longueur du texte 3D, afin de la centrer

    int len = TextLength(text);
    int tempLen = 0;
    int lenCounter = 0;

    float tempTextWidth = 0.0f;

    float scale = fontSize/(float)font.baseSize;
    float textHeight = scale;
    float textWidth = 0.0f;

    int letter = 0;
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        lenCounter++;

        int next = 0;
        letter = GetCodepoint(&text[i], &next);
        index = GetGlyphIndex(font, letter);

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
    // fonction du site raylib permttant de dessiner un poitn code en espace 3D

    int index = GetGlyphIndex(font, codepoint);
    float scale = fontSize/(float)font.baseSize;

    position.x += (float)(font.glyphs[index].offsetX - font.glyphPadding)/(float)font.baseSize*scale;
    position.z += (float)(font.glyphs[index].offsetY - font.glyphPadding)/(float)font.baseSize*scale;

    Rectangle srcRec = { font.recs[index].x - (float)font.glyphPadding, font.recs[index].y - (float)font.glyphPadding,
                         font.recs[index].width + 2.0f*font.glyphPadding, font.recs[index].height + 2.0f*font.glyphPadding };

    float width = (float)(font.recs[index].width + 2.0f*font.glyphPadding)/(float)font.baseSize*scale;
    float height = (float)(font.recs[index].height + 2.0f*font.glyphPadding)/(float)font.baseSize*scale;

    if (font.texture.id > 0)
    {
        const float x = 0.0f;
        const float y = 0.0f;
        const float z = 0.0f;

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

        rlNormal3f(0.0f, 1.0f, 0.0f);
        rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);
        rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height);
        rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height);
        rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);

        if (backface)
        {
            rlNormal3f(0.0f, -1.0f, 0.0f);
            rlTexCoord2f(tx, ty); rlVertex3f(x,         y, z);
            rlTexCoord2f(tw, ty); rlVertex3f(x + width, y, z);
            rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z + height);
            rlTexCoord2f(tx, th); rlVertex3f(x,         y, z + height);
        }
        rlEnd();
        rlPopMatrix();

        rlSetTexture(0);
    }
}

static void DrawText3D(Font font, const char *text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint)
{
    // fonction du site raylib pour ecrire un texte en 3D

    int length = TextLength(text);

    float textOffsetY = 0.0f;
    float textOffsetX = 0.0f;

    float scale = fontSize/(float)font.baseSize;

    for (int i = 0; i < length;)
    {
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[i], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);


        if (codepoint == 0x3f) codepointByteCount = 1;

        if (codepoint == '\n')
        {
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

        i += codepointByteCount;
    }
}

void affichage3d(city c, Camera3D camera, city *c_adresse,Color couleur,Color couleur1,Color capacite) {
    poser_element(&c, camera, c_adresse);



    BeginDrawing();
    // mettre le l'arrière plan en bleu
    ClearBackground(SKYBLUE);

    BeginMode3D(camera);
    // Afficher la Grille
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
                    // afficher la route
                    affichage_route(c, i, j, i2, j2,couleur1);
                    // afficher le niveau -1 et -2 en remplacant le route par du bleu ou du jaune
                    affichageNiveauMoinsUn(c, i, j, i2, j2, couleur);
                } else {
                    // afficher le chateau d'eau en 6 fois car sinon on ne respecterai pas la taille demandé pour un chateau d'eau dans le cahier des charges
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
    //afficher la capacité pour chaque chateau d'eau
    afficherCapaciteCE(&c.chateauEau,capacite);

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

    //afficher les noms des éléments sur le premier affichage
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
// affichage de la route avec toute les possibilités ( ligne droite, tourner vers la gauche, tourner vers la gauche, carrefour
void affichage_route(city c, int i, int j, int i2, int j2,Color couleur1) { // Fonction qui permet d'afficher la route et qui prend en compte les virages et les croisements
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
    // En fonction de la position des routes précédentes la route s'affiche différemment
    if (compteur >= 3) {
        DrawModel(c.model_route[0],
                  (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                             c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                             -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z},
                  c.tableau_element[c.plateau[i2][j2].numero].scale,WHITE);
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

void achat(city *c) {
    // si l'argent est suffisant pour acheter la construction
    if (c->tableau_element[c->joueur1.element_choisie].prix <= c->ece_flouz) {
        // on soustrait à l'argent total le prix de la construction
        c->ece_flouz = c->ece_flouz - c->tableau_element[c->joueur1.element_choisie].prix;
    }
}

void affichageNiveauMoinsUn(city c,int i,int j,int i2,int j2,Color couleur) { // Fonction qui permet de mettre une case bleu ou jaune à la place de la route
    // si la distribution d'eau passe par la case (route)
    if(c.plateau[i2][j2].passage_eau == 1){
        // on affiche la case de la route en jaune
        Vector3 cubePosition = (Vector3) {-2.55f + (float) i + c.tableau_element[c.plateau[i2][j2].numero].decalage_x,
                                          c.tableau_element[c.plateau[i2][j2].numero].decalage_y,
                                          -2 + (float) j + c.tableau_element[c.plateau[i2][j2].numero].decalage_z };
        DrawCube(cubePosition, 2.0f, 0.5f, 2.0f, couleur);
    }
}

void NiveauZeroUnDeux() { // Fonction d'affichage des niveaux 0 -1 et -2 avec animation

    DrawCircleLines(100, 150, 50, WHITE);
    DrawText("0", 93, 135, 30, WHITE);
    DrawCircleLines(100, 300, 50, WHITE);
    DrawText("-1", 85, 285, 30, WHITE);
    DrawCircleLines(100, 450, 50, WHITE);
    DrawText("-2", 85, 435, 30, WHITE);

    // on récupere les coordonées de la souris
    int x = GetMouseX();
    int y = GetMouseY();

    // si notre souris se situe sur le cercle
    if ((x - 100) * (x - 100) + (y - 150) * (y - 150) < 50 * 50) {
        // on le fait voir sur le cercle (le rayon est plus epais)
        DrawCircleLines(100, 150, 51, WHITE);
    }
    if ((x - 100) * (x - 100) + (y - 300) * (y - 300) < 50 * 50) {
        DrawCircleLines(100, 300, 51, WHITE);

    }
    if ((x - 100) * (x - 100) + (y - 450) * (y - 450) < 50 * 50) {
        DrawCircleLines(100, 450, 51, WHITE);
    }
}

void afficherCapaciteCE(chateauEau** listeChateauEau, Color capacite){
    // si la liste chainee des chateaux d'eau n'est pas nulle
    if(*listeChateauEau != NULL){
        // on parcourt chaque maillon de la liste (chateau d'eau)
        for(chateauEau* pChateau= *listeChateauEau; pChateau != NULL; pChateau = pChateau->chateauEau) {
            // on crée un tableau de char pour ecrire le texte
            char texte[20] = {0};
            sprintf(texte, "%d/%d", pChateau->capacite, EAUMAX);

            // on affiche : capacite restante/ capacite maximale  au dessus de la centrale
            rlPushMatrix();
            rlRotatef(90.0f, 1.0f, 0.0f, 0.0f); // on tourne le texte pour qu'il s'affiche droit
            Vector3 m = MeasureText3D(GetFontDefault(), texte, 10.0f, 0.5f, 0.0f); // permet de centrer le texte
            Vector3 pos = (Vector3){((float)pChateau->position_x*2 - colones) + 2, ((float)pChateau->position_y*2 - ligne)+2, -10.0f};
            DrawText3D(GetFontDefault(), texte, pos, 10.0f, 0.5f, 0.0f, false, capacite);
            rlPopMatrix();
        }
    }
}







