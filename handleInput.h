#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H

class handleInput {
public:
    handleInput();

    void moveCharacter();
    float getVelocityY();
    float getVelocityX();

private:
    float gravityForce;

    float spriteX;
    float spriteY;

    float velocityY = gravityForce;
    float velocityX = 0;

};



#endif //HANDLEINPUT_H
