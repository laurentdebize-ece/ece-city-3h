

#include "structure et macros/include.h"


int main() {
    // Initialisation
    const int screenWidth = 1100;
    const int screenHeight = 800;

    int x = 0;
    int y = 0;
    int a=0;

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


    for (int i = 0; i < colones; i++) {
        for (int j = 0; j < ligne; j++) {
            c.plateau[i][j].numero = 0;
        }
    }
    Color background = WHITE;
    Color Toolboxes = BLACK;
    Color rond = BLANK;
    Color rond1 = BLANK;
    Color rond2 = BLANK;
    Color rond3 = BLANK;
    Color couleurMaison = BLANK;
    Color couleurMaison1 = WHITE;


    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {


        calcul(&c);
        evolution(c.plateau);



        afficherSurLaSouris(c,couleurMaison,x,y);
        affichage(c, x, y,couleurMaison);

        afficherToolBoxe(c,Toolboxes, couleurMaison1);
        aggrandirRectangle(x, y, Toolboxes);
        afficherEmplacementMaison(rond,rond1,rond2,rond3,x,y);
        cliqueMenuGeneral(&c,x, y,a, &Toolboxes, &couleurMaison1,&couleurMaison, &rond, &rond1, &rond2, &rond3);


        ClearBackground(background);
    }
    UnloadTexture(c.tableau_element[1].texture );
    CloseWindow();
    return 0;
}
