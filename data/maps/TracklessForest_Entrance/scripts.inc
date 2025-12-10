TracklessForest_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TracklessForest_Entrance_OnTransition
	.byte 0

TracklessForest_Entrance_OnTransition:
	setflag FLAG_LANDMARK_TRACKLESS_FOREST
	end


TracklessForest_Entrance_EventScript_Sign::
	msgbox TracklessForest_Entrance_Sign_Text, MSGBOX_SIGN
	end

TracklessForest_Entrance_Sign_Text:
	.string "AFTER PROVEN WORTH\n"
	.string "THREE BEASTS WILL BE WAITING TO JUDGE\l"
	.string "THOSE PURE IN SPIRIT$"