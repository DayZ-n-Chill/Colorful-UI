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

/*
 * Quick Set URL's for loading menu
 * If you don't use any of the various links, either leave them as they are or keep the string empty. 
 * If you don't want the button showing, you need to modify the layout files.
 *  - *Currently looking to find a way to hide automatically - Dean
 */
class MenuURLS {
	// Link for Discord
	static string urlDiscord  = "https://discord.gg/dayznchill";
	// Link for Facebook
	static string urlFacebook = "https://facebook.com/dayznchill";
	// Link for Twitter
	static string urlTwitter  = "https://twitter.com/dayznchill";
	// Link for Reddit
	static string urlReddit   = "https://reddit.com/dayznchill";
	// Link for Youtube
	static string urlYoutube  = "https://youtube.com/dayznchill";
	// Link to Website
	static string urlWebsite  = "https://dayznchill.com"; 
	// Link for Prio Q
	static string urlPriorityQ   = "#";
	// Can be used anything else
	static string urlCustom   = "#";
}

// RANDOM LOADSCREEN TIPS -------------------------------------------------
string GetRandomHint()
{
	const string tips[] = {
		"Смерть заставляет тебя умереть.",
		"Мётлы дают вам достаточно ресурсов, чтобы построить камин и подставку для приготовления пищи.",
		"Чтобы ваша машина работала бесперебойно, используйте минимум 4 бутылки с водой для заполнения радиатора",
		"Вы можете изготовить костяной нож из одной кости, если для его изготовления используете камни или валуны.",
		"Постарайтесь гармонировать с окружающей средой. Не носите яркие цвета",
		"Если кто-то вас беспокоит, немедленно свяжитесь с администратором сервера",
		"Неагрессивные зараженные обнаружат вас через 2 секунды, когда вы подкрадетесь к ним. Скрытность убьет их быстро",
		"Сделайте бинты для ног, чтобы заглушить звук ваших движений.",
		"Разобрать найденные части маскировочного костюма — это более быстрый способ получить все детали, необходимые для создания целого маскировочного костюма",
		"Выпечка продуктов обеспечивает наибольшую пищевую ценность при приготовлении",
		"Ракетница не может убить в игре никого, кроме вас самих.",
		"Бронебойные патроны не наносят дополнительного урона, они просто быстрее снижают прочность брони.",
		"Если ты потеряешь сознание в воде, ты убьешься через 20 секунд.",
		"Имея полную белую статистику или принимая поливитамины, вы сможете есть сырое мясо, пить из источников грязной воды и есть окровавленными руками.",
		"Кроме Фамаса, все обрезы имеют вдвое большую отдачу",
		"Любое оружие с глушителем не слышно за 150 метров.",
		"Если вы войдете в зону с динамическим газом, вы будете телепортированы из этой зоны.",
		"Если вас нокаутировал вооруженный преступник, вы всегда просыпаетесь лицом, противоположным тому, откуда в вас стреляли",
		"Шлем с шипами появляется только в замке к югу от Ситника на красной тропе.",
		"Вспоминая Поли. Лок. 11930 x 13157 R.I.P"
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
	static int Red()    			  { return ARGB(255, 178, 40, 3); };
	static int Orange() 			  { return ARGB(255, 215, 153, 19); };
	static int Yellow() 			  { return ARGB(255, 253, 190, 53); };
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
	static int BrandColor()   { return UIColor.Yellow(); };
	// This color should be a complimentary color to your brand. 
	static int AccentColor()  { return UIColor.Red(); }

	// Advanced Styling --------------------------------------
	// You can get more Ganular with the colors by editing the syltes below
	// Get wild and create your own color functions and use them throughout the mod.
	// Best to Primary Text as white, but do whatever, Experiment.
	static int PrimaryText()        { return UIColor.White(); }; 	
	static int SecondaryText()      { return AccentColor(); };
	static int ShaderColor()        { return AccentColor(); };
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