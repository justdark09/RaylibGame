#ifndef KNIGHT_H
#define KNIGHT_H

#include "raylib.h"



class knight {
public:

private:
    Texture2D knightSheet{};

    // holds the source Rectangle's animationHeight and the MaxFrames for each object of a texture
    struct AnimationStruct{ float animationHeight; int maxFrames; };

    AnimationStruct attack1_struct{};
    AnimationStruct attack2_struct{};
    AnimationStruct run_struct{};
    AnimationStruct idle_struct{};
    AnimationStruct crouch_walk_struct{};
    AnimationStruct crouch_noMove_struct{};
    AnimationStruct jump_struct{};
};



#endif //KNIGHT_H
