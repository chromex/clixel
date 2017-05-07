#pragma once

#include "ClxNativeKeyboard.h"

class ClxNativeAbstraction
{
public:
    virtual ClxNativeKeyboard* GetKeyboard() = 0;
};