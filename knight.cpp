#include "knight.h"

#define SCREEN_HEIGHT 900
#define SCREEN_WIDTH 1600

knight::knight(): gravity(125)
{
    knightSheet = LoadTexture("assets/sprites/knight_sheet.png");

    frameHeight = static_cast<float>(knightSheet.height) / 30;
    frameWidth = static_cast<float>(knightSheet.width) / 12;

    currentFrame = frameWidth;

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

    // starting animation struct
    current_struct = idle_struct;

    crouchSpeed = 300 * 0.7f * GetFrameTime();
    runSpeed = 500 * 1.25f * GetFrameTime();
    jumpPower = 200.f;

    currentSpeed = 0.f;

    spriteX = 0;
    spriteY = 300;

    velocityX = 0;
    velocityY = 0;

}

void knight::moveLeft(float speed)
{
    current_struct = run_struct;
    spriteX -= speed;
}
void knight::moveRight(float speed)
{
    current_struct = run_struct;
    spriteX += speed;
}
void knight::jump()
{
    velocityY = -30;
}





void knight::drawKnight()
{
    spriteY += velocityY;

    if (spriteX > SCREEN_WIDTH) {
        spriteX = 0 - frameWidth*2;
    }
    if (spriteX < 0 - frameWidth*2.5) {
        spriteX = SCREEN_WIDTH;
    }

    if (spriteY >= 300) {
        spriteY = 300;
    }


    velocityY += GetFrameTime() * gravity;
    spriteY += GetFrameTime() * velocityY;



    if (IsKeyPressed(KEY_W)) {
        jump();
    } else if (IsKeyDown(KEY_A)) {
        currentSpeed = 7;
        moveLeft(currentSpeed);
    } else if (IsKeyDown(KEY_D)) {
        currentSpeed = 7;
        moveRight(currentSpeed);
    }


    int knightFrame = 0;
    knightFrame = trackFrames();
    knightFrame = knightFrame % current_struct.maxFrames;

    timer += GetFrameTime();

    if (spriteX > SCREEN_WIDTH) {
        spriteX = 0 - frameWidth*2;
    }
    if (spriteX < 0 - frameWidth*2.5) {
        spriteX = SCREEN_WIDTH;
    }

    DrawTexturePro(
        knightSheet,
        Rectangle{ frameWidth * knightFrame, current_struct.animationHeight, currentFrame, frameHeight },
        Rectangle{ spriteX, spriteY, frameWidth*5, frameHeight*5 },
        spriteCenter,
        0.f,
        WHITE);
}
