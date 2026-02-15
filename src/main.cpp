#include <iostream>
#include "raylib.h"
#include <cmath>

#include "raymath.h"

struct Circle {
    Vector2 pos;
    int radius;
    Color color;
};

int main() {
    int windowWidth = 1600;
    int windowHeight = 900;
    InitWindow(windowWidth, windowHeight, "Space Invaders");



    // create circle
    Circle ship{};
    ship.pos.x = windowWidth / 2.0;
    ship.pos.y = windowHeight / 2.0;
    ship.radius = 10;
    ship.color = RED;

    Vector2 vel;
    vel.x = 0;
    vel.y = 0;

    int speed = 500;

    // direction vector
    Vector2 dir;

    while (!WindowShouldClose()) {
        float dt =  GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        // draw the circle with ship properties
        DrawCircle(ship.pos.x, ship.pos.y, ship.radius, ship.color);

        // stop the circle when it is on window borders
        if ( (ship.pos.x >= windowWidth - ship.radius) || (ship.pos.x <= 0 + ship.radius)
            || (ship.pos.y >= windowHeight - ship.radius) || (ship.pos.y <= 0 + ship.radius)) {
            dir.x = 0;
            dir.y = 0;
            // std::cout << "in border" << std::endl;
        }

        // move the ship with WASD controls for now, and then later implement controller controls

        dir.x = 0;
        dir.y = 0;

        // WASD controls will set direction
        if (IsKeyDown(KEY_W)) dir.y = -1;
        if (IsKeyDown(KEY_A)) dir.x = -1;
        if (IsKeyDown(KEY_D)) dir.x = 1;
        if (IsKeyDown(KEY_S)) dir.y = 1;

        if (dir.x != 0 || dir.y != 0) {
            vel = Vector2Scale(dir, speed); // scale velocity vector in the direction of dir
        } else {
            vel.x = dir.x;
            vel.y = dir.y;
        }

        ship.pos.x += vel.x * dt;
        ship.pos.y += vel.y * dt;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
