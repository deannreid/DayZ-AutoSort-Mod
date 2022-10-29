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
	ref ACSInGameMain m_ACSInGameMain;
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	ItemBase iteminhands;
	static ref ScriptInvoker m_OnMissionPaused = new ScriptInvoker();
	static ref ScriptInvoker m_OnMissionUnpaused = new ScriptInvoker();


	private bool m_Toggles;
	
	void MissionGameplay() {
		m_ACSInGameMain = NULL;
	}
	
	void ~MissionGameplay() {
	}
	
	override void OnInit()
    {
        super.OnInit();
	    Print("[ACS - missionGameplay] :: OnInit - Client"); 
		
		ACSKeybindHelper.RegisterBind("ASSortingUI", ACSBinds.Press, "OpenSortingTool", this);
		ACSKeybindHelper.RegisterBind("ASAutoSort", ACSBinds.Press,  "AutoSortTool", this);
	}
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        Print("[ACS - missionGameplay] :: OnMissionStart - Client");
    }

    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        Print("[ACS - missionGameplay] :: OnMissionFinish - Client");
    }
	
	override void OnUpdate(float timeslice)
	{

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
		}	
		super.OnUpdate(timeslice);
	}
		

	
	override void Pause()
	{
        super.Pause();

		MissionGameplay.m_OnMissionPaused.Invoke();
	}
	
	override void Continue()
	{
        super.Continue();

        MissionGameplay.m_OnMissionUnpaused.Invoke();
	}
	
	
	
	/*void clear_UI() {
		if(m_ACSMMenu)
		{
			Print("[ACS - missionGameplay] :: Keybind Pressed !");
			GetGame().GetUIManager().HideScriptedMenu(m_ACSMMenu);
			delete m_ACSMMenu;
		}
	}*/

	override void OnKeyPress(int key)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
		
		super.OnKeyPress(key);
		
		if (key == KeyCode.KC_ESCAPE)
		{
			if (m_ACSInGameMain) {
				Print("[ACS - missionGameplay] :: Closing UI");
				GetGame().GetUIManager().HideScriptedMenu(m_ACSInGameMain);
				delete m_ACSInGameMain;
			}
		}
		
					// Open UI
		if (GetGame().GetInput().LocalPress("ASSortingUI", true)){
			Print("[ACS - missionGameplay] :: Opening UI");
			
				m_ACSInGameMain = new ACSInGameMain();
				GetGame().GetUIManager().ShowScriptedMenu(m_ACSInGameMain, NULL);
		}
		
	}
	
	override void OnKeyPress(int key)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
       	ItemBase item_in_hands = ItemBase.Cast(player.GetHumanInventory().GetEntityInHands());
	
		super.OnKeyPress(key);
		
		if (key == KeyCode.KC_ESCAPE)
		{
			if (m_ACSInGameMain)
			{
				GetGame().GetUIManager().HideScriptedMenu(m_ACSInGameMain);
				delete m_ACSInGameMain;
			}
		}
	}
	
}