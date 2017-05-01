#pragma once

class ClxState : ClxGroup
{
public:
    // Called after the game successfully switches to the state. Override this function, not the constructor,
    // to initialize your game state.
    virtual void Create();
};