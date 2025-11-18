

LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_MagmaM::
	lockall
	msgbox LilycoveCity_MoveDeletersHouse_EventScript_MagmaM_Text, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_MoveDeletersHouse_EventScript_AquaF::
	lockall
	msgbox LilycoveCity_MoveDeletersHouse_EventScript_AquaF_Text, MSGBOX_DEFAULT
	releaseall
	end


LilycoveCity_MoveDeletersHouse_EventScript_AquaF_Text:
	.string "I promise you honey, when this is all\n"
	.string "over, we can finally be who we truly\l"
	.string "are, away from this crazy world.\p"
	.string "Nothing can get in the way of our love.\p"
	.string "… … … \p"
	.string "… I love you.$"


LilycoveCity_MoveDeletersHouse_EventScript_MagmaM_Text:
	.string "… I love you too.$"


LilycoveCity_EventScript_MagmaPoochyena::
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	msgbox LilycoveCity_Text_Bufoh, MSGBOX_SIGN
	end

LilycoveCity_EventScript_AquaPoochyena::
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	msgbox LilycoveCity_Text_Bushaa, MSGBOX_SIGN
	end

LilycoveCity_Text_Bufoh:
	.string "Bufoh…$"

LilycoveCity_Text_Bushaa:
	.string "Bushaa…$"
