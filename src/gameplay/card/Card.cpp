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

    void Card::Attack(ActionStatus &status, Card &target)
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

        status._Damage = damage;
        status._IsCritHit = critTestResult;

        target.OnAttacked(status);
    }

    void Card::OnAttacked(ActionStatus &status)
    {
        if (status._Damage >= _HP)
        {
            _HP = 0;
            status._IsDead = true;
        }
        else
        {
            _HP -= status._Damage;
        }
    }

} // namespace aod
