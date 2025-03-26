FireyPath_Connection_MapScripts::
	.byte 0

FireyPath_EventScript_LargeMachine::
	message FireyPath_Text_ThisIsALargeMachine
	waitbuttonpress
	goto EventScript_Headbutt
	end

FireyPath_Text_ThisIsALargeMachine:
	.string "A large machine.$"
