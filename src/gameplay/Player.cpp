#include "Player.h"

#include <iostream>

namespace aod {

    void Player::ResetCardDeck()
    {
        _CardDeck.clear();
    }

    void Player::AppendCard(std::shared_ptr<Card> card)
    {
        _CardDeck.push_back(card);
        _KillCnt.emplace_back();
    }

    void Player::Act(ActionStatus &status, Player &opponent)
    {
        int attacker = 0;
        std::cout << "请输入想要发起攻击的我方卡片序号：";
        std::cin >> attacker;

        int target = 0;
        std::cout << "请输入目标敌方卡片序号：";
        std::cin >> target;

        // TODO：序号合法性检查

        status._AttackerCardID = attacker;
        status._TargetCardID = target;

        GetCard(attacker)->Attack(status, *opponent.GetCard(target));

        _KillCnt[attacker] += static_cast<int>(status._IsDead);
        status._KillCnt = _KillCnt[attacker];
    }

    std::shared_ptr<Card> Player::GetCard(int offset) const
    {
        return _CardDeck.at(offset);
    }

    int Player::GetCardNum() const
    {
        return _CardDeck.size();
    }

    bool Player::IsAlive() const
    {
        for (auto card : _CardDeck)
        {
            if (card->GetHP())
            {
                return true;
            }
        }
        return false;
    }

} // namespace aod
