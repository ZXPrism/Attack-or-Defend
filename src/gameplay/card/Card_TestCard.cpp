#include "Card_TestCard.h"

namespace aod {

    namespace card {

        TestCard::TestCard()
        {
            _Name = "TestCard";
            _HP = 1;
            _AttackPower = 1000000;
            _CritRate = 1.0;
            _CritFactor = 2.0;
        }

        void TestCard::Attack(ActionStatus &status, Card &target)
        {
            return Card::Attack(status, target);
        }

        void TestCard::OnAttacked(ActionStatus &attackStatus)
        {
            Card::OnAttacked(attackStatus);
        }

    } // namespace card

} // namespace aod
