SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_DreamMaster::
	goto_if_unset FLAG_HIDE_MEW, SlateportCity_NameRatersHouse_EventScript_NotReadyYet
	goto_if_unset FLAG_HIDE_DARKRAI, SlateportCity_NameRatersHouse_EventScript_WantNightmare
	goto_if_unset FLAG_HIDE_CRESSELIA, SlateportCity_NameRatersHouse_EventScript_WantDream
	goto SlateportCity_NameRatersHouse_EventScript_NothingMore
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
	.string "Oh my friend, I don't think you're\n"
	.string "ready for this level of sleep yet.$"

SlateportCity_NameRatersHouse_Text_WantToRest:
	.string "Do you want to take a rest?$"

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
