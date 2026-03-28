#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <iostream>

class Enemy {
    private:
        Vector2 pos;
        double speed;
        int size; // enemies will vary in size later
        float timer;
        int shootingInterval;
        int shootingCooldown;
        bool wantShoot;

    public:
        Enemy();
        void Update();
        void Draw();
        bool IsTouchingBorder();
        bool WantShoot();
        Vector2 GetPos();
};


#endif //ENEMY_H