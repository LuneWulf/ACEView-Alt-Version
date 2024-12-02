/*
    Author: 
        SomeRandomDude
    [Description]
		Updates the vitals every second, to be displayed on the HUD.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/
private _debugmode = false;
private _spO2 = 100;
private _isBreathing = true;
private _resp = 1337;

while {player getVariable ["ace_isUnconscious", false]} do 
{	
	private _real_hr = (round(player GetVariable "ace_medical_heartrate")); // sorry if this is confusing, but HR is the only one we reuse frequently, so we have a literal version and a display string variant.
	private _hr = ("HR:		" + (str _real_hr) + "		bpm");
	private _real_bp = format ["%2/%1", (player GetVariable "ace_medical_bloodPressure") select 0, (player GetVariable "ace_medical_bloodPressure") select 1];
	private _bp = ("BP:		" + _real_bp + "		mmHg");
	ctrlSetText [573, _hr]; 
	ctrlSetText [574, _bp]; 
	
	if (isClass (configfile >> "CfgPatches" >> "kat_airway")) then {
		if ((_real_hr == 0) or (player GetVariable "kat_airway_obstruction") or (player GetVariable "kat_airway_occluded")) then { _isBreathing = false};

		_resp = ("Resp:		" + (str (player GetVariable "kat_breathing_breathrate")) + "		/min");


		_spO2 = ("Sp02:		" + (str ((player GetVariable "kat_circulation_bloodgas" select 1) + 5)) + "		%");
		ctrlSetText [575, _resp]; 
		ctrlSetText [576, _spO2]; 
	} else {
		if (ace_medical_vitals_simulateSpo2) then {
			_spO2 = format ["SpO2:		%1		%%", player getVariable "ace_medical_spo2" tofixed 1];

			ctrlSetText [576, _spO2];
		};
	};

	if ((player getVariable "ace_medical_inCardiacArrest") == true) then {
		private _timer = player getvariable "ace_medical_statemachine_cardiacArrestTimeLeft";
		private _min = ((_timer / 60) - (_timer % 60) / 60) tofixed 0;
		private _sec = (_timer % 60) tofixed 0;
		_timer = format ["Death in:		%1:%2		Min:Sec", _min, _sec];
		ctrlSetText [577, _timer];
	};


	// Havnt changed anything here.
	if (_debugmode) then {
		diag_log " - DEBUG LOG - " ;
		private _debug_1 = (player GetVariable "kat_airway_obstruction");
		private _debug_2 = (player GetVariable "kat_airway_occluded");
		diag_log format ["%1, _real_hr", _real_hr];
		diag_log format ["%1, _hr", _hr];
		diag_log format ["%1, _bp", _bp];
		// diag_log format ["%1, _resp", _resp];
		// diag_log format ["%1, _spO2", _spO2];
		diag_log format ["%1, _isBreathing", _isBreathing];
		diag_log format ["%1, kat_airway_obstruction", _debug_1];
		diag_log format ["%1, kat_airway_occluded", _debug_2];
	};
	sleep 1;
};
