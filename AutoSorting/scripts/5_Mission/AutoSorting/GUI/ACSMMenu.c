/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: mainGUI.c
 *  
 * Class Information:
 *
 * Class handles the main user interface.
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 10/03/2022 - Initial Code Development
 */

class ACSMMenu extends UIScriptedMenu
{
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	protected Widget w_Root;
	
    ImageWidget		img_background;
    ButtonWidget	btnSortAll;
    ButtonWidget	btnWeapons;
    ButtonWidget	btnAmmo;
    ButtonWidget	btnMags;
    ButtonWidget	btnAttachments;
    ButtonWidget	btnConsumables;
    ButtonWidget	btnAttire;
    ButtonWidget	btnArmor;
    ButtonWidget	btnTools;
    ButtonWidget	btnElectrical;
    ButtonWidget	btnResources;
    ButtonWidget	btnSpare;
    ButtonWidget	btnMisc;	
    ButtonWidget	btn_back;	
	ButtonWidget    btnHelpMePls;
	
	void ACSMMenu () {}
	void ~ACSMMenu() {}
	
	override Widget Init()
    {
		Print("[ACS UIManager] :: UI  Init");
		layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "AutoSorting/gui/layouts/ACSM_InGameMain.layout" );
		//w_Root.Show( false );
		btnSortAll		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnSortAll" ) );
		btnWeapons		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnWeapons" ) );
		btnAmmo			= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnAmmo" ) );
		btnMags			= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnMags" ) );
		btnAttachments	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnAttachments" ) );
		btnConsumables	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnConsumables" ) );
		btnAttire 	 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnAttire" ) );
		btnArmor 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnArmor" ) );
		btnTools 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnTools" ) );
		btnElectrical 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnElectrical" ) );
		btnResources 	= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnResources" ) );
		btnSpare 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnSpare" ) );
		btnMisc 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnMisc" ) );
		btn_back 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btn_back" ) );
		btnHelpMePls    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnHelpMePls" ) );
		//img_background 	= ImageWidget.Cast( layoutRoot.FindAnyWidget( "imgBackground" ) );
		//img_background.LoadImageFile( 1, "set:main_UI image:main_BG" );

        return layoutRoot;
	}
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);
	}
	
    override void OnShow()
    {
		Print("[ACS - ACSMainMenu - Debug] ACSMMenu - Show");
		    GetGame().GetUIManager().ShowUICursor(true);
    		GetGame().GetUIManager().ShowCursor(true);
    		GetGame().GetInput().ChangeGameFocus(1);
          //GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
          //GetGame().GetMission().GetHud().Show( false );
    }

    override void OnHide()
    {
		Print("[ACS - ACSMainMenu - Debug] ACSMMenu - Hide");
		    GetGame().GetUIManager().ShowCursor(false);
    		GetGame().GetUIManager().ShowUICursor(false);
    		GetGame().GetInput().ResetGameFocus();
          //GetGame().GetUIManager().Back();
          //GetGame().GetMission().GetHud().Show( true );
    }	
	
	override bool OnClick(Widget w, int x, int y, int button)
    {
		super.OnClick(w, x, y, button);
		
		if (button == MouseState.LEFT) {
			if(w == btnSortAll) {	
				
			} else if (w == btnWeapons) {
				Print( "Weapons Sorted");
				return true;
			} else if (w == btnAmmo) {
				Print( "Ammo Sorted");
				return true;
			} else if (w == btnMags) {
				Print( "Magazines Sorted");
				return true;
			} else if (w == btnAttachments) {
				Print( "Attachments Sorted");
				return true;
			} else if (w == btnConsumables) {
				Print( "Consumables Sorted");
				return true;
			} else if (w == btnAttire) {
				Print( "Attire Sorted");
				return true;
			} else if (w == btnArmor) {
				Print( "Armor Sorted");
				return true;
			} else if (w == btnTools) {
				Print( "Tools Sorted");
				return true;
			} else if (w == btnElectrical) {
				Print( "Electrical Sorted");
				return true;
			} else if (w == btnResources) {
				Print( "Resources Sorted");
				return true;
			} else if (w == btnSpare) {
				Print( "Spare Sorted");
				return true;
			} else if (w == btnMisc) { 
				Print( "Misc Items Sorted");
				return true;
			} else if (w == btnHelpMePls) {
				Print( "Help Pls");
				GetGame().OpenURL( "https://www.youtube.com/watch?v=o-YBDTqX_ZU" );
				return true;
				
			} else if (w == btn_back) {
				Print( "Exit Menu");
				GetGame().GetUIManager().HideScriptedMenu(this);
				delete this;
				return true;
			}
		}
		GetGame().GetUIManager().HideScriptedMenu(this);
		delete this;
		return false;
	}
}


