#include <iostream>
#include <cmath>
#include "raylib.h"
#include "raymath.h"
#include "entities/Player.h"
#include "Game.h"


int main() {
    int windowWidth = 1600;
    int windowHeight = 900;
    InitWindow(windowWidth, windowHeight, "Space Invaders");

    Game game;
    while (!WindowShouldClose()) {
        BeginDrawing();

            game.Draw();
            game.Update();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
