/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: moddedrecipe.c
 *  
 * Class Information:
 *
 * Class handles recipe modification
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 06/03/2022 - Initial Code Development
 */

modded class PluginRecipesManager
{
	override void RegisterRecipes() {
		super.RegisterRecipes();
		RegisterRecipe(new ACSSortingHatCraft);
	}
}