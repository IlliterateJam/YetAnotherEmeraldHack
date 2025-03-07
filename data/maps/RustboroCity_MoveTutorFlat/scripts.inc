.set LOCALID_MOVE_RELEARNER, 2
.set LOCALID_SON, 1
.set LOCALID_BROTHER, 3

RustboroCity_MoveTutorFlat_MapScripts::
	.byte 0

RustboroCity_MoveRelearnersFlat_EventScript_Mat::
	msgbox RustboroCity_MoveRelearnersFlat_Text_Mat, MSGBOX_SIGN
	end

RustboroCity_MoveRelearnersFlat_EventScript_Son::
	lock
	faceplayer
	msgbox RustboroCity_MoveRelearnersFlat_Text_IHaveRolledOnlyOnes, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SON, Common_Movement_FaceRight
	waitmovement 0
	release
	end
	
RustboroCity_MoveRelearnersFlat_EventScript_Brother::
	lock
	faceplayer
	msgbox RustboroCity_MoveRelearnersFlat_Text_MyBuildIsUnstoppable, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BROTHER, Common_Movement_FaceRight
	waitmovement 0
	release
	end


RustboroCity_MoveRelearnersFlat_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, RustboroCity_MoveRelearnersFlat_EventScript_AskTeachMove
	msgbox RustboroCity_MoveRelearnersFlat_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto RustboroCity_MoveRelearnersFlat_EventScript_AskTeachMove
	end

RustboroCity_MoveRelearnersFlat_EventScript_AskTeachMove::
	msgbox RustboroCity_MoveRelearnersFlat_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RustboroCity_MoveRelearnersFlat_EventScript_ComeBack
	goto RustboroCity_MoveRelearnersFlat_EventScript_ChooseMon
	end

RustboroCity_MoveRelearnersFlat_EventScript_ChooseMon::
	msgbox RustboroCity_MoveRelearnersFlat_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_MoveRelearnersFlat_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_MoveRelearnersFlat_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, RustboroCity_MoveRelearnersFlat_EventScript_NoMoveToTeachMon
	goto RustboroCity_MoveRelearnersFlat_EventScript_ChooseMove
	end

RustboroCity_MoveRelearnersFlat_EventScript_ChooseMove::
	msgbox RustboroCity_MoveRelearnersFlat_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, RustboroCity_MoveRelearnersFlat_EventScript_ChooseMon
	goto RustboroCity_MoveRelearnersFlat_EventScript_ComeBack
	end

RustboroCity_MoveRelearnersFlat_EventScript_NoMoveToTeachMon::
	msgbox RustboroCity_MoveRelearnersFlat_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto RustboroCity_MoveRelearnersFlat_EventScript_ChooseMon
	end

RustboroCity_MoveRelearnersFlat_EventScript_CantTeachEgg::
	msgbox RustboroCity_MoveRelearnersFlat_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto RustboroCity_MoveRelearnersFlat_EventScript_ChooseMon
	end

RustboroCity_MoveRelearnersFlat_EventScript_ComeBack::
	msgbox RustboroCity_MoveRelearnersFlat_Text_ComeBack, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FaceLeft
	waitmovement 0
	releaseall
	end

RustboroCity_MoveRelearnersFlat_Text_ImTheMoveTutor:
	.string "Huh? Oh hello, I was too busy trying\n"
	.string "playing POCKET DUNGEONS AND MONSTERS.\p"
	.string "I'm Rustboro's MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.$"

RustboroCity_MoveRelearnersFlat_Text_WantMeToTeachMove:
	.string "Are you ready for for me help build\n"
	.string "your POKéMON's moveset?$"

RustboroCity_MoveRelearnersFlat_Text_TutorWhichMon:
	.string "Which POKéMON needs tutoring?$"

RustboroCity_MoveRelearnersFlat_Text_TeachWhichMove:
	.string "Which move should I teach?$"

RustboroCity_MoveRelearnersFlat_Text_DontHaveMoveToTeachPokemon:
	.string "Hmmm…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"


RustboroCity_MoveRelearnersFlat_Text_ComeBack:
	.string "Come back if your POKéMON need to\n"
	.string "learn a move.\l"
	.string "Oh! its my turn now…$"


RustboroCity_MoveRelearnersFlat_Text_CantTeachEgg:
	.string "Hmmm… There isn't a single move that\n"
	.string "I can teach an EGG.$"

RustboroCity_MoveRelearnersFlat_Text_IHaveRolledOnlyOnes::
	.string "I certainly do not have the ability\n"
	.string "SUPER LUCK. I've only rolled ones…$"

RustboroCity_MoveRelearnersFlat_Text_MyBuildIsUnstoppable::
	.string "My POCKET MONSTER is unstoppable!\n"
	.string "It has 31 IVs in all stats!$"

RustboroCity_MoveRelearnersFlat_Text_Mat::
	.string "The mat has various minatures that\n"
	.string "are ready for an adventure.$"