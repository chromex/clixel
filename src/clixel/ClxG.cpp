#include "pch.h"
#include "Clx.h"

void ClxGlobal::SetGame(ClxGame* game)
{
    // TODO: Assert not null
    _game.reset(game);
}
