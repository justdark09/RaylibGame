#ifndef KNIGHT_H
#define KNIGHT_H

#include "entity.h"
#include "raylib.h"

class knight : public entity {
public:
    knight();
    void drawKnight();

private:
    float frameHeight;
    float frameWidth;

    float currentFrame;

    float spriteX = 0;
    float spriteY = 0;

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
