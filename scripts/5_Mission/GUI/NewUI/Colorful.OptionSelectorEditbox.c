modded class OptionSelectorEditbox extends OptionSelectorBase
{
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