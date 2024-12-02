class unconsiousSpectateACE
{

	idd = 859101; // Display identification

	class Controls // Main controls
	{
		class tabMedical
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 547; // Control identification (without it, the control won't be displayed)
			type = CT_BUTTON; // Type
			style = ST_LEFT; // Style
			default = 1; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = -0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = -1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 14 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height

			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorBackgroundDisabled[] = {0,0,0,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground)

			text = "$STR_spc_hud_health"; // Displayed text
			sizeEx = GUI_GRID_CENTER_H; // Text size
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 2; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			borderSize = 0.001; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color

			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed

			period = 1; // Oscillation time between colorBackground and colorFocused when selected
			periodFocus = 2; // Unknown?
			periodOver = 0.5; // Unknown?

			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

			onButtonDown = call SPC_fnc_openHealthTab;

		};
		class tabSpectate
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 548; // Control identification (without it, the control won't be displayed)
			type = CT_BUTTON; // Type
			style = ST_LEFT; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 14 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = -1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 13 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height

			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorBackgroundDisabled[] = {0,0,0,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground)

			text = "$STR_spc_hud_spectator"; // Displayed text
			sizeEx = GUI_GRID_CENTER_H; // Text size
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 2; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			borderSize = 0.001; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color

			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed

			period = 1; // Oscillation time between colorBackground and colorFocused when selected
			periodFocus = 2; // Unknown?
			periodOver = 0.5; // Unknown?

			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

			onButtonDown = call SPC_fnc_openSpectatorTab;

		};
		class tabMap
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 549; // Control identification (without it, the control won't be displayed)
			type = CT_BUTTON; // Type
			style = ST_LEFT; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 27 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = -1 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 13 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height

			colorBackground[] = {0.2,0.2,0.2,1}; // Fill color
			colorBackgroundDisabled[] = {0,0,0,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,1}; // Mouse hover fill color
			colorFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground)

			text = "$STR_spc_hud_map"; // Displayed text
			sizeEx = GUI_GRID_CENTER_H; // Text size
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 2; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {1,1,1,1}; // Tooltip text color
			tooltipColorBox[] = {1,1,1,1}; // Tooltip frame color

			borderSize = 0.001; // Left color width (border is a stripe of the control height on the left side)
			colorBorder[] = {1,1,1,1}; // Left border color

			colorShadow[] = {0,0,0,0}; // Background frame color
			offsetX = 0.0075; // Horizontal background frame offset
			offsetY = 0.01; // Vertical background frame offset
			offsetPressedX = 0.0075; // Horizontal background offset when pressed
			offsetPressedY = 0.01; // Horizontal background offset when pressed

			period = 1; // Oscillation time between colorBackground and colorFocused when selected
			periodFocus = 2; // Unknown?
			periodOver = 0.5; // Unknown?

			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1}; // Sound played after control is activated in format {file, volume, pitch}
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1}; // Sound played when mouse cursor enters the control
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1}; // Sound played when the control is pushed down
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1}; // Sound played when the control is released after pushing down

			onButtonDown = call SPC_fnc_openMapTab;

		};
		class spc_SpectatingInfo_TooFar
		{
			type = CT_STATIC;
			idc = 550;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;

			text = "Too Far Away To Spectate! Nearest Unit: UNIT_NAME UNIT_DISTANCE";
			sizeEx = GUI_GRID_CENTER_H;
			font = GUI_FONT_NORMAL;
			lineSpacing = 1;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
		};
		class spc_SpectatingInfo
		{
			type = CT_STATIC;
			idc = 551;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;

			text = "Spectating Nearest Unit: UNIT_NAME";
			sizeEx = GUI_GRID_CENTER_H;
			font = GUI_FONT_NORMAL;
			lineSpacing = 1;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
		};
		class PiPZone 
		{
			idc = 552;
			type = CT_STATIC;
			style = ST_PICTURE;
			colorText[] = {1,1,1,1};
			colorBackground[] = {1,1,1,1};
			font = GUI_FONT_NORMAL;
			sizeEx = 0.023;
			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 40 * GUI_GRID_CENTER_W; // Width
			h = 25 * GUI_GRID_CENTER_H; // Height
			text = "#(argb,512,512,1)r2t(rtt,1.333)";
			moving = false;
		};
		class spc_NoSignal 
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = 553; // Control identification (without it, the control won't be displayed)
			type = CT_STATIC; // Type
			style = ST_LEFT; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 40 * GUI_GRID_CENTER_W; // Width
			h = 25 * GUI_GRID_CENTER_H; // Height

			colorBackground[] = {0.2,0.2,0.2,0.2}; // Fill color
			colorBackgroundDisabled[] = {0,0,0,0.5}; // Disabled fill color
			colorBackgroundActive[] = {0,0,0,0.2}; // Mouse hover fill color
			colorFocused[] = {1,0.5,0,1}; // Selected fill color (oscillates between this and colorBackground)

			text = "$STR_spc_hud_nosignal"; // Displayed text
			sizeEx = GUI_GRID_CENTER_H; // Text size
			font = GUI_FONT_NORMAL; // Font from CfgFontFamilies
			shadow = 2; // Shadow (0 - none, 1 - N/A, 2 - black outline)
			colorText[] = {1,1,1,1}; // Text color
			colorDisabled[] = {1,1,1,0.5}; // Disabled text color
		};
		class _CT_MAP: RscSpcMap
		{
			idc = 555; // Control identification (without it, the control won't be displayed)

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 40 * GUI_GRID_CENTER_W; // Width
			h = 25 * GUI_GRID_CENTER_H; // Height

		};
		class spc_HeartRate
		{
			type = CT_STATIC;
			idc = 573;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 0 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 6.25 * GUI_GRID_CENTER_H;

			text = "80";
			sizeEx = GUI_GRID_CENTER_H * 4;
			font = GUI_FONT_NORMAL;
			lineSpacing = 0;
			colorText[] = {1,0.2,0.2,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
			shadow = 2;
			fixedWidth = 0;
		};
		class spc_BloodPressure
		{
			type = CT_STATIC;
			idc = 574;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 6.25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 6.25 * GUI_GRID_CENTER_H;

			text = "120/80";
			sizeEx = GUI_GRID_CENTER_H * 4;
			font = GUI_FONT_NORMAL;
			lineSpacing = 0;
			colorText[] = {0.9,0.9,0.2,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
			shadow = 2;
			fixedWidth = 0;
		};
		class spc_Respiration
		{
			type = CT_STATIC;
			idc = 575;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 18.75 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 6.25 * GUI_GRID_CENTER_H;

			text = "20";
			sizeEx = GUI_GRID_CENTER_H * 4;
			font = GUI_FONT_NORMAL;
			lineSpacing = 0;
			colorText[] = {0.2,0.2,0.9,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
			shadow = 2;
			fixedWidth = 0;
		};
		class spc_SpO2
		{
			type = CT_STATIC;
			idc = 576;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 12.5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 6.25 * GUI_GRID_CENTER_H;

			text = "100";
			sizeEx = GUI_GRID_CENTER_H * 4;
			font = GUI_FONT_NORMAL;
			lineSpacing = 0;
			colorText[] = {0.9,0.2,0.9,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
			shadow = 2;
			fixedWidth = 0;
		};
		class spc_Timer
		{
			type = CT_STATIC;
			idc = 577;
			style = ST_LEFT;

			x = 0 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 25 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 40 * GUI_GRID_CENTER_W;
			h = 6.25 * GUI_GRID_CENTER_H;

			text = "Death in:	N/A";
			sizeEx = GUI_GRID_CENTER_H * 4;
			font = GUI_FONT_NORMAL;
			lineSpacing = 0;
			colorText[] = {1,0.2,0.2,1};
			colorBackground[] = {0.2,0.2,0.2,0.5};
			shadow = 2;
			fixedWidth = 0;
		};
	};
};
////////////////////////////////////////////////////////
// GUI EDITOR OUTPUT END
////////////////////////////////////////////////////////
