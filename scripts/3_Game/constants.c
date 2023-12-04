static bool m_ShowDeathScreen = false;

string GetRandomBackground()
{
	const string images[] = {
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-1.edds", 
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-2.edds",
        "Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-3.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-4.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-5.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-6.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-7.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-UI-BG-8.edds"
	};
	const int IMAGES_COUNT = 8;
	int bgIndex = Math.RandomInt(0, IMAGES_COUNT - 1);
	return images[bgIndex];
}

class MenuURLS {

	static string urlDiscord  = "https://discord.gg/dayzthelab";
	static string urlFacebook = "#";
	static string urlTwitter  = "#";
	static string urlReddit   = "#";
	static string urlYoutube  = "https://www.youtube.com/@Nezar";
	static string urlWebsite  = "https://discord.gg/dayzthelab"; 
	static string urlPriorityQ   = "https://discord.gg/dayzthelab";
	static string urlCustom   = "#";
	static string urlBattleMetrics   = "https://www.battlemetrics.com/servers/dayz/21537246";
}

string GetRandomHint()
{
	const string tips[] = {
		"In the aftermath of the USSR's collapse, shadows of a new world emerged.",
		"Atlas Industries rose in the chaos, shaping the fate of Chernarus.",
		"Chernarus, scarred by civil war in 2009, faced an unforeseen epidemic.",
		"Cancer cases soared, affecting both young and old.",
		"Atlas and Chernarussian government collaborated to combat the crisis.",
		"In 2013, the northern reaches became Atlas' enigmatic headquarters.",
		"Scientific experiments took a dark turn, altering the course of history.",
		"A hidden project re-emerged, its purpose far more sinister than before.",
		"Survivors navigate a world tainted by the remnants of Atlas' ambitions.",
		"The threat of infection looms, an unintended consequence of past actions.",
		"Towns fall one by one as the aftermath of Atlas' experiments unfolds.",
		"Chernarus, once familiar, now a landscape haunted by the ghosts of the past.",
		"Moral choices shape alliances in a world governed by survival instincts.",
		"The infected roam, a constant reminder of humanity's darker tendencies.",
		"Resources dwindle as survivors face the aftermath of Atlas' legacy.",
		"Hidden secrets within Atlas' labs hold both danger and potential salvation.",
		"Echoes of the past reverberate through the ruins of once-thriving cities.",
		"Survivors grapple with the blurred lines between friend and foe.",
		"Atlas' experiments unleashed horrors that now roam the wastelands.",
		"In the post-apocalyptic chaos, whispers of a cure become a beacon of hope.",
		"Factions rise, each with their own motives in the struggle for survival.",
		"The infected, once human, now part of a relentless force.",
		"Atlas' downfall warns of the consequences of tampering with the unknown.",
		"Trust becomes a rare commodity as survivors navigate the ruins.",
		"The shattered remnants of civilization hold the key to a new beginning.",
		"In the heart of darkness, remnants of Atlas pose both threat and opportunity.",
		"The world crumbled, and survivors seek answers in the remnants of Atlas.",
		"Atlas' experiments pushed the limits of science, leaving a legacy of fear.",
		"Chernarus, a nation transformed, now faces the consequences of ambition.",
		"As the infected grow in number, survivors face an uphill battle for survival.",
		"The legacy shapes the struggle for dominance in the wasteland.",
		"In the fog of war, alliances shift and crumble in the fight for resources.",
		"The infected exhibit terrifying resilience, challenging the survivors' mettle.",
		"Atlas' underground labs remain as cryptic puzzles waiting to be unraveled.",
		"Whispers of the past guide survivors through the uncertain present.",
		"Survivors grapple with the consequences of Atlas' experiments on the world.",
		"Atlas' dark legacy is a constant reminder in the midst of the wasteland.",
		"In the search for answers, survivors uncover the mysteries within Northern Chernarus.",
		"The aftermath of Atlas' actions shapes the survivors' journey through chaos.",
		"In the struggle for survival, remnants of Atlas pose a constant threat.",
		"The infected, driven by the unknown, exhibit an eerie tenacity.",
		"Atlas' experiments blur the line between science and madness in Chernarus.",
		"As the world crumbles, survivors must confront the sins of the past.",
		"The ruins tell tales of a Chernarus forever changed by Atlas' ambitions.",
		"Echoes of Atlas' experiments linger in the silent corners of the wasteland.",
		"Moral dilemmas shape the survivors' journey through a world undone.",
		"Atlas' downfall becomes a cautionary tale in the survivors' struggle.",
		"Chernarus, once a nation, now a canvas painted with the aftermath.",
		"Remnants pose a constant threat in the wasteland.",
		"Atlas' experiments forge a path through the dark corridors of Northern Chernarus."
	};
	Math.Randomize(-1);
	int tipIndex = Math.RandomInt(0, 100) % 48;
	return tips[tipIndex];
}

class UIColor
{
	// GreyScale
	static int White()                { return ARGB(255, 255, 255, 255); };
	static int Grey()                 { return ARGB(255, 130, 130, 130); };
	static int Black()                { return ARGB(255, 0, 0, 0); };
	static int Transparent()          { return ARGB(1, 0, 0, 0); };
	static int SemiTransparentWhite() { return ARGB(120, 255, 255, 255); };
	
	// R.O.Y.G.B.I.V
	static int Red()    			  { return ARGB(255, 173, 35, 35); };
	static int Orange() 			  { return ARGB(255, 215, 153, 19); };
	static int Yellow() 			  { return ARGB(255, 204, 204, 66); };
	static int Green()  			  { return ARGB(255, 51, 204, 51); };
	static int Blue()   			  { return ARGB(255, 51, 102, 102); };
	static int Indigo() 			  { return ARGB(255, 102, 51, 204); };
	static int Violet() 			  { return ARGB(255, 204, 51, 204); };
	
	// Social Network Colors 
	static int discord() 			  { return ARGB(255, 88, 101, 242); };
	static int twitter() 			  { return ARGB(255, 29, 161, 242); };
	static int youtube() 			  { return ARGB(255, 255, 0, 0); };
	static int reddit()               { return ARGB(255, 255, 69, 0); };
	static int meta()                 { return ARGB(255, 24, 119, 242); };
	
	// Custom Colors (Use to add your own branding colors)
	static int Teal()                 { return ARGB(255, 0, 102, 102); };
	static int DPGPurple()            { return ARGB(255, 72, 27, 159); };
	static int TLBlue()           	  { return ARGB(255, 17, 146, 211);};
}

class colorScheme 
{

	static int BrandColor() 		{ return UIColor.TLBlue();};
	static int AccentColor()  		{ return ARGB(255, 255, 204, 102);};
	static int PrimaryText()        { return UIColor.White(); }; 	
	static int SecondaryText()      { return AccentColor(); };
	static int ShaderColor()        { return BrandColor(); };
	static int SeparatorColor()     { return BrandColor(); };
	static int LoadingbarColor()    { return BrandColor(); };
	static int MainMenuTrim()       { return BrandColor(); };
	static int ButtonHoverColor()   { return BrandColor(); };	
	static int TabHoverColor()      { return BrandColor(); };	
	static int OptionInputColors()  { return BrandColor(); };
	static int OptionCaretColors()  { return BrandColor(); };
	static int OptionSliderColors() { return BrandColor(); };
}
 
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;
