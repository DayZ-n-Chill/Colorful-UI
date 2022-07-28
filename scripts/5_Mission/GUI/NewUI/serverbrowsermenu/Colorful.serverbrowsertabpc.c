modded class ServerBrowserTabPc extends ServerBrowserTab
{
	override void SetSort( ESortType type, ESortOrder order )
	{
		//Print("m_SortType: "+ type +" m_SortOrder: "+ order +" m_SortInverted[type]: "+ m_SortInverted[type]);
		super.SetSort( type, order);
		
		#ifdef PLATFORM_WINDOWS
		m_Root.FindAnyWidget( "host_sort" ).Show( false );
		m_Root.FindAnyWidget( "population_sort" ).Show( false );
		m_Root.FindAnyWidget( "slots_sort" ).Show( false );
		
		m_Root.FindAnyWidget( "time_sort" ).Show( false );
		m_Root.FindAnyWidget( "ping_sort" ).Show( false );
		
		TextWidget root;
		root = TextWidget.Cast( m_Root.FindAnyWidget( "server_list_content_header_host_label" ) );
		root.SetColor( colorScheme.PrimaryText() );
		root = TextWidget.Cast( m_Root.FindAnyWidget( "server_list_content_header_population_label" ) );
		root.SetColor( colorScheme.PrimaryText() );
		root = TextWidget.Cast( m_Root.FindAnyWidget( "server_list_content_header_slots_label" ) );
		root.SetColor( colorScheme.PrimaryText() );
		
		root = TextWidget.Cast( m_Root.FindAnyWidget( "server_list_content_header_ping_label" ) );
		root.SetColor( colorScheme.PrimaryText() );
		root = TextWidget.Cast( m_Root.FindAnyWidget( "server_list_content_header_time_label" ) );
		root.SetColor( colorScheme.PrimaryText() );
		
		string r_name;
		string w_name;
		
		switch( type )
		{
			case ESortType.HOST:
			{
				r_name = "server_list_content_header_host_label";
				w_name = "host_sort";
				break;
			}
			case ESortType.TIME:
			{
				r_name = "server_list_content_header_time_label";
				w_name = "time_sort";
				break;
			}
			case ESortType.POPULATION:
			{
				r_name = "server_list_content_header_population_label";
				w_name = "population_sort";
				break;
			}
			case ESortType.SLOTS:
			{
				r_name = "server_list_content_header_slots_label";
				w_name = "slots_sort";
				break;
			}
			case ESortType.PING:
			{
				r_name = "server_list_content_header_ping_label";
				w_name = "ping_sort";
				break;
			}
		}
		
		root = TextWidget.Cast( m_Root.FindAnyWidget( r_name ) );
		root.SetColor(colorScheme.BrandColor());
		
		m_Root.FindAnyWidget( w_name ).Show( true );
		m_Root.FindAnyWidget( w_name + "_asc" ).Show( !m_SortOrder );
		m_Root.FindAnyWidget( w_name + "_dsc" ).Show( m_SortOrder );		
		#endif
	}
}