/*
    Author: 
        SomeRandomDude
    [Description]
       Waits untill the mission is loaded and then executes the main script.

    Arguments:
	None

    Return Value:
    None

    Scope: Client
    Environment: Local
    Public: No
     
*/
diag_log "Starting ACEView!";
// Exit if its a dedicated server
if (isDedicated) exitWith {diag_log "ACEView didnt initalize because it was loaded on a dedicated server!";};

diag_log "ACEView Initalized!";
[] spawn SPC_fnc_main;
