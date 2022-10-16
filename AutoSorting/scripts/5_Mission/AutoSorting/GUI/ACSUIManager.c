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
 * 06/03/2022 - Initial Code Development
 */
class ACSUIManager extends PluginBase
{
	private ref array<ref ACSScriptedMenu> M_SCRIPTED_UI_INSTANCES;
	
	void ACSUIManager()
	{
		M_SCRIPTED_UI_INSTANCES = new array<ref ACSScriptedMenu>;
	}
	
	override void OnInit()
	{
		Print("Client: ACSUIManager Plugin Init blud!");
	}
	
	void ~ACSUIManager()
	{
		if (!GetGame().IsClient())
			return;
		
		if (M_SCRIPTED_UI_INSTANCES)
		{
			foreach(ACSScriptedMenu menu : M_SCRIPTED_UI_INSTANCES)
			{
				if (menu != null)
				{
					Print("~ACSUIManager() :: Delete: "+menu);
					delete menu;
				}
			}
		}
	}
	bool CreateMenu(typename menuType, int menuID, UIScriptedMenu menuParent = NULL)
	{
		if (GetMenuByType(menuType) == NULL)
		{
			ACSScriptedMenu ACSMenu;
			if (Class.CastTo(ACSMenu,GetGame().GetUIManager().EnterScriptedMenu(menuID, menuParent))){
				M_SCRIPTED_UI_INSTANCES.Insert( ACSMenu );
				Print("[ACSUIManager] Menu "+ACSMenu.GetType() + " with ID: "+ menuID+ " was created");
				ACSMenu.OnInit();
				return true;
			}
		}
		
		Print("[ACSUIManager] Unable to create menu: "+menuType.ToString() + " with ID: "+menuID + " Instance probably there already silly.");
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
	
	/*
	Note: this only removes instance from the M_SCRIPTED_UI_INSTANCES array
	*/
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
	
	//true is locked
	void SetKeybindsStatus(bool state)
	{
		m_LockCommandKeybinds = state;
	}
	
	bool GetKeybindsStatus()
	{
		return m_LockCommandKeybinds;
	}
	bool IsTyping()
	{
		if (GetGame().GetUIManager().GetMenu() == null) return false;
		Widget underCursor = GetWidgetUnderCursor();
		UIScriptedMenu chatInput = GetGame().GetUIManager().FindMenu(MENU_CHAT_INPUT);
				
		if (underCursor != null && (underCursor.GetTypeID() == EditBoxWidgetTypeID || underCursor.GetTypeID() == MultilineEditBoxWidgetTypeID))
			return true;
		
		if (chatInput != null && chatInput.IsVisible())
			return true;
		
		return false;
	}
};