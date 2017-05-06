#include "pch.h"
#include "Clx.h"

ClxObject::ClxObject(float x, float y, float width, float height)
    : _x(x)
    , _y(y)
    , _width(width)
    , _height(height)
{
}

float ClxObject::GetX() const
{
    return _x;
}

void ClxObject::SetX(float x)
{
    _x = x;
}

float ClxObject::GetY() const
{
    return _y;
}

void ClxObject::SetY(float y)
{
    _y = y;
}

void ClxObject::GetPosition(float* x, float* y) const
{
    *x = _x;
    *y = _y;
}

void ClxObject::SetPosition(float x, float y)
{
    _x = x;
    _y = y;
}
