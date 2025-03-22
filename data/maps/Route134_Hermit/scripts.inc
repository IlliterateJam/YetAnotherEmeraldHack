Route134_Hermit_MapScripts::
	.byte 0

Route134_Hermit_Eventscript_Expert::
	goto_if_set FLAG_ROUTE_134_HERMIT_CHOICE, Route134_Hermit_Eventscript_ChoiceMade
	lock
	faceplayer
	msgbox Route134_Hermit_Text_MakeAChoice, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route134_Hermit_Eventscript_ActionBand
	call_if_eq VAR_RESULT, NO, Route134_Hermit_Eventscript_InactionSpecs
	end

Route134_Hermit_Eventscript_ActionBand::
	msgbox Route134_Hermit_Text_ISeeAction, MSGBOX_DEFAULT
	giveitem ITEM_CHOICE_BAND
	goto_if_eq VAR_RESULT, FALSE, Route134_Hermit_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_134_HERMIT_CHOICE
	msgbox Route134_Hermit_Text_DoesEveryActionMatter, MSGBOX_DEFAULT
	release
	end

Route134_Hermit_Eventscript_InactionSpecs::
	msgbox Route134_Hermit_Text_ISeeInaction, MSGBOX_DEFAULT
	giveitem ITEM_CHOICE_SPECS
	goto_if_eq VAR_RESULT, FALSE, Route134_Hermit_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE_134_HERMIT_CHOICE
	msgbox Route134_Hermit_Text_EveryInactionIsAction, MSGBOX_DEFAULT
	release
	end

Route134_Hermit_EventScript_ShowBagIsFull::
	msgbox Route134_Hermit_Text_IronyOfItAll, MSGBOX_DEFAULT
	release
	end


Route134_Hermit_Eventscript_ChoiceMade::
	msgbox Route134_Hermit_Text_WeAllMakeChoices, MSGBOX_NPC
	end

Route134_Hermit_Text_MakeAChoice:
	.string "Young one, to make it all the way out\n"
	.string "here, you must be brave in spirit.\p"
	.string "But, you must pass one final test,\n"
	.string "a test of your will.\p"
	.string "For one day you will be confronted with\n"
	.string "a choice that will be the most important\p"
	.string "decision of your life, whether you know it\n"
	.string "or not.\p"
	.string "Now tell me, are you ready for such\n"
	.string "a choice?$"

Route134_Hermit_Text_ISeeAction:
	.string "Ahh, you are truly adamant in spirit…\p"
	.string "Such a choice is its own reward.$"

Route134_Hermit_Text_DoesEveryActionMatter:
	.string "Be careful to not think to highly of your\n"
	.string "your choices.\p"
	.string "You will never know their full impact.$"

Route134_Hermit_Text_ISeeInaction:
	.string "Ahh, you are truly modest in spirit…\p"
	.string "Such a choice is its own reward.$"	


Route134_Hermit_Text_EveryInactionIsAction:
	.string "Remember now, action and inaction are\n"
	.string "the same thing, two sides of the coin.$"


Route134_Hermit_Text_IronyOfItAll:
	.string "The irony of it all…\p"
	.string "Now you see that sometimes we are not\n"
	.string "free to make our own choices…$"

Route134_Hermit_Text_WeAllMakeChoices:
	.string "A choice a person makes becomes a\n"
	.string "permanent part of their being.\p"
	.string "Make good choices not for us but\n"
	.string "for yourself.$"
