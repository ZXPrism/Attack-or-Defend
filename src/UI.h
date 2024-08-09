#pragma once

#include "Color.h"

#include <string>

namespace aod {

    void Text(int x, int y, const std::string &text, Color color = Color::WHITE);
    void TextCentered(const std::string &text, Color color = Color::WHITE);

    void PushText(int x, int y, const std::string &text, Color color = Color::WHITE,
                  int speedMs = 10);
    void PushTextCentered(const std::string &text, Color color = Color::WHITE, int speedMs = 10);

    void DissolveText(int x, int y, const std::string &text, Color color = Color::WHITE,
                      int speedMs = 10);
    void DissolveTextCentered(const std::string &text, Color color = Color::WHITE,
                              int speedMs = 10);

} // namespace aod
