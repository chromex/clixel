#pragma once

#include "clixel\ClxNativeAbstraction.h"

class NativeKeyboard : public ClxNativeKeyboard
{
public:
    bool Pressed(const std::string& key) const;
    bool JustPressed(const std::string& key) const;
    bool JustReleased(const std::string& key) const;
};

class NativeAbstraction : public ClxNativeAbstraction
{
public:
    ClxNativeKeyboard* GetKeyboard();

private:
    NativeKeyboard _keyboard;
};