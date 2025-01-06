#include <iostream>
#include "raylib.h"

#include "knight.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

int printThanks()
{
    std::cout<<"\nThanks for play testing!\n";
    return 0;
}

int main()
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Knight Game");
    SetTargetFPS(60);



    // gravity
    float gravity = 750;
    float velocityY = 0;

    // holds the source Rectangle and the MaxFrames for each object of a texture
    struct AnimationStruct {
        float animationHeight;
        int maxFrames;
    };

    float timer = 0.0f;
    int frame = 0;

    //float spriteX = 0 - frameWidth*2;
    //float spriteY = 300;

    float frameTime = .12f;



    knight Knight;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);



        Knight.drawKnight();

        EndDrawing();

    }
    printThanks();
    return 0;
}
