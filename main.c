#include "structure et macros/include.h"

/*
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

    Color noir=BLANK;
    Color blanc=BLANK;
    //Color rond1 = NULL;

    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {


        calcul(&c);
        evolution(c.plateau,&c);



        afficherSurLaSouris(c,couleurMaison,x,y);
        affichage(c, x, y,couleurMaison);

        afficherToolBoxe(c,Toolboxes, couleurMaison1);
        aggrandirRectangle(x, y, Toolboxes);
        afficherEmplacementMaison(rond,rond1,rond2,rond3,x,y);
        cliqueMenuGeneral(&c,x, y,a, &Toolboxes, &couleurMaison1,&couleurMaison, &rond, &rond1, &rond2, &rond3);


        ClearBackground(background);
    }
    for(int i = 0;i<10;i++){
     UnloadTexture(c.tableau_element[i].texture );
    }

    CloseWindow();
    return 0;
}

///////////////////////////////////////////////////////////////3D///////////////////////////////////////////////////////
*/


int main() {


    const int screenWidth = 1200;
    const int screenHeight = 700;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    city c = initialisation();

    for(int i = 0 ; i<colones;i ++){
        c.plateau[i][15].numero = 1;
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


    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3) {30.0f, 30.0f, 30.0f}; // Camera position
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    Vector3 cubePosition = {1, 0, 1};

    //Material* tileMaterial = LoadMaterials("../model3d/WoodHouse.mtl", &compt);

    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        if (GetMouseX() > 1060 && GetMouseX() < 1360 && GetMouseY() > 20 && GetMouseY() < 100) {
            if (IsMouseButtonDown(1)) {
                c.etage=1;
            }
        }
        if (IsKeyDown('Z')){
            c.etage=1;
        }
        evolution(c.plateau,&c);
        calcul(&c);
        UpdateCamera(&camera);
        if(camera.position.y <0){
            camera.position.y =0;
        }




        affichage3d(c,camera,&c);
    }
    for (int i = 0; i < 10; i++) {
        UnloadTexture(c.tableau_element[i].texture);
        UnloadModel(c.tableau_element[i].model);
    }
    for (int i = 0; i < nombreTexture; i++) {
        UnloadTexture(c.tableau_texture[i]);
    }
    UnloadModel(c.model_route[0]);
    UnloadModel(c.model_route[1]);
    CloseWindow();
}
