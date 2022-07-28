modded class InGameMenu extends UIScriptedMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful-UI/gui/layouts/colorful.day_z_ingamemenu.layout");
				
		m_ContinueButton			= layoutRoot.FindAnyWidget( "continuebtn" );
		m_ExitButton				= layoutRoot.FindAnyWidget( "exitbtn" );
		m_RestartButton				= layoutRoot.FindAnyWidget( "restartbtn" );
		m_RespawnButton 			= layoutRoot.FindAnyWidget( "respawn_button" );
		m_RestartDeadRandomButton	= layoutRoot.FindAnyWidget( "respawn_button_random" );
		m_RestartDeadCustomButton	= layoutRoot.FindAnyWidget( "respawn_button_custom" );
		m_OptionsButton				= layoutRoot.FindAnyWidget( "optionsbtn" );
		m_ModdedWarning				= TextWidget.Cast( layoutRoot.FindAnyWidget( "ModdedWarning" ) );
		m_HintPanel					= new UiHintPanel(layoutRoot.FindAnyWidget( "hint_frame" ));
		m_ServerInfoPanel 			= layoutRoot.FindAnyWidget( "server_info" );
		m_ServerIP 					= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_ip" ) );
		m_ServerPort 				= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_port" ) );
		m_ServerName 				= TextWidget.Cast( layoutRoot.FindAnyWidget( "server_name" ) );
		m_FavoriteImage 			= layoutRoot.FindAnyWidget( "favorite_image" );
		m_UnfavoriteImage 			= layoutRoot.FindAnyWidget( "unfavorite_image" );
		m_CopyInfoButton 			= layoutRoot.FindAnyWidget( "copy_button" );
		
		HudShow( false );
		return layoutRoot;
	}
	
	// If you want to change the way the buttons work.  
	// Visit the Colorful.MainMenu.c file. It has notes.
	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.BrandColor()); 
	};

}
