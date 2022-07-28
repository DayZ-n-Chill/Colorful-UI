modded class ServerBrowserMenuNew extends UIScriptedMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "Colorful-UI/gui/layouts/new_ui/server_browser/pc/colorful.server_browser.layout" );
		m_OfficialTab	= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_0" ), this, TabType.OFFICIAL );
		m_CommunityTab	= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_1" ), this, TabType.COMMUNITY );
		m_LANTab		= new ServerBrowserTabPc( layoutRoot.FindAnyWidget( "Tab_2" ), this, TabType.LAN );
		
		layoutRoot.FindAnyWidget( "Tabber" ).GetScript( m_Tabber );
		
		m_Play					= layoutRoot.FindAnyWidget( "play" );
		m_Back					= layoutRoot.FindAnyWidget( "back_button" );
		m_CustomizeCharacter	= layoutRoot.FindAnyWidget( "customize_character" );
		m_PlayerName			= TextWidget.Cast( layoutRoot.FindAnyWidget( "character_name_text" ) );
		m_Version				= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		
		Refresh();
		
		string version;
		GetGame().GetVersion( version );

		OnlineServices.m_ServersAsyncInvoker.Insert( OnLoadServersAsync );
		OnlineServices.m_ServerModLoadAsyncInvoker.Insert( OnLoadServerModsAsync );
		m_Tabber.m_OnTabSwitch.Insert( OnTabSwitch );
				
		m_OfficialTab.RefreshList();
		
		return layoutRoot;
	}

	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Black();
		int color_lbl = colorScheme.BrandColor();
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
	}
}