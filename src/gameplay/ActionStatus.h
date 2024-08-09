#pragma once

namespace aod {

    struct ActionStatus
    {
        // src - phase 1
        bool _IsCritHit;
        int _Damage;

        // dest - phase 2
        bool _IsDead = false;
    };

} // namespace aod
