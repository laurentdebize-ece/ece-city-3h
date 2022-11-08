

#include "structure et macros/include.h"


int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
    Vector2 ballPosition = { -100.0f, -100.0f };
    int x = 0;
    int y = 0;

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
        evolution(c.plateau);
        calcul(&c);
        affichage(c);


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







    }
    UnloadTexture(c.tableau_element[1].texture );
    CloseWindow();
    return 0;
}
