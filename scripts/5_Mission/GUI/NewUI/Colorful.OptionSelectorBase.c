modded class OptionSelectorBase extends ScriptedWidgetEventHandler
{	
	
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
				
		ButtonSetColor(w, colorScheme.BrandColor());
	}
	
	void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.White();
		int color_lbl = UIColor.White();
		
		ButtonSetColor(w, color_pnl);
		
		Widget title_label = w.FindAnyWidget( w.GetName() + "_label" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( title_label )
		{
			title_label.SetColor( color_lbl );
		}
		
		if ( option_label )
		{
			option_label.SetColor( color_lbl );
		}
	}
	
	void ColorDisabled( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.White();
		
		ButtonSetColor(w, color_pnl);
		
		Widget title_label = w.FindAnyWidget( w.GetName() + "_label" );
		Widget option_label = w.FindAnyWidget( "option_label" );
		
		if ( title_label )
		{
			title_label.SetColor( color_lbl );
		}
		
		if ( option_label )
		{
			option_label.SetColor( color_lbl );
		}		
	}
	
	void ButtonSetColor( Widget w, int color )
	{
		Widget option = w.FindAnyWidget( w.GetName() + "_image" );
		
		if ( option )
		{
			option.SetColor( color );
		}
	}
	
	void ColorHighlightConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = colorScheme.BrandColor();
		int color_lbl = UIColor.White();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
	
	void ColorNormalConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.White();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
	
	void ColorDisabledConsole( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = UIColor.SemiTransparentWhite();
		
		ButtonSetColorConsole(w, color_pnl);
		ButtonSetAlphaAnimConsole( null );
		ButtonSetTextColorConsole(w, color_lbl);
	}
	
	// void ButtonSetColorConsole( Widget w, int color )
	// {
	// 	w.SetColor( color );
	// }
	
	// void ButtonSetAlphaAnimConsole( Widget w )
	// {
	// 	if( !w )
	// 		return;
		
	// 	Widget panel = w.FindAnyWidget( w.GetName() + "_panel" );
		
	// 	if( panel )
	// 	{
	// 		//m_Root.SetWidgetAnimAlpha( panel );
	// 	}
	// }
	
	// void ButtonSetTextColorConsole( Widget w, int color )
	// {
	// 	if( !w )
	// 		return;

	// 	TextWidget label	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_label" ) );
	// 	TextWidget text		= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text" ) );
	// 	TextWidget text2	= TextWidget.Cast(w.FindAnyWidget( w.GetName() + "_text_1" ) );
		
	// 	if( label )
	// 	{
	// 		label.SetColor( color );
	// 	}
		
	// 	if( text )
	// 	{
	// 		text.SetColor( color );
	// 	}
		
	// 	if( text2 )
	// 	{
	// 		text2.SetColor( color );
	// 	}
	// }
}