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
		dir="AutoSorting";
		picture="AutoSorting/gui/images/logoOpaque.edds";
		action="";
		hideName=0;
		hidePicture=0;
		name="AutoSorting";
		authorID="76561198001768308";
		type="mod";
		creditsJson = "AutoSorting/scripts/Data/Credits.json";
		versionPath = "AutoSorting/scripts/Data/Version.hpp";
		inputs="AutoSorting/scripts/inputsSortingHatmaster.xml";
		dependencies[]=
		{
			"Game",	"World", "Mission"
		};
		class defs
		{
			class imageSets
            {
                files[] = {"AutoSorting/gui/imagesets/main_UI.imageset"};
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
				files[]=
				{
					"AutoSorting/scripts/5_Mission"
				};
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