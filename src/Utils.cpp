#include "Utils.h"

#include <chrono>
#include <thread>

namespace aod {

    void SleepFor(int ms)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

} // namespace aod
