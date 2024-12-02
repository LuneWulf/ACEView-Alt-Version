/*
    Author: 
        SomeRandomDude
    [Description]
		Used to open the Map Tab when dialog "unconsiousSpectateACE" is open.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/

call SPC_fnc_hidePreviousTabs;
ctrlEnable [555, true];
ctrlShow [555, true];
