#pragma once

class ClxNativeKeyboard
{
public:
    virtual bool Pressed(const std::string& key) const = 0;
    virtual bool JustPressed(const std::string& key) const = 0;
    virtual bool JustReleased(const std::string& key) const = 0;
};