.set LOCALID_MOVE_RELEARNER, 2

SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MT. PYRE…\p"
	.string "At its peak are two orbs placed side\n"
	.string "by side. Did you know?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Yes, two orbs side by side…\p"
	.string "The sight of them together…\n"
	.string "It is somehow soothing…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Is that so?\n"
	.string "Perhaps you ought to visit and see…$"




SootopolisCity_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	goto_if_set FLAG_TEMP_1, SootopolisCity_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox SootopolisCity_MoveRelearnersHouse_Text_Welcome, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_HIGH_PITCH
	msgbox SootopolisCity_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_ThisMayBeShocking, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_IcanTeachaMove, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_HIGH_PITCH
	msgbox SootopolisCity_MoveRelearnersHouse_Text_MyStory, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_Normal, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
	msgbox SootopolisCity_MoveRelearnersHouse_Text_IWasWeak, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_Dreams, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto SootopolisCity_MoveRelearnersHouse_EventScript_AskTeachMove
	end

SootopolisCity_MoveRelearnersHouse_EventScript_AskTeachMove::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_HIGH_PITCH
	msgbox SootopolisCity_MoveRelearnersHouse_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SootopolisCity_MoveRelearnersHouse_EventScript_ComeBack
	goto SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMon::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SootopolisCity_MoveRelearnersHouse_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, SootopolisCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMove
	end

SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMove::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMon
	goto SootopolisCity_MoveRelearnersHouse_EventScript_ComeBack
	end

SootopolisCity_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
	msgbox SootopolisCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

SootopolisCity_MoveRelearnersHouse_EventScript_CantTeachEgg::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_FAINT
	msgbox SootopolisCity_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto SootopolisCity_MoveRelearnersHouse_EventScript_ChooseMon
	end

SootopolisCity_MoveRelearnersHouse_EventScript_ComeBack::
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SootopolisCity_MoveRelearnersHouse_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_MoveRelearnersHouse_Text_Welcome:
	.string "Zigzagoon: Pshoo! <Welcome to\n"
	.string "Sootopolis!>$"

SootopolisCity_MoveRelearnersHouse_Text_ImTheMoveTutor:
	.string "Zigzagoon: Guguuhuh. <I'm the local\n"
	.string "MOVE TUTOR.>$"

SootopolisCity_MoveRelearnersHouse_Text_ThisMayBeShocking:
	.string "Zigzagoon: Buh buh. <This may be shocking\n"
	.string "to you, but I know all the moves that\p"
	.string "POKéMON learn--every one of them--and\n"
	.string "I can teach POKéMON those moves.>$"

SootopolisCity_MoveRelearnersHouse_Text_IcanTeachaMove:
	.string "Zigzagoon: Pshuu. <I can teach a move to \n"
	.string "a POKéMON of yours if you'd like.>\p"
	.string "… … … $"

SootopolisCity_MoveRelearnersHouse_Text_MyStory:
	.string "Zigzagoon: Bo bo bo? <Oh, my story?>$"


SootopolisCity_MoveRelearnersHouse_Text_Normal:
	.string "Zigzagoon: Gumomoh goh. <I was just a\n"
	.string "normal 'Goon until one day a kid beat\l"
	.string "me in battle.>$"

SootopolisCity_MoveRelearnersHouse_Text_IWasWeak:
	.string "Zigzagoon: Guguu guh… <I was weak in\n"
	.string "body so I decided to study the nature\l"
	.string "of POKéMON…>$"

SootopolisCity_MoveRelearnersHouse_Text_Dreams:
	.string "Zigzagoon: Kyu! <Now I have achieved my\n"
	.string "wildest dreams!>$"

SootopolisCity_MoveRelearnersHouse_Text_WantMeToTeachMove:
	.string "Zigzagoon: Pshoo? <Would you be\n"
	.string "interested in my help?>$"

SootopolisCity_MoveRelearnersHouse_Text_TutorWhichMon:
	.string "Zigzagoon: Guguu? <Which POKéMON needs\n"
	.string "tutoring?>$"

SootopolisCity_MoveRelearnersHouse_Text_TeachWhichMove:
	.string "Zigzagoon: Bo bah buh? <Which move\n"
	.string "should I teach?>$"

SootopolisCity_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
	.string "Zigzagoon: Kyuuu… <Sorry…>\p"
	.string "<It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.>$"

SootopolisCity_MoveRelearnersHouse_Text_ComeBack:
	.string "Zigzagoon: Bufufufu! <If need to learn\n"
	.string "from a POKéMON, feel free to come back\l"
	.string "anytime!>$"

SootopolisCity_MoveRelearnersHouse_Text_CantTeachEgg:
	.string "Zigzagoon: Kyuuu… <Sorry…>\p"
	.string "<There isn't a single move that\n"
	.string "I can teach an EGG.>$"
