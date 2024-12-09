#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class entity {
public:
    void setCoords(float, float);
    void setWidth(float);
    void setHeight(float);
    Vector2 spriteCenter{};
    float timer = 0.f;

    int trackFrames();

    Rectangle getCollisionRec() const;
private:
    int frame = 0;
    float frameTime = .12;

    float x = 0;
    float y = 0;
    float frameWidth = 0;
    float frameHeight = 0;

    Rectangle collisionRec = {  x, y, frameWidth, frameHeight };
};

#endif //ENTITY_H