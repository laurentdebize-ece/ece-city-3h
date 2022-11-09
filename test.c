

#include "test.h"


void afficherToolBox(){
    //DrawRectangleLines(1100/2 - 10,80 , 200 -10, 600, BLACK);
    DrawRectangleLines(1100/2,100 , 80, 80, BLACK);
    DrawText("-1",1100/2 +5 , 100, 20, BLACK);

    DrawRectangleLines(1100/2 +90 ,100 , 80, 80, BLACK);
    DrawText("-2",1100/2 +90 +5, 100, 20, BLACK);

    DrawRectangleLines(1100/2,200 , 80, 80, BLACK);
    DrawText("Maison",1100/2 + 5, 200, 20, BLACK);

    DrawRectangleLines(1100/2 +90 ,200 , 80, 80, BLACK);
    DrawText("route",1100/2 +90 +5, 200, 20, BLACK);

    DrawRectangleLines(1100/2,300 , 80, 80, BLACK);
    DrawText("elec",1100/2 +5, 300, 20, BLACK);

    DrawRectangleLines(1100/2 +90 ,300 , 80, 80, BLACK);
    DrawText("eau",1100/2 +90 +5, 300, 20, BLACK);

    DrawRectangleLines(1100/2,400 , 80, 80, BLACK);
    DrawText("0",1100/2 +5, 400, 20, BLACK);

    DrawRectangleLines(1100/2 +90 ,400 , 80, 80, BLACK);

    //sprintf_s(time,"%d",c.ece_flouz);
    //DrawText(, 1100/2, 100, 10, BLUE);


    int x = GetMouseX();
    int y = GetMouseY();
    if ( x > 1100/2 && x < 1100/2 + 80 && y > 100 && y < 180){
        DrawRectangleLines(1100/2 - 1,100-1 , 80+2, 80+2, BLACK);
        if (IsMouseButtonPressed(1)){
            CloseWindow();
        }
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 100 && y < 180){
        DrawRectangleLines(1100/2 +90 - 1,100 -1 , 80+2, 80+2, BLACK);
        if (IsMouseButtonPressed(1)){
            CloseWindow();
        }
    }

    if ( x > 1100/2  && x < 1100/2 + 80  && y > 200 && y < 280){
        DrawRectangleLines(1100/2 - 1,200 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 200 && y < 280){
        DrawRectangleLines(1100/2 +90 - 1,200 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2  && x < 1100/2 + 80  && y > 300 && y < 380){
        DrawRectangleLines(1100/2 - 1,300 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 300 && y < 380){
        DrawRectangleLines(1100/2 +90 - 1,300 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 && x < 1100/2 + 80  && y > 400 && y < 480){
        DrawRectangleLines(1100/2 - 1,400 -1 , 80+2, 80+2, BLACK);
    }
    if ( x > 1100/2 +90  && x < 1100/2 + 160  && y > 400 && y < 480){
        DrawRectangleLines(1100/2 +90 - 1,400 -1 , 80+2, 80+2, BLACK);
    }

}
