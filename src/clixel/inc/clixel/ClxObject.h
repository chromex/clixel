#pragma once

// TODO: Physics, path finding, flicker, automatic movement, drawDebug... really everything

class ClxObject : ClxBasic
{
public:
    ClxObject(float x, float y, float width, float height);

    /// Overrides

    /// Locals

    float GetX() const;
    void SetX(float x);

    float GetY() const;
    void SetY(float y);

    void GetPosition(float* x, float* y) const;
    void SetPosition(float x, float y);

private:
    float _x;
    float _y;
    float _width;
    float _height;
};