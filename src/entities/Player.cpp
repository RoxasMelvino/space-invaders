#include "Player.h"


Player::Player() {
    // default position
    pos.x = GetScreenWidth() / 2;
    pos.y = GetScreenHeight() / 2;

    vel.x = 0;
    vel.y = 0;

    dir.x = 0;
    dir.y = 0;

    // hardcoded for now
    size = 10;
    speed = 500;
    health = 500;
    wantShoot = false;
}

void Player::Draw(Color color) {
    DrawCircle(pos.x, pos.y, size, color);
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

    // Check for left click input
    wantShoot = false;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {wantShoot = true;}
    if (IsTouchingBorder()) {
        // clamp the player's position so that they don't move beyond the screen
        float Xmin = size;
        float Xmax = GetScreenWidth() - size;
        float Ymin = size;
        float Ymax = GetScreenHeight() - size;

        pos.x = std::clamp(pos.x, Xmin, Xmax);
        pos.y = std::clamp(pos.y, Ymin, Ymax);

    }

}

Vector2 Player::GetPos() {
    return pos;
}

bool Player::WantShoot() {
    return wantShoot;
}

bool Player::IsTouchingBorder() {
    return (pos.x <= size || pos.x >= GetScreenWidth() - size || pos.y <= size || pos.y >= GetScreenHeight() - size);
}




