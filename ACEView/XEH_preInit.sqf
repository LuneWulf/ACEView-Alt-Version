//#include "CBA_initKeybinds.sqf"
[
  "spc_tab1",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle_med1",
    "STR_spc_menu_toggle_med2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_medicalTabEnabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_tab2",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle_spectator1",
    "STR_spc_menu_toggle_spectator2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_spectatorTabEnabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_tab3",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle_map1",
    "STR_spc_menu_toggle_map2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_mapTabEnabled = _value;
  }
] call cba_settings_fnc_init;

//
//
//

[
  "spc_specDistance",
  "SLIDER",
  [
    "STR_spc_menu_slider_distance1",
    "STR_spc_menu_slider_distance2"
  ],
  "ACEView",
  [1, 500, 50, 0],
  nil,
  {
	  params ["_value"];
	  _spc_maxDistance = _value;
  }
] call cba_settings_fnc_init;

//
//
//

[
  "spc_med1",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle2_HR1",
    "STR_spc_menu_toggle2_HR2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_hrEnabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_med2",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle2_BP1",
    "STR_spc_menu_toggle2_BP2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_bpEnabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_med4",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle2_SPO21",
    "STR_spc_menu_toggle2_SPO22"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_sp02Enabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_med3",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle2_RR1",
    "STR_spc_menu_toggle2_RR2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_respEnabled = _value;
  }
] call cba_settings_fnc_init;

[
  "spc_med5",
  "CHECKBOX",
  [
    "STR_spc_menu_toggle2_Timer1",
    "STR_spc_menu_toggle2_Timer2"
  ],
  "ACEView",
  true,
  nil,
  {
	  params ["_value"];
	  _spc_timerEnabled = _value;
  }
] call cba_settings_fnc_init;
