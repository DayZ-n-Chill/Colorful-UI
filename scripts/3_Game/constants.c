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
	int bgIndex = Math.RandomInt(0,16);
	return images[bgIndex];
}

// RANDOM LOADSCREEN TIPS -------------------------------------------------
string GetRandomHint()
{
	const string tips[] = {
		"TIP: This is Tip 1.  You can change me in the constants.c file",
		"TIP: This is Tip 2.  You can change me in the constants.c file",
		"TIP: This is Tip 3.  You can change me in the constants.c file",
		"TIP: This is Tip 4.  You can change me in the constants.c file",
		"TIP: This is Tip 5.  You can change me in the constants.c file",
		"TIP: This is Tip 6.  You can change me in the constants.c file",
		"TIP: This is Tip 7.  You can change me in the constants.c file",
		"TIP: This is Tip 8.  You can change me in the constants.c file",
		"TIP: This is Tip 9.  You can change me in the constants.c file",
		"TIP: This is Tip 10.  You can change me in the constants.c file",
		"TIP: This is Tip 11.  You can change me in the constants.c file",
		"TIP: This is Tip 12.  You can change me in the constants.c file",
		"TIP: This is Tip 13.  You can change me in the constants.c file",
		"TIP: This is Tip 14.  You can change me in the constants.c file",
		"TIP: This is Tip 15.  You can change me in the constants.c file",
		"TIP: This is Tip 16.  You can change me in the constants.c file",
		"TIP: This is Tip 17.  You can change me in the constants.c file",
		"TIP: This is Tip 18.  You can change me in the constants.c file",
		"TIP: This is Tip 19.  You can change me in the constants.c file",
		"TIP: This is Tip 20.  You can change me in the constants.c file",
	};
	int tipIndex = Math.RandomInt(0,19);
	return tips[tipIndex];
}

// COLOR PALETTES ---------------------------------------------------------
// Use these colors to mix and match the theme of your choice.
// You can add to it, remove colors from it.  Whatever you like.
class UIColor
{
	// GreyScale
	static int White() { return ARGB(255, 55, 102, 102); };
	static int Grey() { return ARGB(255, 55, 102, 102); };
	static int Black() { return ARGB(255, 55, 102, 102); };
	// R.O.Y.G.B.I.V
	static int Red() { return ARGB(255, 186, 15, 15); };
	static int Orange() { return ARGB(255, 215, 153, 19); };
	static int Yellow() { return ARGB(255, 204, 204, 66); };
	static int Green() { return ARGB(255, 51, 204, 51); };
	static int Blue() { return ARGB(255, 51, 102, 102); };
	static int Indigo() { return ARGB(255, 102, 51, 204); };
	static int Violet() { return ARGB(255, 204, 51, 204); };
	// Custom Colors
	static int Teal() { return ARGB(255, 55, 102, 102); };
}

// DEFINE YOUR THEME -------------------------------------------------------
// You can the fucntions above to set the theme across the entire app.
class colorScheme 
{
	static int PrimaryColor() { return UIColor.Teal(); };
	static int TooltipColor() { return UIColor.Blue(); };
}
