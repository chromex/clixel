#pragma once

class ClxGlobal
{
public:
    void Init(std::shared_ptr<ClxNativeAbstraction> native);
    void SetGame(ClxGame* game);

    ClxNativeKeyboard* Keys();

private:
    std::unique_ptr<ClxGame> _game;
    std::shared_ptr<ClxNativeAbstraction> _native;
};

ClxGlobal* ClxG();
