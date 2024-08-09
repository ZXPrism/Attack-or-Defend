#include "gameplay/GameSystem.h"

int main(int argc, char *argv[])
{
    aod::GameSystem sys;

    sys.Init();
    sys.Run();
    sys.Shutdown();

    return 0;
}
