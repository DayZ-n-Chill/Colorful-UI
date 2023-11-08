modded class UiHintPanel extends ScriptedWidgetEventHandler
{	
	protected int 			m_SlideShowDelay			= 25000;											// The speed of the slideshow 
	protected string 				m_RootPath			= "Colorful-UI/gui/layouts/new_ui/hints/in_game_hints.layout";	// Layout path 
	protected const string 			m_DataPath			= "Colorful-UI/Scripts/data/hints.json";						// Json path
}

// ---------------------------------------------------------------------------------------------------------
modded class UiHintPanelLoading extends UiHintPanel
{
	override void Init(DayZGame game)
	{
		m_RootPath = "Colorful-UI/gui/layouts/new_ui/hints/in_game_hints_load.layout";
		super.Init(game);
	}
}
