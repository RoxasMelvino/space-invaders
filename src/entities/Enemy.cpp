#include "Enemy.h"

Enemy::Enemy() {
    size = 25;

     int startingPosX = GetScreenWidth() - (size * 2);
     int startingPosY = size * 2;

    pos.x = startingPosX;
    pos.y = startingPosY;

    speed = 500;            // hardcoded for now
    shootingCooldown = 2;   // 2 seconds cooldown initially for now
    shootingInterval = 3;   // for shootingCooldown
    timer = 0.0;            // to keep track of time for shootingCooldown
}

void Enemy::Update() {
    float dt = GetFrameTime();
    timer += dt;

    pos.x += -speed * dt; // Enemies will only move left

    if (pos.x <= 0 - size) {
        pos.x = GetScreenWidth() + size;
    }

    //TODO: Fix enemy moving down too much after hitting border
    if (IsTouchingBorder()) {
        std::cout << "x: " << pos.x << " " << "y: " << pos.y << std::endl;
        speed *= -1;
        pos.y += (size / 2); // move down
    }

    wantShoot = false;
    if (timer >= shootingCooldown) {
        timer = 0;
        wantShoot = true;
        shootingCooldown = GetRandomValue(0, shootingInterval);
    }
}

void Enemy::Draw() {
    DrawRectangle(pos.x, pos.y, size, size, RED); // they will be squares for now
}

bool Enemy::IsTouchingBorder() {
    return (pos.x <= size || pos.x >= GetScreenWidth() - size);
}

bool Enemy::WantShoot() {
    return wantShoot;
}

Vector2 Enemy::GetPos() {
    return pos;
}


