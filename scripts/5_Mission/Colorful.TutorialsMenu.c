modded class TutorialsMenu extends UIScriptedMenu
{
	override Widget Init()
	{
		#ifdef PLATFORM_CONSOLE
		layoutRoot	= GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/tutorials/xbox/tutorials.layout");
		#else
		layoutRoot	= GetGame().GetWorkspace().CreateWidgets("gui/layouts/new_ui/tutorials/pc/tutorials.layout");
		#endif
		
		m_InfoTextLeft	= layoutRoot.FindAnyWidget("InfoTextLeft");
		m_InfoTextRight	= layoutRoot.FindAnyWidget("InfoTextRight");
		
		m_Back			= ButtonWidget.Cast(layoutRoot.FindAnyWidget("back"));
		
		layoutRoot.FindAnyWidget("Tabber").GetScript(m_TabScript);
		m_TabScript.m_OnTabSwitch.Insert(DrawConnectingLines);
		
		#ifdef PLATFORM_CONSOLE
		if (GetGame().GetInput().IsEnabledMouseAndKeyboard())
		{
			m_KeybindsTab = new TutorialKeybinds(layoutRoot.FindAnyWidget("Tab_6"), this);
			m_TabScript.EnableTabControl(6, true);
		}
		#endif
		
		m_tab_images[0] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MovementTabBackdropImageWidget"));
		m_tab_images[1] = ImageWidget.Cast(layoutRoot.FindAnyWidget("WeaponsAndActionsBackdropImageWidget"));
		m_tab_images[2] = ImageWidget.Cast(layoutRoot.FindAnyWidget("InventoryTabBackdropImageWidget"));
		m_tab_images[3] = ImageWidget.Cast(layoutRoot.FindAnyWidget("MenusTabBackdropImageWidget"));
		
		#ifdef PLATFORM_CONSOLE
		UpdateControlsElements();
		#endif
		
		PPERequesterBank.GetRequester(PPERequester_TutorialMenu).Start(new Param1<float>(0.6));
		DrawConnectingLines(0);
		return layoutRoot;
	}
	
	
	//Coloring functions (Until WidgetStyles are useful)
	void ColorHighlight( Widget w )
	{
		if( !w )
			return;
		
		//SetFocus( w );
		
		int color_pnl = UIColor.Transparent();
		int color_lbl = colorScheme.Primarycolor();
		int color_img = ARGB(255, 200, 0, 0);
			
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
	
	void ColorNormal( Widget w )
	{
		if( !w )
			return;
		
		int color_pnl = ARGB(0, 0, 0, 0);
		int color_lbl = ARGB(255, 255, 255, 255);
		int color_img = ARGB(255, 255, 255, 255);
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	}
	
	// void ButtonSetText( Widget w, string text )
	// {
	// 	if( !w )
	// 		return;
				
	// 	TextWidget label = TextWidget.Cast(w.FindWidget( w.GetName() + "_label" ) );
		
	// 	if( label )
	// 	{
	// 		label.SetText( text );
	// 	}
		
	// }
	
	// void ButtonSetColor( Widget w, int color )
	// {
	// 	if( !w )
	// 		return;
		
	// 	Widget panel = w.FindWidget( w.GetName() + "_panel" );
		
	// 	if( panel )
	// 	{
	// 		panel.SetColor( color );
	// 	}
	// }
	
	// void ImagenSetColor( Widget w, int color )
	// {
	// 	if( !w )
	// 		return;
		
	// 	Widget panel = w.FindWidget( w.GetName() + "_image" );
		
	// 	if( panel )
	// 	{
	// 		panel.SetColor( color );
	// 	}
	// }
	
	// void ButtonSetTextColor( Widget w, int color )
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
	
	// protected void UpdateControlsElements()
	// {
	// 	RichTextWidget toolbar_b	= RichTextWidget.Cast(layoutRoot.FindAnyWidget("BackIcon"));
	// 	RichTextWidget toolbar_b2	= RichTextWidget.Cast(layoutRoot.FindAnyWidget("BackIcon0"));
	// 	toolbar_b.SetText(InputUtils.GetRichtextButtonIconFromInputAction("UAUIBack", "", EUAINPUT_DEVICE_CONTROLLER, InputUtils.ICON_SCALE_TOOLBAR));
	// 	toolbar_b2.SetText(InputUtils.GetRichtextButtonIconFromInputAction("UAUIBack", "", EUAINPUT_DEVICE_CONTROLLER, InputUtils.ICON_SCALE_TOOLBAR));
	// }
}
