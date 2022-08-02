modded class OptionSelectorEditbox extends OptionSelectorBase
{
	// protected EditBoxWidget			m_EditBox;
	
	// void OptionSelectorEditbox( Widget parent, string value, ScriptedWidgetEventHandler parent_menu, bool disabled )
	// {
	// 	m_Root					= GetGame().GetWorkspace().CreateWidgets( "gui/layouts/new_ui/option_editbox.layout", parent );
	// 	#ifdef PLATFORM_CONSOLE
	// 		m_Parent				= parent.GetParent().GetParent();
	// 	#else
	// 	#ifdef PLATFORM_WINDOWS
	// 		m_Parent				= parent.GetParent();
	// 	#endif
	// 	#endif
		
	// 	m_SelectorType				= 1;
	// 	m_ParentClass				= parent_menu;
	// 	m_EditBox					= EditBoxWidget.Cast( m_Root.FindAnyWidget( "option_value" ) );
		
	// 	SetValue( value );
	// 	Enable();
		
	// 	m_Parent.SetHandler( this );
	// }
	
	
	override void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		if ( m_EditBox )
		{
			SetFocus( m_EditBox );
			m_EditBox.SetColor( colorScheme.BrandColor() );
		}
		
		super.ColorHighlight( w );
	}
	
	override void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		if ( m_EditBox )
		{
			m_EditBox.SetColor( UIColor.SemiTransparentWhite() );
		}
		
		super.ColorNormal( w );
	}
}