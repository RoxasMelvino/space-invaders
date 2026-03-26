#include "Game.h"
#include <iostream>

void Game::CreateBullet(Vector2 posInp, Vector2 dirInp, int speed) {
    Bullet bullet(posInp, dirInp, speed);
    bullets.push_back(bullet);
}

void Game::Update() {
    ClearBackground(BLACK);

    player.Update();
    enemy.Update();

    Vector2 playerBulletDir;
    playerBulletDir.x = 0;
    playerBulletDir.y = -1; // player bullets will shoot straight up for now.

    if (player.WantShoot()) { CreateBullet(player.GetPos(), playerBulletDir, 2000); }

    for (Bullet& bullet : bullets) {
        // std::cout << "Updating bullet" << std::endl;
        bullet.Update();
    }
}

void Game::Draw() {
    player.Draw();
    enemy.Draw();
    for (Bullet& bullet : bullets) {
        bullet.Draw();
    }
}

