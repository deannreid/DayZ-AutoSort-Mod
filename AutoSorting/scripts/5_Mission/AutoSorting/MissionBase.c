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
	override UIScriptedMenu CreateScriptedMenu(int id) {
		UIScriptedMenu menu = NULL;
		menu = super.CreateScriptedMenu(id);
		if(!menu) { 
				switch (id) {
					case MENU_SORTINGUI_MENU;
					 	menu = new SortingUI;
					break;
				}
				if (menu) {
					menu.SetID(id);
				}
			}
		}
		return menu;
	}
}