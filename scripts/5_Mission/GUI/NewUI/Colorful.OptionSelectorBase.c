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
		
		int color_pnl = colorScheme.ButtonHoverColor();
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
}