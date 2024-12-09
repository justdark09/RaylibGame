#include <iostream>
#include "raylib.h"

#include "knight.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

int printThanks()
{
    std::cout<<"\nThanks for PlayTesting!\n";
    return 0;
}

int main()
{
    knight Knight;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Knight Game");
    SetTargetFPS(60);

    Texture2D knightSheet = LoadTexture("assets/sprites/knight_sheet.png");
    const float frameHeight = static_cast<float>(knightSheet.height)/30;
    const float frameWidth = static_cast<float>(knightSheet.width)/12;
    const float flippedFrame = -frameWidth;
    float currentFrame = frameWidth;

    // gravity
    float gravity = 750;
    float velocityY = 0;

    // holds the source Rectangle and the MaxFrames for each object of a texture
    struct AnimationStruct {
        float animationHeight;
        int maxFrames;
    };


    AnimationStruct attack1_struct{};
    AnimationStruct attack2_struct{};
    AnimationStruct run_struct{};
    AnimationStruct idle_struct{};
    AnimationStruct crouch_walk_struct{};
    AnimationStruct crouch_noMove_struct{};
    AnimationStruct jump_struct{};

    // placeholder struct so the textures can be changed
    AnimationStruct current_struct{};



    float timer = 0.0f;
    int frame = 0;

    float spriteX = 0 - frameWidth*2;
    float spriteY = 300;

    float frameTime = .12f;

    Vector2 spriteCenter = {frameWidth/2, frameHeight/2 };

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        timer += GetFrameTime();

        // increases the frame value every frameTime (tf does that actually mean)
        if (timer > frameTime) {
            timer = 0.0f;
            frame += 1;
        }

        velocityY += GetFrameTime() * gravity;
        spriteY += GetFrameTime() * velocityY;



        // initialize the animation structs
        // !! maxFrames should equal the number of frames the animation has MINUS ONE !!
        idle_struct.maxFrames = 9;
        idle_struct.animationHeight = frameHeight * 16.f;

        attack2_struct.maxFrames = 5;
        attack2_struct.animationHeight = frameHeight * 2.f;

        attack1_struct.maxFrames = 3;
        attack1_struct.animationHeight = frameHeight;

        run_struct.maxFrames = 9;
        run_struct.animationHeight = frameHeight * 20.f;

        crouch_noMove_struct.maxFrames = 3;
        crouch_noMove_struct.animationHeight = frameHeight * 7;

        crouch_walk_struct.maxFrames = 7;
        crouch_walk_struct.animationHeight = frameHeight * 10;

        jump_struct.maxFrames = 2;
        jump_struct.animationHeight = frameHeight * 15;

        float runSpeed = 500 * 1.25 * GetFrameTime();
        float crouchWalkSpeed = 300 * 0.7 * GetFrameTime();

        if (IsKeyPressed(KEY_W)) {

            velocityY = -500;
            current_struct = jump_struct;

        } else if (IsKeyDown(KEY_D)) {
            currentFrame = frameWidth;
            frameTime = .10f;

            if (IsKeyDown(KEY_S)) {
                frameTime = .12f;
                spriteX += crouchWalkSpeed;
                current_struct = crouch_walk_struct;
            } else if (IsKeyDown(KEY_LEFT_SHIFT)) {
                current_struct = run_struct;
                spriteX += runSpeed;
                frameTime = .08f;
            } else {
                spriteX += 300 * GetFrameTime();
                current_struct = run_struct;
            }

        } else if (IsKeyDown(KEY_A)) {
            currentFrame = flippedFrame;
            frameTime = .10f;

            if (IsKeyDown(KEY_S)) {
                frameTime = .12f;
                spriteX -= crouchWalkSpeed;
                current_struct = crouch_walk_struct;
            } else if (IsKeyDown(KEY_LEFT_SHIFT)) {
                current_struct = run_struct;
                spriteX -= runSpeed;
                frameTime = .08f;
            } else {
                spriteX -= 300 * GetFrameTime();
                current_struct = run_struct;
                currentFrame = flippedFrame;
            }

        } else if (IsKeyDown(KEY_S)) {
            current_struct = crouch_noMove_struct;
            frameTime = .48f;
        } else {
            current_struct = idle_struct;
            frameTime = .12f;
            spriteY = 300;
        }

        if (spriteX > SCREEN_WIDTH) {
            spriteX = 0 - frameWidth*2;
        }
        if (spriteX < 0 - frameWidth*2.5) {
            spriteX = SCREEN_WIDTH;
        }

        if (spriteY >= 300) {
            spriteY = 300;
        }


        /*

        frame = frame % current_struct.maxFrames;

        DrawTexturePro(
            knightSheet,
            Rectangle{ frameWidth*frame, current_struct.animationHeight, currentFrame, frameHeight },
            Rectangle{ spriteX, spriteY, frameWidth*5, frameHeight*5 },
            spriteCenter,
            0.f,
            WHITE);

         */

        Knight.drawKnight();

            // todo:
            //  * - spriteX and spriteY do not work with SCREEN_HEIGHT or SCREEN_WIDTH
            //  * causing the sprite to not be drawn on the screen in the first place
            //  *
            //  * - edit the if, if-else, else tree so KEY_D does not have priority
            //  * over KEY_A. kind of a mix of IsKeyDown(int key) and GetKeyPressed(void)
            //  *                                   ^^^  found in rcore.c  ^^^
            //  * - as of 12.7.24 @ 4:42 pm, I think the bounds-checking is still as if
            //  * the origin of the sprite was the top left of it


        EndDrawing();

    }
    UnloadTexture(knightSheet);
    printThanks();
    return 0;
}
