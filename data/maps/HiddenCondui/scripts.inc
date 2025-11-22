HiddenCondui_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, HiddenCondui_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, HiddenCondui_OnTransition
	.byte 0

HiddenCondui_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, HiddenCondui_EventScript_TryRemoveRegieleki
	end

HiddenCondui_EventScript_TryRemoveRegieleki::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

HiddenCondui_OnTransition:
	@setflag FLAG_LANDMARK_ANCIENT_TOMB @REMEMBER THIS!!!!!!!!
	clearflag FLAG_HIDE_REGIELEKI
	call_if_set FLAG_CAUGHT_REGIELEKI, HiddenCondui_EventScript_HideRegieleki
	call_if_set FLAG_DEFEATED_REGIELEKI, HiddenCondui_EventScript_HideRegieleki
	end

HiddenCondui_EventScript_HideRegieleki::
	setflag FLAG_HIDE_REGIELEKI
	return

HiddenCondui_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, HiddenCondui_EventScript_DefeatedRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, HiddenCondui_EventScript_RanFromRegieleki
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, HiddenCondui_EventScript_RanFromRegieleki
	setflag FLAG_CAUGHT_REGIELEKI
	release
	end

HiddenCondui_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

HiddenCondui_EventScript_RanFromRegieleki::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end
