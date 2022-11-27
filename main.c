#include "structure et macros/include.h"

#include "fonction/menu.h"


int main() {
    const int screenWidth = 1200;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "ECE CITY");

    Camera3D camera = {0};
    camera.position = (Vector3) {30.0f, 30.0f, 30.0f};
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);
    Color couleur = BLANK;
    Color couleur1 = WHITE;
    Color capacite = BLANK;
    city c;
    c = initialisation();

    menu(&c);

    while (!WindowShouldClose()){
        partie(&c, &couleur, &couleur1,&capacite,camera);
    }

    unload(&c);
    return 0;
}

