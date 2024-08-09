#pragma once

#include "gameplay/card/Card.h"

#include <memory>

namespace aod {

    class ICardFactory
    {
    public:
        virtual ~ICardFactory() = default;

        [[nodiscard]] virtual const Card &GetSampleCard() const = 0;
    };

    template <typename T>
    class CardFactory : public ICardFactory
    {
    public:
        [[nodiscard]] virtual const Card &GetSampleCard() const override;

        [[nodiscard]] std::shared_ptr<T> AllocCard();

    private:
        T _SampleCard;
    };

    template <typename T>
    std::shared_ptr<T> CardFactory<T>::AllocCard()
    {
        return std::make_shared<T>();
    }

    template <typename T>
    const Card &CardFactory<T>::GetSampleCard() const
    {
        return _SampleCard;
    }

} // namespace aod
