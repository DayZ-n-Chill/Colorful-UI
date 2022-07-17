modded class ServerBrowserTab extends ScriptedWidgetEventHandler
{
	void ColorHighlight( Widget w )
	{
		if( w.IsInherited( ButtonWidget ) )
		{
			ButtonWidget button = ButtonWidget.Cast( w );
			button.SetTextColor(colorScheme.BrandColor());
		}
		
		w.SetColor( UIColor.Black() );
		
		TextWidget text1	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
		TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
		TextWidget text3	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		ImageWidget image	= ImageWidget.Cast( w.FindAnyWidget( w.GetName() + "_image" ) );
		Widget option		= Widget.Cast( w.FindAnyWidget( w.GetName() + "_option_wrapper" ) );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if( text1 )
		{
			text1.SetColor(colorScheme.BrandColor());
		}
		
		if( text2 )
		{
			text2.SetColor(colorScheme.BrandColor());
		}
		
		if( text3 )
		{
			text3.SetColor(colorScheme.BrandColor());
			w.SetAlpha(1);
		}
		
		if( image )
		{
			image.SetColor(colorScheme.BrandColor());
		}
		
		if ( option )
		{
			option.SetColor(colorScheme.BrandColor());
		}
		
		if ( option_label )
		{
			option_label.SetColor(colorScheme.BrandColor());
		}
	}
}