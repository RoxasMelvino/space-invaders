#include "Enemy.h"

Enemy::Enemy() {
    size = 25;

     int startingPosX = GetScreenWidth() - (size * 2);
     int startingPosY = size * 2;

    pos.x = startingPosX;
    pos.y = startingPosY;

    speed = 300; // hardcoded for now
}

void Enemy::Update() {
    pos.x += -speed * GetFrameTime(); // Enemies will only move left

    if (pos.x <= 0 - size) {
        pos.x = GetScreenWidth() + size;
    }

    if (IsTouchingBorder()) {
        speed *= -1;
        pos.y += (size / 2); // move down
    }
}

void Enemy::Draw() {
    DrawRectangle(pos.x, pos.y, size, size, RED); // they will be squares for now
}

bool Enemy::IsTouchingBorder() {
    return (pos.x <= size || pos.x >= GetScreenWidth() - size);
}

