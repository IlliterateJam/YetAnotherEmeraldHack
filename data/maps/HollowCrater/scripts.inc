HollowCrater_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, HollowCrater_OnResume
	map_script MAP_SCRIPT_ON_LOAD, HollowCrater_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, HollowCrater_OnTransition
	.byte 0

HollowCrater_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, HollowCrater_EventScript_TryRemoveRegidrago
	end

HollowCrater_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, HollowCrater_EventScript_HideRegiEntrance
	end

HollowCrater_EventScript_HideRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 8, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 9, 19, METATILE_Cave_EntranceCover, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return


HollowCrater_EventScript_OpenRegiEntrance::
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, TRUE
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, TRUE
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, TRUE
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, TRUE
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, FALSE
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setflag FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED
	releaseall
	end



HollowCrater_EventScript_CaveEntrance::
	lockall
	braillemsgbox HollowCrater_Braille_Message
	goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, HollowCrater_EventScript_NoEffect
	specialvar VAR_RESULT, SpellUnownOmega
	goto_if_eq VAR_RESULT, FALSE, HollowCrater_EventScript_NoEffect
	goto HollowCrater_EventScript_OpenRegiEntrance
	end


HollowCrater_EventScript_NoEffect::
	releaseall
	end




HollowCrater_EventScript_TryRemoveRegidrago::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

HollowCrater_OnTransition:
	setflag FLAG_LANDMARK_HOLLOW_CRATER
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
	addvar VAR_REGIS_CAUGHT, 1
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
