modded class MainMenu extends UIScriptedMenu
{
	// Register your variables
	private Widget m_Discord;
	private Widget m_Twitter;
	private Widget m_Youtube;
	private Widget m_Reddit;
	private Widget m_Facebook;
	private Widget m_Website;
	private Widget m_PriorityQueue;
	private Widget m_CharacterBtn;
	private Widget m_Separator1;
	private Widget m_Separator2;
	private Widget m_SeparatorPanel;
	private Widget m_ProgressLoading;
	private	Widget m_shader;
	private Widget m_ImageBackground;
	private ImageWidget m_Background;
	private Widget m_ComingSoon


	private string US_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_1.edds";
	private string EU_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_2.edds";
	private string AU_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_3.edds";

	private bool m_FadingInBackground = false;
	private float m_Alpha = 1.0; 


	private ButtonWidget m_LeftSelect;
	private ButtonWidget m_RightSelect;
	private ImageWidget m_ChevronLeft;
	private ImageWidget m_ChevronRight;
	bool isSelectedUSMAIN = true; 
	bool isSelectedEUMAIN = false; 
	bool isSelectedAUMAIN = false; 

	private	Widget m_USMAIN;
	private	Widget m_EUMAIN;
	private	Widget m_AUMAIN;
	private	Widget m_USMAINDIS;
	private	Widget m_EUMAINDIS;
	private	Widget m_AUMAINDIS;
	private Widget m_ServerOnline;
	private Widget m_ServerOffline;
	private Widget m_ServerOnlineIMG;
	private Widget m_ServerOfflineIMG;
	private Widget m_PrioQ;

	private Widget m_Press2Start;
	bool m_FadingOut = true;
	bool m_FadingIn = true;
	
	ButtonWidget connectButton;
	
	override Widget Init()
	{
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );

		m_Play						= layoutRoot.FindAnyWidget( "connectButton" );
		m_Discord					= layoutRoot.FindAnyWidget( "Discord_button" );
		m_Website					= layoutRoot.FindAnyWidget( "Website_Button" );
		
		m_Press2Start 				= layoutRoot.FindAnyWidget( "Press2Start" );
		m_ComingSoon 				= layoutRoot.FindAnyWidget( "Coming Soon" );
		m_LeftSelect				= layoutRoot.FindAnyWidget( "LeftSelect" );
		m_Background 				= ImageWidget.Cast(layoutRoot.FindAnyWidget("ImageBackground"));

		m_RightSelect				= layoutRoot.FindAnyWidget( "RightSelect" );
		m_USMAIN					= layoutRoot.FindAnyWidget( "USMainActive" );
		m_EUMAIN					= layoutRoot.FindAnyWidget( "EUMainActive" );
		m_AUMAIN					= layoutRoot.FindAnyWidget( "AUMainActive" );
		m_USMAINDIS					= layoutRoot.FindAnyWidget( "USMainDisabled" );
		m_EUMAINDIS					= layoutRoot.FindAnyWidget( "EUMainDisabled" );
		m_AUMAINDIS					= layoutRoot.FindAnyWidget( "AUMainDisabled" );

		m_PriorityQueue				= layoutRoot.FindAnyWidget( "PrioQ_button" );
		
		m_ServerOffline				= layoutRoot.FindAnyWidget( "ServerOffline" );
		m_ServerOnline				= layoutRoot.FindAnyWidget( "ServerOnline" );

		m_ServerOfflineIMG				= layoutRoot.FindAnyWidget( "ServerOffline_Img" );
		m_ServerOnlineIMG				= layoutRoot.FindAnyWidget( "ServerOnline_Img" );
		
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_PlayVideo					= layoutRoot.FindAnyWidget( "play_video" );
		m_Tutorials					= layoutRoot.FindAnyWidget( "tutorials" );
		m_TutorialButton			= layoutRoot.FindAnyWidget( "tutorial_button" );
		m_MessageButton				= layoutRoot.FindAnyWidget( "message_button" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );
		m_PrevCharacter				= layoutRoot.FindAnyWidget( "prev_character" );
		m_NextCharacter				= layoutRoot.FindAnyWidget( "next_character" );		
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
		m_ProgressLoading  = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());	
		AnimatePress2StartFade();
		return layoutRoot;
	}	

	void AnimatePress2StartFade() {
    if (m_FadingOut) {
        m_Alpha -= 0.05; 
        if (m_Alpha <= 0) {
            m_Alpha = 0;
            m_FadingOut = false;
        }
    } else {
        m_Alpha += 0.05; 
        if (m_Alpha >= 1) {
            m_Alpha = 1;
            m_FadingOut = true;
        }
    }

    m_Press2Start.SetAlpha(m_Alpha);
	m_ComingSoon.SetAlpha(m_Alpha);
	
    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.AnimatePress2StartFade, 50, false);
	}

	void SwitchServerRight()
	{
	    if (isSelectedUSMAIN)
	    {
	        m_USMAIN.Show(false);
	        m_EUMAINDIS.Show(true);
			m_Background.LoadImageFile(0, EU_Background);
			m_ComingSoon.Show(true);
			m_Press2Start.Show(false);
			m_ServerOnlineIMG.Show(false);
			m_ServerOfflineIMG.Show(true);
	        isSelectedUSMAIN = false;
	        isSelectedEUMAIN = true;
	    }
	    else if (isSelectedEUMAIN)
	    {
	        m_EUMAINDIS.Show(false);
	        m_AUMAINDIS.Show(true);
			m_Background.LoadImageFile(0, AU_Background);
			m_ComingSoon.Show(true);
			m_Press2Start.Show(false);
			m_ServerOnlineIMG.Show(false);
			m_ServerOfflineIMG.Show(true);
	        isSelectedEUMAIN = false;
	        isSelectedAUMAIN = true;
	    }
	    else if (isSelectedAUMAIN)
	    {
	        m_AUMAINDIS.Show(false);
	        m_USMAIN.Show(true);
			m_Background.LoadImageFile(0, US_Background);
			m_ComingSoon.Show(false);
			m_Press2Start.Show(true);
			m_ServerOnlineIMG.Show(true);
			m_ServerOfflineIMG.Show(false);
	        isSelectedAUMAIN = false;
	        isSelectedUSMAIN = true;
	    }
	}

	void SwitchServerLeft()
	{
	    if (isSelectedAUMAIN)
	    {
	        m_AUMAINDIS.Show(false);
	        m_EUMAINDIS.Show(true);
			m_Background.LoadImageFile(0, EU_Background);
			m_ComingSoon.Show(true);
			m_Press2Start.Show(false);
			m_ServerOnlineIMG.Show(false);
			m_ServerOfflineIMG.Show(true);
	        isSelectedAUMAIN = false;
	        isSelectedEUMAIN = true;
	    }
	    else if (isSelectedEUMAIN)
	    {
	        m_EUMAINDIS.Show(false);
	        m_USMAIN.Show(true);
			m_Background.LoadImageFile(0, US_Background);
			m_ComingSoon.Show(false);
			m_Press2Start.Show(true);
			m_ServerOnlineIMG.Show(true);
			m_ServerOfflineIMG.Show(false);
	        isSelectedEUMAIN = false;
	        isSelectedUSMAIN = true;
	    }
	    else if (isSelectedUSMAIN)
	    {
	        m_USMAIN.Show(false);
	        m_AUMAINDIS.Show(true);
			m_Background.LoadImageFile(0, AU_Background);
			m_ComingSoon.Show(true);
			m_Press2Start.Show(false);
			m_ServerOnlineIMG.Show(false);
			m_ServerOfflineIMG.Show(true);
	        isSelectedUSMAIN = false;
	        isSelectedAUMAIN = true;
	    }
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
	    if (w == m_LeftSelect && button == MouseState.LEFT)
    	{
			SwitchServerLeft()
    	    return true;
    	}
		if (w == m_RightSelect && button == MouseState.LEFT)
    	{
			SwitchServerRight()
    	    return true;
    	}
		if (button == MouseState.LEFT && w == m_USMAIN)
		{
			g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_EUMAIN)
		{
			// g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_AUMAIN)
		{
			// g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(MenuURLS.urlDiscord);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(MenuURLS.urlTwitter);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_ServerOnline)
		{
			GetGame().OpenURL(MenuURLS.urlBattleMetrics);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_ServerOffline)
		{
			GetGame().OpenURL(MenuURLS.urlBattleMetrics);
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

		else if ( w == m_CharacterBtn )
		{
			OpenMenuCustomizeCharacter();
			return true;
		}
		return super.OnClick(w, x, y, button);
	};

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
		if (w == m_LeftSelect)
    	{
    	    ColorHighlight(w);
    	    return true;
    	}

    	if (w == m_RightSelect)
    	{
    	    ColorHighlight(w);
    	    return true;
    	}

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

	override void Exit()
	{
		EnterScriptedMenu( COLORFUL_EXIT );
	}

}
