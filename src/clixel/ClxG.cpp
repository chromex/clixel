#include "pch.h"
#include "clixel/Clx.h"

void ClxGlobal::Init(std::shared_ptr<ClxNativeAbstraction> native)
{
    // TODO: Assert not null
    _native = native;
}

void ClxGlobal::SetGame(ClxGame* game)
{
    // TODO: Assert not null
    // TODO: Assert not already set
    _game.reset(game);
}

ClxNativeKeyboard* ClxGlobal::Keys()
{
    return _native->GetKeyboard();
}

ClxGlobal* ClxG()
{
    static ClxGlobal g;
    return &g;
}
