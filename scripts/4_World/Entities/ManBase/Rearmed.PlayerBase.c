modded class PlayerBase
{
    protected int m_CombatLogTime;
    protected ref Timer m_CombatLogTimer;

    void PlayerBase()
    {
        RegisterNetSyncVariableInt( "m_CombatLogTime", 0, 8192 );

        if ( GetGame().IsServer() )
        {
            m_CombatLogTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
            m_CombatLogTimer.Run( CombatLogSettings.UPDATE_RATE, this, "OnCombatLogTimerUpdate", null, true );
        }
    }

    void OnCombatLogTimerUpdate()
    {
        // if base is not assigned, or timer is at 0, do nothing
        if ( m_CombatLogTime <= 0 || !GetIdentity() )
        {
            return;
        }

        m_CombatLogTime -= CombatLogSettings.UPDATE_RATE;
        if ( m_CombatLogTime < 0 )
        {
            m_CombatLogTime = 0;
        }

        SetSynchDirty();
    }

    void SetCombatTimer(int combat_timer)
    {
        if ( !GetGame().IsServer() )
        {
            Error("SetCombatTimer must be called on server");
            return;
        }

        if ( combat_timer < m_CombatLogTime )
        {
            return;
        }

        m_CombatLogTime = combat_timer;
        SetSynchDirty();
    }

    bool IsInCombat()
    {
        return ( m_CombatLogTime > 0 );
    }

    int GetCombatTimer()
    {
        return m_CombatLogTime;
    }

    override void EEHitBy( TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef )
    {
        super.EEHitBy( damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef );

        if ( !GetGame().IsServer() )
        {
            return;
        }

        if ( ammo == "FallDamage" ) {
            return;
        }
#ifdef ___DISABLED
        array<Man> players = {};
        GetGame().GetPlayers( players );
        foreach ( Man man: players )
        {
            PlayerBase player = PlayerBase.Cast( man );
            if ( !player || player == this )
            {
                continue;
            }

            if (vector.DistanceSq( GetPosition(), player.GetPosition() ) > CombatLogSettings.RADIUS_FOR_NEAR_CHECK * CombatLogSettings.RADIUS_FOR_NEAR_CHECK )
            {
                continue;
            }

            // optimization to avoid network traffic spam
            if ( player.GetCombatTimer() > ( CombatLogSettings.NEAR_SHOTS_TIME - 10 ) )
            {
                continue;
            }

            player.SetCombatTimer( CombatLogSettings.NEAR_SHOTS_TIME );
        }
#endif
        // optimization
        if ( GetCombatTimer() > ( CombatLogSettings.HIT_TIME - 10 ) )
        {
            return;
        }

        SetCombatTimer( CombatLogSettings.HIT_TIME );
    }

    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        
        if ( GetGame().IsServer() )
        {
            g_Script.CallFunction( GetGame().GetMission(), "DoPlayerKilledTest", null, this );
        }
    }
}