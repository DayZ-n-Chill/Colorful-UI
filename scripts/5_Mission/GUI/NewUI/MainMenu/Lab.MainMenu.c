modded class MainMenu extends UIScriptedMenu
{
	private Widget m_Discord;
	private Widget m_Website;
	private Widget m_PriorityQueue;
	private Widget m_CharacterBtn;
	private Widget m_ProgressLoading;
	private ImageWidget m_Background;

	private string US_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_1.edds";
	private string EU_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_2.edds";
	private string AU_Background = "Colorful-UI/gui/textures/loading_screens/LabLoadScreen_3.edds";

	private ButtonWidget m_LeftSelect;
	private ButtonWidget m_RightSelect;
	
	bool isSelectedUSMAIN = true; 
	private	Widget m_USMainBtn;
	private	Widget m_USMainHover;
	private	Widget m_USMainDisabled;
	
	bool isSelectedEUMAIN = false; 
	private	Widget m_EUMainBtn;
	private	Widget m_EUMainHover;
	private	Widget m_EUMainDisabled;
	
	bool isSelectedAUMAIN = false; 
	private	Widget m_AUMainBtn;
	private	Widget m_AUMainHover;
	private	Widget m_AUMainDisabled;

	private Widget m_ServerOnline;
	private Widget m_ServerOffline;
	private Widget m_ServerOnlineIMG;
	private Widget m_ServerOfflineIMG;

	private Widget m_Press2Start;
	private Widget m_ComingSoon
	
	private float m_Alpha = 1.0; 
	bool m_FadingOut = true;

	ButtonWidget connectButton;
	
	override Widget Init()
	{
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );
		
		m_Background 				= ImageWidget.Cast(layoutRoot.FindAnyWidget("ImageBackground"));

		m_Play						= layoutRoot.FindAnyWidget( "connectButton" );
		m_Discord					= layoutRoot.FindAnyWidget( "Discord_button" );
		m_Website					= layoutRoot.FindAnyWidget( "Website_Button" );
		m_PriorityQueue				= layoutRoot.FindAnyWidget( "PrioQ_button" );

		m_LeftSelect				= layoutRoot.FindAnyWidget( "LeftSelect" );
		m_RightSelect				= layoutRoot.FindAnyWidget( "RightSelect" );
		
		m_USMainBtn					= layoutRoot.FindAnyWidget( "USMainBtn" );
		m_USMainHover				= layoutRoot.FindAnyWidget( "USMainHover" );
		m_USMainDisabled			= layoutRoot.FindAnyWidget( "USMainDisabled" );
		
		m_EUMainBtn					= layoutRoot.FindAnyWidget( "EUMainBtn" );
		m_USMainHover				= layoutRoot.FindAnyWidget( "USMainHover" );
		m_EUMainDisabled			= layoutRoot.FindAnyWidget( "EUMainDisabled" );
		
		m_AUMainBtn					= layoutRoot.FindAnyWidget( "AUMainBtn" );
		m_AUMainHover				= layoutRoot.FindAnyWidget( "AUMainHover" );
		m_AUMainDisabled			= layoutRoot.FindAnyWidget( "AUMainDisabled" );

		m_ComingSoon 				= layoutRoot.FindAnyWidget( "Coming Soon" );
		m_Press2Start 				= layoutRoot.FindAnyWidget( "Press2Start" );
		
		m_ServerOffline				= layoutRoot.FindAnyWidget( "ServerOffline" );
		m_ServerOnline				= layoutRoot.FindAnyWidget( "ServerOnline" );

		m_ServerOfflineIMG			= layoutRoot.FindAnyWidget( "ServerOffline_Img" );
		m_ServerOnlineIMG			= layoutRoot.FindAnyWidget( "ServerOnline_Img" );
		
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );

		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );

		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		m_ScenePC					= m_Mission.GetIntroScenePC();

		GetGame().GetUIManager().ScreenFadeOut(0);
		SetFocus( null );
		Refresh();
		LoadMods();
		GetDayZGame().GetBacklit().MainMenu_OnShow();

		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );

		m_ProgressLoading  = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());	
		FadeInOut();
		return layoutRoot;
	}	

	void FadeInOut() {
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
	
    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.FadeInOut, 50, false);
	}

	void SwitchServerRight()
	{
	    if (isSelectedUSMAIN)
	    {
			m_EUMainBtn.Show(false);
	        m_EUMainDisabled.Show(true);
	        m_USMainBtn.Show(false);
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
			m_AUMainBtn.Show(false);
	        m_AUMainDisabled.Show(true);
	        m_EUMainDisabled.Show(false);
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
	        m_USMainBtn.Show(true);
			m_USMainDisabled.Show(false);
	        m_AUMainDisabled.Show(false);
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
			m_EUMainBtn.Show(false);
	        m_EUMainDisabled.Show(true);
	        m_AUMainDisabled.Show(false);
			m_ComingSoon.Show(true);
			m_Press2Start.Show(false);
			m_ServerOnlineIMG.Show(false);
			m_ServerOfflineIMG.Show(true);
			m_Background.LoadImageFile(0, EU_Background);
	        isSelectedAUMAIN = false;
	        isSelectedEUMAIN = true;
	    }
	    else if (isSelectedEUMAIN)
	    {
	        m_USMainBtn.Show(true);
			m_USMainDisabled.Show(false);
	        m_EUMainDisabled.Show(false);
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
			m_AUMainBtn.Show(false);
	        m_AUMainDisabled.Show(true);
	        m_USMainBtn.Show(false);
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
		if (button == MouseState.LEFT && w == m_USMainBtn)
		{
			g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_EUMainBtn)
		{
			// g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_AUMainBtn)
		{
			// g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(MenuURLS.urlDiscord);
			return true;
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

	void emptyHighlight( Widget w )
	{
		if( !w )
			return;	
			
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.Transparent();
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
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

		if( w == m_Discord )
		{
			DiscordHighlight( w );
			return true;
		}

		if( w == m_PriorityQueue )
		{
			emptyHighlight( w );
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
