MossdeepCity_Rocket_MapScripts::
	.byte 0

Mossdeep_City_Rocket_Eventscript_AuroraTicket::
	lock
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, MossdeepCity_Rocket_Eventscript_AuroraTicket_Obtained
	message MossdeepCity_Rocket_Text_AuroraTicketFound
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_Rocket_Eventscript_AuroraTicket_NoBagSpace
	finditem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	release
	end

MossdeepCity_Rocket_Eventscript_AuroraTicket_NoBagSpace::
	message MossdeepCity_Rocket_Text_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_Rocket_Eventscript_AuroraTicket_Obtained::
	message MossdeepCity_Rocket_Text_Yuck
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_Rocket_Text_AuroraTicketFound:
	.string "Yuck! Should not have looked.\p"
	.string "But wait…\p"
	.string "it appears that an astronaut left\n"
	.string "something behind here.$"


MossdeepCity_Rocket_Text_Yuck:
	.string "Yuck! Should have known better.$"

MossdeepCity_Rocket_Text_AuroraTicketBagFull:
	.string "Yuck! Should not have looked.\p"
	.string "But wait…\p"
	.string "it appears that an astronaut left\n"
	.string "something behind here.$"
	.string "However, you are not reaching in with\n"
	.string "a full bag.$"