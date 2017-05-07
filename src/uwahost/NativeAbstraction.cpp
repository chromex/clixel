#include "pch.h"
#include "NativeAbstraction.h"

bool NativeKeyboard::Pressed(const std::string& key) const
{
    return false;
}

bool NativeKeyboard::JustPressed(const std::string& key) const
{
    return true;
}

bool NativeKeyboard::JustReleased(const std::string& key) const
{
    return false;
}

ClxNativeKeyboard* NativeAbstraction::GetKeyboard()
{
    return &_keyboard;
}
