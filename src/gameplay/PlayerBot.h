#pragma once

#include "Player.h"

namespace aod {

    class PlayerBot : public Player
    {
    public:
        PlayerBot();

        virtual void Act(ActionStatus &status, Player &opponent) override;
    };

} // namespace aod
