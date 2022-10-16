// Script File
class CfgPatches {
	class AutoSortMod {
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]= {
			"CF",
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class AutoSortMod
	{
		type="mod";
		name="AutoSorting";
		picture = "AutoSorting//assets/icons/iconOpaque.edds";
		logo = "AutoSorting//assets/icons/iconOpaque.edds";
		logoSmall = "AutoSorting//assets/icons/iconOpaque.edds";
		logoOver = "AutoSorting//assets/icons/iconOpaque.edds";
		action="https://github.com/deannreid/DayZ-AutoSort-Mod";
		author="BigDeano";
		authorID="76561198001768308";
		version = "1.0.0";
		overview = "A mod to sort your junk";
		tooltip = "A mod to sort your junk";
		inputs="AutoSorting/scripts/inputsSortingHatmaster.xml";
		dependencies[]=
		{
			"Game",	"World", "Mission"
		};
		class defs
		{
			class imageSets
            {
                files[] = {"AutoSorting/assets/imagesets/main_UI.imageset"};
            };
			class engineScriptModule
			{
				value="";
				files[]={"AutoSorting/scripts/1_Core"}; 
			};
			class gameLibScriptModule
			{
				value="";
				files[]={"AutoSorting/scripts/2_GameLib"};
			};

			class gameScriptModule
			{
				value="";
				files[]={"AutoSorting/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"AutoSorting/scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"AutoSorting/scripts/5_Mission"};
			};
		};
	};
};
class CfgSlots
{
	class Slot_SortingHat
	{
		name="Sorting Hat";
		displayName="Sorting Hat";
		ghostIcon="missing";
	};
};