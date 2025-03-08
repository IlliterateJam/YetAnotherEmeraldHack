MauvilleCity_MoveTutor_MapScripts::
	.byte 0

MauvilleCity_MoveRelearner_EventScript_MoveRelearner::
	lockall
	faceplayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, MauvilleCity_MoveRelearner_EventScript_AskTeachMove
	msgbox MauvilleCity_MoveRelearner_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto MauvilleCity_MoveRelearner_EventScript_AskTeachMove
	end

MauvilleCity_MoveRelearner_EventScript_AskTeachMove::
	msgbox MauvilleCity_MoveRelearner_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MauvilleCity_MoveRelearner_EventScript_ComeBack
	goto MauvilleCity_MoveRelearner_EventScript_ChooseMon
	end

MauvilleCity_MoveRelearner_EventScript_ChooseMon::
	msgbox MauvilleCity_MoveRelearner_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_MoveRelearner_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_MoveRelearner_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, MauvilleCity_MoveRelearner_EventScript_NoMoveToTeachMon
	goto MauvilleCity_MoveRelearner_EventScript_ChooseMove
	end

MauvilleCity_MoveRelearner_EventScript_ChooseMove::
	lockall
	msgbox MauvilleCity_MoveRelearner_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_MoveRelearner_EventScript_ChooseMon
	goto MauvilleCity_MoveRelearner_EventScript_ComeBack
	end

MauvilleCity_MoveRelearner_EventScript_NoMoveToTeachMon::
	msgbox MauvilleCity_MoveRelearner_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto MauvilleCity_MoveRelearner_EventScript_ChooseMon
	end

MauvilleCity_MoveRelearner_EventScript_CantTeachEgg::
	msgbox MauvilleCity_MoveRelearner_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto MauvilleCity_MoveRelearner_EventScript_ChooseMon
	end

MauvilleCity_MoveRelearner_EventScript_ComeBack::
	lockall
	msgbox MauvilleCity_MoveRelearner_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_MoveRelearner_Text_ImTheMoveTutor:
	.string "HEY WHAT'S UP FELLOW TRAINER!\n"
	.string "IM THE MAUVILLE MOVE TUTOR!\p"
	.string "I KNOW ALL THE MOVES THAT POKéMON\n"
	.string "LEARN--EVERY ONE OF THEM--AND I CAN\l"
	.string "TEACH POKéMON THOSE MOVES!\p"
	.string "I CAN TEACH A MOVE TO A POKéMON\n"
	.string "OF YOURS IF YOU'D LIKE!\p"
	.string "DOES THAT MAKE SENSE?!$"

MauvilleCity_MoveRelearner_Text_WantMeToTeachMove:
	.string "ARE YOUR POKéMON READY TO DO\n"
	.string "SOMETHING AWESOME?!$"

MauvilleCity_MoveRelearner_Text_TutorWhichMon:
	.string "WHICH POKéMON NEEDS TUTORING?!$"

MauvilleCity_MoveRelearner_Text_TeachWhichMove:
	.string "WHICH MOVE SHOULD I TEACH?!$"

MauvilleCity_MoveRelearner_Text_DontHaveMoveToTeachPokemon:
	.string "HUH?! IMPOSSIBLE!\p"
	.string "IT DOESN'T APPEAR AS IF I HAVE ANY\n"
	.string "MOVE I CAN TEACH THAT POKéMON!$"

MauvilleCity_MoveRelearner_Text_ComeBack:
	.string "I LIKE YOU FELLOW TRAINER!\n"
	.string "COME BACK ANYTIME YOU WANT!$"

MauvilleCity_MoveRelearner_Text_CantTeachEgg:
	.string "HUH?! YOUR KIDDING!\n"
	.string "THERE ISN'T A SINGLE MOVE THAT\l"
	.string "I CAN TEACH AN EGG!$"
