#include "pch.h"
#include "Clx.h"

ClxGame::ClxGame(ClxNativeAbstraction* abstraction, CreateStateFunc initialState, uint32_t zoom)
    : _abstraction(abstraction)
    , _iState(initialState)
    , _requestedReset(true)
{
    // TODO: Use zoom!
    // Set singleton
}

ClxGame::~ClxGame()
{
}

void ClxGame::Step()
{
    if (_requestedReset)
    {
        _requestedReset = false;
        _requestedState.reset(_iState());
        // TODO? FlxG.reset();
    }

    if (_requestedState.get() != nullptr)
    {
        this->SwitchState();
    }

    // TODO? FlxG.updateInput();

    this->Update();

    // TODO? FlxG.mouse.wheel = 0;
}

void ClxGame::Draw()
{
    // LockCameras
    // _state->Draw();
    // UnlockCameras
}

void ClxGame::SwitchState()
{
    _state.swap(_requestedState);
    _requestedState.reset();
    // TODO: _state->Create();
}

void ClxGame::Update()
{
    // UpdateSounds
    // TODO: _state->Update();
    // UpdateCameras
}