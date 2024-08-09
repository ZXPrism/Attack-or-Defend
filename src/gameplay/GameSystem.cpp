#include "GameSystem.h"

#include "Console.h"
#include "UI.h"
#include "Utils.h"
#include "card/Card_TestCard.h"

#include <format>
#include <string>

namespace aod {

    void GameSystem::Init()
    {
        std::string title("Attack or Defend ~ Re Ver.");

        auto &console = Console::GetInstance();
        console.SetWindowTitle(title);
        console.SetCursorVisibility(false);
        console.ClearScreen();

        _InitCards();
    }

    void GameSystem::_InitCards()
    {
        _CardManager.RegisterCard<card::TestCard>();
    }

    void GameSystem::Run()
    {
        while (1)
        {
            Menu_SelectCards();
        }
    }

    void GameSystem::Shutdown()
    {
        ;
    }

    void GameSystem::Menu_SelectCards()
    {
        auto &cardNameMap = _CardManager.GetCardNameMap();
        int nCardNameMap = cardNameMap.size();
        for (int i = 0; i < nCardNameMap; i++)
        {
            std::cout << std::format("[{}] {}", i, cardNameMap[i]) << std::endl;
        }

        // TODO: menu
    }

} // namespace aod
