#pragma once

#include "ActionStatus.h"
#include "card/Card.h"

#include <memory>
#include <vector>

namespace aod {

    class Player
    {
    public:
        virtual ~Player() = default;
        virtual void Act(ActionStatus &status, Player &opponent);

        void ResetCardDeck();
        void AppendCard(std::shared_ptr<Card> card);

        std::shared_ptr<Card> GetCard(int offset) const;
        int GetCardNum() const;
        bool IsAlive() const;

    protected:
        std::vector<std::shared_ptr<Card>> _CardDeck;
        std::vector<int> _KillCnt;
    };

} // namespace aod
