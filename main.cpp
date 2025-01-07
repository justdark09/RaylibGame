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

    knight Knight;

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        Knight.drawKnight();

        EndDrawing();
    }
    //printThanks();
    Knight.unload();
    return 0;
}