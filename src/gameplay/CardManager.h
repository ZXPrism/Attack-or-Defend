#pragma once

#include "CardFactory.h"
#include "card/Card.h"

#include <memory>
#include <vector>

namespace aod {

    class CardManager
    {
    public:
        template <typename T>
        void RegisterCard();

        [[nodiscard]] std::shared_ptr<Card> AllocCard(int cardID) const;
        [[nodiscard]] const Card &GetSampleCard(int cardID) const;
        [[nodiscard]] int GetCardCnt() const;

    private:
        std::vector<std::shared_ptr<ICardFactory>> _CardFactoryMap;
    };

    template <typename T>
    void CardManager::RegisterCard()
    {
        _CardFactoryMap.push_back(std::make_shared<CardFactory<T>>());
    }

    extern CardManager gCardManager;

} // namespace aod
