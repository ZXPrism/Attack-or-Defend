#ifdef _WIN32

#include "WindowsConsole.h"

#include <cstdlib>

namespace aod {

    WindowsConsole::WindowsConsole()
    {
        _consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void WindowsConsole::SetWindowTitle(const std::string &title)
    {
        SetConsoleTitle(title.c_str());
    }

    void WindowsConsole::MoveCursor(int x, int y)
    {
        COORD coord{(SHORT)x, (SHORT)y};
        SetConsoleCursorPosition(_consoleHandle, coord);
    }

    void WindowsConsole::SetColor(Color color)
    {
        SetConsoleTextAttribute(_consoleHandle, (WORD)color);
    }

    void WindowsConsole::SetColor(Color fgColor, Color bgColor)
    {
        SetConsoleTextAttribute(_consoleHandle, (WORD)fgColor + ((WORD)bgColor << 4));
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

} // namespace aod

#endif
