#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <algorithm>


class Player {
    private:
        Vector2 pos;
        Vector2 vel;
        Vector2 dir;
        double speed;
        int health;
        bool wantShoot;
        int size;

    public:
        Player();
        void Draw(Color color = BLUE); // for now, the player will just be a circle
        void Update();
        Vector2 GetPos();
        bool WantShoot();
        bool IsTouchingBorder();
};


#endif //PLAYER_H