modded class MissionGameplay extends MissionBase
{
	// Food to Strings
	Widget m_FoodPanel;
	
	TextWidget m_ThirstValue;
	TextWidget m_HungerValueText;
	
	// Vanilla
	override void OnInit()
	{
		super.OnInit();
	
	    if ( m_HudRootWidget )
    	    m_HudRootWidget.Unlink();

		if ( !m_HudRootWidget )
		{
			m_HudRootWidget	= GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.day_z_hud.layout");
			m_HudRootWidget.Show(false);

			m_Chat.Init(m_HudRootWidget.FindAnyWidget("ChatFrameWidget"));
			
			m_ActionMenu.Init( m_HudRootWidget.FindAnyWidget("ActionsPanel"), TextWidget.Cast( m_HudRootWidget.FindAnyWidget("DefaultActionWidget") ) );
			
			m_Hud.Init( m_HudRootWidget.FindAnyWidget("HudPanel") );
			
			m_MicrophoneIcon = ImageWidget.Cast( m_HudRootWidget.FindAnyWidget("mic") );
			m_MicrophoneIcon.Show(false);
			
			m_VoiceLevels = m_HudRootWidget.FindAnyWidget("VoiceLevelsPanel");
			m_VoiceLevelsWidgets = new map<int, ImageWidget>; 
			m_VoiceLevelTimers = new map<int,ref WidgetFadeTimer>; 

			if( m_VoiceLevels )
			{
				m_VoiceLevelsWidgets.Set(VoiceLevelWhisper, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Whisper") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelTalk, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Talk") ));
				m_VoiceLevelsWidgets.Set(VoiceLevelShout, ImageWidget.Cast( m_VoiceLevels.FindAnyWidget("Shout") ));

				m_VoiceLevelTimers.Set(VoiceLevelWhisper, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelTalk, new WidgetFadeTimer);
				m_VoiceLevelTimers.Set(VoiceLevelShout, new WidgetFadeTimer);
			}
			
			HideVoiceLevelWidgets();
			
			m_ChatChannelArea = m_HudRootWidget.FindAnyWidget("ChatChannelPanel");
			m_ChatChannelText = TextWidget.Cast( m_HudRootWidget.FindAnyWidget("ChatChannelText") );

			// Added Items
			m_FoodPanel = Widget.Cast(m_HudRootWidget.FindAnyWidget("FoodPanel"));
			m_ThirstValue = TextWidget.Cast(m_HudRootWidget.FindAnyWidget("ThirstValue"));
		}
	}

	void RefreshPlayerStats() 
	{

	}
}
