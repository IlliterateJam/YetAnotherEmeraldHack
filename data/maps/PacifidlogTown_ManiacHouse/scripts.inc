.set LOCALID_BEASTMANIAC, 2
.set LOCALID_BIRDMANIAC, 3
.set LOCALID_MYTHMANIAC, 4
.set LOCALID_EONMANIAC, 5


PacifidlogTown_ManiacHouse_MapScripts::
	.byte 0

PacifidlogTown_ManiacHouse_EventScript_Manic1::
	lock
	faceplayer
	goto_if_set FLAG_SAVED_HOENN, PacifidlogTown_ManiacHouse_EventScript_Manic1Hint
	msgbox PacifidlogTown_ManiacHouse_Text_PeacefulPlace, MSGBOX_DEFAULT
	applymovement LOCALID_BEASTMANIAC, Common_Movement_FaceRight
	waitmovement 0
	release
	end

PacifidlogTown_ManiacHouse_EventScript_Manic1Hint::
	msgbox PacifidlogTown_ManiacHouse_Text_LegendaryBirdsHint, MSGBOX_DEFAULT
	applymovement LOCALID_BEASTMANIAC, Common_Movement_FaceRight
		waitmovement 0
	release
	end



PacifidlogTown_ManiacHouse_EventScript_Manic2::
	lock
	faceplayer
	goto_if_set FLAG_SAVED_HOENN, PacifidlogTown_ManiacHouse_EventScript_Manic2Hint
	msgbox PacifidlogTown_ManiacHouse_Text_NoSpiritsNow, MSGBOX_DEFAULT
	applymovement LOCALID_BIRDMANIAC, Common_Movement_FaceUp
		waitmovement 0
	release
	end

PacifidlogTown_ManiacHouse_EventScript_Manic2Hint::
	msgbox PacifidlogTown_ManiacHouse_Text_LegendaryBirdsHints, MSGBOX_DEFAULT
	applymovement LOCALID_BIRDMANIAC, Common_Movement_FaceUp
		waitmovement 0
	release
	end




PacifidlogTown_ManiacHouse_EventScript_Manic3::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PacifidlogTown_ManiacHouse_EventScript_Manic3Hint
	msgbox PacifidlogTown_ManiacHouse_Text_AsAGroup, MSGBOX_DEFAULT
	applymovement LOCALID_MYTHMANIAC, Common_Movement_FaceLeft
		waitmovement 0
	release
	end

PacifidlogTown_ManiacHouse_EventScript_Manic3Hint::
	msgbox PacifidlogTown_ManiacHouse_Text_MythicalHint, MSGBOX_DEFAULT
	applymovement LOCALID_MYTHMANIAC, Common_Movement_FaceLeft
		waitmovement 0
	release
	end


PacifidlogTown_ManiacHouse_EventScript_Manic4::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, PacifidlogTown_ManiacHouse_EventScript_Manic4Hint
	msgbox PacifidlogTown_ManiacHouse_Text_ImhereForStockOptions, MSGBOX_DEFAULT
	applymovement LOCALID_EONMANIAC, Common_Movement_FaceDown
		waitmovement 0
	release
	end

PacifidlogTown_ManiacHouse_EventScript_Manic4Hint::
	msgbox PacifidlogTown_ManiacHouse_Text_EonTicketHint, MSGBOX_DEFAULT
	applymovement LOCALID_EONMANIAC, Common_Movement_FaceDown
		waitmovement 0
	release
	end


acifidlogTown_ManiacHouse_EventScript_Teacher::
	msgbox PacifidlogTown_ManiacHouse_Text_TheseAreMyStudents, MSGBOX_NPC
	end


PacifidlogTown_ManiacHouse_Text_PeacefulPlace:
	.string "I moved to PACIFIDLOG TOWN to find a\n"
	.string "peaceful place to listen to the spirits\l"
	.string "spirits of the waves.\p"
	.string "Sometimes, they reveal wisdom from\n"
	.string "ancient times to me.\p"
	.string "…\p"
	.string "…\p"
	.string "You spirit is still one of unfulfilled\n"
	.string "restlessness, it is too noisy to hear the\l"
	.string "waves over it.$"


PacifidlogTown_ManiacHouse_Text_NoSpiritsNow:
	.string "Bearer of Truth, I know you also\n"
	.string "desire true knowledge…\p"
	.string "…\p"
	.string "…\p"
	.string "The waves tell me that you must\n"
	.string "come back when you are worthy.$"


PacifidlogTown_ManiacHouse_Text_AsAGroup:
	.string "It is important that we meditate\n"
	.string "together as a group…\p"
	.string "Our spirits can help guide each other\n"
	.string "through the fog that is the future…\p"
	.string "…\p"
	.string "…\p"
	.string "Ahh, for you, it is still too murky\n"
	.string "for us to discern, for now…"

PacifidlogTown_ManiacHouse_Text_ImhereForStockOptions:
	.string "OOOHHHHHHMMMMMMM…\p"
	.string "…\p"
	.string "…\p"
	.string "Oh, don't mind me, I'm just here for\n"
	.string "for figuring out stock options.$"

PacifidlogTown_ManiacHouse_Text_TheseAreMyStudents:
	.string "Ever since ancient times, people have been\n"
	.string "trying to divine the future though a\l"
	.string "variety of means.\p"
	.string "PACIFIDLOG offers a unique place where\n"
	.string "one can meditate as if they were just a\l"
	.string "drop in the ocean.\p"
	.string "Everyone one of them can be a help for\n"
	.string "your adventure, trainer.$"




PacifidlogTown_ManiacHouse_Text_LegendaryBirdsHint:
	.string "Well done, your spirit has become still\n"
	.string "as the waves. I can now tell your fortune.\p"
	.string "…\p"
	.string "Three beasts wait for you up in the\n"
	.string "northern forest.\p"
	.string "And three girls will guide the way as it\n"
	.string "has been chorused.$"

PacifidlogTown_ManiacHouse_Text_LegendaryBirdsHints:
	.string "Ahh, Bearer, you has been rewarded.\p"
	.string "…\p"
	.string "Seek the old mariner,\n"
	.string "seek the three birds,\l"
	.string "lest the TEAMS return to their hideouts\l"
	.string "and caves to capture them first.$"

PacifidlogTown_ManiacHouse_Text_MythicalHint:
	.string "So you have returned to find your\n"
	.string "fortune…p"
	.string "…\p"
	.string "Fragments we see, but each still distict…\p"
	.string "A shrine in the woods…\p"
	.string "A truck in a market place…\p"
	.string "A rocket ready to launch…\p"
	.string "…$"

PacifidlogTown_ManiacHouse_Text_EonTicketHint:
	.string "I can't get this out of my head:\p"
	.string "ZELDA TOGETHER WITH ALL.\p"
	.string "It just doesn't make sense, who names a\n"
	.string "boy that?\p"
	.string "…\p"
	.string "Oh, and don't ask me for financial advice.\n"
	.string "I've lost 96% of my net worth being in\l"
	.string "this crazy group.$"