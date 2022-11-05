

#include "structure et macros/include.h"


int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");
    city c = initialisation();

    for(int i = 0 ; i<30 ;i ++){
        c.plateau[10][i].numero = 1;
    }

    c.plateau[0][0].numero = 2;

    c.plateau[20][0].numero = 3;
    c.plateau[20][0].temps = 15;

    c.plateau[30][0].numero = 4;
    c.plateau[30][0].temps = 15;

    c.plateau[20][20].numero = 5;
    c.plateau[20][20].temps = 15;

    c.plateau[20][10].numero = 6;
    c.plateau[20][10].temps = 15;

    c.plateau[30][20].numero = 7;
    c.plateau[30][10].numero = 8;
    c.plateau[0][30].numero = 9;


    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        evolution(c.plateau);
        calcul(&c);
        affichage(c);

    }
    UnloadTexture(c.tableau_element[1].texture );
    CloseWindow();
    return 0;
}
