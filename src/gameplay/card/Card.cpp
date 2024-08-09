#include "Card.h"

#include <random>

namespace aod {

    std::string Card::GetName() const
    {
        return _Name;
    }

    int Card::GetHP() const
    {
        return _HP;
    }

    int Card::GetAttackPower() const
    {
        return _AttackPower;
    }

    double Card::GetCritRate() const
    {
        return _CritRate;
    }

    double Card::GetCritFactor() const
    {
        return _CritFactor;
    }

    ActionStatus Card::Attack(Card &target)
    {
        static std::mt19937_64 sRndEng;

        std::random_device rd;
        sRndEng.seed(rd());

        int damage = _AttackPower;

        std::bernoulli_distribution critTest(_CritRate);
        bool critTestResult = critTest(sRndEng);
        if (critTestResult)
        {
            damage *= _CritFactor;
        }

        ActionStatus status;
        status._Damage = damage;
        status._IsCritHit = critTestResult;

        target.OnAttacked(status);

        return status;
    }

    void Card::OnAttacked(ActionStatus &attackStatus)
    {
        if (attackStatus._Damage >= _HP)
        {
            _HP = 0;
            attackStatus._IsDead = true;
        }
        else
        {
            _HP -= attackStatus._Damage;
        }
    }

} // namespace aod
