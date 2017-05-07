#include "pch.h"
#include "clixel/Clx.h"

ClxSprite::ClxSprite(float x, float y)
    : ClxObject(x, y)
{
    this->health() = 1;
}
