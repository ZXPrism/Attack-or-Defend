#pragma once

#include "gameplay/ActionStatus.h"

#include <string>

namespace aod {

    class Card
    {
    public:
        virtual ~Card() = default;

    public:
        std::string GetName() const;
        int GetHP() const;
        int GetAttackPower() const;
        double GetCritRate() const;
        double GetCritFactor() const;

        virtual ActionStatus Attack(Card &target);

    protected:
        virtual void OnAttacked(ActionStatus &attackStatus);

    protected:
        std::string _Name;
        int _HP;
        int _AttackPower;
        double _CritRate;
        double _CritFactor;
    };

} // namespace aod
