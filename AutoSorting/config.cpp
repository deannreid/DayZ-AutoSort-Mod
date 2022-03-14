// Script File
class CfgPatches {
	class AutoSortMod {
		requiredAddons[]= {"CF"};
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
		author="Dean Reid";
		credits="Dean Reid";
		authorID="76561198001768308";
		version="0.1";
		type="mod";
		inputs="AutoSorting/scripts/inputsSortingHatmaster.xml";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
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