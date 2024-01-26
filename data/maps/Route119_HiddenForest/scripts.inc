Route119_HiddenForest_MapScripts::
	.byte 0

Route119_HiddenForest_EventScripts_WarpBack1::
	warp MAP_ROUTE119, 3
	end

Route119_HiddenForest_EventScripts_WarpBack2::
	warp MAP_ROUTE119, 3
	end

Route119_HiddenForest_EventScript_XerneasFight::
	lockall
	playmoncry SPECIES_XERNEAS, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_XERNEAS, 50, ITEM_LAVA_COOKIE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Route119_HiddenForest_EventScript_PostXerneasBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route119_HiddenForest_EventScript_PostXerneasBattle
	releaseall
	end

Route119_HiddenForest_EventScript_PostXerneasBattle::
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_XERNEAS
	end
