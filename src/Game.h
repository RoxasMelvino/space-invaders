#ifndef GAME_H
#define GAME_H

#include <vector>
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "projectiles/Bullet.h"

class Game {
    private:
        Player player;
        Enemy enemy;
        std::vector<Bullet> bullets;

    public:
        void Update();
        void Draw();
        void CreateBullet(Vector2 posInp, Vector2 dirInp, int speed);
};

#endif //GAME_H