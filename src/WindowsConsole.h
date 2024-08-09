#pragma once

#ifdef _WIN32

#include "Console.h"

#include <string>

#include <Windows.h>

namespace aod {

    class WindowsConsole : public Console
    {
    public:
        WindowsConsole();

        virtual void SetWindowTitle(const std::string &title) override;
        virtual void MoveCursor(int x, int y) override;
        virtual void SetColor(Color color) override;
        virtual void SetColor(Color fgColor, Color bgColor) override;
        virtual void ClearScreen() override;
        virtual void SetCursorVisibility(bool visibility) override;
        virtual int GetCharNonblocking() override;

    private:
        HANDLE _consoleHandle;
    };

} // namespace aod

#endif
