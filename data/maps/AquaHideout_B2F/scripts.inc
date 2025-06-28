.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4
.set LOCALID_ZAPDOS, 7

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B2FOnResume @DONT FORGET!
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	call_if_set FLAG_BADGE08_GET, AquaHideout_B2FEventScript_SetZapdosState
	end

AquaHideout_B2FEventScript_SetZapdosState::
	call_if_set FLAG_CAUGHT_ZAPDOS, AquaHideout_B2FEventScript_HideZapdos
	call_if_unset FLAG_CAUGHT_ZAPDOS, AquaHideout_B2FEventScript_TryShowZapdos
	end

AquaHideout_B2FEventScript_HideZapdos::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_ZAPDOS
	return

AquaHideout_B2FEventScript_TryShowZapdos::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_ZAPDOS
	return

AquaHideout_B2FOnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B2FEventScript_TryRemoveZapdos
	end

AquaHideout_B2FEventScript_TryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ZAPDOS
	return

AquaHideout_B2FEventScript_Zapdos::
	lock
	faceplayer
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	msgbox AquaHideout_B2FText_ZapdosCry, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 50
	closemessage
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B2FEventScript_DefeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B2FEventScript_RanFromZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B2FEventScript_RanFromZapdos
	setflag FLAG_DEFEATED_ZAPDOS
	releaseall
	end

AquaHideout_B2FEventScript_DefeatedZapdos::
	setflag FLAG_DEFEATED_ZAPDOS
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

AquaHideout_B2FEventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

AquaHideout_B2FText_ZapdosCry:
	.string "Gyaoo!$"

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_6, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_8, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Hehehe…\p"
	.string "Got here already, did you?\n"
	.string "We underestimated you!\p"
	.string "But this is it!\p"
	.string "I'm a cut above the GRUNTS you've seen\n"
	.string "so far.\p"
	.string "I'm not stalling for time.\n"
	.string "I'm going to pulverize you!$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Hehehe…\n"
	.string "So, I lost, too…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Hehehe!\p"
	.string "While I was toying with you, our BOSS\n"
	.string "got through his preparations!$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Hehehe!\p"
	.string "Our BOSS has already gone on his way to\n"
	.string "some cave under the sea!\p"
	.string "If you're going to give chase, you'd\n"
	.string "better search the big, wide sea beyond\l"
	.string "LILYCOVE.\p"
	.string "But will you find it then?\n"
	.string "Hehehe!$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, I grew weary of waiting!\n"
	.string "You owe me a battle, too!$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS…\n"
	.string "Is this good enough?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Warp panels, the HIDEOUT's pride\n"
	.string "and joy!\p"
	.string "You're clueless about where you are,\n"
	.string "aren't you?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom! That's our plan!$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "What's wrong with you?\n"
	.string "You're not tired at all!$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "That reminds me… I can't remember\n"
	.string "where I put the MASTER BALL.\p"
	.string "If I fail to guard it, our BOSS will\n"
	.string "chew me out…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "When I joined TEAM AQUA, the first\n"
	.string "thing I had to learn was how these\l"
	.string "warp panels connected.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "I'll have to learn about how I can\n"
	.string "battle more effectively…$"
