modded class KeybindingElement extends ScriptedWidgetEventHandler
{
	override bool OnMouseEnter( Widget w, int x, int y )
	{
		if( w == m_PrimaryBindButton || w == m_PrimaryClear )
		{
			m_PrimaryBindButton.SetColor(colorScheme.BrandColor());
			m_PrimaryClear.Show( true );
			m_PrimaryClear.Update();
			m_AlternativeClear.Show( false );
			return true;
		}
		else if( w == m_AlternativeBindButton || w == m_AlternativeClear )
		{
			m_AlternativeBindButton.SetColor(colorScheme.BrandColor());
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( true );
			m_AlternativeClear.Update();
			return true;
		}
		else
		{
			m_PrimaryBindButton.SetColor( UIColor.Transparent() );
			m_AlternativeBindButton.SetColor( UIColor.Transparent() );
			m_PrimaryClear.Show( false );
			m_AlternativeClear.Show( false );
		}
		return false;
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		if( w == m_PrimaryClear || w == m_PrimaryBindButton )
		{
			if( enterW != m_PrimaryClear && enterW != m_PrimaryBindButton )
			{
				m_PrimaryClear.Show( false );
				m_PrimaryBindButton.SetColor(  UIColor.Transparent() );
			}
		}
		if( w == m_AlternativeClear || w == m_AlternativeBindButton )
		{
			if( enterW != m_AlternativeClear && enterW != m_AlternativeBindButton )
			{
				m_AlternativeClear.Show( false );
				m_AlternativeBindButton.SetColor( UIColor.Transparent() );
			}
		}
		return false;
	}
}

