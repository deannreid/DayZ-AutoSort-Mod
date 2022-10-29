class CfgPatches
{
	class ACSDefine
	{
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};
class CfgMods
{
	class ACSDefine
	{
		dir="ACSDefine";
		name="AutoSorting";
		type="mod";
		dependencies[]=
		{
			"GameLib",
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameLibScriptModule
			{
				value="";
				files[]=
				{
					"AutoSorting/ACSDefine/Core"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"AutoSorting/ACSDefine/Core"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"AutoSorting/ACSDefine/Core"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"AutoSorting/ACSDefine/Core"
				};
			};
		};
	};
};
