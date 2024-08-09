#include "Card_ZXP4.h"

namespace aod {

    namespace card {

        ZXP4::ZXP4()
        {
            _Name = "ZXP4";
            _HP = 123;
            _AttackPower = 1;
            _CritRate = 0.5;
            _CritFactor = 2.0;
        }

        void ZXP4::Attack(ActionStatus &status, Card &target)
        {
            return Card::Attack(status, target);
        }

        void ZXP4::OnAttacked(ActionStatus &attackStatus)
        {
            Card::OnAttacked(attackStatus);
        }

    } // namespace card

} // namespace aod
