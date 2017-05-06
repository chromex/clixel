#include "pch.h"
#include "clixel/Clx.h"

void ClxGlobal::Init(ClxNativeAbstraction* native)
{
    // TODO: Assert not null
    _native.reset(native);
}

void ClxGlobal::SetGame(ClxGame* game)
{
    // TODO: Assert not null
    _game.reset(game);
}

ClxGlobal* ClxG()
{
    static ClxGlobal g;
    return &g;
}
