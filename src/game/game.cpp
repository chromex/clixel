#include "pch.h"
#include "game/game.h"
#include "game/TestState.h"

Game::Game() 
    : ClxGame(
        []() { return new TestState(); }, 
        2)
{
}
