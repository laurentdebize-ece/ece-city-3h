#include "structure et macros/include.h"

#include "menu.h"



int main() {
    const int screenWidth = 1200;
    const int screenHeight =700;


    InitWindow(screenWidth, screenHeight, "ECE CITY");

    city c = initialisation();
    //lire_sauvegarde(&c);
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

    Color noir = BLANK;
    Color blanc = BLANK;

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        if (GetMouseX() > 1060 && GetMouseX() < 1360 && GetMouseY() > 20 && GetMouseY() < 100) {
            if (IsMouseButtonPressed(1)) {
                if (c.joueur1.element_choisie == 0) {
                    afficherToolBoxe3d(c, camera, &c);
                } else {
                    c.joueur1.element_choisie = 0;

                }
            }
        }
        //afficherCapaciteCE(&c.chateauEau);

        evolution(c.plateau, &c);
        calcul(&c);
        creer_graphe(c,&c);
        distributionEau(c.chateauEau,&c);
        distributionElectricite(&c);
        UpdateCamera(&camera);
        if (camera.position.y < 0) {
            camera.position.y = 0;
        }


        affichage3d(c, camera, &c);
    }
    sauvegarde(c);
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







/*int main(){
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
}*/


