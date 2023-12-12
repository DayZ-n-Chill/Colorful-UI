// This Constants Page is meant to act as a config file for the UI. 
// Make adustments as needed to this files to suit your servers needs.

// RANDOM BACKGROUND IMAGES -----------------------------------------------
string GetRandomBackground()
{
	const string images[] = {
		// "Colorful-UI/gui/textures/loading_screens/Yourscreen_1.edds",
		// "Colorful-UI/gui/textures/loading_screens/Yourscreen_2.edds",
		// "Colorful-UI/gui/textures/loading_screens/Yourscreen_3.edds",
		"Colorful-UI/gui/textures/loading_screens/WakeyBG.edds"
		
	};
	Math.Randomize(-1);
	int bgIndex = Math.RandomInt(0, 100) % 1;
	return images[bgIndex];
}

/*
 * Quick Set URL's for loading menu
 * If you don't use any of the various links, either leave them as they are or keep the string empty. 
 * If you don't want the button showing, you need to modify the layout files.
 *  - *Currently looking to find a way to hide automatically - Dean
 */
class MenuURLS {
	// Link for Discord
	static string urlDiscord  = "";
	// Link for Facebook
	static string urlFacebook = "#";
	// Link for Twitter
	static string urlTwitter  = "#";
	// Link for Reddit
	static string urlReddit   = "#";
	// Link for Youtube
	static string urlYoutube  = "#";
	// Link to Website
	static string urlWebsite  = ""; 
	// Link for Prio Q
	static string urlPriorityQ   = "#";
	// Can be used anything else
	static string urlCustom   = "#";
}

// RANDOM LOADSCREEN TIPS -------------------------------------------------
string GetRandomHint()
{
	const string tips[] = {
		"Always record your gameplay. Staff will ask for evidence regarding rule breaks/compensation.",
		"Make sure to never break character.",
		"You can directly give items to people (Default key:'H') You can rebind this in the settings.",
		"When driving a vehicle, press 'H' to clear the road!",
		"There are only two certainties in life, death and taxes.",
		"If the enemy is in range, so are you.",
		"Try to look unimportant, they may be low on ammo.",
		"Teamwork is essential, it gives them someone else to shoot at.",
		"If your attack is going well, you have walked into an ambush.",
		"All five second grenade fuses are three seconds.",
		"When driving a vehicle, press 'V' for a better view.",
		"Press 'F5' to surrender, this will save your life.",
		"Consider investing in boots, the Zone is a rough place to traverse.",
		"Screaming 'I have a bomb!' might help you, it might not.",
		"Hold 'B' to grab a bolt (make sure your hands are empty).",
		"Double-barreled shotguns can be used to fire both barrels simultaneously.",
		"If you want to move with minimal noise, press 'C' (default) to crouch or hold 'Ctrl' (default) to walk.",
		"Most weapons have several firing modes. To switch between firing modes, press 'X' (default).",
		"To turn your head torch on or off, hold 'L' (default) briefly.",
		"To quick save, press 'F5'. Press 'F9' to quick load the last quick save.",
		"If someone aims their weapon at you, refrain from pressing 'F4'.",
		"You may NEVER loot your own body after death.",
		"Reporting rule breaks is the only way to help the community remove troublemakers.",
		"Make friends, adventuring solo can be deadly.",
		"Try to find shelter during an Emission.",
		"Exploiting game mechanics will get you in trouble",
		"Have an unexplained 'hickey'? Just say a Bloodsucker did it",
		"Make sure your character name is assigned on the launcher, it's REQUIRED",
		"[Insert pro tip here]",
		"Keep your feet dry! The last thing you want is trenchfoot.",
		"Tough time never last, only tough people last"
	};
	Math.Randomize(-1);
	int tipIndex = Math.RandomInt(0, 100) % 20;
	return tips[tipIndex];
}


// NOTE: ------------------------------------------------------------------
// I used two fucntions because I wanted to be able to use colorin both
// a global way and in possible uniuqe situations. 
// There is probably a better way to do this, so suggestions are welcome. 
// Please submit a pull request to the dev branch for suggestions.
// https://github.com/DayZ-n-Chill/Colorful-UI/tree/dev


// COLOR PALETTES ---------------------------------------------------------
// Use these coloring functions to mix and match the theme of your choice.
// You can add to it, remove colors from it.  Whatever you like.

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
	static int JLK_Yellow()      { return ARGB(255, 190, 160, 40); };
	static int JLK_Orange()      { return ARGB(255, 165, 85, 0); };
	static int JLK_Yellow_2()    { return ARGB(255, 204, 153, 0); };
	static int JLK_Red()         { return ARGB(255, 105, 0, 0); };
}

// DEFINE YOUR THEME -------------------------------------------------------
// You can use the fucntions above to set the theme across the entire app.
class colorScheme 
{
	// Quick Styling --------------------------------------
	// This color should be Servers/Communities Brand Color
	static int BrandColor()   { return UIColor.JLK_Yellow(); };
	// This color should be a complimentary color to your brand. 
	static int AccentColor()  { return UIColor.JLK_Red(); };

	// Advanced Styling --------------------------------------
	// You can get more Ganular with the colors by editing the syltes below
	// Get wild and create your own color functions and use them throughout the mod.
	// Best to Primary Text as white, but do whatever, Experiment.
	static int PrimaryText()        { return UIColor.White(); }; 	
	static int SecondaryText()      { return UIColor.JLK_Orange(); };
	static int ShaderColor()        { return UIColor.JLK_Orange(); };
	static int SeparatorColor()     { return UIColor.JLK_Red(); };
	static int LoadingbarColor()    { return BrandColor(); };
	static int MainMenuTrim()       { return UIColor.JLK_Red(); };
	static int ButtonHoverColor()   { return BrandColor(); };
	static int TabHoverColor()      { return BrandColor(); };
	static int OptionInputColors()  { return BrandColor(); };
	static int OptionCaretColors()  { return BrandColor(); };
	static int OptionSliderColors() { return BrandColor(); };
}
 
// Dialog Menus (No need to touch)
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;