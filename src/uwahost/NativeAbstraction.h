#pragma once

#include "clixel\ClxNativeAbstraction.h"

class NativeKeyboard : public ClxNativeKeyboard
{
public:
    NativeKeyboard();

    // ClxNativeKeyboard
    bool Pressed(const std::string& key) const;
    bool JustPressed(const std::string& key) const;
    bool JustReleased(const std::string& key) const;

    // Local
    void OnKeyDown(Windows::System::VirtualKey key);
    void OnKeyUp(Windows::System::VirtualKey key);
    void Update();

private:
    std::unordered_map<std::string, int> _lookup;
    std::bitset<256> _keys;
    std::bitset<256> _prevKeys;
};

class NativeAbstraction : public ClxNativeAbstraction
{
public:
    ClxNativeKeyboard* GetKeyboard();

private:
    NativeKeyboard _keyboard;
};