#include "pch.h"
#include "clixel\ClxPoint.h"

ClxPoint::ClxPoint(float x, float y)
    : _x(x)
    , _y(y)
{
}

void ClxPoint::Set(float x, float y)
{
    _x = x;
    _y = y;
}

float ClxPoint::x() const
{
    return _x;
}

float& ClxPoint::x()
{
    return _x;
}

float ClxPoint::y() const
{
    return _y;
}

float& ClxPoint::y()
{
    return _y;
}
