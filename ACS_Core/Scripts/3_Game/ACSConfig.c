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

	//Game Booleans
	bool ACS_RequireSortingHat;  // Enable/Disable requirement for Sorting Hat item in-game.
	bool ACS_EnableCooldown; // Enable/Disable cooldown between auto-sort to mitigate lag fags
	bool ACS_CooldownTime; // Select Cooldown Time
	bool ACS_RequireCodeLock; //Might be useful for something - may as well add incase :) 
	bool ACS_ForceDarkMode; // Force Dark Mode Skin
	

	bool ACS_RequireSortTimer;
	int  ACS_SortTimerTime;
	
	//Server Booleans
	bool ACS_EnableLogging; // Enable server logging
	
	
	//Arrays
	ref array<string> ACS_SkinTypes;
	
	//Only Blacklist or Whitelist can be populated, if both are populated then blacklist will take over.
	ref array<string> ACS_BlacklistItemTypes; //Blacklist certain types of Items - Might be useful
	ref array<string> ACS_WhitelistItemTypes; //Whitelist certain types of Items - Might be useful
	ref array<string> ACS_BlacklistObjectTypes;
	ref array<string> ACS_AcceptedModList; // Add classnames to the accepted mod list if the creator hasn't done it themselves.
	ref array<string> ACS_AcceptedItemTypes; // Types of storage that is acceptable.
	bool acsStorageType;
	
}

class ACSGlobal {
	private static ref ACSConfig m_ACSConfig = NULL;
	private static const string configPath = "$profile:\\AutoSorting\\ACS_Settings.json"; // json better
	private static const string configRoot = "$profile:\\AutoSorting";
	
	/*Get Config file*/
	static ACSConfig Get()
	{
		if (m_ACSConfig == null){
			Set();
		}
	return m_ACSConfig;	
	} 
	
	/*Load Config file*/
	static void Set()
	{
		m_ACSConfig = LoadConfig();
	}
	
	private static ACSConfig LoadConfig()
	{
		ACSConfig config = new ACSConfig;
		
		if (!FileExist(configPath))
		{
			Print("[ACSConfig] :: No Configuration file found - Creating...");
			CreateDefaultConfig(config);
		}
		
		JsonFileLoader<ACSConfig>.JsonLoadFile(configPath, config);
		Print ("[ACSConfig] :: Configuration file found - Phew");
		return config;
	}
	
	/*If no config file, populate with entries*/
	private static void CreateDefaultConfig(ACSConfig config)
	{
		config.ACS_RequireSortingHat = true;
		config.ACS_EnableCooldown = true; 
		config.ACS_RequireCodeLock = false;
		config.ACS_ForceDarkMode = false; 
		config.ACS_SkinTypes = {"DefaultLight","DefaultDark","Custom"};

		
		// Sort Timer Requirements
		config.ACS_RequireSortTimer = false; // Probably won't need this. 
		config.ACS_SortTimerTime = 0; // 0 = Instant/Disabled, 60 = 60 Seconds, etc, etc, etc. Any more than 60 and your a looser.
		
		/* will use later
		//Disable Certain Sort Functions
		config.ACS_DisableWeapons = false;
		config.ACS_DisableAmmo = false;
		config.ACS_DisableMagazines = false;
		config.ACS_DisableAttachments = false;
		config.ACS_DisableConsumables = false;
		config.ACS_DisableAttire = false;
		config.ACS_DisableArmor = false;
		config.ACS_DisableTools = false;
		config.ACS_DisableElectrical = false;
		config.ACS_DisableResources = false;
		config.ACS_DisableMisc = false;
		config.ACS_DisableSortAll = false;*/
		
		config.ACS_BlacklistItemTypes = { "" };
		config.ACS_WhitelistItemTypes = { "" };
		
		config.ACS_BlacklistObjectTypes = { "" };
		
		//Enable Custom Storage if mod creator hasn't enabled through mod.
		config.ACS_AcceptedModList = { 
			"",
			""
		};	
		
		
		// To make it a globally useful mod - mod creators will be able to add the following to their mod - Save me a job Pls. 
	/*	acsStorageType = "Generic"; // Generic storage box - not limited to type
		acsStorageType = "Ammo";    // Ammo Storage Box that accepts Ammo only.
		acsStorageType = "Weapon";  // Weapon Storage Box that accepts Weapons only.
		acsStorageType = "Medical";  // Medical Storage Box that accepts Medical only.
		acsStorageType = "Food";  // Food Storage Box that accepts Food only.*/
		
		if (!FileExist(configPath))
		{
			Print("[ACSConfig] :: No Configuration file found - Creating...");
			CreateDefaultConfig(config);
		}
	}
}