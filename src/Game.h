#ifndef GAME_H
#define GAME_H

#include "entities/Player.h"

class Game {
    private:
        Player player;
    public:
        void Update();
        void Draw();
};

#endif //GAME_H