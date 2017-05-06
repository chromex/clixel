#include "pch.h"
#include "game/game.h"

Game::Game() 
    : ClxGame(
        []() { return (ClxState*)nullptr; }, 
        2)
{
}
