/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: ACSSortingHatCraft.c
 *  
 * Class Information:
 *
 * Class handles base mission
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

class ACSSortingHatCraft extends RecipeBase {

	override void Init(){
		m_Name = "Craft Sorting Hat Kit"; 
		m_IsInstaRecipe = false; // Should animation be shown to craft? -- Config Option will override.
		m_AnimationLength = 1; // Length of animation in relative time units
		m_Specialty = 0.01; // Value > 0 for roughness or < 0 for precision
		
		
		//CheckConditions
		m_MinDamageIngredient[0] = -1;   //-1 == Disable Check
		m_MaxDamageIngredient[0] = -1;   //-1 == Disable Check
		
		m_MinQuantityIngredient[0] = -1; //-1 == Disable Check
		m_MaxQuantityIngredient[0] = -1; //-1 == Disable Check
		
		m_MinDamageIngredient[1] = -1;   //-1 == Disable Check
		m_MaxDamageIngredient[1] = -1;   //-1 == Disable Check
		
		m_MinQuantityIngredient[1] = -1; //-1 == Disable Check
		m_MaxQuantityIngredient[1] = -1; //-1 == Disable Check
		
		
		//Ingredients
		//Ingredient 1
		InsertIngredient(0,"BeanieHat_Beige");
		m_IngredientAddHealth[0]   	 = -1;     	//-1 == Disable Check	
		m_IngredientsSetHealth[0] 	 = -1;    	//-1 == Disable Check
		m_IngredientAddQuantity[0] 	 = -1;   	//-1 == Disable Check
		m_IngredientDestroy[0] 	  	 = -1;      //-1 == Disable Check
		m_IngredientDestroy[0] 	   	 = true;    // True = Destroy, False = Don't
		m_IngredientUseSoftSkills[0] = -1; 	 	//-1 == Disable Check

		//Ingredient 2
		InsertIngredient(0,"BandageDressing");
		m_IngredientAddHealth[0]   	 = -1;     	//-1 == Disable Check	
		m_IngredientsSetHealth[0] 	 = -1;    	//-1 == Disable Check
		m_IngredientAddQuantity[0] 	 = -1;   	//-1 == Disable Check
		m_IngredientDestroy[0] 	  	 = -1;      //-1 == Disable Check
		m_IngredientDestroy[0] 	   	 = true;    // True = Destroy, False = Don't
		m_IngredientUseSoftSkills[0] = -1; 	 	//-1 == Disable Check

		//Result
		AddResult("ACS_SortingHat");
		m_ResultSetFullQuantity[0] = false; //True = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1; //-1 = do nothing
		m_ResultSetHealth[0] = -1; //-1 = do nothing
		m_ResultInheritsHealth[0] = -1;
		m_ResultInheritsColor[0] = -1;
		m_ResultToInventory[0] = -2;
		m_ResultUseSoftSkills[0] = false;
		m_ResultReplacesIngredient[0] = -1;
	}
	
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, fload specialty_weight) // Called when complete
	{
		Print("[ACS - ACSCrafted - Debug] ACS Item Crafted");
	}
};