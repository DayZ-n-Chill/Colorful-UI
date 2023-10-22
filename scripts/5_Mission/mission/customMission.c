// class CustomMission: MissionServer
// {
//     super.OnInit();
//     override void OnInit()
//     {
//         if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
//         {
//             GetGame().GetUIManager().EnterScriptedMenu(MENU_MAIN, NULL);
//         }
//         else
//         {
//             super.OnInit();
//         }
//     }
// };

// class colorful_server_info
// {
// 	private	string	m_ServerName	=	"";
// 	private	string	m_IP			=	"0.0.0.0";
// 	private	int		m_Port			=	0;
	
// 	void colorful_server_info( string v_ServerName, string v_IP, int v_Port)
// 	{
// 		m_ServerName	=	v_ServerName;
// 		m_IP			=	v_IP;
// 		m_Port			=	v_Port;
// 	}
	
// 	string GetServerName()
// 	{
// 		return m_ServerName;
// 	}

// 	string GetIP()
// 	{
// 		return m_IP;
// 	}
	
// 	int GetPort()
// 	{
// 		return m_Port;
// 	}
// }