/*
    Author: 
        SomeRandomDude
    [Description]
       Generate the reqiured camera constraints for the mod.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/

// make these private i guess
_spc_targetObject = objNull;
_spc_allyCamera = objNull;
_spc_nearestAlly = objNull;
_spc_selectedAlly = objNull;
_spc_tooFar = true;

_spc_maxDistance = spc_specDistance;


while {player getVariable ["ACE_isUnconscious", false]} do 
{
	waitUntil {ctrlEnabled 551};
	
	// Gets the nearby allies
	private _allyUnits = units (side (group player));
	_allyUnits deleteAt (_allyUnits find player);
	{ if ( _x getVariable ["ACE_isUnconscious", false] == true) then {_allyUnits deleteAt (_allyUnits find _x);}} forEach _allyUnits;
	_allyUnits = _allyUnits apply { [_x distance player, _x] };
	_allyUnits sort true;
	if ((_allyUnits select 0) select 0 < _spc_maxDistance) then {_spc_nearestAlly = (_allyUnits select 0) select 1; _spc_tooFar = false;} else {_spc_nearestAlly = (_allyUnits select 0) select 1; _spc_tooFar = true;}; //nested arrays boiii
	// diag_log format ["%1, %2", "UnitsWestVar = ", _allyUnits];
	// diag_log format ["%1, %2", "NearestAllyVar = ", _spc_nearestAlly];
	// diag_log format ["%1, %2", "SelectedAllyVar = ",_spc_selectedAlly];
	
	// Displays the relevant info on the HUD
	private _specText = "ERROR";
	if ( !isNull _spc_nearestAlly ) then { _specText = format [ localize "STR_spc_hud_formatted_nearby", name ((_allyUnits select 0) select 1), round ((_allyUnits select 0) select 0) ];};
	if ( isNull _spc_nearestAlly ) then { _specText = localize "STR_spc_hud_noally";};
	ctrlSetText [551, _specText]; 

	// Creates the camera to attach to the nearest ally
	if (( !isNull _spc_nearestAlly) and { _spc_nearestAlly != player } and { _spc_nearestAlly != _spc_selectedAlly } ) then 
	{
		//TargetObj
		if (( !isNull _spc_targetObject) and { _spc_nearestAlly != _spc_selectedAlly }) then {deleteVehicle _spc_targetObject;};
		_spc_targetObject = "Sign_Sphere100cm_F" createVehicleLocal [ 0, 0, 0 ]; hideObject _spc_targetObject;

		//Switch Camera
		if (( !isNull _spc_allyCamera) and { _spc_nearestAlly != _spc_selectedAlly }) then {
			detach _spc_allyCamera;
			_spc_selectedAlly =  _spc_nearestAlly;
			_spc_allyCamera camSetTarget  _spc_targetObject;
			_spc_targetObject attachTo [ _spc_selectedAlly, [0, 10, 0.05], "neck" ];
			_spc_allyCamera attachTo [ _spc_selectedAlly, [0, 0.25, 0.05], "neck" ];
			_spc_allyCamera camcommit 0;
			
		}
		//Create Camera
		else {
			_spc_allyCamera = "camera" camCreate (getpos player);
			_spc_selectedAlly =  _spc_nearestAlly;
			_spc_allyCamera cameraEffect ["internal","back", "rtt"];
			_spc_allyCamera camSetTarget  _spc_targetObject;
			"rtt" setPiPEffect [0];
			_spc_targetObject attachTo [ _spc_selectedAlly, [0, 10, 0.05], "neck" ];
			_spc_allyCamera attachTo [ _spc_selectedAlly, [0, 0.25, 0.05], "neck" ];
			_spc_allyCamera camcommit 0;		
		}; 
	};
	if (!_spc_tooFar) then {
		ctrlEnable [552, true];
		ctrlShow [552, true];
		ctrlEnable [553, false];
		ctrlShow [553, false];
	} else {
		ctrlEnable [552, false];
		ctrlShow [552, false];
		ctrlEnable [553, true];
		ctrlShow [553, true];
	};
	if (ctrlEnabled 551) then {sleep 0.4;}; // 0.5 second delay on refresh if the menu is open
	sleep 0.1;
};
	
	// old code for cleaning up stuff i guess.
	//if ( !isNull_spc_targetObject) then {deleteVehicle _spc_targetObject;};
	//if ( !isNull_spc_allyCamera) then {camDestroy _spc_allyCamera;};

	//waitUntil {!(player getVariable ["ACE_isUnconscious", false]) or (_alive == false)}; //needs sleep 1
	//deleteVehicle _spc_targetObject;
