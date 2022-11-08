

#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include "affichage.h"
#include "raymath.h"
#include "structure et macros/macros.h"
#include "structure et macros/STRUCTURE.h"

int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
    Vector2 ballPosition = { -100.0f, -100.0f };
    int x = 0;
    int y = 0;
    struct ece_city c;

    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c.plateau[i][j] = 0;
        }
    }
    c.plateau[10][10] = 1;
    c.tableau_element[1].color = RED;
    c.tableau_element[1].espacement_x = 3;
    c.tableau_element[1].espacement_y = 3;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");
    Color background = WHITE;
    Color Toolboxes = BLACK;
    Color rond = BLANK;
    Color rond1 = BLANK;
    Color rond2 = BLANK;
    Color rond3 = BLANK;
    //Color rond1 = NULL;

    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        afficherToolBoxe(Toolboxes);
        aggrandirRectangle(x, y, Toolboxes);


            x = GetMouseX();
            y = GetMouseY();
            if (clickNiveauUn(x,y) == 1) {
                Toolboxes = WHITE;
                afficherNiveau1(Toolboxes);
                //background = YELLOW;
            }
            if (clickNiveauDeux(x,y) == 1){
                Toolboxes = WHITE;
                afficherNiveau2(Toolboxes);
                //background = BLUE;
            }

            if (clickNiveauZero(x,y) == 1){
                Toolboxes=BLACK;
                afficherNiveau0(Toolboxes);
            }
            if (clickNiveauBack(x,y)==1){
                rond = BLANK;
                rond1 = BLANK;
                rond2 = BLANK;
                rond3 = BLANK;
            }
            if (clickCaseMaison(x,y)==1){
                rond = RED;
                //rond1 = RED;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond);
            }
            if (clickCaseRoute(x,y)==1){
                rond1 = BLUE;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond1);

            }
            if (clickCaseElec(x,y)==1){
                rond2 = GREEN;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond2);

            }
            if (clickCaseEau(x,y)==1){
                rond3 = YELLOW;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond3);

            }


        BeginDrawing();
        ClearBackground(background);
        ballPosition = GetMousePosition();
        DrawCircleV(ballPosition, 40, rond);
        DrawCircleV(ballPosition, 40, rond1);
        DrawCircleV(ballPosition, 40, rond2);
        DrawCircleV(ballPosition, 40, rond3);
        //DrawCircleV(ballPosition, 1, rond1);




        for (int i = 20; i < (ligne+1)*espacement+20; i+=espacement) {
            DrawLine(i, 20, i, colones*espacement+20, BLUE);
        }
        double time1 =GetTime();
        char time[15] = {0};
        sprintf(time, "%.2lf", GetTime());
        DrawText(time, 10, 10, 10, BLUE);

        for (int i = 20; i < (colones+1)*espacement+20; i+=espacement) {
            DrawLine(20, i, ligne*espacement+20, i, BLUE );
        }
        for (int i = 0; i < colones; i++) {
            for (int j = 0; j < ligne; j++) {
               if (c.plateau[i][j]!=0){
                   for(int x = 0 ; x < c.tableau_element[c.plateau[i][j]].espacement_x; x++){
                       for(int y = 0 ; y < c.tableau_element[c.plateau[i][j]].espacement_y; y++){
                           DrawRectangle((i+x)*espacement+20,(j+y)*espacement+20, espacement, espacement, c.tableau_element[c.plateau[i][j]].color);
                       }
                   }

               }
            }
        }



        //sprintf_s(time,"%d",c.ece_flouz);
        //DrawText(, 1100/2, 100, 10, BLUE);




        EndDrawing();
    }
    CloseWindow();
    return 0;
}
