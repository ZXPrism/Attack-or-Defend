#pragma once

#include "gameplay/card/Card.h"

#include <memory>

namespace aod {

    class ICardFactory
    {
    public:
        virtual ~ICardFactory() = default;

        [[nodiscard]] virtual const Card &GetSampleCard() const = 0;
        [[nodiscard]] virtual std::shared_ptr<Card> AllocCard() const = 0;
    };

    template <typename T>
    class CardFactory : public ICardFactory
    {
    public:
        [[nodiscard]] virtual const Card &GetSampleCard() const override;
        [[nodiscard]] virtual std::shared_ptr<Card> AllocCard() const override;

    private:
        T _SampleCard;
    };

    template <typename T>
    std::shared_ptr<Card> CardFactory<T>::AllocCard() const
    {
        return std::static_pointer_cast<Card>(std::make_shared<T>());
    }

    template <typename T>
    const Card &CardFactory<T>::GetSampleCard() const
    {
        return _SampleCard;
    }

} // namespace aod
