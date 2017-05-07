#pragma once

class ClxPoint
{
public:
    ClxPoint(float x = 0.f, float y = 0.f);

    void Set(float x = 0.f, float y = 0.f);

    float x() const;
    float& x();

    float y() const;
    float& y();

private:
    float _x;
    float _y;
};