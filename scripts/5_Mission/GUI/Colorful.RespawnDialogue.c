modded class RespawnDialogue extends UIScriptedMenu
{
	private Widget m_Separator
	override Widget Init()
	{
		layoutRoot 					= GetGame().GetWorkspace().CreateWidgets("colorful-ui/gui/layouts/colorful.day_z_respawn_dialogue.layout");
		m_DetailsRoot 				= layoutRoot.FindAnyWidget( "menu_details_tooltip" );
		m_DetailsLabel				= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_label" ) );
		m_DetailsText				= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_tooltip_content" ) );
		
		m_Separator 				= layoutRoot.FindAnyWidget( "actionItems_separator" );
		m_Separator.SetColor(colorScheme.BrandColor());
		return layoutRoot;
	};
	
	protected void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		ButtonSetColor(w, UIColor.Transparent());
		ButtonSetTextColor(w, colorScheme.BrandColor()); 
	};
	
};
