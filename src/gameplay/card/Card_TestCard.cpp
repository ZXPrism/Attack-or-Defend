#include "Card_TestCard.h"

namespace aod {

    namespace card {

        TestCard::TestCard()
        {
            _Name = "TestCard";
            _HP = 123;
            _AttackPower = 456;
            _CritRate = 0.5;
            _CritFactor = 2.0;
        }

        ActionStatus TestCard::Attack(Card &target)
        {
            return Card::Attack(target);
        }

        void TestCard::OnAttacked(ActionStatus &attackStatus)
        {
            Card::OnAttacked(attackStatus);
        }

    } // namespace card

} // namespace aod
