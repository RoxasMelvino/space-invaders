
#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

class Bullet {
    private:
        Vector2 pos;
        Vector2 dir;
        Vector2 vel;
        int speed;

    public:
        Bullet(Vector2 posInp, Vector2 dirInp, int speed);
        void Update();
        void Draw();
};

#endif //BULLET_H