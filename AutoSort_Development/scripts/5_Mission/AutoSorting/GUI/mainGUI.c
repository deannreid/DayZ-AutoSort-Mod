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

class mainGUI extends UIScriptedMenu
{
	protected Widget w_acsRootGUI;
	
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
	
	override Widget Init()
    {
		layoutRoot		= GetGame().GetWorkspace().CreateWidgets( "AutoSort/gui/layouts/ACSMain.layout" );
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
		
		if (button == MouseState.LEFT)
        {
			if(w == btnSortAll) {	
				
			} else if (w == btnWeapons) {
				
				return true;
			} else if (w == btnAmmo) {
				
				return true;
			} else if (w == btnMags) {
				
				return true;
			} else if (w == btnAttachments) {
				
				return true;
			} else if (w == btnConsumables) {
				
				return true;
			} else if (w == btnAttire) {
				
				return true;
			} else if (w == btnArmor) {
				
				return true;
			} else if (w == btnTools) {
				
				return true;
			} else if (w == btnElectrical) {
				
				return true;
			} else if (w == btnResources) {
				
				return true;
			} else if (w == btnSpare) {
				
				return true;
			} else if (w == btnMisc) { 
			
				return true;
			} else if (w == btnHelpMePls) {
				GetGame().OpenURL( "https://www.youtube.com/watch?v=o-YBDTqX_ZU" );
				return true;
				
			} else if (w == btn_back) {
				GetGame().GetUIManager().HideScriptedMenu(this);
				delete this;
				return true;
			}
		}
		return false;
	}
}


