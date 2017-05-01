#pragma once

class ClxGlobal
{
public:
    void SetGame(ClxGame* game);

private:
    std::unique_ptr<ClxGame> _game;
};