class CfgFunctions {
	class SPC
	{
		class UIfunc
		{
			file = "\ACEView\functions\UIfunc";
			class vitalsUpdate {};
			class hidePreviousTabs {};
			class openHealthTab {};
			class openSpectatorTab {};
			class openMapTab {};
		};
		class Initalization
		{
			file = "\ACEView\functions\Init";
			class init {postInit	= 1;};
		};
		class Main
		{
			file = "\ACEView\functions\Main";
			class main {};
			class createSpectator {};
		};
	};
};
