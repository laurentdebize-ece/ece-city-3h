

#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "structure et macros/macros.h"
#include "structure et macros/STRUCTURE.h"
#include "menu.h"

/*int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;
    Vector2 ballPosition = { -100.0f, -100.0f };
    int x = 0;
    int y = 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");
    city c = initialisation();



    c.plateau[20][20].numero = 5;
    c.plateau[20][20].temps = 15;

    Color background = WHITE;
    Color Toolboxes = BLACK;
    Color rond = BLANK;
    Color rond1 = BLANK;
    Color rond2 = BLANK;
    Color rond3 = BLANK;
    Color noir=BLANK;
    Color blanc=BLANK;
    //Color rond1 = NULL;

    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        afficherToolBoxe(Toolboxes);
        aggrandirRectangle(x, y, Toolboxes);
        evolution(c.plateau, &c);
        calcul(&c);
        affichage(c);
        achat(&c,noir, blanc);



        x = GetMouseX();
            y = GetMouseY();
            if (clickNiveauUn(x,y) == 1) {
                Toolboxes = WHITE;
                noir = BLANK;
                blanc = BLANK;
                afficherNiveau1(Toolboxes);
                //background = YELLOW;
            }
            if (clickNiveauDeux(x,y) == 1){
                Toolboxes = WHITE;
                noir = BLANK;
                blanc = BLANK;
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
                noir = BLANK;
                blanc = BLANK;
            }
            if (clickCaseMaison(x,y)==1){
                rond = RED;
                blanc = WHITE;
                noir = BLACK;
                //rond1 = RED;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond);
                c.joueur1.element_choisie = 3;
            }
            if (clickCaseRoute(x,y)==1){
                rond1 = BLUE;
                blanc = WHITE;
                noir = BLACK;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond1);
                c.joueur1.element_choisie = 1;


            }
            if (clickCaseElec(x,y)==1){
                rond2 = GREEN;
                blanc = WHITE;
                noir = BLACK;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond2);
                c.joueur1.element_choisie = 8;

            }
            if (clickCaseEau(x,y)==1){
                rond3 = YELLOW;
                blanc = WHITE;
                noir = BLACK;
                ballPosition = GetMousePosition();
                DrawCircleV(ballPosition, 40, rond3);
                c.joueur1.element_choisie = 9;

            }

            // si il refuse finalement l'achat
            if((GetMouseX() - (1100 / 2 + 240)) * (GetMouseX() - (1100 / 2 + 240)) + (GetMouseY() - 580) * (GetMouseY() - 580) < 40 * 40 && IsMouseButtonDown(1)){
            noir = BLANK;
            blanc= BLANK;
            }


            if (c.tableau_element[c.joueur1.element_choisie].prix > c.ece_flouz){
                DrawText("Vous ne pouvez pas acheter, ", 1100 / 2 + 95, 500, 20, noir);
                DrawText("par manque de moyens.", 1100 / 2 + 95, 520, 20, noir);
                noir = BLANK;
                blanc = BLANK;
            }


        BeginDrawing();
        ClearBackground(background);
        ballPosition = GetMousePosition();
        DrawCircleV(ballPosition, 40, rond1);
        DrawCircleV(ballPosition, 40, rond2);
        DrawCircleV(ballPosition, 40, rond3);
        //DrawCircleV(ballPosition, 1, rond1);







    }
    UnloadTexture(c.tableau_element[1].texture );
    CloseWindow();
    return 0;
}*/
int main(){
    const int screenWidth = 1200;
    const int screenHeight = 700;
    int a=0;

    InitWindow(screenWidth, screenHeight, "ECE CITY");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        switch (a) {
            case 0:
                menu(&a);
                break;
            case 2:
                ClearBackground(GetColor(0x052c46ff));
                DrawText("Jeu capitaliste", 190, 200, 20, LIGHTGRAY);
                break;
            case 3:
                ClearBackground(GetColor(0x052c46ff));
                DrawText("Jeu comuniste", 190, 200, 20, LIGHTGRAY);
                break;
            case 4:
                ClearBackground(GetColor(0x052c46ff));
                DrawText("Sauvegarde", 190, 200, 20, LIGHTGRAY);
                break;
        }
        //menu();


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
