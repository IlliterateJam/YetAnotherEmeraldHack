PacifidlogTown_ManiacHouse_MapScripts::
	.byte 0

PacifidlogTown_ManiacHouse_EventScript_Manic::
	goto_if_set FLAG_TEMP_1, PacifidlogTown_ManiacHouse_EventScript_HearTheWaves
	msgbox PacifidlogTown_ManiacHouse_Text_PeacefulPlace, MSGBOX_NPC
	setflag FLAG_TEMP_1
	goto PacifidlogTown_ManiacHouse_EventScript_HearTheWaves
	end

PacifidlogTown_ManiacHouse_EventScript_PeacefulPlace::
	msgbox PacifidlogTown_ManiacHouse_Text_PeacefulPlace, MSGBOX_NPC
	end

PacifidlogTown_ManiacHouse_EventScript_HearTheWaves::
	msgbox PacifidlogTown_ManiacHouse_Text_NoSpiritsNow, MSGBOX_NPC
	end


PacifidlogTown_ManiacHouse_Text_PeacefulPlace:
	.string "I moved to PACIFIDLOG TOWN\n"
	.string "to find a peaceful place to listen\l"
	.string "to the spirits of the waves.\p"
	.string "Sometimes, they reveal wisdom\n"
	.string "from ancient times to me\p"

PacifidlogTown_ManiacHouse_Text_NoSpiritsNow:
	.string "Seeker of Truth, I know you also\n"
	.string "desire true knowledge…\p"
	.string "…\p"
	.string "…\p"
	.string "…\p"
	.string "The waves tell me that you must\n"
	.string "come back when you are worthy.$"
