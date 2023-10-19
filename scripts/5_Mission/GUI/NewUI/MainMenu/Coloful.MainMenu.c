modded class MainMenu extends UIScriptedMenu
{
	// Register your variables
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
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
		// Load the layout file
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );

		// Custom Buttons  
		// NOTE: THe "NameBtn" is the name of the widget in the layout file.
		m_Discord 					= layoutRoot.FindAnyWidget( "DiscordBtn" );
		m_Twitter 					= layoutRoot.FindAnyWidget( "TwitterBtn" );
		m_Youtube 					= layoutRoot.FindAnyWidget( "YoutubeBtn" );
		m_Reddit 					= layoutRoot.FindAnyWidget( "RedditBtn" );
		m_Facebook 					= layoutRoot.FindAnyWidget( "FacebookBtn" );
		m_Website					= layoutRoot.FindAnyWidget( "WebsiteBtn" );
		m_PriorityQueue				= layoutRoot.FindAnyWidget( "QueueBtn" );
		m_CharacterBtn 				= layoutRoot.FindAnyWidget( "CharacterBtn" );
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
		// This progress bar is just used as trim. 
		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());
		return layoutRoot;
	}	

	override bool OnClick(Widget w, int x, int y, int button)
	{
		// NOTE: ------------------------------------------------------------
		// Just drop in your URL to the desired social media outlet in the constants file
		// If you dont want to use one.  Just leave the code as is
		// You can Hide the buttons in the Colorful.main_menu.layout file
		// Located: Colorful-UI/gui/layouts/new_ui/Colorful.main_menu.layout
		// ------------------------------------------------------------------
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL("http://discord.gg/saltnpepper");
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(MenuURLS.urlTwitter);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL(MenuURLS.urlReddit);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL(MenuURLS.urlYoutube);
			return false;
		}	
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL(MenuURLS.urlFacebook);
			return false;
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
		// TODO: Find out why default btn only says "rename", and wont let me chant text. 
		// For now just use a custom button. (Don't Remove till I find a fix)
		else if ( w == m_CharacterBtn )
		{
			OpenMenuCustomizeCharacter();
			return true;
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

	// Coloring Functions 
	// NOTE: Varient Styles -------------------------------------
	// I have included a few variations of this code so you
	// can easily comment/uncomment the code you want to use. 
	//-----------------------------------------------------------
	
	//-----------------------------------------------------------
	// Button with a solid background highlight.
	//-----------------------------------------------------------
	// Background is your colorScheme.BrandColor();
	// Text is colorScheme.PrimaryText() ;
	// Use the Colors in the constants.c to change them
	// ----------------------------------------------------------
	//
	// void ColorHighlight( Widget w )
	// {
	// 	if( !w )
	// 		return;	
	// 	int color_pnl = colorScheme.BrandColor();
	// 	int color_lbl = colorScheme.PrimaryText() ;
	// 	int color_img = colorScheme.BrandColor();		
	// 	// Button Highlights. 
	// 	// The buttons in your layout must follow the structure within the layout files.
	// 	// Just look in the colorful.Main_Menu.layout in Workbench. 
	// 	ButtonSetColor(w, color_pnl);
	// 	ButtonSetTextColor(w, color_lbl);
	// 	// Top right icons
	//  // TODO: Add social icons to an imageset. 
	// 	ImagenSetColor(w, color_img);
	// }
	
	// ----------------------------------------
	// Button with a text only highlight.
	//-----------------------------------------
	// Background is your UIColor.Transparent()
	// Text is sss
	// ----------------------------------------
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

	void TwitterHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.twitter();
		int color_img = UIColor.twitter();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void DiscordHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.discord();
		int color_img = UIColor.discord();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void YoutubeHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.youtube();
		int color_img = UIColor.youtube();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void RedditHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.reddit();
		int color_img = UIColor.reddit();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}

	void MetaHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.meta();
		int color_img = UIColor.meta();	

		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);	
	}
	
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		
		if( w == m_Twitter )
		{
			TwitterHighlight( w );
			return true;
		}

		if( w == m_Facebook )
		{
			MetaHighlight( w );
			return true;
		}

		if( w == m_Discord )
		{
			DiscordHighlight( w );
			return true;
		}

		if( w == m_Youtube )
		{
			YoutubeHighlight( w );
			return true;
		}

		if( w == m_Reddit )
		{
			RedditHighlight( w );
			return true;
		}

		
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
