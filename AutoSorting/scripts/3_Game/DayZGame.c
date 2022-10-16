/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: DayZGame.c
 *  
 * Class Information:
 *
 * Class handles DayZ stuff and Loads Variables from Config.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 10/03/2022 - Initial Code Development
 */

modded class DayZGame {
	
	protected ref ACSConfig m_CheckACSConfig;
	
	void setACSGlobals(ACSConfig config)
	{
		m_CheckACSConfig = config;
	}
	
	ACSConfig getACSGlobals()
	{
		return m_CheckACSConfig;
	}

}