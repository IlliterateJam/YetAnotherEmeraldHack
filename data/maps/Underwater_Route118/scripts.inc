Underwater_Route118_MapScripts::
	.byte 0

Underwater_Route118_Eventscript_StrangeSymbols::
	lockall
	braillemsgbox Route118_Braille_Message
	releaseall
	end

Underwater_Route118_Eventscript_StrangeButton::
	msgbox Underwater_Route118_Text_StrangeButton, MSGBOX_DEFAULT
	waitmessage 
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, Underwater_Route118_Eventscript_AlteringCaveIncrement
	goto_if_eq VAR_RESULT, NO, Underwater_Route118_Eventscript_Decline
	end

Underwater_Route118_Eventscript_AlteringCaveIncrement::
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	goto_if_ne VAR_ALTERING_CAVE_WILD_SET, 6, Underwater_Route118_Eventscript_SomethingHappens
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
	goto Underwater_Route118_Eventscript_SomethingHappens
	end

Underwater_Route118_Eventscript_SomethingHappens::
	msgbox Underwater_Route118_Text_PressButton, MSGBOX_DEFAULT
	waitmessage
	playse SE_SWITCH
	waitse
	delay 40
	msgbox Underwater_Route118_Text_WhatHappened, MSGBOX_DEFAULT
	releaseall
	end

Underwater_Route118_Eventscript_Decline::
	msgbox Underwater_Route118_Text_NothingHappens, MSGBOX_DEFAULT
	releaseall
	end

Underwater_Route118_Text_StrangeButton:
	.string "You notice a strange button carved\n"
	.string "on the rock face.\p"
	.string "Do you want to press it?$"

Underwater_Route118_Text_PressButton:
	.string "{PLAYER} pressed the button.$"

Underwater_Route118_Text_WhatHappened:
	.string "Nothing else happens.\p"
	.string "Maybe you will find out one day.$"

Underwater_Route118_Text_NothingHappens:
	.string "You decide not to press it.\n"
	.string "For sure nothing will come about it.$"

