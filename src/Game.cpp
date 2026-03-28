#include "Game.h"
#include <iostream>

void Game::CreateBullet(Vector2 posInp, Vector2 dirInp, int speed) {
    Bullet bullet(posInp, dirInp, speed);
    bullets.push_back(bullet);
}

Vector2 Game::BulletTrackEntity(Vector2 source, Vector2 target) {
    Vector2 direction = Vector2Normalize(Vector2Subtract(target, source)); // target - source
    // std::cout << direction.x << " " << direction.y << std::endl;
    return direction;
}


void Game::Update() {
    ClearBackground(BLACK);

    player.Update();
    enemy.Update();

    Vector2 playerBulletDir = BulletTrackEntity(player.GetPos(), GetMousePosition());
    Vector2 enemyBulletDir = BulletTrackEntity(enemy.GetPos(), player.GetPos());

    if (player.WantShoot()) { CreateBullet(player.GetPos(), playerBulletDir, 2000); }
    if (enemy.WantShoot()) {CreateBullet(enemy.GetPos(), enemyBulletDir, 1000);}

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

