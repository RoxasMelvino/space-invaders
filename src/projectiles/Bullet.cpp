#include "Bullet.h"
#include "raymath.h"

Bullet::Bullet(Vector2 posInp, Vector2 dirInp, int speedInp) {
    dir = dirInp;
    pos = posInp;
    speed = speedInp;
}

void Bullet::Update() {
    float dt = GetFrameTime();
    vel = Vector2Scale(dir, speed);

    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
}

void Bullet::Draw() {
    int width = 2;
    int height = 16;
    DrawRectangle(pos.x, pos.y, width, height, WHITE);
}


