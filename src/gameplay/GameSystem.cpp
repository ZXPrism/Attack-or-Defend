#include "GameSystem.h"

#include "CardManager.h"
#include "Console.h"
#include "PlayerBot.h"
#include "UI.h"
#include "Utils.h"
#include "card/Card_TestCard.h"
#include "card/Card_ZXP4.h"

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

        DissolveTextCentered("Attack or Defend ~ Re Ver.");
        SleepFor(2000);
        console.ClearScreen();
        DissolveTextCentered("Presented by ZXP4");
        SleepFor(2000);

        _InitCards();
    }

    void GameSystem::_InitCards()
    {
        gCardManager.RegisterCard<card::TestCard>();
        gCardManager.RegisterCard<card::ZXP4>();
    }

    void GameSystem::Run()
    {
        while (1)
        {
            _playerA = std::make_unique<Player>();
            _playerB = std::make_unique<PlayerBot>();

            SelectCards();
            Battle();
        }
    }

    void GameSystem::Shutdown()
    {
        ;
    }

    void GameSystem::SelectCards()
    {
        auto &console = Console::GetInstance();
        console.ClearScreen();

        int cardCnt = gCardManager.GetCardCnt();

        std::vector<int> selectedCard(cardCnt);
        int selectedCnt = 0;

        while (1)
        {
            std::cout
                << Color::WHITE
                << "选择我方出战的卡片（输入数字以选择对应卡片，输入同样的数字以取消选择，全部"
                   "选择完毕后按回车确认）："
                << std::endl;

            for (int i = 0; i < cardCnt; i++)
            {
                auto &card = gCardManager.GetSampleCard(i);

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
                    std::cout << Color::LIGHTAQUA << "请选择至少一张卡片出战！" << std::endl;
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
                _playerA->AppendCard(gCardManager.AllocCard(i));
            }
        }
        std::cout << std::endl;

        SleepFor(1000);
    }

    void GameSystem::Battle()
    {
        auto &console = Console::GetInstance();

        auto CheckStatus = [](ActionStatus &status, const Player &attacker, const Player &target,
                              int turn) -> bool {
            static Color sPlayerColors[2] = {Color::LIGHTGREEN, Color::LIGHTRED};

            auto cardAttacker = attacker.GetCard(status._AttackerCardID);
            auto cardTarget = target.GetCard(status._TargetCardID);

            std::cout << sPlayerColors[turn] << cardAttacker->GetName();
            std::cout << Color::WHITE << " 对 ";
            std::cout << sPlayerColors[turn ^ 1] << cardTarget->GetName();
            std::cout << Color::WHITE << " 造成了 ";
            std::cout << (status._IsCritHit ? Color::YELLOW : Color::WHITE) << status._Damage;
            std::cout << Color::WHITE << " 点伤害" << std::endl;

            if (status._IsDead)
            {
                std::cout << Color::LIGHTBLUE << std::format("{} 被击败了。", cardTarget->GetName())
                          << std::endl;
                if (status._KillCnt > 1)
                {
                    std::cout << Color::WHITE << cardAttacker->GetName() << ' ' << Color::RED
                              << status._KillCnt << Color::WHITE << " 杀！" << std::endl;
                }
            }

            return !target.IsAlive();
        };

        bool gameResult = false;
        int turn = 0; // 0: PlayerA / 1: PlayerB

        while (1)
        {
            PrintPlayerDecks();

            ActionStatus status;
            if (!turn)
            {
                _playerA->Act(status, *_playerB);
                if (CheckStatus(status, *_playerA, *_playerB, turn))
                {
                    gameResult = true;
                    break;
                }
            }
            else
            {
                _playerB->Act(status, *_playerA);
                if (CheckStatus(status, *_playerB, *_playerA, turn))
                {
                    gameResult = false;
                    break;
                }
            }

            SleepFor(1000);
            console.ClearScreen();

            turn ^= 1;
        }

        SleepFor(1000);
        PrintPlayerDecks();

        if (gameResult)
        {
            std::cout << Color::LIGHTGREEN << "你获胜了！" << std::endl;
        }
        else
        {
            std::cout << Color::RED << "败北。" << std::endl;
        }

        std::cin.ignore();
        std::cout << "回车开始新的一局..." << std::endl;
        std::cin.get();
    }

    void GameSystem::PrintPlayerDecks()
    {
        auto &console = Console::GetInstance();
        console.ClearScreen();

        int maxY = 0;

        auto PrintDeck = [&](int xOffset, const Player &player) {
            int playerCardNum = player.GetCardNum();

            for (int i = 0; i < playerCardNum; i++)
            {
                console.MoveCursor(xOffset, 1 + i * 3);
                maxY = std::max(maxY, 1 + i * 3);

                auto card = player.GetCard(i);
                std::cout << (card->GetHP() ? Color::WHITE : Color::GRAY)
                          << std::format(" [{}] {} -> 血量: {}, 攻击力: {}", i, card->GetName(),
                                         card->GetHP(), card->GetAttackPower());
            }
        };

        PrintDeck(0, *_playerA);
        PrintDeck(50, *_playerB);

        console.MoveCursor(0, maxY + 5);
        std::cout << Color::WHITE;
        for (int i = 0; i < DEFAULT_WINDOW_WIDTH; i++)
        {
            std::cout << '*';
        }
        console.MoveCursor(0, maxY + 6);
    }

} // namespace aod
