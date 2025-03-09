MauvilleCity_Flat_F1_MapScripts::
	.byte 0

MauvilleCity_Flat_F1_Man::
	msgbox MauvilleCity_Text_Man, MSGBOX_NPC
	end

MauvilleCity_Text_Man:
	.string "I'm worried about my daughter.\p"
	.string "She's been behaving kind of odd\n"
	.string "recently, but it might just be \l"
	.string "that she is deep in thought.$"

MauvilleCity_Flat_F1_Daughter::
	lock
	msgbox MauvilleCity_Text_Daughter, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Text_Daughter:
	.string "… … …\p"
	.string "She does not seem to notice you.$"
