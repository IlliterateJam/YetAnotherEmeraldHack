DewfordTown_House3_MapScripts::
	.byte 0

DewfordTown_House3_MoveRelearner_EventScript_MoveRelearner::
	lockall
	faceplayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, DewfordTown_House3_MoveRelearner_EventScript_AskTeachMove
	msgbox DewfordTown_House3_MoveRelearner_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto DewfordTown_House3_MoveRelearner_EventScript_AskTeachMove
	end

DewfordTown_House3_MoveRelearner_EventScript_AskTeachMove::
	msgbox DewfordTown_House3_MoveRelearner_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, DewfordTown_House3_MoveRelearner_EventScript_ComeBack
	goto DewfordTown_House3_MoveRelearner_EventScript_ChooseMon
	end

DewfordTown_House3_MoveRelearner_EventScript_ChooseMon::
	msgbox DewfordTown_House3_MoveRelearner_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, DewfordTown_House3_MoveRelearner_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_House3_MoveRelearner_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, DewfordTown_House3_MoveRelearner_EventScript_NoMoveToTeachMon
	goto DewfordTown_House3_MoveRelearner_EventScript_ChooseMove
	end

DewfordTown_House3_MoveRelearner_EventScript_ChooseMove::
	lockall
	msgbox DewfordTown_House3_MoveRelearner_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, DewfordTown_House3_MoveRelearner_EventScript_ChooseMon
	goto DewfordTown_House3_MoveRelearner_EventScript_ComeBack
	end

DewfordTown_House3_MoveRelearner_EventScript_NoMoveToTeachMon::
	msgbox DewfordTown_House3_MoveRelearner_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto DewfordTown_House3_MoveRelearner_EventScript_ChooseMon
	end

DewfordTown_House3_MoveRelearner_EventScript_CantTeachEgg::
	msgbox DewfordTown_House3_MoveRelearner_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto DewfordTown_House3_MoveRelearner_EventScript_ChooseMon
	end

DewfordTown_House3_MoveRelearner_EventScript_ComeBack::
	lockall
	msgbox DewfordTown_House3_MoveRelearner_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end




DewfordTown_House3_MoveRelearner_Text_ImTheMoveTutor:
	.string "Ahh, nothing like cooking a big\n"
	.string "meal after a day on the beach.\p"
	.string "My bad, as a MOVE TUTOR I should\n"
	.string "be doing my job fufufu!\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours out here if you'd like.$"

DewfordTown_House3_MoveRelearner_Text_WantMeToTeachMove:
	.string "Do your POKéMON want to learn\n"
	.string "some moves?$"

DewfordTown_House3_MoveRelearner_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

DewfordTown_House3_MoveRelearner_Text_TeachWhichMove:
	.string "Which move should I teach?$"

DewfordTown_House3_MoveRelearner_Text_DontHaveMoveToTeachPokemon:
	.string "Ahh…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

DewfordTown_House3_MoveRelearner_Text_ComeBack:
	.string "If your POKéMON need to learn a move,\n"
	.string "you know where to find me!$"

DewfordTown_House3_MoveRelearner_Text_CantTeachEgg:
	.string "Ahh… There isn't a single move that\n"
	.string "I can teach an EGG.$"