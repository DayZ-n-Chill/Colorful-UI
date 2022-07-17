modded class ServerBrowserEntry extends ScriptedWidgetEventHandler
{
	void Select( bool notify = true )
	{
		if( !m_Selected )
		{
			if( notify )
			{
				m_Tab.SelectServer( this );
			}
			
			m_ServerData.m_IsSelected = true;
			m_Selected = true;
			m_ServerName.SetColor(colorScheme.BrandColor());
		}
	}
	
	void Deselect()
	{
		if( m_Selected )
		{
			m_ServerData.m_IsSelected = false;
			
			m_Selected = false;
			float alpha = 0.1;
			if( m_Index % 2 )
			{
				alpha = 0.3;
			}
			m_Root.SetColor( ARGB( alpha, 50, 50, 50 ) );
			m_ServerName.SetColor( ARGB( 255, 255, 255, 255 ) );
			
			Lighten( m_Root, null, 0, 0 );
		}
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void Darken( Widget w, int x, int y )
	{
		if( m_Selected )
			return;
		
		if( w == m_Root || w == m_Favorite || w == m_Expand )
		{
			m_Root.SetColor( ARGB( 255, 0, 0, 0) );
			m_Root.SetAlpha( 1 );
			m_ServerName.SetColor( ARGB( 255, 255, 255, 255 ) );
		}
	}
	
	//Coloring functions (Until WidgetStyles are useful)
	void Preview( Widget w, int x, int y )
	{		
		if( m_Selected )
			return;
		
		if( w == m_Root || w == m_Favorite || w == m_Expand )
		{
			m_Root.SetColor( ARGB( 100, 0, 0, 0) );
			m_Root.SetAlpha( 1 );
			m_ServerName.SetColor(colorScheme.BrandColor());
		}
	}
	
	void Lighten( Widget w, Widget enterW, int x, int y )
	{
		if( GetFocus() == w || m_Selected )
		{
			return;
		}
		
		if( w == m_Root && ( ( m_Favorite && enterW == m_Favorite ) || ( m_Expand && enterW == m_Expand ) ) )
		{
			return;
		}
		
		m_Root.SetColor( ARGB( 100, 0, 0, 0) );
		m_ServerName.SetColor( ARGB( 255, 255, 255, 255 ) );
		UpdateColors();
	}
}
