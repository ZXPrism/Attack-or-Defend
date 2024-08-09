#include "CardManager.h"

#include "card/Card.h"

#include <iostream>

namespace aod {

    const Card &CardManager::GetSampleCard(int cardID) const
    {
        return _CardFactoryMap.at(cardID)->GetSampleCard();
    }

    int CardManager::GetCardCnt() const
    {
        return _CardFactoryMap.size();
    }

} // namespace aod
