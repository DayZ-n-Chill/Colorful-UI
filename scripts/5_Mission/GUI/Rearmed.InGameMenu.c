modded class InGameMenu
{
    protected TextWidget m_ExitButtonLabel;

    override Widget Init()
    {
        Widget root = super.Init();

        m_ExitButtonLabel = TextWidget.Cast( root.FindAnyWidget( "exitbtn_label" ) );

        return root;
    }

    override bool OnMouseEnter( Widget w, int x, int y )
    {
        if ( w != m_ExitButton )
        {
            ColorHighlight(w);

            return true;
        }

        PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
        if ( player && ( !player.IsInCombat() || !player.IsAlive() ) )
        {
            ColorHighlight( w );
        }

        return true;
    }

    protected override void UpdateGUI()
    {
        super.UpdateGUI();

        // Update exit button for combat log
        PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
        if ( !player )
        {
            return;
        }

        m_ExitButton.Enable( ( !player.IsInCombat() || !player.IsAlive() ) );
        if ( player.IsInCombat() && player.IsAlive() )
        {
            m_ExitButtonLabel.SetText( string.Format( "YOU ARE IN COMBAT [%1]", player.GetCombatTimer() ) );
        }
        else
        {
            m_ExitButtonLabel.SetText( "#main_menu_exit" );
        }
    }
}