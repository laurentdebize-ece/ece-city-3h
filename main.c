

#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "structure et macros/macros.h"
#include "structure et macros/STRUCTURE.h"

int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
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

    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(WHITE);
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

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
