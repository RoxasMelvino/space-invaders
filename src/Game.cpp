#include "Game.h"
#include <iostream>

void Game::Update() {
    ClearBackground(BLACK);

    player.Update();
}

void Game::Draw() {
    player.Draw();
}
