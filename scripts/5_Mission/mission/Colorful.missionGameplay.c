modded class MissionGameplay extends MissionBase
{
	float ticktime = 0;
	float UpdateInterval_ = 4.0;
	int playerIsAlive = 0;
	
	protected bool 				m_HasCompass
	protected bool 				m_HasGPS
	protected Widget			m_ToolsCompassBase;
	protected Widget 			m_FoodPanel;
	
	//Player Stats
	protected TextWidget		m_ThirstValue;
	protected TextWidget		m_HungerValue;
	protected TextWidget		m_HealthValue;
	protected TextWidget		m_BloodValue;
	protected ImageWidget		m_TempValue;
	
	//Compass Stats
	protected TextWidget		m_CompassAzimuthValue;
	protected TextWidget		m_CompassCardinalValue;
	protected ImageWidget 		m_ToolsCompassArrow;
	
	//Weapon Stats
	protected TextWidget		m_ItemInHandsTitle;
	protected TextWidget		m_MagCount;
	protected TextWidget		m_SpareAmmoCount;
	protected TextWidget		m_WeaponHealth;
	protected TextWidget		m_WeaponRange;
	protected TextWidget		m_WeaponFRTop;
	protected TextWidget		m_WeaponFTBottom;
	
	void MissionGameplay() {
		if (GetGame().IsClient()) {
			GetRPCManager().AddRPC( "RPCPlayerSats", 
									"SyncPlayers", 
									this, 
									SingeplayerExecutionType.Client );
		}
    }
		
	override void OnInit() {		
	    if ( m_HudRootWidget ){ m_HudRootWidget.Unlink(); }

		if ( !m_HudRootWidget )	{
			m_HudRootWidget = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.day_z_hud.layout");
			m_HudRootWidget.Show(false);
			
			//Main HUD
			m_Hud.Init( m_HudRootWidget.FindAnyWidget("HudPanel") );
			m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));
			m_ActionMenu.Init( m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast( m_HudRootWidget.FindAnyWidget("DefaultActionWidget") ) );
			
			//Mic Widget
			m_MicrophoneIcon = ImageWidget.Cast( m_HudRootWidget.FindAnyWidget("mic") );
			m_MicrophoneIcon.Show(false);
			
			//Voice Widgets
			m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
			m_VoiceLevelsWidgets = 	new map<int, ImageWidget>; 
			m_VoiceLevelTimers = 	new map<int,ref WidgetFadeTimer>; 

			if( m_VoiceLevels )	{
				m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Whisper") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelTalk, 	ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Talk") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelShout, 	ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Shout") ));

				m_VoiceLevelTimers.Set(VoiceLevelWhisper, 	new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelTalk, 		new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelShout, 	new WidgetFadeTimer);
			}
			
			HideVoiceLevelWidgets();
			
			// Chat Box
			m_ChatChannelArea = m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
			m_ChatChannelText = TextWidget.Cast( m_HudRootWidget.FindAnyWidget("ChatChannelText") );

			// Player Stats
			m_ThirstValue = TextWidget.Cast(m_HudRootWidget.FindAnyWidget("StatValueThirst"));
			m_HungerValue = TextWidget.Cast(m_HudRootWidget.FindAnyWidget("StatValueHunger"));
			m_HealthValue = TextWidget.Cast(m_HudRootWidget.FindAnyWidget("StatValueHealth"));
			m_BloodValue =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("StatValueBlood"));
			Class.CastTo(m_TempValue, m_HudRootWidget.FindAnyWidget("IconTemperature"));
			
			// Compass
			m_CompassAzimuthValue =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("Heading"));
			m_CompassCardinalValue =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("CardinalDirection"));
			
			// Weapon Stats
			m_ItemInHandsTitle =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("ExileItemInHandsTitle"));
			m_MagCount =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("MagCount"));
			m_SpareAmmoCount =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("SpareAmmoCount"));
			m_WeaponHealth =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("WeaponHealth"));
			m_WeaponRange =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("WeaponRange"));
			m_WeaponFRTop =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("FireRate_Top"));
			m_WeaponFTBottom =  TextWidget.Cast(m_HudRootWidget.FindAnyWidget("FireRate_Bottom"));	
		}
		super.OnInit();
	}
	
    void SyncPlayers( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		Param1<ref TFloatArray> PlayerServerData;
        ref TFloatArray ClientPlayerData = new TFloatArray;
        
		if ( type == CallType.Client && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			if ( !ctx.Read( PlayerServerData ) ) {return;}
		    ClientPlayerData = PlayerServerData.param1;
		
			int plrSrvData_Health =  ClientPlayerData[0];
			int plrSrvData_Blood = ClientPlayerData[1];
			int plrSrvData_Water = ClientPlayerData[2];
			int plrSrvData_Energy = ClientPlayerData[3];
			playerIsAlive = ClientPlayerData[4];
			int plrSrvData_Disease = ClientPlayerData[5];
			int plrSrvData_Temp = ClientPlayerData[6];
		}
		
		if(m_HudRootWidget.IsVisible()) {
			m_HealthValue.SetText(plrSrvData_Health.ToString());
			m_BloodValue.SetText(plrSrvData_Blood.ToString());
			m_HungerValue.SetText(plrSrvData_Energy.ToString());
			m_ThirstValue.SetText(plrSrvData_Water.ToString());
			if ( plrSrvData_Temp <= 10 )    { m_TempValue.SetColor(ARGB(255,55,55,255)); }   //Cold
			if ( plrSrvData_Temp >  10 )    { m_TempValue.SetColor(ARGB(255,255,255,255)); } //Normal
			if ( plrSrvData_Temp >= 15 )	{ m_TempValue.SetColor(ARGB(255,255,55,55)); } 	 //Hot
		}
	}

	override void TickScheduler(float timeslice) {
		super.TickScheduler( timeslice);
		ticktime += timeslice;
		if(ticktime > UpdateInterval_) {
		    ticktime = 0;
			if(playerIsAlive == 1) {
				m_HudRootWidget.Show(true);
			} else {
				m_HudRootWidget.Show(false);
			}
			GetRPCManager().SendRPC( "RPCPlayerSats", 
									 "SyncPlayersRequest", 
									 new Param1< int >(0), 
									 true, 
									 NULL );
	    }	
	}
}
