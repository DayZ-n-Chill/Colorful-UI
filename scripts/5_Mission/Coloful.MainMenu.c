modded class MainMenu extends UIScriptedMenu
{
	// Register your variables
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;

	override Widget Init()
	{
		// Load the layout file
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );
		// Print("Colorful Main Menu Loaded!");	
		
		// Custom Buttons  
		// NOTE: THe "NameBtn" is the name of the widget in the layout file.
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Twitter 					= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_Youtube 					= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_Reddit 					= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_Facebook 					= layoutRoot.FindAnyWidget( "FacebookBtn" );

		// Vanilla Code
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
		
		
		
		m_LastPlayedTooltip.Show(false);
		if(m_ScenePC){m_ScenePC.ResetIntroCamera();}
		string version;
		GetGame().GetVersion( version );
		m_Version.SetText( "#main_menu_version" + " " + version );
		GetGame().GetUIManager().ScreenFadeOut(0);
		SetFocus( null );
		Refresh();
		LoadMods();
		GetDayZGame().GetBacklit().MainMenu_OnShow();
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );	
		return layoutRoot;
	}	

	override bool OnClick(Widget w, int x, int y, int button)
	{
		// NOTE: ------------------------------------------------------------
		// Just drop in your URL to the desired social media outlet
		// If you dont want to use one.  Just leave the code as is
		// You can Hide the buttons in the Colorful.main_menu.layout file
		// Located: Colorful-UI/gui/layouts/new_ui/Colorful.main_menu.layout
		// ------------------------------------------------------------------
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL("https://discord.gg/#");
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL("https://twitter.com/#");
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL("https://reddit.com/#");
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL("https://youtube.com/#");
			return false;
		}	
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL("https://facebook.com/#");
			return false;
		}	
		// NOTE: --------------------------------------------------------------------
		// Want to add your own buttons. 
		// Use this snippet as a template for creating buttons.  
		//
		// else if (button == MouseState.LEFT && w == m_YOURVARIABLENAME)
		// {
		// 	GetGame().OpenURL("https://yourlink/#");
		// 	return false;
		// }
		// 
		// Make sure the m_YOURVARIABLENAME is registered at the top of this document
		// EXAMPLE: private Widget m_YOURVARIABLENAME;
		// 
		// You will also have to make the approporiuate addjustments to
		// the colorful.mainmenu.layout file. like adding the actual button.
		// Located: Colorful-UI/gui/layouts/new_ui/Colorful.main_menu.layout
		//
		// You will also need to reference the button in the layout. At the top of this file.
		// m_YOURVARIABLENAME	= layoutRoot.FindAnyWidget( "YourBtn" ); 
		// ---------------------------------------------------------------------------
		return super.OnClick(w, x, y, button);
	};

	// Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;	
		// int color_pnl = colorScheme.PrimaryColor();		
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.White();
		int color_img = colorScheme.PrimaryColor();		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
}
