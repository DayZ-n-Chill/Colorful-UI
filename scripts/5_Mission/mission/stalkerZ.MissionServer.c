modded class MissionServer
{
    void ~MissionServer()
    {
        foreach ( PlayerBase player, LogoutInfo logout_info: m_LogoutPlayers )
        {
            // properly log out combat logged players, invoked on server restart
            PlayerDisconnected( player, player.GetIdentity(), logout_info.param2 );
        }
    }

    override void OnClientDisconnectedEvent( PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed )
    {
        if ( player && player.IsInCombat() && player.IsAlive() )
        {
            logoutTime += player.GetCombatTimer();
        }

        super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
    }

    // This is for combat logging, we disconnect the player if they are in the logout cache
    void DoPlayerKilledTest( PlayerBase player )
    {
        if ( !m_LogoutPlayers.Contains( player ) || player.IsAlive() )
        {
            return;
        }

        //LogToCF( player, "", "", "Disconnecting a combat logged player " + player.GetIdentity().GetId() );
        Print("Disconnecting a combat logged player " + player.GetIdentity().GetId() );

        PlayerDisconnected( player, player.GetIdentity(), player.GetIdentity().GetId() );
    }
}