/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: missionServer.c
 *  
 * Class Information:
 *
 * Class handles serverside bits
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionServer {
	
	void MissionServer()
    {
        ACSConfig config = ACSGlobals.Get();
        GetDayZGame().setACSGlobals(config);
    }
	
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
		Print("[ACS - missionServer] :: Plugin InvokeOnConnect!");
        super.InvokeOnConnect(player, identity);
        auto configParams = new Param1<ACSConfig>(GetDayZGame().getACSGlobals());
       // GetGame().RPCSingleParam(player, ACSRPC.CHECKACSCONFIG, configParams, true, identity); Not Implemented Yet
    }
	
	override void OnInit() {
		Print("[ACS - missionServer] :: Init - Server!");
		super.OnInit();	
	}
}