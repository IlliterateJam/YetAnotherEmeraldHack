TracklessForest_Entei_MapScripts::
	.byte 0

.set LOCALID_ENTEI, 0

TracklessFroest_Entei_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TracklessFroest_Entei_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, TracklessFroest_EnteiOnResume @DONT FORGET!
	.byte 0

TracklessFroest_Entei_OnTransition:
	call_if_set FLAG_BADGE08_GET, TracklessForest_EnteiEventScript_SetEnteiState
	end

TracklessForest_EnteiEventScript_SetEnteiState::
	call_if_set FLAG_CAUGHT_ENTEI, TracklessForest_EnteiEventScript_HideEntei
	call_if_unset FLAG_CAUGHT_ENTEI, TracklessForest_EnteiEventScript_TryShowEntei
	end

TracklessForest_EnteiEventScript_HideEntei::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_ENTEI
	return

TracklessForest_EnteiEventScript_TryShowEntei::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_ENTEI
	return

TracklessFroest_EnteiOnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TracklessForest_EnteiEventScript_TryRemoveEntei
	end

TracklessForest_EnteiEventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

TracklessForest_EnteiEventScript_Entei::
	lock
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	msgbox TracklessFroest_EnteiText_EnteiCry, MSGBOX_DEFAULT
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 50
	closemessage
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TracklessForest_EnteiEventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, TracklessForest_EnteiEventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, TracklessForest_EnteiEventScript_RanFromEntei
	setflag FLAG_DEFEATED_ENTEI
	releaseall
	end

TracklessForest_EnteiEventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

TracklessForest_EnteiEventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryRanAway
	end

TracklessFroest_EnteiText_EnteiCry:
	.string "Bwrahhh!$"