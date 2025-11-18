TracklessForest_Suicune_MapScripts::
	.byte 0

.set LOCALID_SUICUNE, 0

TracklessFroest_Suicune_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TracklessFroest_Suicune_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TracklessFroest_SuicuneOnResume @DONT FORGET!
	.byte 0

TracklessFroest_Suicune_OnTransition:
	call_if_set FLAG_BADGE08_GET, TracklessForest_SuicuneEventScript_SetSuicuneState
	end

TracklessForest_SuicuneEventScript_SetSuicuneState::
	call_if_set FLAG_CAUGHT_SUICUNE, TracklessForest_SuicuneEventScript_HideSuicune
	call_if_unset FLAG_CAUGHT_SUICUNE, TracklessForest_SuicuneEventScript_TryShowSuicune
	end

TracklessForest_SuicuneEventScript_HideSuicune::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_SUICUNE
	return

TracklessForest_SuicuneEventScript_TryShowSuicune::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_SUICUNE
	return

TracklessFroest_SuicuneOnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TracklessForest_SuicuneEventScript_TryRemoveSuicune
	end

TracklessForest_SuicuneEventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SUICUNE
	return

TracklessForest_SuicuneEventScript_Suicune::
	lock
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	msgbox TracklessFroest_SuicuneText_SuicuneCry, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 50
	closemessage
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TracklessForest_SuicuneEventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TracklessForest_SuicuneEventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TracklessForest_SuicuneEventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	releaseall
	end

TracklessForest_SuicuneEventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end

TracklessForest_SuicuneEventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryRanAway
	end

TracklessFroest_SuicuneText_SuicuneCry:
	.string "Bwrahhh!$"