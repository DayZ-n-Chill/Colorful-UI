modded class WarningMenuBase extends UIScriptedMenu
{
    private Widget m_Separator1
	private	Widget m_shader

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("Colorful_UI/gui/layouts/Colorful.day_z_dropped_items.layout");
		string text = GetText();
		if(text)
		{
			MultilineTextWidget w = MultilineTextWidget.Cast(layoutRoot.FindAnyWidget("Text"));
			if(w)
				w.SetText(text);
		}
        m_Separator1 = layoutRoot.FindAnyWidget( "SeparatorPanel" );
        m_Separator1.SetColor(colorScheme.BrandColor());
		Class.CastTo(m_shader, layoutRoot.FindAnyWidget("Colorful_Shader"));
		m_shader.SetColor(colorScheme.BrandColor());
        
		return layoutRoot;
	}
}