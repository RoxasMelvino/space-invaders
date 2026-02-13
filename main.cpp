#include <iostream>
#include "raylib.h"
#include "assets.h"
#include <cmath>

#include "raymath.h"


int main() {
    int windowWidth = 800;
    int windowHeight = 600;
    InitWindow(windowWidth, windowHeight, "Space Invaders");

    // create circle
    Circle ship;
    ship.pos.x = windowWidth / 2.0;
    ship.pos.y = windowHeight / 2.0;
    ship.radius = 10;
    ship.color = RED;

    Vector2 vel;
    vel.x = 1;
    vel.y = 1;
    int speed = 30;

    // direction vector
    // Vector2 dir;



    while (!WindowShouldClose()) {
        float dt =  GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        // draw the circle with ship properties
        DrawCircle(ship.pos.x, ship.pos.y, ship.radius, ship.color);

        // move the circle with uniform velocity
        // ship.pos.x += vel.x * dt;
        // ship.pos.y -= vel.y * dt;

        // stop the circle when it is on window border
        if ((ship.pos.x >= windowWidth - ship.radius) || (ship.pos.x <= 0 + ship.radius)) {
            vel.x = 0;
        }

        // TODO: FIX THE GODDAMN MOVEMENT!!!!
        // this movement is sloppy and fucking horrendous. fix it later.
        // possible solution: have a separate direction vector and then scale it with the velocity/speed!!@!!1.
        // move the ship with WASD controls, and then later implement controller controls

        // vel.x = 0; // resetting velocity causes the ship to stutter when changing direction
        // vel.y = 0;


        if (IsKeyPressed(KEY_W) || IsKeyPressedRepeat(KEY_W)) {
            vel.y *= -1;
            vel = Vector2Scale(vel, speed);
        }

        // if (IsKeyPressed(KEY_A) || IsKeyPressedRepeat(KEY_A)) {
        //     vel.x *= -1;
        //     vel = Vector2Scale(vel, speed);
        // }
        //
        // if (IsKeyPressed(KEY_D) || IsKeyPressedRepeat(KEY_D)) {
        //     vel.x *= 1;
        //     vel = Vector2Scale(vel, speed);
        // }
        //
        // if (IsKeyPressed(KEY_S) || IsKeyPressedRepeat(KEY_S)) {
        //     vel.y *= 1;
        //     vel = Vector2Scale(vel, speed);
        // }

        // Vector2 Vector2Scale(Vector2 v, float scale);
        std::cout << vel.x << std::endl;
        std::cout << vel.y << std::endl;

        ship.pos.x += vel.x * dt;
        ship.pos.y += vel.y * dt;

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
