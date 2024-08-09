#pragma once

#include "Color.h"

#include <iostream>
#include <string>

namespace aod {

    class Console
    {
    public:
        virtual ~Console() = default;

        virtual void SetWindowTitle(const std::string &title) = 0;
        virtual void MoveCursor(int x, int y) = 0;
        virtual void SetColor(Color color) = 0;
        virtual void SetColor(Color fgColor, Color bgColor) = 0;
        virtual void ClearScreen() = 0;
        virtual void SetCursorVisibility(bool visibility) = 0;
        [[nodiscard]] virtual int GetCharNonblocking() = 0;

        static Console &GetInstance();
    };

} // namespace aod

std::ostream &operator<<(std::ostream &stream, aod::Color color);
