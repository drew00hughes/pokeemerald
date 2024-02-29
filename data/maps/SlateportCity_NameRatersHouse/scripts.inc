SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_DreamMaster::
	lock
	faceplayer
	goto_if_set FLAG_DREAM_STATE, SlateportCity_NameRatersHouse_EventScript_NothingMore
	msgbox SlateportCity_NameRatersHouse_Text_Explain, MSGBOX_NPC
	goto_if_unset FLAG_HIDE_MEW, SlateportCity_NameRatersHouse_EventScript_NotReadyYet
	msgbox SlateportCity_NameRatersHouse_Text_WantToRest, MSGBOX_DEFAULT
	scrollingmultichoice 3, 2, 3, 2, TRUE
	goto_if_eq VAR_RESULT, 0, SlateportCity_NameRatersHouse_EventScript_WantDream
	goto_if_eq VAR_RESULT, 1, SlateportCity_NameRatersHouse_EventScript_WantNightmare
	release
	end

SlateportCity_NameRatersHouse_EventScript_WantNightmare::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_WantToRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_ComebackWhenYouWant
	msgbox SlateportCity_NameRatersHouse_Text_BlackVial, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	clearflag FLAG_DREAM_STATE
	warp MAP_ISLAND_OF_DREAMS, 0
	release
	end

SlateportCity_NameRatersHouse_EventScript_WantDream::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_WantToRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_ComebackWhenYouWant
	msgbox SlateportCity_NameRatersHouse_Text_WhiteVial, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag FLAG_DREAM_STATE
	warp MAP_ISLAND_OF_DREAMS, 0
	release
	end

SlateportCity_NameRatersHouse_EventScript_NothingMore::
	msgbox SlateportCity_NameRatersHouse_Text_NothingLeft, MSGBOX_NPC
	end

SlateportCity_NameRatersHouse_EventScript_ComebackWhenYouWant::
	msgbox SlateportCity_NameRatersHouse_Text_ComeBack, MSGBOX_NPC
	end

SlateportCity_NameRatersHouse_EventScript_NotReadyYet::
	msgbox SlateportCity_NameRatersHouse_Text_NotReady, MSGBOX_NPC
	end

SlateportCity_NameRatersHouse_Text_ComeBack:
	.string "Come back when you're ready.$"

SlateportCity_NameRatersHouse_Text_NotReady:
	.string "But oh, I don't think you're\n"
	.string "ready for this level of sleep yet.$"

SlateportCity_NameRatersHouse_Text_Explain:
	.string "Oh hello there! I am the\n"
	.string "Dream Master. I can help you have\l"
	.string "certain dreams with my elixirs.$"

SlateportCity_NameRatersHouse_Text_WantToRest:
	.string "What kind of rest would you like?$"

SlateportCity_NameRatersHouse_Text_BlackVial:
	.string "Take this black vial. This will\n"
	.string "help you sleep...$"

SlateportCity_NameRatersHouse_Text_NothingLeft:
	.string "I've shown you all I can. I have\n"
	.string "nothing left to offer you, strong\l"
	.string "trainer.$"

SlateportCity_NameRatersHouse_Text_WhiteVial:
	.string "Take this white vial. This will\n"
	.string "help you sleep...$"
