.set LOCALID_MOVE_RELEARNER, 1

FortreeCity_MoveTutor_MapScripts::
	.byte 0

FortreeCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FortreeCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FortreeCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FortreeCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FortreeCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	msgbox FortreeCity_MoveRelearnersHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FortreeCity_MoveRelearnersHouse_EventScript_ComeBack
	goto FortreeCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

FortreeCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FortreeCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_MoveRelearnersHouse_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FortreeCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FortreeCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

FortreeCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FortreeCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FortreeCity_MoveRelearnersHouse_EventScript_ChooseMon
	goto FortreeCity_MoveRelearnersHouse_EventScript_ComeBack
	end

FortreeCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FortreeCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FortreeCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

FortreeCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FortreeCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FortreeCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

FortreeCity_MoveRelearnersHouse_EventScript_ComeBack::
	msgbox FortreeCity_MoveRelearnersHouse_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end


FortreeCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Huh? What do you want?\p"
	.string "Can't you see I'm busy here?\p"
	.string "So what if I'm the local MOVE TUTOR?\p"
	.string "I'm not going to give you that boring old\n"
	.string "speech that we are all required to say.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--blah blah blah.\p"
	.string "Waste of everyone's time.$"

FortreeCity_MoveRelearnersHouse_Text_WantMeToTeachMove:
	.string "Quite dwaddling around! Do you want me to\n"
	.string "teach your POKéMON a move?$"

FortreeCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Sigh… I guess you really need my help…$"

FortreeCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "… Pick a move already would you?$"

FortreeCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Pay attention!\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"


FortreeCity_MoveRelearnersHouse_Text_ComeBack:
	.string "If you come back, don't waste my time.$"

@Huh???

FortreeCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "You aren't paying attention! There isn't a\n"
	.string "single move that I can teach an EGG.$"
