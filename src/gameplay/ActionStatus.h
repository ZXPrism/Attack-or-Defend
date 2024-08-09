#pragma once

namespace aod {

    struct ActionStatus
    {
        // attacker
        int _AttackerCardID;
        bool _IsCritHit;
        int _Damage;
        int _KillCnt;

        // target
        int _TargetCardID;
        bool _IsDead = false;
    };

} // namespace aod
