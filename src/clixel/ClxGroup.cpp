#include "pch.h"
#include "clixel/Clx.h"

ClxGroup::ClxGroup(size_t maxSize)
    : _maxSize(maxSize)
    , _marker(0)
{
}

void ClxGroup::Update()
{
    for (auto member : _members)
    {
        if (member.get() != nullptr && member->IsExist() && member->IsActive())
        {
            member->PreUpdate();
            member->Update();
            member->PostUpdate();
        }
    }
}

void ClxGroup::Draw()
{
    for (auto member : _members)
    {
        if (member.get() != nullptr && member->IsExist() && member->IsVisible())
        {
            member->Draw();
        }
    }
}

size_t ClxGroup::GetMaxSize() const
{
    return _maxSize;
}

void ClxGroup::SetMaxSize(size_t maxSize)
{
    _maxSize = maxSize;
    
    if (_marker >= _maxSize)
    {
        _marker = 0;
    }

    if (_maxSize < _members.size())
    {
        _members.resize(_maxSize);
    }
}

void ClxGroup::Add(spClxBasic object)
{
    ClxBasic* pObject = object.get();

    // Don't re-add an item
    for (auto member : _members)
    {
        if (member.get() == pObject)
            return;
    }

    // First, look for an empty slot where it can be placed
    size_t nMembers = _members.size();
    for (size_t index = 0; index < nMembers; ++index)
    {
        if (_members[index].get() == nullptr)
        {
            _members[index] = object;
            return;
        }
    }

    // If we are out of space, do nothing
    if (_maxSize > 0 && _members.size() >= _maxSize)
    {
        return;
    }

    // Add
    _members.push_back(object);
}

spClxBasic ClxGroup::Remove(spClxBasic object)
{
    ClxBasic* pObject = object.get();

    for (auto member : _members)
    {
        if (member.get() == pObject)
        {
            member.reset();
            break;
        }
    }

    return object;
}
