// modded class MissionMainMenu extends MissionBase
// {
// 	protected ref MissionMainMenu m_MissionMainMenu;
// 	override void OnInit()
// 	{	
// 		GetOnInputDeviceChanged().Insert(OnInputDeviceChanged);
// 	}
// 	override void Reset()
// 	{
// 		delete m_MissionMainMenu;
// 		m_MissionMainMenu = new MissionMainMenu();
// 	}
// 	override void CreateIntroScene() { }
// 	override void OnMissionStart()
// 	{
// 		if (!m_MissionMainMenu) {
// 			m_MissionMainMenu = new MissionMainMenu();
// 		}
// 		GetDayZGame().SetMissionState(DayZGame.MISSION_STATE_MAINMENU);
// 		GetDayZGame().SetGameState(DayZGameState.MAIN_MENU);
// 		GetDayZGame().SetLoadState(DayZLoadState.MAIN_MENU_START);	
// 		ProgressAsync.DestroyAllPendingProgresses();	
// 		PlayMusic();
// 	}
// 	override void OnMissionFinish()
// 	{
// 		delete m_MissionMainMenu;
// 	}
// 	override void OnUpdate(float timeslice) { }
// }
