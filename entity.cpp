#include "entity.h"


int entity::trackFrames()
{
    if (timer > frameTime) {
        timer = 0.0f;
        frame += 1;
    }
    return frame;
}


void entity::setCoords(float a, float b)
{
    x = a;
    y = b;
}

void entity::setWidth(float w)
{
    frameWidth = w;
}

void entity::setHeight(float h)
{
    frameHeight = h;
}

Rectangle entity::getCollisionRec() const
{
    return collisionRec;
}