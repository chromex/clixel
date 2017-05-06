#pragma once

class ClxGame
{
public:
    typedef std::function<ClxState*()> CreateStateFunc;

    ClxGame(CreateStateFunc initialState, uint32_t zoom);
    virtual ~ClxGame();

    void Step();

    void Draw();

    void RequestState(CreateStateFunc state);

private:
    void Update();

    void SwitchState();

private:
    CreateStateFunc _iState;
    std::unique_ptr<ClxState> _requestedState;
    std::unique_ptr<ClxState> _state;
    bool _requestedReset;

    // OnKeyUp
    // OnKeyDown
    // OnMouseDown
    // OnMouseUp
    // OnMouseWheel
};