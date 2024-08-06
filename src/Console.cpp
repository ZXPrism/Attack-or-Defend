#include "Console.h"

#include "WindowsConsole.h"

namespace aod {

    Console &Console::GetInstance()
    {
#ifdef _WIN32
        static WindowsConsole sConsoleInstance;
#endif

        return sConsoleInstance;
    }

} // namespace aod

std::ostream &operator<<(std::ostream &stream, aod::Color color)
{
    auto &inst = aod::Console::GetInstance();
    inst.SetColor(color);
    return stream;
}
