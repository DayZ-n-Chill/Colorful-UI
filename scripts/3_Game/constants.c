// This Constants Page is meant to act as a config file for the UI. 
// Make adustments as needed to this files to suit your servers needs.

// RANDOM BACKGROUND IMAGES -----------------------------------------------
string GetRandomBackground()
{
	const string images[] = {
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-1.edds", 
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-2.edds",
        "Colorful-UI/gui/textures/loading_screens/Colorful-BG-3.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-4.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-5.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-6.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-7.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-8.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-9.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-10.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-11.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-12.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-13.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-14.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-15.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-16.edds",
		"Colorful-UI/gui/textures/loading_screens/Colorful-BG-17.edds"
	};
	Math.Randomize(-1);
	int bgIndex = Math.RandomInt(0, 100) % 17;
	return images[bgIndex];
}

// RANDOM LOADSCREEN TIPS -------------------------------------------------
string GetRandomHint()
{
	const string tips[] = {
		"Death makes you die.",
		"Broomsticks give you enough resources to make a fire place and cooking stand.",
		"Keep your car running smoothby using min 4 water bottles to fill the radioator.",
		"You can crafrt a bone knife with one bone if you use rocks or boulders to craft it.",
		"Try to blend in with your enviornment. Do not wear bright colors",
		"If someone is harrassing you contact a server admin immediately",
		"Non aggro infected will detect you in 2 seconds when sneaking up on them. Stealth kill them quick",
		"Craft foot wraps to dampen the sound of your movement.",
		"Breaking down ghillie parts you find is a faster way to get all the parts you need to make a full one.",
		"Baking food provides the most nutritional value when cooking.",
		"The flare gun can not kill anything in the game but yourself.",
		"Armor Peircing rounds do not do extra damage, they just reduce the durability of armor faster.",
		"Going unconsiousl in water will kill you in 20 seconds.",
		"Having full white stats, or taking multivitamins will allow you to eat raw meat, drink from dirty water sources, and consume with bloody hands.",
		"Apart from the Famas, all sawed off weapons have twice the ammount of recoil",
		"Any weapon with a suppressor cannot be heard after 150 meters.",
		"If you log into a dynamic gas zone you will be teleported out of the area.",
		"If you are K.O. by a gunman you will always wake up facing the opposite the direction from where you were shot. ",
		"Spike helemt only spawns at the Castle south of Sitnik on the red trail.",
		"Remebering Paulie.  Loc. 11930 x 13157 - R.I.P"
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
	static int Teal()                 { return ARGB(255, 0, 102, 102); };
	static int DPGPurple()            { return ARGB(255, 72, 27, 159); };
}

// DEFINE YOUR THEME -------------------------------------------------------
// You can use the fucntions above to set the theme across the entire app.
class colorScheme 
{
	// Quick Styling --------------------------------------
	// This color should be Servers/Communities Brand Color
	static int BrandColor()   { return UIColor.Teal(); };
	// This color should be a complimentary color to your brand. 
	static int AccentColor()  { return UIColor.Red(); }

	// Advanced Styling --------------------------------------
	// You can get more Ganular with the colors by editing the syltes below
	// Get wild and create your own color functions and use them throughout the mod.
	// Best to Primary Text as white, but do whatever, Experiment.
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
 
// Dialog Menus (No need to touch)
const int COLORFUL_EXIT				= 666;
const int COLORFUL_CONFIGURE 		= 667;
const int COLORFUL_DEFAULTS 		= 668;