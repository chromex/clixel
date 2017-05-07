#pragma once

// TODO: Scale, blend, animation, stamping, antialiasing, frame data, dirty, anim callback, etc.

class ClxSprite : ClxObject
{
public:
    // TODO: SimpleGraphic
    ClxSprite(float x = 0, float y = 0);

private:
    ClxPoint _origin;
    ClxPoint _offset;
};