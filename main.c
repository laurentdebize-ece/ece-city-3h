#include "structure et macros/include.h"

#include "fonction/menu.h"
void unload(city* c){
    sauvegarde(*c);
    for (int i = 0; i < 10; i++) {
        UnloadTexture(c->tableau_element[i].texture);
        UnloadModel(c->tableau_element[i].model);
    }
    for (int i = 0; i < nombreTexture; i++) {
        UnloadTexture(c->tableau_texture[i]);
    }
    UnloadModel(c->model_route[0]);
    UnloadModel(c->model_route[1]);
    CloseWindow();
}
void partie(city *c){
    Camera3D camera = {0};
    camera.position = (Vector3) {30.0f, 30.0f, 30.0f};
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);
    // Initialisation des couleurs pour la route
    Color noir = BLANK;
    Color blanc = BLANK;
    Color couleur = BLANK;
    Color couleur1 = WHITE;
    Color capacite = BLANK;
    if ((GetMouseX() - 100) * (GetMouseX() - 100) + (GetMouseY() - 150) * (GetMouseY() - 150) < 50 * 50) {
        if (IsMouseButtonPressed(1)) {
            couleur = BLANK;
            couleur1 = WHITE;                         //clique pour le niveau 0
            capacite = BLANK;
        }
    }
    // niveau -1
    if ((GetMouseX() - 100) * (GetMouseX() - 100) + (GetMouseY() - 300) * (GetMouseY() - 300) < 50 * 50) {
        if (IsMouseButtonPressed(1)) {
            couleur = BLUE;
            couleur1 = BLUE;                         //clique pour le niveau -1
            capacite = DARKBLUE;
        }
    }
    // niveau -2
    if ((GetMouseX() - 100) * (GetMouseX() - 100) + (GetMouseY() - 450) * (GetMouseY() - 450) < 50 * 50) {
        if (IsMouseButtonPressed(1)) {

            couleur = YELLOW;
            couleur1 = YELLOW;                       //clique pour le niveau -2
            capacite = BLANK;


        }
    }

    if (GetMouseX() > 1060 && GetMouseX() < 1360 && GetMouseY() > 20 && GetMouseY() < 100) {
        if (IsMouseButtonPressed(1)) {
            if (c->joueur1.element_choisie == 0) {
                afficherToolBoxe3d(*c, camera, c);
            } else {
                c->joueur1.element_choisie = 0;

            }
        }
    }
    //afficherCapaciteCE(&c.chateauEau);

    evolution(c->plateau, c);
    calcul(c);
    creer_graphe(*c, c);
    distributionEau(c->chateauEau, c);
    distributionElectricite(c);
    UpdateCamera(&camera);
    if (camera.position.y < 0) {
        camera.position.y = 0;
    }

    affichage3d(*c, camera, c, couleur, couleur1,
                capacite); // fonction principale du jeu pour l'affichage 3D



}
int main() {
    const int screenWidth = 1200;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "ECE CITY");

    city c;
    c = initialisation();

    menu(&c);

    while (!WindowShouldClose()){
        partie(&c);
    }

    unload(&c);
    return 0;
}

