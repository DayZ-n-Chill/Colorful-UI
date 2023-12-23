modded class MainMenu extends UIScriptedMenu
{
	private Widget m_Discord;
	private Widget m_Website;
	private Widget m_PriorityQueue;
	private Widget m_CharacterBtn;
	private Widget m_ProgressLoading;
	private ImageWidget m_Background;

	private ButtonWidget m_LeftSelect;
	private ButtonWidget m_LeftSelectImg;
	private ButtonWidget m_LeftSelectHover;
	
	private ButtonWidget m_RightSelect;
	private ButtonWidget m_RightSelectImg;
	private ButtonWidget m_RightSelectHover;
	
	bool isSelectedUSMAIN = true; 
	private	Widget m_USMainBtn;
	private	Widget m_USMainIMG
	private	Widget m_USMainHover;
	private	Widget m_USMainDisabled;
	private string US_Background = "Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-1.edds";
	private string US_BattleMetrics = "https://www.battlemetrics.com/servers/dayz/21537246";
	
	bool isSelectedEUMAIN = false; 
	private	Widget m_EUMainBtn;
	private	Widget m_EUMainIMG
	private	Widget m_EUMainHover;
	private	Widget m_EUMainDisabled;
	private string EU_Background = "Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-2.edds";
	private string EU_BattleMetrics = "https://www.battlemetrics.com/servers/dayz/21537246";
	
	bool isSelectedAUMAIN = false; 
	private	Widget m_AUMainBtn;
	private	Widget m_AUMainIMG
	private	Widget m_AUMainHover;
	private	Widget m_AUMainDisabled;
	private string AU_Background = "Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-3.edds";
	private string AU_BattleMetrics = "https://www.battlemetrics.com/servers/dayz/21537246";

	private Widget m_ServerStatusOn;
	private Widget m_OnlineImg
	private Widget m_OnlineHover

	private Widget m_ServerStatusOff;
	private Widget m_OfflineImg
	private Widget m_OfflineHover
	
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
		m_LeftSelectImg				= layoutRoot.FindAnyWidget( "LeftSelectImg" );
		m_LeftSelectHover			= layoutRoot.FindAnyWidget( "LeftSelectHover" );

		m_RightSelect				= layoutRoot.FindAnyWidget( "RightSelect" );
		m_RightSelectImg			= layoutRoot.FindAnyWidget( "RightSelectImg" );
		m_RightSelectHover			= layoutRoot.FindAnyWidget( "RightSelectHover" );
		
		m_USMainBtn					= layoutRoot.FindAnyWidget( "USMainBtn" );
		m_USMainIMG					= layoutRoot.FindAnyWidget( "USMainIMG" );
		m_USMainHover				= layoutRoot.FindAnyWidget( "USMainHover" );
		m_USMainDisabled			= layoutRoot.FindAnyWidget( "USMainDisabled" );
		
		m_EUMainBtn					= layoutRoot.FindAnyWidget( "EUMainBtn" );
		m_EUMainIMG					= layoutRoot.FindAnyWidget( "EUMainIMG" );
		m_EUMainHover				= layoutRoot.FindAnyWidget( "EUMainHover" );
		m_EUMainDisabled			= layoutRoot.FindAnyWidget( "EUMainDisabled" );
		
		m_AUMainBtn					= layoutRoot.FindAnyWidget( "AUMainBtn" );
		m_AUMainIMG					= layoutRoot.FindAnyWidget( "AUMainIMG" );
		m_AUMainHover				= layoutRoot.FindAnyWidget( "AUMainHover" );
		m_AUMainDisabled			= layoutRoot.FindAnyWidget( "AUMainDisabled" );

		m_ComingSoon 				= layoutRoot.FindAnyWidget( "Coming Soon" );
		m_Press2Start 				= layoutRoot.FindAnyWidget( "Press2Start" );
		
		m_ServerStatusOn			= layoutRoot.FindAnyWidget( "ServerStatusOn" );
		m_OnlineImg					= layoutRoot.FindAnyWidget( "OnlineImg" );
		m_OnlineHover				= layoutRoot.FindAnyWidget( "OnlineHover" );

		m_ServerStatusOff		    = layoutRoot.FindAnyWidget( "ServerStatusOff" );
		m_OfflineImg				= layoutRoot.FindAnyWidget( "OfflineImg" );
		m_OfflineHover				= layoutRoot.FindAnyWidget( "OfflineHover" );

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

	void UpdateServerUI(bool showUS, bool showEU, bool showAU, string background, bool showComingSoon, bool showPress2Start, bool showServerOnline, bool showServerOffline)
	{
		m_USMainBtn.Show(showUS);
		m_EUMainDisabled.Show(showEU);
		m_AUMainBtn.Show(showAU);
		m_Background.LoadImageFile(0, background);
		m_ComingSoon.Show(showComingSoon);
		m_Press2Start.Show(showPress2Start);
		m_ServerStatusOn.Show(showServerOnline);
		m_ServerStatusOff.Show(showServerOffline);
	}

	void SwitchServerRight()
	{
		if (isSelectedUSMAIN)
		{
			UpdateServerUI(false, true, false, EU_Background, true, false, false, true);
			isSelectedUSMAIN = false;
			isSelectedEUMAIN = true;
		}
		else if (isSelectedEUMAIN)
		{
			UpdateServerUI(false, false, true, AU_Background, false, true, true, false);
			isSelectedEUMAIN = false;
			isSelectedAUMAIN = true;
		}
		else if (isSelectedAUMAIN)
		{
			UpdateServerUI(true, false, false, US_Background, false, true, true, false);
			isSelectedAUMAIN = false;
			isSelectedUSMAIN = true;
		}
	}

	void SwitchServerLeft()
	{
		if (isSelectedAUMAIN)
		{
			UpdateServerUI(false, true, false, EU_Background, true, false, false, true);
			isSelectedAUMAIN = false;
			isSelectedEUMAIN = true;
		}
		else if (isSelectedEUMAIN)
		{
			UpdateServerUI(true, false, false, US_Background, false, true, true, false);
			isSelectedEUMAIN = false;
			isSelectedUSMAIN = true;
		}
		else if (isSelectedUSMAIN)
		{
			UpdateServerUI(false, false, true, AU_Background, false, true, true, false);
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
			g_Game.ConnectFromServerBrowser( "195.60.166.182", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_AUMainBtn)
		{
			g_Game.ConnectFromServerBrowser( "168.100.163.22", 2302, "" );
			return true;
		}
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(MenuURLS.urlDiscord);
			return true;
		}
		if (button == MouseState.LEFT && w == m_ServerStatusOn)
		{
			GetGame().OpenURL("https://www.battlemetrics.com/servers/dayz/21537246");
			return true;
		}
		if (button == MouseState.LEFT && w == m_ServerStatusOff)
		{
			GetGame().OpenURL("https://www.battlemetrics.com/servers/dayz/21537246");
			return true;
		}	
		if (button == MouseState.LEFT && w == m_Website)
		{
			GetGame().OpenURL(MenuURLS.urlWebsite);
			return true;
		}
		if (button == MouseState.LEFT && w == m_PriorityQueue)
		{
			GetGame().OpenURL(MenuURLS.urlPriorityQ);
			return true;
		}
		if ( w == m_CharacterBtn )
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
    	    m_LeftSelectHover.Show(true);
    	    return true;
    	}
    	if (w == m_RightSelect)
    	{
    	    m_RightSelectHover.Show(true);
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
		if (w == m_USMainBtn)
        {
			m_USMainHover.Show(true);
			m_USMainIMG.Show(false);
            return true;
        }
		if (w == m_AUMainBtn)
        {
			m_AUMainHover.Show(true);
			m_AUMainIMG.Show(false);
            return true;
        }
		if (w == m_EUMainBtn)
        {
			m_EUMainHover.Show(true);
			m_EUMainIMG.Show(false);
            return true;
        }
		if (w == m_ServerStatusOn)
        {
			m_OnlineHover.Show(true);
            return true;
        }
		if (w == m_ServerStatusOff)
        {
			m_OfflineHover.Show(true);
            return true;
        }
		if( IsFocusable( w ) )
		{
			ColorHighlight( w );
			return true;
		}

		return false;
	}

	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if (w == m_LeftSelect)
    	{
    	    m_LeftSelectHover.Show(false);
    	    return true;
    	}
		if (w == m_RightSelect)
    	{
    	    m_RightSelectHover.Show(false);
    	    return true;
    	}
		if (w == m_ServerStatusOn)
        {
			m_OnlineHover.Show(false);
            return true;
        }
		if (w == m_ServerStatusOff)
        {
			m_OfflineHover.Show(false);
            return true;
        }
		if (w == m_USMainBtn)
        {
			m_USMainIMG.Show(true);
			m_USMainHover.Show(false);
            return true;
        }
		if (w == m_AUMainBtn)
        {
			m_AUMainIMG.Show(true);
			m_AUMainHover.Show(false);
            return true;
        }
		if (w == m_EUMainBtn)
        {
			m_EUMainIMG.Show(true);
			m_EUMainHover.Show(false);
            return true;
        }
		if (IsFocusable(w))
		{
			ColorNormal(w);
			return true;
		}	
		return false;
	}

	override void Exit()
	{
		EnterScriptedMenu( COLORFUL_EXIT );
	}

}
