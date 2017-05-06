#include "pch.h"
#include "clixel/Clx.h"

ClxGame::ClxGame(CreateStateFunc initialState, uint32_t zoom)
    : _iState(initialState)
    , _requestedReset(true)
{
    // TODO: Use zoom!
    ClxG()->SetGame(this);
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

void ClxGame::RequestState(CreateStateFunc state)
{
    _requestedState.reset(state());
}

void ClxGame::SwitchState()
{
    _state.swap(_requestedState);
    _requestedState.reset();
    _state->Create();
}

void ClxGame::Update()
{
    // UpdateSounds
    _state->Update();
    // UpdateCameras
}