#include "Game.h"

void Game::Update() {
    ClearBackground(BLACK);
    player.Update();
    enemy.Update();
}

void Game::Draw() {
    player.Draw();
    enemy.Draw();
}
