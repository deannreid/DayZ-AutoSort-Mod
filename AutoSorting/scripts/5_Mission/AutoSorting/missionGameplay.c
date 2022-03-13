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
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	ItemBase iteminhands;

	
	void MissionGameplay() {
		Print("[ACSUIManager] :: Plugin Init!");
		m_ACSMMenu = NULL;
	}
	
	override void OnInit()
    {
        super.OnInit();
	    Print("[ACSUIManager] :: OnInit - Client"); 
	}
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        Print("[ACSUIManager] :: OnMissionStart - Client");
    }

    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        Print("[ACSUIManager] :: OnMissionFinish - Client");
    }
	
	override void OnUpdate(float timeslice)
	{
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
		if (GetGame().GetInput().LocalPress("ASSortingUI", true)){
			Print("[ACSUIManager] :: Keybind Pressed !");
			//clear_UI;
			m_ACSMMenu = new ACSMMenu();
			GetGame().GetUIManager().ShowScriptedMenu(m_ACSMMenu, NULL);
		}
	}
	
	void clear_UI() {
		if(m_ACSMMenu)
		{
			Print("[ACSUIManager] :: Keybind Pressed !");
			GetGame().GetUIManager().HideScriptedMenu(m_ACSMMenu);
			delete m_ACSMMenu;
		}
	}
	
	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);

		if (key == KeyCode.KC_ESCAPE)
		{
			if(m_ACSMMenu)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_ACSMMenu);
				delete m_ACSMMenu;
			}
		}
	}
}