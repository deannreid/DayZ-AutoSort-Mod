/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: missionGameplay.c
 *  
 * Class Information:
 *
 * Class handles Userside Mission.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class MissionGameplay {

	// UI reference
	ref ACSMMenu m_ACSMMenu;

	
	void MissionGameplay() {
		m_ACSMMenu = NULL;
	}
	
	override void OnInit()
    {
        super.OnInit();
        
        Print("[ACS - MissionGameplay] OnInit - Client"); 
	}
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        Print("[ACS - MissionGameplay] OnMissionStart - Client");
    }

    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        Print("[ACS - MissionGameplay] OnMissionFinish - Client");
    }
	
	override void OnUpdate(float timeslice)
	{
		Print("[ACS - MissionGameplay] OnUpdate - Client"); 
		super.OnUpdate(timeslice);
/*
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		ItemBase iteminhands;

		if(player)
		{
			if(player.GetHumanInventory())
			{
				if(player.GetHumanInventory().GetEntityInHands())
				{
					iteminhands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
				}
			}
		}*/
	
		// Open UI
		if (GetGame().GetInput().LocalPress("m_ACSMMenu", true)){
			
		}
	}
}