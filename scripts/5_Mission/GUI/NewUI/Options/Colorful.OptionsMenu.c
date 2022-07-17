modded class OptionsMenu extends UIScriptedMenu
{

	override Widget Init()
	{
		m_Options		= new GameOptions();
		
		layoutRoot		= GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/options/pc/options_menu.layout", null);
		
		layoutRoot.FindAnyWidget("Tabber").GetScript(m_Tabber);
		
		m_Details		= layoutRoot.FindAnyWidget("settings_details");
		m_Version		= TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		
		m_GameTab		= new OptionsMenuGame(layoutRoot.FindAnyWidget("Tab_0"), m_Details, m_Options, this);
		m_SoundsTab		= new OptionsMenuSounds(layoutRoot.FindAnyWidget("Tab_1"), m_Details, m_Options, this);
		
		m_VideoTab		= new OptionsMenuVideo(layoutRoot.FindAnyWidget("Tab_2"), m_Details, m_Options, this);
		m_ControlsTab	= new OptionsMenuControls(layoutRoot.FindAnyWidget("Tab_3"), m_Details, m_Options, this);

		m_Apply			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("apply"));
		m_Back			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("back"));
		m_Reset			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("reset"));
		m_Defaults		= ButtonWidget.Cast(layoutRoot.FindAnyWidget("defaults"));
		
		m_ModalLock = false;
		m_CanApplyOrReset = false;
		
		string version;
		m_Version.SetText( version );
		
		SetFocus( layoutRoot );
		ToggleFocus();
			
		// m_Tabber.m_OnTabSwitch.Insert(OnTabSwitch);
		// m_Tabber.m_OnAttemptTabSwitch.Insert(OnAttemptTabSwitch);
		

		// GetGame().GetMission().GetOnInputPresetChanged().Insert(OnInputPresetChanged);
		
		OnChanged();
		
		return layoutRoot;
	}
		
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if ( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( colorScheme.BrandColor() );
		}
		
		w.SetColor( ARGB( 255, 0, 0, 0) );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( text1 )
		{
			text1.SetColor(colorScheme.BrandColor() );
		}
		
		if ( text2 )
		{
			text2.SetColor(colorScheme.BrandColor() );
		}
		
		if ( text3 )
		{
			text3.SetColor(colorScheme.BrandColor() );
			w.SetAlpha(1);
		}
		
		if ( image )
		{
			image.SetColor( colorScheme.BrandColor() );
		}
		
		if ( option )
		{
			option.SetColor(colorScheme.BrandColor() );
		}
		
		if ( option_label )
		{
			option_label.SetColor(colorScheme.BrandColor() );
		}
	}
	
	void ColorNormal( Widget w )
	{
		if ( (w.GetFlags() & WidgetFlags.IGNOREPOINTER) == WidgetFlags.IGNOREPOINTER )
		{
			return;
		}
		
		if ( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor( colorScheme.PrimaryText() );
		}
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= w.FindAnyWidget( w.GetName() + "_option_wrapper" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( text1 )
		{
			text1.SetColor( colorScheme.PrimaryText() );
		}
		
		if ( text2 )
		{
			text2.SetColor( colorScheme.PrimaryText() );
		}
		
		if ( text3 )
		{
			text3.SetColor( colorScheme.PrimaryText() );
			w.SetAlpha(0);
		}
		
		if ( image )
		{
			image.SetColor( colorScheme.PrimaryText() );
		}
		
		if ( option )
		{
			w.SetAlpha(0.5);
			option.SetColor( colorScheme.PrimaryText() );
		}
		
		if ( option_label )
		{
			option_label.SetColor( colorScheme.PrimaryText() );
		}
	}
	
}
