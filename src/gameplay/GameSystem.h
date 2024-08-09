#pragma once

#include "CardManager.h"

#include <vector>

namespace aod {

    class GameSystem
    {
    public:
        void Init();
        void Run();
        void Shutdown();

        void Menu_SelectCards();

    private:
        void _InitCards();

    private:
        CardManager _CardManager;
    };

} // namespace aod
