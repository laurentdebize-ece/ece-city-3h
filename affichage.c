
#include "affichage.h"
#include <stdio.h>
#include "raylib.h"
#include "rlgl.h"

void afficherToolBoxe( Color Toolboxes ){
    DrawRectangleLines(1100/2, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 + 5, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 300, 80, 80, Toolboxes);
    DrawText("maison", 1100 / 2 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 400, 80, 80, Toolboxes);
    DrawText("elec", 1100 / 2 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 + 5, 400, 20, Toolboxes);


}

void aggrandirRectangle( int x, int y,Color Toolboxes){

     x = GetMouseX();
     y = GetMouseY();

    if ( x > 1100/2 && x < 1100/2 + 80 && y > 100 && y < 180){
        DrawRectangleLines(1100/2 - 1,100-1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 100 && y < 180){
        DrawRectangleLines(1100/2 +90 - 1,100 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2  && x < 1100/2 + 80  && y > 200 && y < 280 ){
        DrawRectangleLines(1100/2 - 1,200 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 200 && y < 280 ){
        DrawRectangleLines(1100/2 +90 - 1,200 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2  && x < 1100/2 + 80  && y > 300 && y < 380 ){
        DrawRectangleLines(1100/2 - 1,300 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 300 && y < 380){
        DrawRectangleLines(1100/2 +90 - 1,300 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 && x < 1100/2 + 80  && y > 400 && y < 480 ){
        DrawRectangleLines(1100/2 - 1,400 -1 , 80+2, 80+2, Toolboxes);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 400 && y < 480 ){
        DrawRectangleLines(1100/2 +90 - 1,400 -1 , 80+2, 80+2, Toolboxes);
    }
}


int clickNiveauUn(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 && x < 1100 / 2 + 80 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauDeux(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 + 90 && x < 1100 / 2 + 160 && y > 100 && y < 180) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauZero(int x, int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2  && x < 1100/2 + 80  && y > 200 && y < 280 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickNiveauBack(int x,int y){
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 200 && y < 280 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseMaison(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100 / 2 && x < 1100 / 2 + 80 && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseRoute(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 300 && y < 380) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseElec(int x,int y) {
    x = GetMouseX();
    y = GetMouseY();
    if ( x > 1100/2 && x < 1100/2 + 80  && y > 400 && y < 480 ) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

int clickCaseEau(int x,int y){
    x = GetMouseX();
    y = GetMouseY();
    if (x > 1100/2 +90  && x < 1100/2 + 160  && y > 400 && y < 480) {
        if (IsMouseButtonDown(1)) {
            return 1;
        }
    }
}

void afficherNiveau1( Color Toolboxes){
    DrawRectangleLines(1100/2, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 + 5, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 + 5, 400, 20, Toolboxes);
}

void afficherNiveau2(Color Toolboxes){
    DrawRectangleLines(1100/2, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2, 200, 80, 80, BLACK);
    DrawText("0", 1100 / 2 + 5, 200, 20, BLACK);

    DrawRectangleLines(1100 / 2 + 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 + 5, 400, 20, Toolboxes);
}

void afficherNiveau0(Color Toolboxes){
    DrawRectangleLines(1100/2, 100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 , 100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100 / 2, 200, 80, 80, Toolboxes);
    DrawText("0", 1100 / 2 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 200, 80, 80, Toolboxes);
    DrawText("back", 1100 / 2 + 90 + 5, 200, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 300, 80, 80,Toolboxes);
    DrawText("maison", 1100 / 2 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 300, 80, 80, Toolboxes);
    DrawText("route", 1100 / 2 + 90 + 5, 300, 20, Toolboxes);

    DrawRectangleLines(1100 / 2, 400, 80, 80,Toolboxes );
    DrawText("elec", 1100 / 2 + 5, 400, 20, Toolboxes);

    DrawRectangleLines(1100 / 2 + 90, 400, 80, 80, Toolboxes);
    DrawText("eau", 1100 / 2 + 90 + 5, 400, 20, Toolboxes);
}