.set LOCALID_MOVE_RELEARNER, 3

MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


MossdeepCity_GameCorner_1F_EventScript_MoveRelearner::
	lockall
	playse SE_M_SNORE
	delay 60
	playse SE_M_SNORE
	playse SE_PIN
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_ExclamationMark
	waitmovement 8
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, MossdeepCity_GameCorner_1F_EventScript_AskTeachMove
	msgbox MossdeepCity_GameCorner_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto MossdeepCity_GameCorner_1F_EventScript_AskTeachMove
	end

MossdeepCity_GameCorner_1F_EventScript_AskTeachMove::
	msgbox MossdeepCity_GameCorner_1F_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, MossdeepCity_GameCorner_1F_EventScript_ComeBack
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseMon
	end

MossdeepCity_GameCorner_1F_EventScript_ChooseMon::
	msgbox MossdeepCity_GameCorner_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MossdeepCity_GameCorner_1F_EventScript_ComeBack
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_GameCorner_1F_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, MossdeepCity_GameCorner_1F_EventScript_NoMoveToTeachMon
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseMove
	end

MossdeepCity_GameCorner_1F_EventScript_ChooseMove::
	msgbox MossdeepCity_GameCorner_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, MossdeepCity_GameCorner_1F_EventScript_ChooseMon
	goto MossdeepCity_GameCorner_1F_EventScript_ComeBack
	end

MossdeepCity_GameCorner_1F_EventScript_NoMoveToTeachMon::
	msgbox MossdeepCity_GameCorner_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseMon
	end

MossdeepCity_GameCorner_1F_EventScript_CantTeachEgg::
	msgbox MossdeepCity_GameCorner_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto MossdeepCity_GameCorner_1F_EventScript_ChooseMon
	end

MossdeepCity_GameCorner_1F_EventScript_ComeBack::
	msgbox MossdeepCity_GameCorner_1F_Text_ComeBack, MSGBOX_DEFAULT
	releaseall
	end


MossdeepCity_GameCorner_1F_Text_ImTheMoveTutor:
	.string "…Yawn…\p"
	.string "Uh…\p"
	.string "Sorry, it's boring at the cable club with\n"
	.string "no friends to play Dodrio Picking…\p"
	.string "…Yawn… I'm the local MOVE TUTOR\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like…\p"
	.string "…\p"
	.string "…Zzz…$"

MossdeepCity_GameCorner_1F_Text_WantMeToTeachMove:
	.string "…Zzz-oh do you need my help?$"

MossdeepCity_GameCorner_1F_Text_TutorWhichMon:
	.string "Uh, which POKéMON needs tutoring…$"

MossdeepCity_GameCorner_1F_Text_TeachWhichMove:
	.string "Which …yawn… move should I teach?$"

MossdeepCity_GameCorner_1F_Text_DontHaveMoveToTeachPokemon:
	.string "Zzz…\p"
	.string "Uh, it doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"


MossdeepCity_GameCorner_1F_Text_ComeBack:
	.string "Wake me up when you need me again…\p"
	.string "…\p"
	.string "Zzz…$"

MossdeepCity_GameCorner_1F_Text_CantTeachEgg:
	.string "zzz… Uh, there isn't a single move that\n"
	.string "I can teach an EGG.$"



@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "When I was young, I traveled the world\n"
	.string "as a POKéMON TRAINER.\p"
	.string "Now that I've become an old buzzard,\n"
	.string "my only amusement is watching young\l"
	.string "TRAINERS battle.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "The door appears to be locked.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "A TRAINER named {STR_VAR_1} is\n"
	.string "visiting my home.\p"
	.string "Would you like to challenge\n"
	.string "{STR_VAR_1}?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "You won't battle? I'm disappointed\n"
	.string "that I can't see you battle…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, good, good!\p"
	.string "But my house isn't all that sturdy.\p"
	.string "Could I ask you to keep it down to\n"
	.string "a 3-on-3 match?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Before you two battle, you should\n"
	.string "save your progress.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "I hope to see a good match!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "So, it became a standoff.\p"
	.string "It was a brilliant match in which\n"
	.string "neither side conceded a step!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "That was superlative!\p"
	.string "Why, it was like seeing myself in\n"
	.string "my youth again!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, too bad for you!\p"
	.string "But it was a good match.\n"
	.string "I hope you can win next time.$"
