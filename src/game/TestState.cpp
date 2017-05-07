#include "pch.h"
#include "game/TestState.h"

void TestState::Create()
{
}

void TestState::Update()
{
    if (ClxG()->Keys()->JustPressed("X"))
    {
        OutputDebugString(L"Shoot\n");
    }

    if (ClxG()->Keys()->Pressed("Space"))
    {
        OutputDebugString(L"Jump\n");
    }
}
