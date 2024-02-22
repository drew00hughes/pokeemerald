.set LOCALID_NURSE, 1

BattleFrontier_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

BattleFrontier_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST
	end

BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeOpening::
	lock
	msgbox BattleFrontier_PokemonCenter_1F_Text_WondertradeWelcome, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeBye
	goto_if_eq VAR_RESULT, YES, BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeStation
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeStation::
	lock
	followerintopokeball
	setvar VAR_0x8008, INGAME_TRADE_WONDER
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeBye
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special GenerateWondertradeMon
	special DoInGameTradeScene
	waitstate
	updatefollowerpokemongraphic
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_PokemonCenter_1F_Text_WondertradeAgain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeBye
	goto_if_eq VAR_RESULT, YES, BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeRepeat
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeRepeat::
	goto BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeStation
	end

BattleFrontier_PokemonCenter_1F_EventScript_WonderTradeBye::
	msgbox BattleFrontier_PokemonCenter_1F_Text_WondertradeGoodbye, MSGBOX_DEFAULT
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_PokemonCenter_1F_EventScript_SchoolKid::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Man::
	msgbox BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Picnicker::
	msgbox BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge, MSGBOX_NPC
	end

BattleFrontier_PokemonCenter_1F_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox BattleFrontier_PokemonCenter_1F_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_PokemonCenter_1F_Text_NeverSeenPokemon:
	.string "There was someone here using a \n"
	.string "POKéMON I've never seen before.\p"
	.string "I never learned about it at\n"
	.string "TRAINER'S SCHOOL at least.\p"
	.string "I wonder where you can catch POKéMON\n"
	.string "like that.$"

BattleFrontier_PokemonCenter_1F_Text_NextStopBattleArena:
	.string "Okay! Next stop, the BATTLE ARENA!\n"
	.string "I'd better get the right POKéMON from\l"
	.string "the PC Storage System.$"

BattleFrontier_PokemonCenter_1F_Text_GoingThroughEveryChallenge:
	.string "Giggle… I'm going to go through every\n"
	.string "challenge with just this baby!$"

BattleFrontier_PokemonCenter_1F_Text_Skitty:
	.string "SKITTY: Mya myaaah!$"

BattleFrontier_PokemonCenter_1F_Text_WondertradeWelcome:
	.string "Welcome to the Wonder Trade Station!\n"
	.string "Do you want to trade for a random\l"
	.string "POKéMON?$"

BattleFrontier_PokemonCenter_1F_Text_WondertradeGoodbye:
	.string "Thanks for using Wonder Trade!$"

BattleFrontier_PokemonCenter_1F_Text_WondertradeAgain:
	.string "Would you like to Wonder Trade again?$"
