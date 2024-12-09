#include "handleInput.h"
#include "knight.h"

handleInput input;

handleInput::handleInput()
{
    gravityForce = -300 * GetFrameTime();
    spriteX += velocityX;
    spriteY = 300;
}

/*
* void handleInput::moveCharacter()
{
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
}
 */




float handleInput::getVelocityX()
{
    return velocityX;
}
float handleInput::getVelocityY()
{
    return velocityY;
}

