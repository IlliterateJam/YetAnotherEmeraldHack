SealedChamber_InnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SealedChamber_InnerRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SealedChamber_InnerRoom_OnLoad
	.byte 0

SealedChamber_InnerRoom_EventScript_BrailleBackWall::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
	goto_if_set FLAG_REGI_DOORS_OPENED, SealedChamber_InnerRoom_EventScript_NoEffect
	specialvar VAR_RESULT, CheckRelicanthWailord
	goto_if_eq VAR_RESULT, FALSE, SealedChamber_InnerRoom_EventScript_NoEffect
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	special DoSealedChamberShakingEffect_Long
	waitstate
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect_Short
	waitstate
	playse SE_DOOR
	delay 40
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setflag FLAG_REGI_DOORS_OPENED
	releaseall
	end

SealedChamber_InnerRoom_EventScript_NoEffect::
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart1::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart2::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart3::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart4::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_WeFearedIt
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart5::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
	releaseall
	end

SealedChamber_InnerRoom_EventScript_BrailleStoryPart6::
	lockall
	braillemsgbox SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
	releaseall
	end






SealedChamber_InnerRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SealedChamber_InnerRoom_EventScript_TryRemoveRegigigas
	end

SealedChamber_InnerRoom_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return


SealedChamber_InnerRoom_OnLoad:
	call_if_set FLAG_CAUGHT_REGIGIGAS, SealedChamber_InnerRoom_EventScript_HideRegigigas
	call_if_unset FLAG_CAUGHT_REGIGIGAS, SealedChamber_InnerRoom_EventScript_TryShowRegigigas
	end

SealedChamber_InnerRoom_EventScript_HideRegigigas::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_REGIGIGAS
	return

SealedChamber_InnerRoom_EventScript_TryShowRegigigas::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_REGIGIGAS, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_REGIGIGAS
	return

SealedChamber_InnerRoom_EventScript_Statue::
	goto_if_eq VAR_REGIS_CAUGHT, 5, SealedChamber_InnerRoom_EventScript_Regigigas
	msgbox SealedChamber_InnerRoom_Text_Statue, MSGBOX_DEFAULT
	end



SealedChamber_InnerRoom_EventScript_Regigigas::
	lock
	faceplayer 
	msgbox SealedChamber_InnerRoom_Text_TheStatueIsCrumbling, MSGBOX_DEFAULT
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SealedChamber_InnerRoom_EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SealedChamber_InnerRoom_EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SealedChamber_InnerRoom_EventScript_RanFromRegigigas
	setflag FLAG_CAUGHT_REGIGIGAS
	release
	end

SealedChamber_InnerRoom_EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

SealedChamber_InnerRoom_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end


SealedChamber_InnerRoom_Text_TheStatueIsCrumbling:
	.string "The seal of the statue starts to crumble\n"
	.string "away.\p"
	.string "There's a giant POKéMON underneath!$"

SealedChamber_InnerRoom_Text_Statue:
	.string "A statue dedicated to an guardian\n"
	.string "made by ancient people.$"