.set LOCALID_MAN, 1

FallarborTown_House3_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_House3_OnFrame
	.byte 0

FallarborTown_House3_OnFrame:
	map_script_2 VAR_UNUSED_0x408B, 0, FallarborTown_House3_Trigger
	.2byte 0


FallarborTown_House3_Trigger::
	lock
	playse SE_PIN
	applymovement LOCALID_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	message FallarborTown_House3_Text_YouCantWalkInHere
	waitmessage
	waitbuttonpress
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	warp MAP_FALLARBOR_TOWN, 3, 20
	waitstate
	release
	end


FallarborTown_House3_Text_YouCantWalkInHere:
	.string "Hey! What do you think you are\n"
	.string "doing here?\p"
	.string "You just can't walk into everyone's\n"
	.string "house because you feel like it!\p"
	.string "Now scram!\n"
	.string "…Children these days…$"
