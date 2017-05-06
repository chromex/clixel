#pragma once

class ClxGlobal
{
public:
    void Init(ClxNativeAbstraction* native);
    void SetGame(ClxGame* game);

private:
    std::unique_ptr<ClxGame> _game;
    std::unique_ptr<ClxNativeAbstraction> _native;
};

ClxGlobal* ClxG();
