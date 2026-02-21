#include "Enemy.h"

Enemy::Enemy() {
    size = 25;

     int startingPosX = GetScreenWidth() + size;
     int startingPosY = GetScreenHeight() / 4;

    pos.x = startingPosX;
    pos.y = startingPosY;

    speed = 150; // hardcoded for now
}

void Enemy::Update() {
    pos.x -= speed * GetFrameTime(); // Enemies will only move left

    if (pos.x <= 0 - size) {
        pos.x = GetScreenWidth() + size;
    }
}

void Enemy::Draw() {
    DrawRectangle(pos.x, pos.y, size, size, RED); // they will be squares for now
}
