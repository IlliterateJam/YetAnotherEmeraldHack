.set LOCALID_MOVE_RELEARNER, 1

FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_Eventscript_Display::
	goto_if_set FLAG_GAVE_HEART_SCALES, FallarborTown_MoveRelearnersHouse_Eventscript_FullDisplay
	msgbox FallarborTown_MoveRelearnersHouse_Text_EmptyDisplay, MSGBOX_SIGN
	end

FallarborTown_MoveRelearnersHouse_Eventscript_FullDisplay::
	msgbox FallarborTown_MoveRelearnersHouse_Text_FullDisplay, MSGBOX_SIGN
	end

FallarborTown_MoveRelearnersHouse_Eventscript_AbilityAficionado::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_GoToShop
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheAficionado, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_GoToShop
	end

FallarborTown_MoveRelearnersHouse_EventScript_GoToShop::
	goto_if_set FLAG_GAVE_HEART_SCALES, FallarborTown_MoveRelearnersHouse_EventScript_ExpandedShop
	msgbox FallarborTown_MoveRelearnersHouse_Text_CouldYouUnderstand, MSGBOX_DEFAULT
	checkitem ITEM_HEART_SCALE, 7
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NormalShop
	msgbox FallarborTown_MoveRelearnersHouse_Text_GiveMeHeartScales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_GiveHeartScales
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_DeclineGiveHeartScales
	end

FallarborTown_MoveRelearnersHouse_EventScript_GiveHeartScales::
	removeitem ITEM_HEART_SCALE, 7
	setflag FLAG_GAVE_HEART_SCALES
 	msgbox FallarborTown_MoveRelearnersHouse_Text_ThankYou, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ExpandedShop
	end

FallarborTown_MoveRelearnersHouse_EventScript_DeclineGiveHeartScales::
	msgbox FallarborTown_MoveRelearnersHouse_Text_HeartScalesDeclined, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_NormalShop
	end 

FallarborTown_MoveRelearnersHouse_EventScript_NormalShop::
	msgbox FallarborTown_MoveRelearnersHouse_Text_AbilityCapsule, MSGBOX_DEFAULT
	pokemart FallarborTown_Mart_AbilityAficionado_Normal
	msgbox FallarborTown_MoveRelearnersHouse_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_AbilityAficionado_Normal:
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_NONE
	release
	end

FallarborTown_MoveRelearnersHouse_EventScript_ExpandedShop::
	msgbox FallarborTown_MoveRelearnersHouse_Text_AbilityPatch, MSGBOX_DEFAULT
	pokemart FallarborTown_Mart_AbilityAficionado_Expanded
	msgbox FallarborTown_MoveRelearnersHouse_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FallarborTown_Mart_AbilityAficionado_Expanded:
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_NONE
	release
	end


FallarborTown_MoveRelearnersHouse_Text_ImTheAficionado:
	.string "I'm the ABILITY AFICIONADO.\p"
	.string "I've surpassed the practice of\n"
	.string "move tutoring to develop the practice\l"
	.string "of unlocking a POKéMON's potential.\p"
	.string "I have distilled all of my teaching\n"
	.string "into medicine form.$"

FallarborTown_MoveRelearnersHouse_Text_CouldYouUnderstand:
	.string "Though I doubt you can fathom the skill\n"
	.string "and time it takes to be an aficionado.\p"
	.string "You probably even couldn't be a simple\n"
	.string "HEART SCALE collector…$"

FallarborTown_MoveRelearnersHouse_Text_GiveMeHeartScales:
	.string "… Wait! I've seem to underestimate you!\p"
	.string "Those SEVEN HEART SCALES you have would be\n"
	.string "perfect for my collection.\p"
	.string "How about if you give them to me, I'll\n"
	.string "give you full access to my creations, OK?$"

FallarborTown_MoveRelearnersHouse_Text_ThankYou:
	.string "… And its a done deal.\n"
	.string "You are a smart kid, you know.$"

FallarborTown_MoveRelearnersHouse_Text_HeartScalesDeclined:
	.string "You don't want access to my full wares?\p"
	.string "You know, I somewhat respect it from one\n"
	.string "collector to another.\p"
	.string "Anyways…$"


FallarborTown_MoveRelearnersHouse_Text_AbilityCapsule:
	.string "I am still happy to be of service.\n"
	.string "Here is just a taste of my finest creations.$"

FallarborTown_MoveRelearnersHouse_Text_AbilityPatch:
	.string "Fellow aficionado, let us relish in\n"
	.string "unlocking a POKéMON's hidden potential!$\p"

FallarborTown_MoveRelearnersHouse_Text_PleaseComeAgain:
	.string "Please come back when you require the\n"
	.string "service of the ABILITY AFICIONADO.$"

FallarborTown_MoveRelearnersHouse_Text_EmptyDisplay:
	.string "An ornate display of rare collectables.\p"
	.string "There are SEVEN missing slots in a\n"
	.string "rainbow pattern.$"

FallarborTown_MoveRelearnersHouse_Text_FullDisplay:
	.string "An ornate display of rare collectables.\p"
	.string "There are SEVEN HEART SCALES in a\n"
	.string "rainbow pattern.$"


@Old Code to not break debug cuz Im lazy

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "I'll do it for a HEART SCALE.\n"
	.string "I'm collecting those now.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
	.string "Oh! That's it! That's an honest to\n"
	.string "goodness HEART SCALE!\p"
	.string "Let me guess, you want me to teach\n"
	.string "a move?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
	.string "If your POKéMON need to learn a move,\n"
	.string "come back with a HEART SCALE.$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"
