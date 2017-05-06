#include "pch.h"
#include "clixel/Clx.h"

ClxBasic::ClxBasic()
    : _exists(true)
    , _active(true)
    , _visible(true)
    , _alive(true)
{
}

ClxBasic::~ClxBasic()
{}

bool ClxBasic::IsExist() const { return _exists; }
void ClxBasic::SetExist(bool val) { _exists = val; }

bool ClxBasic::IsActive() const { return _active; }
void ClxBasic::SetActive(bool val) { _active = val; }

bool ClxBasic::IsVisible() const { return _visible; }
void ClxBasic::SetVisible(bool val) { _visible = val; }

bool ClxBasic::IsAlive() const { return _alive; }
void ClxBasic::SetAlive(bool val) { _alive = val; }

void ClxBasic::PreUpdate() {}

void ClxBasic::Update() {}

void ClxBasic::PostUpdate() {}

void ClxBasic::Draw() {}

void ClxBasic::Kill()
{
    _alive = false;
    _exists = false;
}

void ClxBasic::Revive()
{
    _alive = true;
    _exists = true;
}