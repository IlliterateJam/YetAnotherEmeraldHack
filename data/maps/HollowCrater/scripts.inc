HollowCrater_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, HollowCrater_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, HollowCrater_OnTransition
	.byte 0

HollowCrater_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, HollowCrater_EventScript_TryRemoveRegidrago
	end

HollowCrater_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

HollowCrater_OnTransition:
	@setflag FLAG_LANDMARK_ANCIENT_TOMB @REMEMBER THIS!!!!!!!!
	clearflag FLAG_HIDE_REGIDRAGO
	call_if_set FLAG_CAUGHT_REGIDRAGO, HollowCrater_EventScript_HideRegidrago
	call_if_set FLAG_DEFEATED_REGIDRAGO, HollowCrater_EventScript_HideRegidrago
	end

HollowCrater_EventScript_HideRegidrago::
	setflag FLAG_HIDE_REGIDRAGO
	return

HollowCrater_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, HollowCrater_EventScript_DefeatedRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, HollowCrater_EventScript_RanFromRegidrago
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, HollowCrater_EventScript_RanFromRegidrago
	setflag FLAG_CAUGHT_REGIDRAGO
	release
	end

HollowCrater_EventScript_DefeatedRegidrago::
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

HollowCrater_EventScript_RanFromRegidrago::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end
