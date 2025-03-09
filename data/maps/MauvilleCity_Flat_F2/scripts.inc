.set LOCALID_TWIN, 7

MauvilleCity_Flat_F2_MapScripts::
	.byte 0

MauvilleCity_Flat_F2_Chef::
	msgbox MauvilleCity_Text_Chef, MSGBOX_NPC
	end

MauvilleCity_Text_Chef:
	.string "Because cooking is my job, I'm\n"
	.string "expected to do it for my family\p"
	.string "At least I can watch TV here!$"


MauvilleCity_Flat_F2_PokefanF::
	lock
	msgbox MauvilleCity_Text_PokefanF, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_PokefanF:
	.string "Now stop fighting and let your little\n"
	.string "sister play on the GAMEBOY!\p"
	.string "Also pick up your dolls or you won't\n"
	.string "get desset tonight!$"


MauvilleCity_Flat_F2_Twin::
	lock
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MauvilleCity_Text_Twin, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_Twin:
	.string "Pwease can I play Zwelda?\n"
	.string "Mommy says it's my twurn.$"

MauvilleCity_Flat_F2_Kid::
	lock
	msgbox MauvilleCity_Text_Kid, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_Kid:
	.string "Come on Mom! I just unlocked the\n"
	.string "GUST JAR. It totally sucks!$"


MauvilleCity_Flat_F2_Doll::
	msgbox MauvilleCity_Text_Doll, MSGBOX_SIGN
	end

MauvilleCity_Text_Doll:
	.string "It's a POKé DOLL!\n"
	.string "Luckily you didn't trip over it.$"


MauvilleCity_Flat_F2_Wailmer::
	msgbox MauvilleCity_Text_Wailmer, MSGBOX_SIGN
	end

MauvilleCity_Text_Wailmer:
	.string "It's a very, very large POKé DOLL!\n"
	.string "The parents likely know this all too well.$"
