LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	goto_if_unset FLAG_BADGE08_GET, LavaridgeTown_HerbShop_EventScript_PokemartBasic
	goto_if_set FLAG_BADGE08_GET, LavaridgeTown_HerbShop_EventScript_PokemartExpanded
	end

LavaridgeTown_HerbShop_EventScript_PokemartBasic::
	pokemart LavaridgeTown_HerbShop_PokemartBasic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_PokemartBasic:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end


LavaridgeTown_HerbShop_EventScript_PokemartExpanded::
	pokemart LavaridgeTown_HerbShop_PokemartExpanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_PokemartExpanded:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_POWER_HERB
	.2byte ITEM_MIRROR_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_BADGE08_GET, LavaridgeTown_HerbShop_EventScript_NewHerbsInStock
	msgbox LavaridgeTown_HerbShop_Text_WaitingForStock, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_EventScript_NewHerbsInStock::
	msgbox LavaridgeTown_HerbShop_Text_NewHerbsInStock, MSGBOX_DEFAULT
	release
	end



LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end


LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Welcome to the HERB SHOP, home of\n"
	.string "effective and inexpensive medicine!$"

LavaridgeTown_HerbShop_Text_WaitingForStock:
	.string "MT. CHIMNEY goes through its own seasons\n"
	.string "where ash falls to fertilize the ground.\p"
	.string "This means that we must be patient\n"
	.string "for the next herb harvest.$"

LavaridgeTown_HerbShop_Text_NewHerbsInStock:
	.string "Come celebrate the harvest with us!\p"
	.string "We grew many unique herbs that would\n"
	.string "interest a trainer like you.$"


LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "You've come to look at herbal medicine\n"
	.string "in LAVARIDGE?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "That CHARCOAL I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a POKéMON.\p"
	.string "It intensifies the power of FIRE-type\n"
	.string "moves.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Herbal medicine works impressively well.\n"
	.string "But your POKéMON will dislike you for it.\l"
	.string "It must be horribly bitter!$"

