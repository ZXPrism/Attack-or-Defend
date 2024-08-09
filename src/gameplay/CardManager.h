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

        [[nodiscard]] const std::vector<std::string> &GetCardNameMap() const;

    private:
        std::unordered_map<std::size_t, std::shared_ptr<ICardFactory>> _CardFactoryMap;
        std::vector<std::string> _CardNameMap;
    };

    template <typename T>
    void CardManager::RegisterCard()
    {
        auto pCardFactory = std::make_shared<CardFactory<T>>();

        _CardFactoryMap.insert({_CardNameMap.size(), pCardFactory});
        _CardNameMap.push_back(pCardFactory->GetSampleCard().GetName());
    }

} // namespace aod
