#pragma once

#include "gameplay/card/Card.h"

namespace aod {

    namespace card {

        class TestCard : public Card
        {
        public:
            TestCard();

            virtual ActionStatus Attack(Card &target) override;

        protected:
            virtual void OnAttacked(ActionStatus &attackStatus) override;
        };

    } // namespace card

} // namespace aod
