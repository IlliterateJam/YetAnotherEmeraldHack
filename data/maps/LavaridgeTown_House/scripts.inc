.set LOCALID_MOVE_RELEARNER, 1

LavaridgeTown_House_MapScripts::
	.byte 0


LavaridgeTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, LavaridgeTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LavaridgeTown_MoveRelearnersHouse_EventScript_ComeBack
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LavaridgeTown_MoveRelearnersHouse_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, LavaridgeTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMon
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_ComeBack
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto LavaridgeTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

LavaridgeTown_MoveRelearnersHouse_EventScript_ComeBack::
	msgbox LavaridgeTown_MoveRelearnersHouse_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end




LavaridgeTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Ahh young one, welcome to our peaceful\n"
	.string "town. I'm the local MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn, every one of them in fact, and I\l"
	.string "can teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "It's a most agreeable affair!$"

LavaridgeTown_MoveRelearnersHouse_Text_WantMeToTeachMove:
	.string "Are you in need of assistance for\n"
	.string "relearning a move?$"

LavaridgeTown_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which one of your POKéMON needs tutoring?$"

LavaridgeTown_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

LavaridgeTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Ahh…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"


LavaridgeTown_MoveRelearnersHouse_Text_ComeBack:
	.string "If your POKéMON need to learn a move,\n"
	.string "feel free to come back anytime!$"


LavaridgeTown_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Ahh… There isn't a single move that\n"
	.string "I can teach an EGG.$"




LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings:
	.string "My wife's warming an EGG in the hot\n"
	.string "springs. This is what she told me.\p"
	.string "She left two POKéMON with the DAY CARE.\n"
	.string "And they discovered that EGG!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "ZIGZAGOON: Pshoo!$"

