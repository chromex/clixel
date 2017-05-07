#include "pch.h"
#include "NativeAbstraction.h"

using namespace Windows::System;

NativeKeyboard::NativeKeyboard()
{
#define ADD_LOOKUP(VKey) { std::string str(#VKey); _lookup[str.substr(12)] = (int)VKey; }
    ADD_LOOKUP(VirtualKey::A);
    ADD_LOOKUP(VirtualKey::B);
    ADD_LOOKUP(VirtualKey::C);
    ADD_LOOKUP(VirtualKey::D);
    ADD_LOOKUP(VirtualKey::E);
    ADD_LOOKUP(VirtualKey::F);
    ADD_LOOKUP(VirtualKey::G);
    ADD_LOOKUP(VirtualKey::H);
    ADD_LOOKUP(VirtualKey::I);
    ADD_LOOKUP(VirtualKey::J);
    ADD_LOOKUP(VirtualKey::K);
    ADD_LOOKUP(VirtualKey::L);
    ADD_LOOKUP(VirtualKey::M);
    ADD_LOOKUP(VirtualKey::N);
    ADD_LOOKUP(VirtualKey::O);
    ADD_LOOKUP(VirtualKey::P);
    ADD_LOOKUP(VirtualKey::Q);
    ADD_LOOKUP(VirtualKey::R);
    ADD_LOOKUP(VirtualKey::S);
    ADD_LOOKUP(VirtualKey::T);
    ADD_LOOKUP(VirtualKey::U);
    ADD_LOOKUP(VirtualKey::V);
    ADD_LOOKUP(VirtualKey::W);
    ADD_LOOKUP(VirtualKey::X);
    ADD_LOOKUP(VirtualKey::Y);
    ADD_LOOKUP(VirtualKey::Z);

    ADD_LOOKUP(VirtualKey::Escape);
    
    ADD_LOOKUP(VirtualKey::F1);
    ADD_LOOKUP(VirtualKey::F2);
    ADD_LOOKUP(VirtualKey::F3);
    ADD_LOOKUP(VirtualKey::F4);
    ADD_LOOKUP(VirtualKey::F5);
    ADD_LOOKUP(VirtualKey::F6);
    ADD_LOOKUP(VirtualKey::F7);
    ADD_LOOKUP(VirtualKey::F8);
    ADD_LOOKUP(VirtualKey::F9);
    ADD_LOOKUP(VirtualKey::F10);
    ADD_LOOKUP(VirtualKey::F11);
    ADD_LOOKUP(VirtualKey::F12);

    ADD_LOOKUP(VirtualKey::Space);
    ADD_LOOKUP(VirtualKey::LeftControl);
    ADD_LOOKUP(VirtualKey::RightControl);
    ADD_LOOKUP(VirtualKey::LeftShift);
    ADD_LOOKUP(VirtualKey::RightShift);

    ADD_LOOKUP(VirtualKey::Left);
    ADD_LOOKUP(VirtualKey::Right);
    ADD_LOOKUP(VirtualKey::Up);
    ADD_LOOKUP(VirtualKey::Down);
}

bool NativeKeyboard::Pressed(const std::string& key) const
{
    auto entry = _lookup.find(key);
    if (entry != _lookup.end())
    {
        return _keys.test(entry->second);
    }
    else
    {
        // TODO: Trace failure
        return false;
    }
}

bool NativeKeyboard::JustPressed(const std::string& key) const
{
    auto entry = _lookup.find(key);
    if (entry != _lookup.end())
    {
        return _keys.test(entry->second) && !_prevKeys.test(entry->second);
    }
    else
    {
        // TODO: Trace failure
        return false;
    }
}

bool NativeKeyboard::JustReleased(const std::string& key) const
{
    auto entry = _lookup.find(key);
    if (entry != _lookup.end())
    {
        return !_keys.test(entry->second) && _prevKeys.test(entry->second);
    }
    else
    {
        // TODO: Trace failure
        return false;
    }
}

void NativeKeyboard::OnKeyDown(VirtualKey key)
{
    _keys.set((int)key);
}

void NativeKeyboard::OnKeyUp(VirtualKey key)
{
    _keys.reset((int)key);
}

void NativeKeyboard::Update()
{
    _prevKeys = _keys;
}

ClxNativeKeyboard* NativeAbstraction::GetKeyboard()
{
    return &_keyboard;
}
