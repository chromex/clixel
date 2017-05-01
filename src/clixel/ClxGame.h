#pragma once

class ClxGame
{
public:
    typedef std::function<ClxState*()> CreateStateFunc;

    ClxGame(ClxNativeAbstraction* abstraction, CreateStateFunc initialState, uint32_t zoom);
    virtual ~ClxGame();

private:
    ClxNativeAbstraction* _abstraction;
    CreateStateFunc _iState;
    std::unique_ptr<ClxState> _requestedState;
    std::unique_ptr<ClxState> _state;
    bool _requestedReset;

    // OnKeyUp
    // OnKeyDown
    // OnMouseDown
    // OnMouseUp
    // OnMouseWheel

    void Step();

    void Draw();

    void SwitchState();

    void Update();
};