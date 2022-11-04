


#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "structure et macros/macros.h"

#include "structure et macros/STRUCTURE.h"
#include <stdio.h>
#include "fonction/char.h"

int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");
    city c = initialisation();

    for(int i = 0 ; i<30 ;i ++){
        c.plateau[10][i] = 1;
    }

    c.plateau[0][0] = 2;
    c.plateau[20][0] = 3;
    c.plateau[30][0] = 4;
    c.plateau[20][20] = 5;
    c.plateau[20][10] = 6;
    c.plateau[30][20] = 7;
    c.plateau[30][10] = 8;
    c.plateau[0][30] = 9;


    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(WHITE);
        for (int i = 20; i < (ligne + 1) * espacement + 20; i += espacement) {
            DrawLine(i, 20, i, colones * espacement + 20, BLUE);
        }
        double time1 = GetTime();
        char time[15] = {0};
        sprintf(time, "%.2lf", GetTime());
        DrawText(time, 10, 10, 10, BLUE);

        for (int i = 20; i < (colones + 1) * espacement + 20; i += espacement) {
            DrawLine(20, i, ligne * espacement + 20, i, BLUE);
        }

        for (int i = 0; i < colones; i++) {
            for (int j = 0; j < ligne; j++) {
                if (c.plateau[i][j] != 0) {
                    DrawTexture(c.tableau_element[c.plateau[i][j]].texture,i*espacement+ 20,j*espacement+ 20, WHITE);


                }
            }
        }

        EndDrawing();
    }
    UnloadTexture(c.tableau_element[1].texture );
    CloseWindow();
    return 0;
}
