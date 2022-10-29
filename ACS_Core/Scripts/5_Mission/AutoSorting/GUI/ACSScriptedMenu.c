/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: ACSScriptedMenu.c
 *  
 * Class Information:
 *
 * Class handles Scripted Menu
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */
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


		//Called When menu is created with ACSUIManager::CreateMenu();

	void OnInit()
	{
		Print("Client: [ACSScriptedMenu] :: Initializing ScriptedMenu Helper.");
		//lock Control and show mouse cursor + set menu state to showing
		if (GetGame().GetUIManager().GetMenu().ClassName().ToType() == GetType() && !IsShowing())
		{
			menuStatus = true;
			LockPlayerControl();
			Print("[ACSScriptedMenu]: Initializing Scripted UI: "+ GetType());
		}else{
			Print("[ACSScriptedMenu]: FAILED to Initialize Scripted UI: "+ GetType());
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
			}else{
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
		GetACSUIManager().SetKeybindsStatus(true); //Lock shortcut keys
		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetUIManager().ShowUICursor( true );
		GetGame().GetMission().GetHud().Show( false );
		m_GameFocus = false;
	}
	
	void UnlockPlayerControl()
	{
		GetACSUIManager().SetKeybindsStatus(false); //unlock shortcut keys
		GetGame().GetMission().PlayerControlEnable(false);
		GetGame().GetInput().ResetGameFocus();
		GetGame().GetUIManager().ShowUICursor( false );
		GetGame().GetMission().GetHud().Show( true );
		m_GameFocus = true;
	}
	
	/* Widget Events */
	override bool OnClick( Widget w, int x, int y, int button )
	{
		return super.OnClick( w, x, y, button );
	}

	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		return super.OnMouseButtonDown( w, x, y, button);
	}

	override bool OnMouseWheel(Widget  w, int  x, int  y, int wheel)
	{
		return super.OnMouseWheel( w, x, y, wheel);
	}

	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		return super.OnChange( w, x, y, finished);
	}
	
     override bool OnMouseEnter( Widget w, int x, int y )
	{
		return super.OnMouseEnter( w, x, y );
	}
	
	override bool OnMouseLeave( Widget w, Widget enterW, int x, int y )
	{
		return super.OnMouseLeave( w, enterW, x, y );
	}
	
	string GetTypeName(){
		return ClassName();
	}

	typename GetType(){
		return GetTypeName().ToType();
	}
};