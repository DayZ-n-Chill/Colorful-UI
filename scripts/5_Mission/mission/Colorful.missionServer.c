modded class MissionServer {
	void MissionServer() { 
		if (GetGame().IsServer()) {
			GetRPCManager().AddRPC( "RPCPlayerSats", 
									"SyncPlayersRequest", 
									this, 
									SingeplayerExecutionType.Server );		
		}
    }
	
	void SyncPlayersRequest( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		ref TFloatArray PlayerStatsValues	= new TFloatArray;
		array<Man> players 					= new array<Man>;
		PlayerBase player;
		PlayerIdentity plrIdentity;
       
		if ( type == CallType.Server && GetGame().IsServer() ) {
			GetGame().GetPlayers(players);
			for (int i = 0; i < players.Count(); ++i) {
				player 			= PlayerBase.Cast(players.Get(i));
				plrIdentity 	= player.GetIdentity();
				
				if (plrIdentity.GetPlayerId() == sender.GetPlayerId()) {
					PlayerStatsValues.Insert(player.GetHealth("","Health"));
					PlayerStatsValues.Insert(player.GetHealth("","Blood"));
					PlayerStatsValues.Insert(player.GetStatWater().Get());
					PlayerStatsValues.Insert(player.GetStatEnergy().Get());
					PlayerStatsValues.Insert(player.IsAlive());
					PlayerStatsValues.Insert(player.m_DiseaseCount);
					PlayerStatsValues.Insert(player.m_Environment.GetTemperature());	
				}
			}
			GetRPCManager().SendRPC( "RPCPlayerSats", 
									 "SyncPlayers", 
									 new Param1<ref TFloatArray> (PlayerStatsValues), 
									 true, sender );
		}
	}
};