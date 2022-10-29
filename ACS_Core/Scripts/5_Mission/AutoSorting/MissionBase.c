/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: MissionBase.c
 *  
 * Class Information:
 *
 * Class handles base mission
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionBase {
	override UIScriptedMenu CreateScriptedMenu(int id)
	{
		Print("[ACS - missionBase] :: Create Menu!");
		UIScriptedMenu menu = NULL;
		menu = super.CreateScriptedMenu(id);
		
		if (!menu)
		{
			//switch (id) 
			//{
			//	case MENU_ACS_MAIN_UI:
			Print("[ACS - missionBase] :: Load Menu");
					menu = new ACSInGameMain;
					
			//	break;
				
				//case ACS_SETTINGS_UI:
				//	menu = new ACSSettingsUI;
				//break;
			//}
			if (menu)
			{
				Print("[ACS - missionBase] :: Created Menu: " + id);
				
				menu.SetID(id);
			}
		}
		return menu;
	}
}