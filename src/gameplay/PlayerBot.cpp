#include "PlayerBot.h"

#include "CardManager.h"

#include <random>

namespace aod {

    PlayerBot::PlayerBot()
    {
        int cardCnt = gCardManager.GetCardCnt();

        // 目前策略：选择所有卡片
        for (int i = 0; i < cardCnt; i++)
        {
            AppendCard(gCardManager.AllocCard(i));
        }
    }

    void PlayerBot::Act(ActionStatus &status, Player &opponent)
    {
        // 目前策略：随机选择一张敌方卡片进行攻击
        static std::mt19937_64 sRndEng;

        std::random_device rd;
        sRndEng.seed(rd());

        // 数据量不大，使用拒绝采样法，不断循环直至找到可被攻击（血量不为零）的敌方卡片
        std::uniform_int_distribution<int> distTarget(0, opponent.GetCardNum() - 1);
        int target = 0;
        do
        {
            target = distTarget(sRndEng);
        } while (opponent.GetCard(target)->GetHP() == 0);

        // 同理，找到可攻击（血量不为零）的我方卡片
        std::uniform_int_distribution<int> distPlayer(0, GetCardNum() - 1);
        int attacker = 0;
        do
        {
            attacker = distPlayer(sRndEng);
        } while (GetCard(attacker)->GetHP() == 0);

        status._AttackerCardID = attacker;
        status._TargetCardID = target;

        GetCard(attacker)->Attack(status, *opponent.GetCard(target));

        _KillCnt[attacker] += static_cast<int>(status._IsDead);
        status._KillCnt = _KillCnt[attacker];
    }

} // namespace aod
