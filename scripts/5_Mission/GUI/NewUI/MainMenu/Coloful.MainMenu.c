modded class MainMenu extends UIScriptedMenu
{
	// Register your variables
	private Widget m_Discord;
	private Widget m_Youtube;
	private Widget m_Website;
	private Widget m_PriorityQueue
	private Widget m_CharacterBtn;
	private Widget m_Separator1
	private Widget m_Separator2
	private Widget m_SeparatorPanel
	private Widget m_ProgressLoading
	private	Widget m_shader
	
	override Widget Init()
	{
		// Load the layout files
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );

		// Custom Buttons  
		// NOTE: THe "NameBtn" is the name of the widget in the layout file.
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Website					= layoutRoot.FindAnyWidget( "WebsiteBtn" );
		m_PriorityQueue				= layoutRoot.FindAnyWidget( "QueueBtn" );
		m_CharacterBtn 				= layoutRoot.FindAnyWidget( "CharacterBtn" );
		// May Remove Later
		m_Separator1				= layoutRoot.FindAnyWidget( "separator_1" );
		m_Separator2				= layoutRoot.FindAnyWidget( "separator_2" );
		m_SeparatorPanel			= layoutRoot.FindAnyWidget( "SeparatorPanel" );
		
		// Required Vanilla Code (Most are just hidden in the layout file.)
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_ChooseServer				= layoutRoot.FindAnyWidget( "choose_server" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
		m_TutorialButton			= layoutRoot.FindAnyWidget( "tutorial_button" );
		m_MessageButton				= layoutRoot.FindAnyWidget( "message_button" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );
		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );
		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_ModdedWarning				= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		m_LastPlayedTooltip			= layoutRoot.FindAnyWidget( "last_server_info" );
		m_LastPlayedTooltipLabel	= m_LastPlayedTooltip.FindAnyWidget( "last_server_info_label" );
		m_LastPlayedTooltipName 	= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_name" ) );
		m_LastPlayedTooltipIP		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_ip" ) );
		m_LastPlayedTooltipPort		= TextWidget.Cast( m_LastPlayedTooltip.FindAnyWidget( "last_server_info_port" ) );
		m_LastPlayedTooltipTimer	= new WidgetFadeTimer();
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget( "character_stats_root" ) );
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		m_ScenePC					= m_Mission.GetIntroScenePC();

		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version );
		GetGame().GetUIManager().ScreenFadeOut(0);
		SetFocus( null );
		Refresh();
		LoadMods();
		GetDayZGame().GetBacklit().MainMenu_OnShow();
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		m_shader.SetColor(colorScheme.ShaderColor());
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		m_Separator1.SetColor(colorScheme.SeparatorColor());
		m_Separator2.SetColor(colorScheme.SeparatorColor());
		m_SeparatorPanel.SetColor(colorScheme.SeparatorColor());
		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());
		return layoutRoot;
	}	

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(MenuURLS.urlDiscord);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Website)
		{
			GetGame().OpenURL(MenuURLS.urlWebsite);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_PriorityQueue)
		{
			GetGame().OpenURL(MenuURLS.urlPriorityQ);
			return false;
		}
		else if ( w == m_CharacterBtn )
		{
			OpenMenuCustomizeCharacter();
			return true;
		}
		return super.OnClick(w, x, y, button);
	};

	// Coloring Functions 
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.ButtonHoverColor();
		int color_img = colorScheme.ButtonHoverColor();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.PrimaryText();
		int color_img = colorScheme.PrimaryText();

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	
	}

	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
			
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}
		return false;
	}

	// I still have not found a good way to globally edit the generated dialog system colors but I feel like I am close
	// I guess the best way in the meantime is to create a new menu and have it styled as we need.
	override void Exit()
	{
		EnterScriptedMenu( COLORFUL_EXIT );
	}

}
