
modded class LoginQueueBase extends UIScriptedMenu
{
	ProgressBarWidget m_ProgressLoading;
	protected TextWidget m_StatusText;
	private	Widget m_shader

	override Widget Init()
	{		
		layoutRoot 			   = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.dialog_queue_position.layout");
		m_txtPosition		   = TextWidget.Cast(layoutRoot.FindAnyWidget("txtPosition"));
		m_txtNote 			   = TextWidget.Cast(layoutRoot.FindAnyWidget("txtNote"));
		m_btnLeave 			   = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
		ImageWidget Background = ImageWidget.Cast( layoutRoot.FindAnyWidget("BackgroundOverride"));
		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		m_shader.SetColor(colorScheme.ShaderColor());
        Background.LoadImageFile(0, GetRandomBackground());  			
		layoutRoot.FindAnyWidget("notification_root").Show(false);
		m_ProgressLoading.SetColor(colorScheme.LoadingbarColor());
		m_StatusText.SetColor(colorScheme.SecondaryText());
		return layoutRoot;
	}
};

modded class LoginTimeBase extends UIScriptedMenu
{
	ProgressBarWidget m_ProgressLoading;
	protected TextWidget m_TxtHdr;
	private	Widget m_shader
	
	override Widget Init()
	{
		layoutRoot 			   = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.dialog_login_time.layout");
		m_TxtHdr			   = TextWidget.Cast(layoutRoot.FindAnyWidget("TxtHdr"));
		m_txtLabel 			   = TextWidget.Cast(layoutRoot.FindAnyWidget("txtLabel"));
		m_txtDescription 	   = TextWidget.Cast(layoutRoot.FindAnyWidget("txtDescription"));
		m_btnLeave 			   = ButtonWidget.Cast(layoutRoot.FindAnyWidget("btnLeave"));
        ImageWidget Background = ImageWidget.Cast( layoutRoot.FindAnyWidget("BackgroundOverride"));
		m_ProgressLoading      = ProgressBarWidget.Cast( layoutRoot.FindAnyWidget("LoadingBar") );
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		m_shader.SetColor(colorScheme.ShaderColor());
		m_ProgressLoading.SetColor(colorScheme.LoadingbarColor());
		m_TxtHdr.SetColor(colorScheme.SecondaryText());
        Background.LoadImageFile(0, GetRandomBackground());  		
		return layoutRoot;
	}

	override void SetTime(int time)
	{
		string text = "";
		TimeConversions.ConvertSecondsToFullTime(time, m_FullTime);
		if (!m_IsRespawn)
			text = "#menu_loading_in_";
		else
			text = "#dayz_game_spawning_in_";

		if (m_FullTime.m_Days > 0)
			text += "dhms";
		else if (m_FullTime.m_Hours > 0)
			text += "hms";
		else if (m_FullTime.m_Minutes > 0)
			text += "ms";
		else
			text += "s";
		
		text = Widget.TranslateString(text);
		text = string.Format(text, m_FullTime.m_Seconds, m_FullTime.m_Minutes, m_FullTime.m_Hours, m_FullTime.m_Days);
		m_txtLabel.SetText(text);
		
		if (m_IsRespawn && time <= 1)
			GetGame().SetLoginTimerFinished();

		m_txtLabel.SetText("Get ready to play in " + time.ToString());
	}
};

modded class LoadingScreen
{	
	protected ImageWidget m_ColorfulLogo;
	protected ref Rotator m_logoRotator;
	protected ImageWidget m_Background; 
	protected TextWidget m_ProTip;
	private	Widget m_shader

	void LoadingScreen(DayZGame game)
	{
		m_DayZGame   = game;		
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.loading.layout");
		Class.CastTo(m_ColorfulLogo, m_WidgetRoot.FindAnyWidget("ColorfulLogo"));
		Class.CastTo(m_ProTip, m_WidgetRoot.FindAnyWidget("ProTip"));
		Class.CastTo(m_shader, m_WidgetRoot.FindAnyWidget("Colorful_Shader"));
		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));	
		Class.CastTo(m_TextWidgetTitle, m_WidgetRoot.FindAnyWidget("TextWidget"));
		Class.CastTo(m_TextWidgetStatus, m_WidgetRoot.FindAnyWidget("StatusText"));
		Class.CastTo(m_ImageWidgetBackground, m_WidgetRoot.FindAnyWidget("BackgroundOverride"));
		Class.CastTo(m_ImageLoadingIcon, m_WidgetRoot.FindAnyWidget("ImageLoadingIcon"));
		Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));
		m_ImageBackground = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("BackgroundOverride") );
		m_ProgressLoading = ProgressBarWidget.Cast( m_WidgetRoot.FindAnyWidget("LoadingBar") );
		m_ProgressLoading.SetColor(colorScheme.LoadingbarColor());
		m_ProTip.SetColor(colorScheme.SecondaryText());
		m_shader.SetColor(colorScheme.ShaderColor());
		ProgressAsync.SetProgressData(m_ProgressLoading);
		ProgressAsync.SetUserData(m_ImageBackground);
	}	

	override void ShowEx(DayZGame game)
	{
		if (!m_HintPanel)
		{
			m_HintPanel					= new UiHintPanelLoading(m_WidgetRoot.FindAnyWidget("hint_frame"));
			m_HintPanel.Init(game);
		}

		Show();
	}

	override void Show()
	{
		Widget lIcon = m_Background;
		ImageWidget m_Background = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("BackgroundOverride"));		
		m_Background.LoadImageFile(0, GetRandomBackground()); 
	}

};
