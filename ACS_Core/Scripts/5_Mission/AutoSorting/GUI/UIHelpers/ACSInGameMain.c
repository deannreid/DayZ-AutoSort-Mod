/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: ACSMainUI.c
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

class ACSInGameMain extends UIScriptedMenu
{
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
    ButtonWidget	btnReturn;	
	ButtonWidget    btnHelpMePls;
	
	void ACSInGameMain() {}
	void ~ACSInGameMain() {}
	
	override Widget Init()
    {
		layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "ACS_Core/Assets/Layouts/UIPlayer/ACSInGameMain.layout" );

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
		btnReturn 		= ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnReturn" ) );
		btnHelpMePls    = ButtonWidget.Cast( layoutRoot.FindAnyWidget( "btnHelpMePls" ) );
		img_background 	= ImageWidget.Cast( layoutRoot.FindAnyWidget( "imgBackground" ) );
		//img_background.LoadImageFile( 0, "set:ACS_SortMenu image:BuildWheel" );

        return layoutRoot;
	}
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);
	}
	
    override void OnShow()
    {
		g_Game.GetUIManager().ShowUICursor(true);
        g_Game.GetUIManager().ShowCursor(true);
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetInput().ChangeGameFocus( 1 );
        GetGame().GetMission().GetHud().Show( false );
    }

    override void OnHide()
    {
        g_Game.GetUIManager().ShowCursor(false);
        g_Game.GetUIManager().ShowUICursor(false);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetMission().PlayerControlEnable(false);
        GetGame().GetUIManager().Back();
        GetGame().GetMission().GetHud().Show( true );
    }	
	override bool OnClick(Widget w, int x, int y, int button)
    {
		super.OnClick(w, x, y, button);
		
		/*
		* TODO: Logic
		*/
		if (button == MouseState.LEFT)
        {
			if(w == btnSortAll) {	
				Print("[ACSUI] :: btnSortAll");
			} else if (w == btnWeapons) {
				Print("[ACSUI] :: btnWeapons");
				return true;
			} else if (w == btnAmmo) {
				Print("[ACSUI] :: btnAmmo");
				return true;
			} else if (w == btnMags) {
				Print("[ACSUI] :: btnMags");
				return true;
			} else if (w == btnAttachments) {
				Print("[ACSUI] :: btnAttachments");
				return true;
			} else if (w == btnConsumables) {
				Print("[ACSUI] :: btnConsumables");
				return true;
			} else if (w == btnAttire) {
				Print("[ACSUI] :: btnAttire");
				return true;
			} else if (w == btnArmor) {
				Print("[ACSUI] :: btnArmor");
				return true;
			} else if (w == btnTools) {
				Print("[ACSUI] :: btnTools");
				return true;
			} else if (w == btnElectrical) {
				Print("[ACSUI] :: btnElectrical");
				return true;
			} else if (w == btnResources) {
				Print("[ACSUI] :: btnResources");
				return true;
			} else if (w == btnSpare) {
				Print("[ACSUI] :: btnSpare");
				return true;
			} else if (w == btnMisc) { 
			Print("[ACSUI] :: btnMisc");
				return true;
			} else if (w == btnHelpMePls) {
				Print("[ACSUI] :: btnHelpMePls");
				GetGame().OpenURL( "https://www.youtube.com/watch?v=o-YBDTqX_ZU" );
				return true;
				
			} else if (w == btnReturn) {
				Print("[ACSUI] :: btnReturn");
				GetGame().GetUIManager().HideScriptedMenu(this);
				delete this;
				return true;
			}
		}
		return false;
	}
}

