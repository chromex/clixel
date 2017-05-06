#pragma once

class ClxGroup : ClxBasic
{
public:
    ClxGroup(size_t maxSize);

    /// Overrides

    void Update();
    void Draw();

    /// Locals

    size_t GetMaxSize() const;
    void SetMaxSize(size_t maxSize);

    // Add a new ClxBasic child which will receive update and draw calls as
    // appropriate. Only adds the object if there is room for it.
    void Add(spClxBasic object);

    // TODO: Recycle

    spClxBasic Remove(spClxBasic object);

    // TODO: Replace

    // TODO: Sort

    // TODO: GetFirstAvailable

    // TODO: GetFirstNull

    // TODO: GetFirstExtant

    // TODO: GetFirstAlive

    // TODO: GetFirstDead

    // TODO: CountLiving

    // TODO: CountDead

    // TODO: GetRandom

    // TODO: Clear

    // TODO: Kill

protected:
    std::vector<spClxBasic> _members;

private:
    size_t _maxSize;
    size_t _marker;
};