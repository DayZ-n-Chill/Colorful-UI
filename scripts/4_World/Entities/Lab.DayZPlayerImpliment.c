// modded class DayZPlayerImplement extends DayZPlayer 
// {
//     override void ShowDeadScreen(bool show, float duration)
// 	{
// 		// #ifdef PLATFORM_PS4
// 		// OnlineServices.SetMultiplayState(false);
// 		// #endif		
		
// 		#ifndef NO_GUI
// 		if (show && IsPlayerSelected())
// 		{
// 			string message = "";
// 			if (!GetGame().GetMission().IsPlayerRespawning())
// 			{
// 				message = "You Died Cunty McCunterson!";
//                 // Add Randmom Message Function Here
// 			}

// 			// #ifdef PLATFORM_CONSOLE
// 			// GetGame().GetUIManager().ScreenFadeIn(duration, message, FadeColors.DARK_RED, FadeColors.WHITE);
// 			// #else
// 			GetGame().GetUIManager().ScreenFadeIn(duration, message, FadeColors.BLACK, FadeColors.WHITE);
//             //added
//             GetGame().GetUIManager().CloseAll();
//             GetGame().GetUIManager().EnterScriptedMenu(MENU_INGAME, null);     
// 			// #endif
// 		}
// 		else
// 		{
// 			GetGame().GetUIManager().ScreenFadeOut(duration);
// 			if (duration > 0)
// 				GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(StopDeathDarkeningEffect, duration*1000, false);
//                 m_ShowDeadScreen = true;
// 			else
// 				GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(StopDeathDarkeningEffect);
//                 m_ShowDeadScreen = false;
// 		}
// 		#endif
// 	}
// }

modded class DayZPlayerImplement extends DayZPlayer 
{

    override void ShowDeadScreen(bool show, float duration)
    {    
        #ifndef NO_GUI
            if ( show && IsPlayerSelected() )
            {
                GetGame().GetUIManager().ScreenFadeIn( duration, "", FadeColors.BLACK, FadeColors.WHITE );
                GetGame().GetUIManager().CloseAll();
                GetGame().GetUIManager().EnterScriptedMenu(MENU_INGAME, null);            
            }
            else
            {
                GetGame().GetUIManager().ScreenFadeOut(0);
            }
            
            if (duration > 0)
            {
                GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLater( StopDeathDarkeningEffect, duration*1000, false );
                m_ShowDeadScreen = true;
            }
            else
            {
                GetGame().GetCallQueue( CALL_CATEGORY_GUI ).Call( StopDeathDarkeningEffect );
                m_ShowDeadScreen = false;
            }
        #endif
    }
};