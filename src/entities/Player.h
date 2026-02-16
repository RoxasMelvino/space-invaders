#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"


class Player {
    private:
        Vector2 pos;
        Vector2 vel;
        Vector2 dir;
        double speed;
        int health;

    public:
        Player();
        void Draw(int radius = 10, Color color = BLUE); // for now, the player will just be a circle
        void Update(); // handle input for WASD
};


#endif //PLAYER_H