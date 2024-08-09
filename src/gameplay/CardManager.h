#pragma once

#include "CardFactory.h"
#include "card/Card.h"

#include <memory>
#include <unordered_map>

namespace aod {

    class CardManager
    {
    public:
        template <typename T>
        void RegisterCard();

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

} // namespace aod
