// modded class MainMenu extends UIScriptedMenu
// {
// 	// Register your variables
// 	private Widget m_Discord;
// 	private Widget m_Twitter;
// 	private Widget m_Youtube;
// 	private Widget m_Reddit;
// 	private Widget m_Facebook;
// 	private Widget m_Website;
// 	private Widget m_PriorityQueue
// 	private Widget m_CharacterBtn;
// 	private Widget m_Separator1
// 	private Widget m_Separator2
// 	private Widget m_SeparatorPanel
// 	private Widget m_ProgressLoading
// 	private	Widget m_shader
// 	TextWidget m_ServerPingWidget;

// 	ButtonWidget connectButton;
	
// 	override Widget Init()
// 	{
// 		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );

// 		m_Play						= layoutRoot.FindAnyWidget( "connectButton" );
// 		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
// 		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
// 		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
// 		m_TutorialButton			= layoutRoot.FindAnyWidget( "tutorial_button" );
// 		m_MessageButton				= layoutRoot.FindAnyWidget( "message_button" );
// 		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
// 		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );
// 		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
// 		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );		
// 		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
// 		m_ScenePC					= m_Mission.GetIntroScenePC();
// 		string version;
// 		GetGame().GetVersion( version );
// 		m_Version.SetText( "#main_menu_version" + " " + version );
// 		GetGame().GetUIManager().ScreenFadeOut(0);
// 		SetFocus( null );
// 		Refresh();
// 		LoadMods();
// 		GetDayZGame().GetBacklit().MainMenu_OnShow();
// 		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
// 		m_shader.SetColor(colorScheme.ShaderColor());
// 		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
// 		m_Separator1.SetColor(colorScheme.SeparatorColor());
// 		m_Separator2.SetColor(colorScheme.SeparatorColor());
// 		m_SeparatorPanel.SetColor(colorScheme.SeparatorColor());
// 		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
// 		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());
// 		return layoutRoot;
// 	}	


// 	override bool OnClick(Widget w, int x, int y, int button)
// 	{

// 		if (button == MouseState.LEFT && w == m_Discord)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlDiscord);
// 			return true;
// 		}
// 		else if (button == MouseState.LEFT && w == m_Twitter)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlTwitter);
// 			return false;
// 		}
// 		else if (button == MouseState.LEFT && w == m_Reddit)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlReddit);
// 			return false;
// 		}
// 		else if (button == MouseState.LEFT && w == m_Youtube)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlYoutube);
// 			return false;
// 		}	
// 		else if (button == MouseState.LEFT && w == m_Facebook)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlFacebook);
// 			return false;
// 		}
// 		else if (button == MouseState.LEFT && w == m_Website)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlWebsite);
// 			return false;
// 		}
// 		else if (button == MouseState.LEFT && w == m_PriorityQueue)
// 		{
// 			GetGame().OpenURL(MenuURLS.urlPriorityQ);
// 			return false;
// 		}


// 		else if ( w == m_CharacterBtn )
// 		{
// 			OpenMenuCustomizeCharacter();
// 			return true;
// 		}
// 		return super.OnClick(w, x, y, button);
// 	};

// 	override void ColorHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = colorScheme.ButtonHoverColor();
// 		int color_img = colorScheme.ButtonHoverColor();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}

// 	override void ColorNormal( Widget w )
// 	{
// 		if( !w )
// 			return;
		
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = colorScheme.PrimaryText();
// 		int color_img = colorScheme.PrimaryText();

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);
	
// 	}

// 	void TwitterHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = UIColor.twitter();
// 		int color_img = UIColor.twitter();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}

// 	void DiscordHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = UIColor.discord();
// 		int color_img = UIColor.discord();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}

// 	void YoutubeHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = UIColor.youtube();
// 		int color_img = UIColor.youtube();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}

// 	void RedditHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = UIColor.reddit();
// 		int color_img = UIColor.reddit();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}

// 	void MetaHighlight( Widget w )
// 	{
// 		if( !w )
// 			return;	
			
// 		int color_pnl = UIColor.Transparent();
// 		int color_lbl = UIColor.meta();
// 		int color_img = UIColor.meta();	

// 		ButtonSetColor(w, color_pnl);
// 		ButtonSetTextColor(w, color_lbl);
// 		ImagenSetColor(w, color_img);	
// 	}
	
// 	override bool OnMouseEnter( Widget w, int x, int y )
// 	{
		
// 		if( w == m_Twitter )
// 		{
// 			TwitterHighlight( w );
// 			return true;
// 		}

// 		if( w == m_Facebook )
// 		{
// 			MetaHighlight( w );
// 			return true;
// 		}

// 		if( w == m_Discord )
// 		{
// 			DiscordHighlight( w );
// 			return true;
// 		}

// 		if( w == m_Youtube )
// 		{
// 			YoutubeHighlight( w );
// 			return true;
// 		}

// 		if( w == m_Reddit )
// 		{
// 			RedditHighlight( w );
// 			return true;
// 		}

		
// 		if( IsFocusable( w ) )
// 		{
// 			ColorHighlight( w );
// 			return true;
// 		}
// 		return false;
// 	}

// 	// I still have not found a good way to globally edit the generated dialog system colors but I feel like I am close
// 	// I guess the best way in the meantime is to create a new menu and have it styled as we need.
// 	override void Exit()
// 	{
// 		EnterScriptedMenu( COLORFUL_EXIT );
// 	}

// }
