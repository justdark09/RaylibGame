#ifndef KNIGHT_H
#define KNIGHT_H

#include "entity.h"
#include "raylib.h"

class knight : public entity {
public:
    knight();
    void drawKnight();

    void moveRight(float);
    void moveLeft(float);
    void jump();

    // unload everything (Textures, Sounds, etc)
    void unload() const;

private:
    float frameHeight;
    float frameWidth;
    float currentFrame;

    float spriteX;
    float spriteY;

    float velocityY;

    float gravity;

    float crouchSpeed;
    float runSpeed;
    float jumpPower;

    float currentSpeed;

    // resets velocity and animation to default values
    void resetVelAndAnim();

    bool isGrounded;

    bool isFlipped;


    Texture2D knightSheet{};

    // holds the source Rectangle's animationHeight and the MaxFrames for each object of a texture
    struct AnimationStruct{ float animationHeight; int maxFrames; };

    // holds the values of each animation available
    AnimationStruct attack1_struct{};
    AnimationStruct attack2_struct{};
    AnimationStruct run_struct{};
    AnimationStruct idle_struct{};
    AnimationStruct crouch_walk_struct{};
    AnimationStruct crouch_noMove_struct{};
    AnimationStruct jump_struct{};

    // holds the value of the current animation playing
    AnimationStruct current_struct{};
};



#endif //KNIGHT_H
