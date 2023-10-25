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

	private string US_Background = "Colorful-UI/gui/textures/loading_screens/TheLab-LS1.edds";
	private string EU_Background = "Colorful-UI/gui/textures/loading_screens/TheLab-LS2.edds";
	private string AU_Background = "Colorful-UI/gui/textures/loading_screens/TheLab-LS3.edds";


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

	private Widget m_Press2Start;
	float m_Alpha = 1.0;
	bool m_FadingOut = true;
	
	ButtonWidget connectButton;
	
	override Widget Init()
	{
		layoutRoot					= GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/colorful.main_menu.layout" );

		m_Play						= layoutRoot.FindAnyWidget( "connectButton" );
		m_Discord					= layoutRoot.FindAnyWidget( "Discord_button" );
		m_Website					= layoutRoot.FindAnyWidget( "Website_Button" );
		
		m_Press2Start 				= layoutRoot.FindAnyWidget( "Press2Start" );
		m_LeftSelect				= layoutRoot.FindAnyWidget( "LeftSelect" );
		m_Background 				= ImageWidget.Cast(layoutRoot.FindAnyWidget("ImageBackground"));

		m_RightSelect				= layoutRoot.FindAnyWidget( "RightSelect" );
		m_USMAIN					= layoutRoot.FindAnyWidget( "USMain" );
		m_EUMAIN					= layoutRoot.FindAnyWidget( "EUMain" );
		m_AUMAIN					= layoutRoot.FindAnyWidget( "AUMain" );
		
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
		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.MainMenuTrim());	
		// m_Background.LoadImageFile(0, "Colorful-UI/gui/textures/loading_screens/TheLab-LS1.edds")  
		AnimatePress2StartFade();
		return layoutRoot;
	}	

	void AnimatePress2StartFade() {
    if (m_FadingOut) {
        m_Alpha -= 0.05; // Adjust this value for faster or slower fades
        if (m_Alpha <= 0) {
            m_Alpha = 0;
            m_FadingOut = false;
        }
    } else {
        m_Alpha += 0.05; // Adjust this value for faster or slower fades
        if (m_Alpha >= 1) {
            m_Alpha = 1;
            m_FadingOut = true;
        }
    }

    m_Press2Start.SetAlpha(m_Alpha);

    // Schedule the next update
    GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.AnimatePress2StartFade, 50, false); // Adjust the value 50 for faster or slower fades
	}


	void SwitchServerRight()
	{
	    if (isSelectedUSMAIN)
	    {
	        m_USMAIN.Show(false);
	        m_EUMAIN.Show(true);
			m_Background.LoadImageFile(0, EU_Background);
	        isSelectedUSMAIN = false;
	        isSelectedEUMAIN = true;
	    }
	    else if (isSelectedEUMAIN)
	    {
	        m_EUMAIN.Show(false);
	        m_AUMAIN.Show(true);
			m_Background.LoadImageFile(0, AU_Background);
	        isSelectedEUMAIN = false;
	        isSelectedAUMAIN = true;
	    }
	    else if (isSelectedAUMAIN)
	    {
	        m_AUMAIN.Show(false);
	        m_USMAIN.Show(true);
			m_Background.LoadImageFile(0, US_Background);
	        isSelectedAUMAIN = false;
	        isSelectedUSMAIN = true;
	    }
	}

	void SwitchServerLeft()
	{
	    if (isSelectedAUMAIN)
	    {
	        m_AUMAIN.Show(false);
	        m_EUMAIN.Show(true);
			m_Background.LoadImageFile(0, EU_Background);
	        isSelectedAUMAIN = false;
	        isSelectedEUMAIN = true;
	    }
	    else if (isSelectedEUMAIN)
	    {
	        m_EUMAIN.Show(false);
	        m_USMAIN.Show(true);
			m_Background.LoadImageFile(0, US_Background);
	        isSelectedEUMAIN = false;
	        isSelectedUSMAIN = true;
	    }
	    else if (isSelectedUSMAIN)
	    {
	        m_USMAIN.Show(false);
	        m_AUMAIN.Show(true);
			m_Background.LoadImageFile(0, AU_Background);
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
