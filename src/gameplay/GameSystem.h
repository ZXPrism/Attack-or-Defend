#pragma once

#include "Player.h"

namespace aod {

    class GameSystem
    {
    public:
        void Init();
        void Run();
        void Shutdown();

        void SelectCards();
        void Battle();

        void PrintPlayerDecks();

    private:
        void _InitCards();

    private:
        std::unique_ptr<Player> _playerA; // human
        std::unique_ptr<Player> _playerB; // bot
    };

} // namespace aod
