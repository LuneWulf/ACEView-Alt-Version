/*
    Author: 
        SomeRandomDude
    [Description]
       When a player is unconscious it will initiate all of the mod elements.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/


private _spc_medicalTabEnabled = spc_tab1;
private _spc_spectatorTabEnabled = spc_tab2;
private _spc_mapTabEnabled = spc_tab3;

while {true} do 
{
	waitUntil {sleep 2; player getVariable ["ACE_isUnconscious", false]};
	_spc_KO = (player getVariable ["ACE_isUnconscious", false]);
	_spc_Alive = true;
	player addEventHandler ["Killed", { _spc_Alive = false; closeDialog 2; }];
	sleep 1;
	
	while { _spc_KO && _spc_Alive} do 
	{
		waitUntil {sleep 2.5; ((findDisplay 859101) isEqualTo displayNull && (findDisplay 49) isEqualTo displayNull && (findDisplay 312) isEqualTo displayNull && isRemoteControlling player == false) or (!(player getVariable ["ACE_isUnconscious", false])) or (_spc_Alive == false)};
		// ^ this one is a doozy, AND checks are as follows: 1. Aceview display is closed 2. main menu is closed 3. Zeus is closed 4. Not remote controlling a unit. THEN if the player wakes up OR dies it unfreezes.
		_spc_KO = (player getVariable ["ACE_isUnconscious", false]);
		if (_spc_KO && _spc_Alive) then {
			createDialog "unconsiousSpectateACE"; 
			if (!_spc_medicalTabEnabled) then {ctrlEnable [547, false];}; 
			if (!_spc_spectatorTabEnabled) then {ctrlEnable [548, false];}; 
			if (!_spc_mapTabEnabled) then {ctrlEnable [549, false];}; 
			call SPC_fnc_hidePreviousTabs;
			private _vitalsUpdateScript = [] spawn SPC_fnc_vitalsUpdate;
			sleep 0.2;
			private _spectatorScript = [] spawn SPC_fnc_createSpectator;
			if (_spc_medicalTabEnabled) then {call SPC_fnc_openHealthTab;}; 
			waitUntil {sleep 0.2; ((findDisplay 859101) isEqualTo displayNull) or (!(player getVariable ["ACE_isUnconscious", false])) or (_spc_Alive == false)};
		};
	};
	closeDialog 2;
	player removeEventHandler ["Killed", 0];
	//terminate _vitalsUpdateScript; IDK IF I NEED TO TERMINATE A SPAWNED FUNCTION TO KEEP IT FROM DUPLICATING AND CAUSING LAG
	//terminate _spectatorScript;
};
