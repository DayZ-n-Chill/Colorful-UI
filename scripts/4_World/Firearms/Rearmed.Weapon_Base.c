modded class Weapon_Base
{
    override void EEFired( int muzzleType, int mode, string ammoType )
    {
        super.EEFired( muzzleType, mode, ammoType );

        if ( !GetGame().IsServer() )
        {
            return;
        }

        PlayerBase shooter = PlayerBase.Cast( GetHierarchyRootPlayer() );
        if ( !shooter )
        {
            return;
        }
#ifdef ___DISABLED
        array<Man> players = {};
        GetGame().GetPlayers( players );
        foreach ( Man man: players )
        {
            PlayerBase player = PlayerBase.Cast( man );
            if ( !player || player == shooter )
            {
                continue;
            }

            if (vector.DistanceSq( shooter.GetPosition(), player.GetPosition() ) > CombatLogSettings.RADIUS_FOR_NEAR_CHECK * CombatLogSettings.RADIUS_FOR_NEAR_CHECK )
            {
                continue;
            }

            player.SetCombatTimer( CombatLogSettings.NEAR_SHOTS_TIME );
        }
#endif
        shooter.SetCombatTimer( CombatLogSettings.SHOOTER_TIME );
    }
}