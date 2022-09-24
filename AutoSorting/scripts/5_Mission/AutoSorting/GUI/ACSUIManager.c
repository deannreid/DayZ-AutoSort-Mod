/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: ACSUIManager.c
 *  
 * Class Information:
 *
 * Class handles UI Manager
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 10/03/2022 - Initial Code Development
 */

	private ref array<ref ACSScriptedMenu> M_SCRIPTED_UI_INSTANCES;

	void ACSUIManager() {
		M_SCRIPTED_UI_INSTANCES = new array<ref ACSScriptedMenu>;
	}

	override void OnInit() {
		Print("[ACS UIManager] :: UI Manager  Init");
	}

	void ~ACSUIManager()
	{
		
	}

	bool CreateMenu(typename menuType, int menuID, UIScriptedMenu menuParent = NULL)
	{
		if (GetMenuByType(menuType) == NULL)
		{
			ACSScriptedMenu ACSMenu;
			if (Class.CastTo(ACSMenu,GetGame().GetUIManager().EnterScriptedMenu(menuID, menuParent))){
				M_SCRIPTED_UI_INSTANCES.Insert( ACSMenu );
				Print("[ACSUIManager] Menu "+ACSMenu.GetType() + " has been created with the ID: "+ menuID);
				VPPMenu.OnInit();
				return true;
			}
		}
		
		Print("[ACSUIManager] Can't create menu: "+menuType.ToString() + " with ID: "+menuID + " Probably because an instance is already there somewhere! Use ShowMenu() ? instead - might fix it.");
		return false;
	}
	
	ACSScriptedMenu GetMenuByType(typename menuType)
	{
		foreach(ACSScriptedMenu menu : M_SCRIPTED_UI_INSTANCES){
			if (menu && menu.GetType() == menuType){
	    			return menu;
	    		}
		}
		return NULL;
	}

	//To remove instance from M_SCRIPTED_UI_INSTANCES array
	void DestroyMenuInstanceByType(typename menuType)
	{
		for(int i = 0; i < M_SCRIPTED_UI_INSTANCES.Count(); i++)
		{
			ACSScriptedMenu menu = M_SCRIPTED_UI_INSTANCES[i];
			if (menu.GetType() == menuType)
			{
	    		M_SCRIPTED_UI_INSTANCES.Remove(i);
				Print("[ACSUIManager]: Destroyed UI: "+ menu.GetType());
	    	}
		}
	}

	ACSUIManager GetACSUIManager()
	{
		if ( GetPluginManager() && GetPluginManager().GetPluginByType(ACSUIManager))
			return ACSUIManager.Cast(GetPluginManager().GetPluginByType(ACSUIManager));
	
		return NULL;
	};

	class ACSScriptedMenu extends UIScriptedMenu
	{
		bool menuStatus; //True == showing
		bool m_GameFocus;
		bool m_toggleFocus;
	
		void ~ACSScriptedMenu()
		{
			if (!GetGame().IsClient())
				return;
			
			if ( GetACSUIManager() != NULL)
				GetACSUIManager().DestroyMenuInstanceByType(GetType());
	
			Print("Destroy Menu: "+GetType());
		}
		
		override void Update(float timeslice)
		{
			super.Update(timeslice);
			if (!menuStatus) return;
			
			Input input = GetGame().GetInput();
	
			if (input.LocalDbl("UAFocusOnGame", false))
			{
				if (m_toggleFocus)
				{
					m_toggleFocus = false;
				}
				else
				{
					m_toggleFocus = true;
					SetFocus(null);
					UnlockPlayerControl();
				}
			}

		if (input.LocalHold("UAFocusOnGame", false))
		{
			if (menuStatus && !m_GameFocus)
			{
				SetFocus(null);
				UnlockPlayerControl();
			}
		}else if (input.LocalRelease("UAFocusOnGame", false) && !m_toggleFocus && menuStatus){
			LockPlayerControl();
		}
	}


	void OnInit()
	{
		//lock Control and show mouse cursor + set menu state to showing
		if (GetGame().GetUIManager().GetMenu().ClassName().ToType() == GetType() && !IsShowing())
		{
			menuStatus = true;
			LockPlayerControl();
			Print("[ACSScriptedMenu]: Initializing UI: "+ GetType());
		}else{
			Print("[ACSScriptedMenu]: FAILED to Initialize UI: "+ GetType());
		}
	}
	
	bool IsShowing()
	{
	   return menuStatus;
	}
	
	void DestroyMenu()
	{
	   delete this;
	}

	void ShowMenu()
	{
		if (!IsShowing() && GetGame().GetUIManager().GetMenu() == NULL){
			ACSScriptedMenu menu = ACSScriptedMenu.Cast(GetGame().GetUIManager().ShowScriptedMenu(this, NULL));
			if (menu){
				LockPlayerControl();
				menuStatus = true;
			} else {
				Print("[ACSScriptedMenu] Unable to show menu: "+ GetType() + " Something went wrong! `ShowScriptedMenu` returned NULL!");
			}
		}else{
			Print("[ACSScriptedMenu] Unable to show menu: "+ GetType() + " Another Menu is on screen OR menu is already showing!");
		}
	}
	

	void HideMenu()
	{
		if (GetGame().GetUIManager().GetMenu() == null) return;
		
		if (GetGame().GetUIManager().GetMenu().ClassName().ToType() == GetType())
		{
			GetGame().GetUIManager().HideScriptedMenu(this);
			UnlockPlayerControl();
			menuStatus = false;
		}else{
			Print("[ACSScriptedMenu] Could not close menu: "+ GetType() + " Menu was not found!");
		}
	}

	void LockPlayerControl()
	{
		GetACSUIManager().SetKeybindsStatus(true); //Lock keys
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetUIManager().ShowUICursor( true );
		GetGame().GetMission().GetHud().Show( false );
		m_GameFocus = false;
	}
	
	void UnlockPlayerControl()
	{
		GetACSUIManager().SetKeybindsStatus(false); //unlock keys
		GetGame().GetMission().PlayerControlEnable(false);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetUIManager().ShowUICursor( false );
		GetGame().GetMission().GetHud().Show( true );
		m_GameFocus = true;
	}