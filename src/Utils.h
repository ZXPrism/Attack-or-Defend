#pragma once

namespace aod {

#ifdef _WIN32
    constexpr unsigned DEFAULT_WINDOW_WIDTH = 120;
    constexpr unsigned DEFAULT_WINDOW_HEIGHT = 30;
#endif

    void SleepFor(int ms);

} // namespace aod
