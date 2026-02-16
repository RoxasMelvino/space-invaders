#include "Player.h"
#include "raymath.h"
#include "raylib.h"

Player::Player() {
    // default position
    pos.x = GetScreenWidth() / 2;
    pos.y = GetScreenHeight() / 2;

    vel.x = 0;
    vel.y = 0;

    dir.x = 0;
    dir.y = 0;

    // hardcoded for now
    speed = 500;
    health = 500;
}

void Player::Draw(int radius, Color color) {
    DrawCircle(pos.x, pos.y, radius, color);
}

void Player::Update() {
    float dt = GetFrameTime();

    dir.x = 0;
    dir.y = 0;

    // WASD controls will set direction
    if (IsKeyDown(KEY_W)) dir.y = -1;
    if (IsKeyDown(KEY_A)) dir.x = -1;
    if (IsKeyDown(KEY_D)) dir.x = 1;
    if (IsKeyDown(KEY_S)) dir.y = 1;

    if (dir.x != 0 || dir.y != 0) {
        vel = Vector2Scale(dir, speed); // scale vel in the direction of dir
    } else {
        vel.x = dir.x;
        vel.y = dir.y;
    }

    pos.x += vel.x * dt;
    pos.y += vel.y * dt;
}

