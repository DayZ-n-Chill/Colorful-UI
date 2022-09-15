class CfgPatches
{
	class COLORFUL_UI
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
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
		credits = "DayZ n' Chill, Combat Log code provided by server owner.";
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
			class worldScriptModule
			{
				value = "";
				files[] = {"Colorful-UI/scripts/4_World"};
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
		class PersonalServices
		{
			fonts[] = {"Colorful-UI/gui/fonts/PersonalServices.fnt"};
		};
		class OpenSansV
		{
			fonts[] = {"Colorful-UI/gui/fonts/OpenSansV.fnt"};
		};
		class OpenSansVItalic
		{
			fonts[] = {"Colorful-UI/gui/fonts/OpenSansV-Italic.fnt"};
		};
		class Roboto
		{
			fonts[] = {"Colorful-UI/gui/fonts/Roboto-Regular.fnt"};
		};
	};
};
