/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: HelperManager.c
 *  
 * Class Information:
 *
 * Class helps with keybinds
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 16/10/2022 - Initial Code Development
 */

modded class PluginManager
{

	void PluginManager()
	{
		Print ("[ACSPluginManager] Loading Helper Classes");
	}

	override void Init()
	{
	 super.Init();
		//Register Modules
		// Module Class :  Client | Server
		
		// Server &OR Client
		//RegisterPlugin("", true, true);
		
		//Client ONLY
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			RegisterPlugin("ACSKeybindHelper", true, false);
			RegisterPlugin("ACSUIManager", true, false);
		}
		
		//Server ONLY
		if(GetGame().IsDedicatedServer())
		{
			RegisterPlugin("ACSLogHelper",false,true);
		}
	}
}