#pragma once

// TODO: Physics, path finding, flicker, automatic movement, drawDebug... really everything

class ClxObject : ClxBasic
{
public:
    ClxObject(float x = 0, float y = 0, float width = 0, float height = 0);

    /// Overrides

    /// Locals

    float x() const;
    float& x();

    float y() const;
    float& y();

    void GetPosition(float* x, float* y) const;
    void SetPosition(float x, float y);

    float health() const;
    float& health();
    void Hurt(float damage);

private:
    float _x;
    float _y;
    float _width;
    float _height;
    float _health;
};