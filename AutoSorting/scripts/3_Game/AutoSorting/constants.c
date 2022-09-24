/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: constants.c
 *  
 * Class Information:
 *
 * Class handles gui constants
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

const int MENU_SORTINGUI_MENU = 24628583613;

static bool ACS_IsModLoadded(string name)
{
	name.ToLower();
	int mod_count = GetGame().ConfigGetChildrenCount("CfgMods");
	for ( int i = 2; i < mod_count; i++ )
	{ 
		string mod_name;
		GetGame().ConfigGetChildName("CfgMods", i, mod_name);
		mod_name.ToLower();
		if (mod_name == name)
			return true;
	}
	return false;
};