#include "CardManager.h"

#include "card/Card.h"

#include <iostream>

namespace aod {

    CardManager gCardManager;

    [[nodiscard]] std::shared_ptr<Card> CardManager::AllocCard(int cardID) const
    {
        return _CardFactoryMap.at(cardID)->AllocCard();
    }

    const Card &CardManager::GetSampleCard(int cardID) const
    {
        return _CardFactoryMap.at(cardID)->GetSampleCard();
    }

    int CardManager::GetCardCnt() const
    {
        return _CardFactoryMap.size();
    }

} // namespace aod
