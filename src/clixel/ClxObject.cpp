#include "pch.h"
#include "clixel/Clx.h"

ClxObject::ClxObject(float x, float y, float width, float height)
    : _x(x)
    , _y(y)
    , _width(width)
    , _height(height)
{
}

float ClxObject::x() const
{
    return _x;
}

float& ClxObject::x()
{
    return _x;
}

float ClxObject::y() const
{
    return _y;
}

float& ClxObject::y()
{
    return _y;
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

float ClxObject::health() const
{
    return _health;
}

float & ClxObject::health()
{
    return _health;
}

void ClxObject::Hurt(float damage)
{
    _health -= damage;
    if (_health <= 0)
        this->Kill();
}
