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
        auto &console = Console::GetInstance();
        console.ClearScreen();

        int cardCnt = _CardManager.GetCardCnt();

        std::vector<int> selectedCard(cardCnt);
        int selectedCnt = 0;

        while (1)
        {
            for (int i = 0; i < cardCnt; i++)
            {
                auto &card = _CardManager.GetSampleCard(i);

                std::cout << (selectedCard[i] ? Color::GREEN : Color::WHITE);
                std::cout
                    << std::format(
                           "[{}] {} -> 血量: {}, 攻击力: {}, 暴击率: {:.2f}, 暴击倍率：{:.2f}", i,
                           card.GetName(), card.GetHP(), card.GetAttackPower(),
                           100 * card.GetCritRate(), card.GetCritFactor())
                    << std::endl;
            }

            auto key = console.GetCharNonblocking();
            if (key == '\r')
            {
                if (!selectedCnt)
                {
                    std::cout << Color::LIGHTAQUA << "请选择至少一张卡牌出战！" << std::endl;
                    SleepFor(1000);
                }
                else
                {
                    break;
                }
            }
            else if (key >= '0' && key <= '9') // 目前最多支持 10 张卡牌
            {
                int cardID = key - '0';
                if (cardID < cardCnt)
                {
                    selectedCard[key - '0'] ^= 1;
                    selectedCnt += selectedCard[key - '0'] ? 1 : -1;
                }
            }

            console.ClearScreen();
        }

        std::cout << Color::LIGHTAQUA << "已选择 ";
        for (int i = 0; i < cardCnt; i++)
        {
            if (selectedCard[i])
            {
                std::cout << std::format("[{}] ", i);
            }
        }
        std::cout << std::endl;

        std::cin.get();
    }

} // namespace aod
