/*
    Author: 
        SomeRandomDude
    [Description]
		Used to open the Spectator Tab when dialog "unconsiousSpectateACE" is open.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/

call SPC_fnc_hidePreviousTabs;
ctrlEnable [551, true];
ctrlEnable [553, true];
ctrlShow [551, true];
ctrlShow [553, true];
