#ifndef GAME_H
#define GAME_H

#include "entities/Player.h"
#include "entities/Enemy.h"

class Game {
    private:
        Player player;
        Enemy enemy;
    public:
        void Update();
        void Draw();
};

#endif //GAME_H