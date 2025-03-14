MauvilleCity_MenuMauville_MapScripts::
	.byte 0

MauvilleCity_MenuMauville_EventScript_Clerk::
	lock
	faceplayer
	message MauvilleCity_MenuMauville_Text_WelcomeMochi
	waitmessage
	pokemart MauvilleCity_MenuMauville_Mochi
	msgbox MauvilleCity_MenuMauville_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_MenuMauville_Mochi:
	.2byte ITEM_HEALTH_MOCHI
	.2byte ITEM_MUSCLE_MOCHI
	.2byte ITEM_RESIST_MOCHI
	.2byte ITEM_GENIUS_MOCHI
	.2byte ITEM_CLEVER_MOCHI
	.2byte ITEM_SWIFT_MOCHI
	.2byte ITEM_NONE
	release
	end

MauvilleCity_MenuMauville_EventScript_MintChef::
	lock
	faceplayer
	message MauvilleCity_MenuMauville_Text_WelcomeMint
	waitmessage
	pokemart MauvilleCity_MenuMauville_Mint
	msgbox MauvilleCity_MenuMauville_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_MenuMauville_Mint:
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_MILD_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_NONE
	release
	end


MauvilleCity_MenuMauville_EventScript_SweetChef::
	lock
	faceplayer
	message MauvilleCity_MenuMauville_Text_WelcomeSweet
	waitmessage
	goto_if_set FLAG_SYS_GAME_CLEAR, MauvilleCity_MenuMauville_EventScript_SweetChef_Expanded
	pokemart MauvilleCity_MenuMauville_Sweet
	msgbox MauvilleCity_MenuMauville_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_MenuMauville_Sweet:
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_NONE
	release
	end



MauvilleCity_MenuMauville_EventScript_SweetChef_Expanded::
	pokemart MauvilleCity_MenuMauville_Sweet_Expanded
	msgbox MauvilleCity_MenuMauville_Text_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_MenuMauville_Sweet_Expanded:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_EXP_CANDY_XS
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_EXP_CANDY_XL
	.2byte ITEM_EXP_SWEET_XS
	.2byte ITEM_EXP_SWEET_S
	.2byte ITEM_EXP_SWEET_M
	.2byte ITEM_EXP_SWEET_L
	.2byte ITEM_EXP_SWEET_XL
	.2byte ITEM_NONE
	release
	end



MauvilleCity_MenuMauville_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox MauvilleCity_MenuMauville_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MauvilleCity_MenuMauville_Wingull:
	.string "WINGULL: Pi Pi Pihyoh!$"


MauvilleCity_MenuMauville_EventScript_Girl::
	msgbox MauvilleCity_MenuMauville_Girl, MSGBOX_NPC
	end

MauvilleCity_MenuMauville_Girl:
	.string "I gave my Gully a BOLD MINT.\n"
	.string "He liked it so much that he's\l"
	.string "become a daring little bird!$"

MauvilleCity_MenuMauville_EventScript_Man::
	msgbox MauvilleCity_MenuMauville_Text_Man, MSGBOX_NPC
	end

MauvilleCity_MenuMauville_Text_Man:
	.string "You can take all the vitamins you\n"
	.string "want, but there is nothing like\l"
	.string "a fresh MOCHI for the soul.$"

MauvilleCity_MenuMauville_Text_WelcomeMochi:
	.string "Welcome to MENU MAUVILLE,\n"
	.string "the candy shop for POKéMON!\p"
	.string "How about trying some of our\n"
	.string "mind-blowing MOCHI?$"

MauvilleCity_MenuMauville_Text_WelcomeMint:
	.string "Welcome to MENU MAUVILLE,\n"
	.string "the candy shop for POKéMON.\p"
	.string "Ready to change things up with\n"
	.string "a miraculous MINT?$"

MauvilleCity_MenuMauville_Text_WelcomeSweet:
	.string "Welcome to MENU MAUVILLE,\n"
	.string "the candy shop for POKéMON.\p"
	.string "I promise our CANDIES are to\n"
	.string "crave for!$"

MauvilleCity_MenuMauville_Text_PleaseComeAgain:
	.string "Thank you, and please come again\n"
	.string "for a sweet treat!$"