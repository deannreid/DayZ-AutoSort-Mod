// Script File
class CfgMods
{
	class AutoSortMod
	{
		dir="AutoSorting";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="AutoSorting";
		author="Dean Reid";
		credits="Dean Reid";
		authorID="0";
		version="1.0";
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