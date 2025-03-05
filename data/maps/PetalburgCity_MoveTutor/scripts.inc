.set LOCALID_MOVE_RELEARNER, 1

PetalburgCity_MoveTutor_MapScripts::
	.byte 0

PetalburgCity_MoveRelearnersHouse_EventScript_Kid::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_TheMoveTutorGroup, MSGBOX_NPC
	end

PetalburgCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, PetalburgCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox PetalburgCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PetalburgCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

PetalburgCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PetalburgCity_MoveRelearnersHouse_EventScript_ComeBack
	goto PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgCity_MoveRelearnersHouse_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, PetalburgCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMon
	goto PetalburgCity_MoveRelearnersHouse_EventScript_ComeBack
	end

PetalburgCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

PetalburgCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PetalburgCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

PetalburgCity_MoveRelearnersHouse_EventScript_ComeBack::
	msgbox PetalburgCity_MoveRelearnersHouse_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end




PetalburgCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Hello! Welcome to Petalburg City!\p"
	.string "I'm your local MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"
	.string "It's completely free!$"

PetalburgCity_MoveRelearnersHouse_Text_WantMeToTeachMove:
	.string "Would you be interested in\n"
	.string "my help?$"

PetalburgCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

PetalburgCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Which move should I teach?$"

PetalburgCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"


PetalburgCity_MoveRelearnersHouse_Text_ComeBack:
	.string "If your POKéMON need to learn a move,\n"
	.string "feel free to come back anytime!$"

@Huh???

PetalburgCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Sorry… There isn't a single move that\n"
	.string "I can teach an EGG.$"

PetalburgCity_MoveRelearnersHouse_Text_TheMoveTutorGroup::
	.string "My mommy is part of a group that helps\n"
	.string "trainers all around HOENN!"
