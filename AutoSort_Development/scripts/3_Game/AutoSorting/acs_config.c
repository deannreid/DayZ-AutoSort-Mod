/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: acs_config.c
 *  
 * Class Information:
 *
 * Class handles configuration parameters
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

class ACSConfig {

	//Game Bools
	bool g_ACSEnableCooldown; //Enable cooldown between auto sort to mitigate lag.
	bool g_ACSRequireSortingHat; //Enable/Disable use of Auto-Sort unless they have the sorting hat.
	bool g_ACSRequireCodeLock; //Require Codelock on item (might be useful for something)
	
	//Server Bools
	bool s_ACSEnableLogging; //Enable Logging of all uses of mod

	int g_ACSCooldownTime; //Time between attempts to auto sort (Default 20 seconds)
	
	//Only 1 can be populated at a time if both are populated then neither will work.
	ref array<string> g_ACSBlacklistTypes; //Blacklist certain types of items - might be useful for some servers.
	ref array<string> g_ACSWhitelistTypes; //Blacklist all types except the listed items - might be useful for some servers.
	ref array<string> g_ACSBlacklistStorageTypes; //Blacklist Storage types to certain objects - e.g mil crates only or custom crate 

}

class ACSGlobals 
{
	private static ref ACSConfig m_ACSConfig = NULL;
	private static const int MAX_CONFIG_LINES = 500;
	private static const string configPath = "$profile:\\ACS_Settings.json";
	private static const string configRoot = "$profile:\\";
	
	static ACSConfig Get() 
	{
		if(m_ACSConfig == NULL) {
			Set();
		}
		return m_ACSConfig;
	}
		
	static void Set() 
	{
		m_ACSConfig = LoadConfig();
	}
	
	private static ACSConfig LoadConfig() 
	{
		if(!FileExists(configPath)) {
		
			Print("(ACS) 'ACS_Settings' does not exist, creating...");
			CreateDefaultConfig(config);
		}
	
		JsonFileLoader<ACSConfig>.JsonLoadFile(configPath, config);
		Print("(ACS) 'ACS_Settings' found, Loading...");
		return config;
	}
		
	private static void CreateDefaultConfig(ACSConfig config) 
	{
		//game config defaults
		config.g_ACSEnableCooldown = true;
		config.g_ACSRequireSortingHat = true; 
		config.g_ACSRequireCodeLock = false; 
		//server config defaults
		config.s_ACSEnableLogging = false;
		config.g_ACSCooldownTime = 20;
		//List Config Defaults
		config.g_ACSBlacklistTypes = { "" };
		config.g_ACSWhitelistTypes = { "" };
		config.g_ACSBlacklistStorageTypes = { "container_protector_small", "container_ammobox300rnd", "SeaChest" };
	
			
		if (!FileExist(configRoot)) 
		{
			Print("[ACS] '" + configRoot + "' does not exist, creating...");
			MakeDirectory(configRoot);
		}
			JsonFileLoader<ACSConfig>.JsonSaveFile(configPath, config);
	}
};