//
// Created by quent on 08/11/2022.
//
#include <stdio.h>
#include "raylib.h"
#include "pthread.h"                        // POSIX style threads management
#include <stdatomic.h>                      // C11 atomic data types

#include <time.h>
#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int clickR(int x,int y,int xr,int xr1,int yr,int yr1){
    x = GetMouseX();
    y = GetMouseY();
    if(x>xr && x<xr+xr1 && y>yr && y< yr+yr1){
        if(IsMouseButtonDown(1)){
            return 1;
        }
    }
    return 0;
}
static atomic_bool dataLoaded = ATOMIC_VAR_INIT(false); // Data Loaded completion indicator
static void *LoadDataThread(void *arg);     // Loading data thread function declaration

static int dataProgress = 0;                // Data progress accumulator


void menu()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int x1=0;
    int t=0;
    int y1=0;
    int affichage=0;
    Vector2 fontPosition = { 215, 65 };
    Vector2 fontPosition2 = { 218, 65 };

    InitWindow(screenWidth, screenHeight, "ECE CITY");
    InitAudioDevice();

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect
    Texture2D background = LoadTexture("C:/Users/quent/OneDrive/Documents/Bureau/textures_background_scrolling.png");
    Texture2D bouton1 = LoadTexture("C:/Users/quent/OneDrive/Documents/Bureau/5261101 (2).png");
    Texture2D Trump = LoadTexture("C:/Users/quent/OneDrive/Documents/Bureau/donald-trump-png-7 (2).png");
    Texture2D simCity = LoadTexture("C:/Users/quent/OneDrive/Documents/Bureau/147-1475237_home-simcity-logo-png (1) (1).png");
    Texture2D Poutine = LoadTexture("C:/Users/quent/OneDrive/Documents/Bureau/vladimir_putin_PNG42 (1).png");
    Font font = LoadFont("C:/Windows/Fonts/8514oem.fon");
    Music music = LoadMusicStream("C:/Users/quent/OneDrive/Documents/Bureau/GAZO - CELINE 3x.mp3");

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    float timePlayed = 0.0f;

    Rectangle btnBounds ={325, 130};
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int btnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool btnAction = false;         // Button action should be activated

    Vector2 mousePoint = { 0.0f, 0.0f };
    PlayMusicStream(music);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //btnAction = false;
        UpdateMusicStream(music);
        // Check button state


        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 0.5f;
        scrollingMid -= 1.0f;
        scrollingFore -= 1.5f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width*2) scrollingBack = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        timePlayed = GetMusicTimePlayed(music)/GetMusicTimeLength(music);
        if (timePlayed > 1.0f) timePlayed = 1.0f;


        BeginDrawing();
        switch(affichage) {

            case 0:
            ClearBackground(GetColor(0x052c46ff));

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
            DrawTexture(bouton1, 325, 130, WHITE);
            DrawRectangleLines(325,160,150,70,WHITE);
            if (clickR(x1,y1,325,150,160,70) == 1 ){
                    affichage =1;
            }


            DrawFPS(0, 0);

            DrawTexture(simCity, 275, 60, WHITE);
            //DrawTextEx(font, "ECE CITY", fontPosition, 75, 7, ORANGE);
            //DrawTextEx(font, "ECE CITY", fontPosition2, 75, 7, RAYWHITE);
            break;

            case 1:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);

                DrawTextEx(font, "En Quel Mode Voulez Vous Jouer", fontPosition, 20, 7, ORANGE);
                DrawTextEx(font, "En Quel Mode Voulez Vous Jouer", fontPosition2, 20, 7, RAYWHITE);
                //DrawRectangle(250,250,150,70,WHITE);
                DrawTexture(Trump,200,190,WHITE);
                DrawTexture(Poutine, 450, 210, WHITE);
                //DrawRectangle(450,250,150,70,WHITE);
                if (clickR(x1,y1,250,150,250,70)==1){
                    affichage =2;
                }
                if (clickR(x1,y1,450,150,250,70)==1){
                    affichage =3;
                }

                break;
            case 2:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+1;

                DrawTextEx(font, "Mode Capitaliste", fontPosition, 20, 7, ORANGE);
                DrawTextEx(font, "Mode Capitaliste", fontPosition2, 20, 7, RAYWHITE);
                DrawRectangle(0,400,t,70,ORANGE);
                break;
            case 3:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+1;

                DrawTextEx(font, "Mode Comuniste", fontPosition, 20, 7, ORANGE);
                DrawTextEx(font, "Mode Comuniste", fontPosition2, 20, 7, RAYWHITE);
                DrawRectangle(0,400,t,70,ORANGE);
                break;
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);
    UnloadMusicStream(music);
    UnloadTexture(bouton1);// Unload background texture
    CloseAudioDevice();
    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}
