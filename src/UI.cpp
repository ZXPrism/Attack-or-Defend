#include "UI.h"

#include "Console.h"
#include "Utils.h"

#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

namespace aod {

    void Text(int x, int y, const std::string &text, Color color)
    {
        auto &console = Console::GetInstance();
        console.MoveCursor(x, y);

        std::cout << color << text;
    }

    void PushText(int x, int y, const std::string &text, Color color, int speedMs)
    {
        auto &console = Console::GetInstance();
        console.MoveCursor(x, y);

        std::cout << color;
        for (auto c : text)
        {
            std::cout << c;
            SleepFor(speedMs);
        }
    }

    void DissolveText(int x, int y, const std::string &text, Color color, int speedMs)
    {
        static std::mt19937_64 sRndEng;

        auto &console = Console::GetInstance();

        int n = text.size();
        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::shuffle(idx.begin(), idx.end(), sRndEng);

        std::cout << color;
        for (auto i : idx)
        {
            console.MoveCursor(x + i, y);
            console.SetColor(Color::WHITE, Color::WHITE);
            std::cout << ' ';
            SleepFor(speedMs);

            console.MoveCursor(x + i, y);
            std::cout << color << text[i];
            SleepFor(speedMs);
        }
    }

    void TextCentered(const std::string &text, Color color)
    {
        Text((DEFAULT_WINDOW_WIDTH - text.size()) / 2, DEFAULT_WINDOW_HEIGHT / 2, text, color);
    }

    void PushTextCentered(const std::string &text, Color color, int speedMs)
    {
        PushText((DEFAULT_WINDOW_WIDTH - text.size()) / 2, DEFAULT_WINDOW_HEIGHT / 2, text, color,
                 speedMs);
    }

    void DissolveTextCentered(const std::string &text, Color color, int speedMs)
    {
        DissolveText((DEFAULT_WINDOW_WIDTH - text.size()) / 2, DEFAULT_WINDOW_HEIGHT / 2, text,
                     color, speedMs);
    }

} // namespace aod
