#pragma once

#include "gameplay/card/Card.h"

namespace aod {

    namespace card {

        class ZXP4 : public Card
        {
        public:
            ZXP4();

            virtual void Attack(ActionStatus &status, Card &target) override;

        protected:
            virtual void OnAttacked(ActionStatus &attackStatus) override;
        };

    } // namespace card

} // namespace aod
