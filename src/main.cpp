#include "Console.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::string title("Attack or Defend ~ Re Ver.");

    auto &console = aod::Console::GetInstance();
    console.SetWindowTitle(title);
    console.SetCursorVisibility(false);
    console.ClearScreen();

    console.MoveCursor(20, 10);
    std::cout << aod::Color::LIGHTGREEN << title;

    console.MoveCursor(50, 12);
    std::cout << aod::Color::LIGHTPURPLE << title;

    console.MoveCursor(30, 14);
    std::cout << aod::Color::LIGHTBLUE << title;

    std::cin.get();

    return 0;
}
