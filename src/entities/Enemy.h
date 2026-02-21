#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

class Enemy {
    private:
        Vector2 pos;
        double speed;
        int size; // enemies will vary in size later

    public:
        Enemy();
        void Update();
        void Draw();
};


#endif //ENEMY_H