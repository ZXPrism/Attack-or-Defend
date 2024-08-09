#include "CardManager.h"

#include "card/Card.h"

#include <iostream>

namespace aod {

    const std::vector<std::string> &CardManager::GetCardNameMap() const
    {
        return _CardNameMap;
    }

} // namespace aod
