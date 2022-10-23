/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: config.cpp
 *  
 * Class Information:
 *
 * Class handels configuration for mod.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */
class CfgPatches {
	class ACS_Core {
		requiredVersion=0.1;
		requiredAddons[]= {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Characters_Headgear"
		};
	};
};

class CfgMods
{
	class AutoSorting
	{
		dir="AutoSorting/ACS_Core";
		type="mod";
		picture="AutoSorting/ACS_Core/Assets/Images/logoOpaque.edds";
		inputs="AutoSorting/ACS_Core/Scripts/Data/ACSKeybinds.xml";
		dependencies[]=
		{
			"World", "Mission"
		};
		class defs
		{
			class coreScriptModule
            {
                value = "";
                files[] = {
					"AutoSorting/ACS_Core/Scripts/1_Core"
				};
            };
			class gameScriptModule
			{
				value="";
				files[]={
					"AutoSorting/ACS_Core/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={
					"AutoSorting/ACS_Core/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={
					"AutoSorting/ACS_Core/Scripts/5_Mission"};
			};
		};
	};
};

/*class CfgSlots
{
	class Slot_SortingHat
	{
		name="Sorting Hat";
		displayName="Sorting Hat";
		ghostIcon="missing";
	};
};*/