TracklessForest_Raikou_MapScripts::
	.byte 0


.set LOCALID_RAIKOU, 0

TracklessFroest_Raikou_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TracklessFroest_Raikou_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TracklessFroest_RaikouOnResume @DONT FORGET!
	.byte 0

TracklessFroest_Raikou_OnTransition:
	call_if_set FLAG_BADGE08_GET, TracklessForest_RaikouEventScript_SetRaikouState
	end

TracklessForest_RaikouEventScript_SetRaikouState::
	call_if_set FLAG_CAUGHT_RAIKOU, TracklessForest_RaikouEventScript_HideRaikou
	call_if_unset FLAG_CAUGHT_RAIKOU, TracklessForest_RaikouEventScript_TryShowRaikou
	end

TracklessForest_RaikouEventScript_HideRaikou::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_RAIKOU
	return

TracklessForest_RaikouEventScript_TryShowRaikou::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_RAIKOU, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_RAIKOU
	return

TracklessFroest_RaikouOnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TracklessForest_RaikouEventScript_TryRemoveRaikou
	end

TracklessForest_RaikouEventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_RAIKOU
	return

TracklessForest_RaikouEventScript_Raikou::
	lock
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	msgbox TracklessFroest_RaikouText_RaikouCry, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 50
	closemessage
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TracklessForest_RaikouEventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TracklessForest_RaikouEventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TracklessForest_RaikouEventScript_RanFromRaikou
	setflag FLAG_CAUGHT_RAIKOU
	releaseall
	end

TracklessForest_RaikouEventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryRanAway
	end

TracklessForest_RaikouEventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryRanAway
	end

TracklessFroest_RaikouText_RaikouCry:
	.string "Bwrahhh!$"