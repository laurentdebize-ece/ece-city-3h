//
// Created by quent on 08/11/2022.
//
#include <stdio.h>
#include "raylib.h"
#include "pthread.h"// POSIX style threads management
#include "rlgl.h"
#include <stdatomic.h>

#include "menu.h"// C11 atomic data types

#include <time.h>
#include "raylib.h"
#include "structure et macros/include.h"

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


void menu(int* a)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1200;//800
    const int screenHeight = 700;//450
    int x1=0;
    int t=0;
    int b=0;
    bool fin=false;
    bool clig=true;
    int timer=0;
    int y1=0;
    int affichage=0;
    Vector2 fontPosition = { 488, 466 };
    //Vector2 fontPosition* = { 215, 300 };
    Vector2 fontPosition2 = { 430, 102 };
    Vector2 fontPosition3 = { 250, 102 };
    Vector2 fontPosition4 = {488,500};
    Vector2 fontPosition5 = {15,t};

    //InitWindow(screenWidth, screenHeight, "ECE CITY");
    InitAudioDevice();

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect//(../image/
    Texture2D background = LoadTexture("../image/textures_background_scrolling.png");
    Texture2D bouton1 = LoadTexture("../image/START-removebg-preview.png");
    Texture2D restart = LoadTexture("../image/START__1_-removebg-preview (1).png");
    Texture2D Trump = LoadTexture("../image/donald-trump-png-7 (2).png");
    Texture2D simCity = LoadTexture("../image/147-1475237_home-simcity-logo-png (1) (1) (1).png");
    Texture2D Poutine = LoadTexture("../image/vladimir_putin_PNG42 (1).png");
    Font font = LoadFont("C:/Windows/Fonts/8514oem.fon");
    Music music = LoadMusicStream("C:/Users/quent/OneDrive/Documents/Bureau/SimCity BuildIt Soundtrack - Tutorial Music.mp3");
    Texture2D ps5= LoadTexture("../image/800px-PlayStation_Studios_logo.svg (1) (1).png");

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
    while (!fin)    // Detect window close button or ESC key
    {
        if(WindowShouldClose()){
            fin=true;
        }
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
            DrawTexture(bouton1, 310, 85, WHITE);
            DrawTexture(restart,320,175,WHITE);
            DrawTexture(ps5,500,570,WHITE);
            //DrawRectangleLines(418,275,300,70,WHITE);
            //DrawRectangleLines(500,570,100,110,WHITE);
            if (clickR(x1,y1,418,300,275,70) == 1 ){
                    affichage =1;
            }

            if (clickR(x1,y1,400,320,375,70)==1){
                affichage = 4;
            }
            if (clickR(x1,y1,500,100,570,110)==1){
                    affichage = 5;
            }




            DrawFPS(0, 0);

            DrawTexture(simCity, 370, 93, WHITE);
            timer=timer+1;
            if(timer<60 && timer >0){
                DrawTextEx(font, "press play", fontPosition4, 20, 7, WHITE);
            }
            //if(timer>60 && timer<120){

            //}
            if(timer>120){
                timer=0;
            }
            //DrawTextEx(font, "press play", fontPosition, 20, 7, ORANGE);


            //DrawTextEx(font, "ECE CITY", fontPosition2, 75, 7, RAYWHITE);
            break;

            case 1:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);

                DrawTextEx(font, "En Quel Mode Voulez Vous Jouer ?", fontPosition3, 40, 7, ORANGE);
                DrawTextEx(font, "En Quel Mode Voulez Vous Jouer ?", fontPosition3, 40, 7, RAYWHITE);
                //DrawRectangleLines(125,250,150,140,WHITE);
                //DrawRectangleLines(550,210,150,170,WHITE);
                DrawTexture(Trump,75,296,WHITE);
                DrawTexture(Poutine, 750, 311, WHITE);
                //DrawRectangleLines(805,295,180,200,WHITE);
                if (clickR(x1,y1,138,200,310,170)==1){
                    affichage =2;
                }
                if (clickR(x1,y1,805,180,295,200)==1){
                    affichage =3;
                }

                break;
            case 2:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+5;

                DrawTextEx(font, "Mode Capitaliste", fontPosition2, 40, 7, ORANGE);
                DrawTextEx(font, "Mode Capitaliste", fontPosition2, 40, 7, RAYWHITE);
                DrawRectangle(0,630,t,70,ORANGE);
                if(t>1200){
                    *a = 2;
                    fin=true;
                }
                break;
            case 3:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+5;

                DrawTextEx(font, "Mode Comuniste", fontPosition2, 40, 7, ORANGE);
                DrawTextEx(font, "Mode Comuniste", fontPosition2, 40, 7, RAYWHITE);
                DrawRectangle(0,630,t,70,ORANGE);
                if(t>1200){
                    *a = 3;
                    fin=true;
                }
                break;
            case 4:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+5;
                DrawTextEx(font, "Sauvegarde", fontPosition2, 40, 7, WHITE);
                DrawRectangle(0,630,t,70,ORANGE);
                if(t>1200){
                    *a = 4;
                    fin=true;
                }
                break;
            case 5:
                ClearBackground(GetColor(0x052c46ff));
                DrawTextureEx(background, (Vector2) {scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, -55}, 0.0f, 2.0f, WHITE);
                t=t+1;
                if(t>700){
                    t=0;
                }
                fontPosition5 = (Vector2){15,t};
                DrawTextEx(font, "Dans le mode comuniste, une construction n evolue pas \n"
                                 "si les ressources (eau+electricité)\n"
                                 "nécessaires à sa croissance ne sont pas disponibles \n"
                                 "Dans le mode Capitaliste, une construction passe \n"
                                 "systématiquement au stade supérieur,\n"
                                 "que lesressources (eau+électricité) soient disponibles ou pas.", fontPosition5, 20, 10, WHITE);
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
    UnloadTexture(background);
    UnloadTexture(simCity);
    UnloadTexture(background);
    UnloadTexture(Trump);
    UnloadTexture(Poutine);
    UnloadFont(font);
    UnloadTexture(bouton1);
    UnloadTexture(background);
    UnloadTexture(restart);
    CloseAudioDevice();
    // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}

