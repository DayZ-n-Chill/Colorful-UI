
modded class LoginQueueBase extends UIScriptedMenu
{
	ProgressBarWidget m_ProgressLoading;
	protected TextWidget m_StatusText;
	private	Widget m_shader

	override Widget Init()
	{		
		layoutRoot 			   = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.dialog_queue_position.layout");
		// Print("Colorful Login Queue Loaded!");	
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
		// Print("Colorful Login Time Loaded!");	
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
	
	void SetTime(int time)
	{
		// NOTE: I recommend keeping this time set low. I usually set it to 5 seconds.
		// Time is set in your globals.xml <var name="TimeLogin" type="0" value="5"/>
		// Change the "text" below to whatever you want. 
		m_txtLabel.SetText("Get ready to play in " + time.ToString());
	}
};

modded class LoadingScreen
{	
	protected ImageWidget m_Background; 
	protected TextWidget m_ProTip;
	private	Widget m_shader

	void LoadingScreen(DayZGame game)
	{
		m_DayZGame   = game;		
		
		m_WidgetRoot = game.GetLoadingWorkspace().CreateWidgets("Colorful-UI/gui/layouts/Colorful.loading.layout");
		// Print("Colorful Loading Screen Loaded!");	
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
		SetStatus(m_TextWidgetStatus.GetRandomHint());
	}	

	void Show()
	{
		Widget lIcon = m_Background;
		ImageWidget m_Background = ImageWidget.Cast( m_WidgetRoot.FindAnyWidget("BackgroundOverride"));		
		m_Background.LoadImageFile(0, GetRandomBackground()); 
	}
};
