/*
 * DayZ - Storage Auto Sorter mod.
 * Developed by @Dean Reid
 *
 * Class: ACSKeybindHelper.c
 *  
 * Class Information:
 *
 * Class helps with keybinds
 * 
 * Program Version: 1.0
 * Code Version: 1.0
 * 
 * Updates: 
 * 16/10/2022 - Initial Code Development
 */
typedef Param4<int, UAIDWrapper, Class, string > ACSKeybindParam; // Mode, Wrapper, Class > Method

enum ACSBinds
{
	Press = 2,
	Release = 4, 
	Hold = 8,
	HoldBegin = 16,
	DoubleClick = 32,
	Click = 64,
};

class ACSKeybindHelper: PluginBase
{
	protected static ref ACSKeybindHelper instance;
	protected ref map < int, ref ACSKeybindParam> m_KeyWrappers;
	protected ref ScriptInvoker m_KeyInvokers;
	
	void ACSKeybindHelper()
	{
		instance = this;
		m_KeyWrappers = new map < int, ref ACSKeybindParam>;
		m_KeyInvokers = new ScriptInvoker();
	}
	
	override void OnInit(){
		Print("[ACSKeybindHelper] :: Initializing Keybind Helper.");
	}
	
	override void OnUpdate(float time)
	{
		if (m_KeyWrappers.Count() <= 0){
			return;
		}
	
		foreach(int id, ACSKeybindParam params: m_KeyWrappers)
		{
			if (!params) 
				continue;
			
			typename e = ACSBinds;
			
			for (int bit = 1, i = 0; i < e.GetVariableCount(); i++)
			{
			 bit <<= 1; 
				if (params.param1 & bit)
				{
					bool paramBuild;
					g_Script.CallFunction(params.param2.InputP(), string.Format("Local%1", typename.EnumToString(ACSBinds, bit)), paramBuild, NULL);
					
					if (paramBuild) 
					{
						g_Script.CallFunction(params.param3, params.param4, NULL, NULL,);
					}
				}
			}
		}
	}
	
	map <int, ref ACSKeybindParam> Binds()
	{
		return m_KeyWrappers;
	}
	
	/*
		Register Bind to call function.
		=======
		@Param0: inputName - Name of the UA input defined in inputsSortingHatmaster
		@Param1: mode - Bind Behavior - see enum
		@Param2: callBackFunction - Method to be called on event
		@Param3: endPoint - Instance of callback, Null = Global Call
	*/
	static void RegisterBind(string inputName, ACSBinds mode, string callBackFunc, Class endPoint = NULL)
	{
		UAInput input = GetUApi().GetInputByName(inputName);
		if (input == NULL)
		{
			Print(string.Format("[ACSKeybindHelper] RegisterBind() :: Failed to bind ["+ inputName +"] is an invalid input! check spelling on input name."));
			return;
		}
	
		ACSKeybindParam params = new ACSKeybindParam(mode, input.GetPersistentWrapper(), endPoint, callBackFunc);
		ACSKeybindHelper.GetInstance().Binds().Insert(input.ID(), params);
		Print(string.Format("[ACSKeybindHelper] RegisterBind() :: Registered bind: [%1] mode: [%2] callback function: [%3]", inputName, typename.EnumToString(ACSBinds, mode), callBackFunc));
	}
	
	static ACSKeybindHelper GetInstance()
	{
		return instance;
	}
}