#ifdef _WIN32

#include "WindowsConsole.h"

#include <cstdlib>

#include <conio.h>

namespace aod {

    WindowsConsole::WindowsConsole()
    {
        _consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        std::system("chcp 65001");
        // 'SetConsoleCP(65001)' doesn't work for unknown reason..
    }

    void WindowsConsole::SetWindowTitle(const std::string &title)
    {
        SetConsoleTitle(title.c_str());
    }

    void WindowsConsole::MoveCursor(int x, int y)
    {
        COORD coord{static_cast<SHORT>(x), static_cast<SHORT>(y)};
        SetConsoleCursorPosition(_consoleHandle, coord);
    }

    void WindowsConsole::SetColor(Color color)
    {
        SetConsoleTextAttribute(_consoleHandle, static_cast<WORD>(color));
    }

    void WindowsConsole::SetColor(Color fgColor, Color bgColor)
    {
        SetConsoleTextAttribute(_consoleHandle,
                                static_cast<WORD>(fgColor) + (static_cast<WORD>(bgColor) << 4));
    }

    void WindowsConsole::ClearScreen()
    {
        std::system("cls");
    }

    void WindowsConsole::SetCursorVisibility(bool visibility)
    {
        CONSOLE_CURSOR_INFO cursorInfo{2, visibility};
        SetConsoleCursorInfo(_consoleHandle, &cursorInfo);
    }

    int WindowsConsole::GetCharNonblocking()
    {
        return _getch();
    }

} // namespace aod

#endif
