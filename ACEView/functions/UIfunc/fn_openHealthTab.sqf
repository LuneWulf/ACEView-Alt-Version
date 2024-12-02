/*
    Author: 
        SomeRandomDude
    [Description]
		Used to open the Health Tab when dialog "unconsiousSpectateACE" is open.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/

// 573 is Heart Rate
// 574 is Blood Pressure
// 575 is Respiration Rate
// 576 is SpO2
// 577 is Death Timer


private _spc_hrEnabled = spc_med1;
private _spc_bpEnabled = spc_med2;
private _spc_respEnabled = spc_med3;
private _spc_sp02Enabled = spc_med4;
private _spc_timerEnabled = spc_med5;

call SPC_fnc_hidePreviousTabs;

if (_spc_hrEnabled) then {ctrlEnable [573, true]; ctrlShow [573, true];}; 
if (_spc_bpEnabled) then {ctrlEnable [574, true]; ctrlShow [574, true];}; 
if (_spc_respEnabled) then {ctrlEnable [575, true]; ctrlShow [575, true];}; 
if (_spc_sp02Enabled) then {ctrlEnable [576, true]; ctrlShow [576, true];};

// Only display death timer when it is enabled and player is in cardiac arrest.
if (_spc_timerEnabled && ((player getVariable "ace_medical_inCardiacArrest")) == true) then {
    ctrlEnable [577, true]; 
    ctrlShow [577, true];
} else {
    ctrlEnable [577, false]; 
    ctrlShow [577, false];
};

// Check if KAT is installed. If KAT isnt installed RR is useless.
if (!(isClass (configFile >> "CfgPatches" >> "kat_airway"))) then {
    ctrlEnable [575, false]; 
    ctrlShow [575, false];
};

// Check if either ACE has SpO2 enabled or KAT is installed.
if (_spc_sp02Enabled && !((ace_medical_vitals_simulateSpo2) || (isClass (configFile >> "CfgPatches" >> "kat_airway")))) then {
    ctrlEnable [576, false]; 
    ctrlShow [576, false];
};

