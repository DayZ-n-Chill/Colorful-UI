class CfgPatches
{
	class COLORFUL_UI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "JMC_DeerIsle_Scripts"};
		// NOTE: Use the example below to have the UI work on Deer Isle
		// EXAMPLE: requiredAddons[] = {"DZ_Data", "JMC_DeerIsle_Scripts" };
	};
};

class CfgMods
{
	class COLORFUL_UI
	{
		dir = "Colorful-UI";
		hideName = 1;
		hidePicture = 1;
		name = "DayZ n' Chill's Colorful UI";
		credits = "DayZ n' Chill";
		author = "DayZ n' Chill";
		authorID = "76561197969255905";
		version = "0.2";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Colorful-UI/scripts/3_Game"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Colorful-UI/scripts/5_Mission"};
			};
		};
	};
	class CfgFontFamilies
	{
		class PersonalServiceB
		{
			fonts[] = {"Colorful-UI/gui/fonts/PersonalServices.fnt"};
		};
	};
};
