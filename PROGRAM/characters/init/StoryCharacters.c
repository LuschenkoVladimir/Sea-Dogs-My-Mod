
int CreateStoryCharacters(int n)
{
    ref ch;
    ///////////////////////////////////
	/*
    makeref(ch,Characters[n]);		// ГУБЕРНАТОР Англия
	ch.name 	= "граф Джеймс";
	ch.lastname = "Карлайл";
	ch.id		= "eng_guber";
	ch.model	= "Modyford";
	ch.model.animation	= "man";
	ch.sex = "man";
	ch.location	= "PortRoyal_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = ENGLAND;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Испания
	ch.name 	= "дон Энрике";
	//ch.middlename = "";
	ch.lastname = "Суарец де Нибла";
	ch.id		= "spa_guber";
	ch.model	= "Gaskon";
	ch.model.animation	= "man";
	ch.sex = "man";
	ch.location	= "Muelle_Residence";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = SPAIN;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Франция
	ch.name 	= "шевалье Филлип Лонвийе";
	ch.lastname = "де Пуанси";
	ch.id		= "fra_guber";
	ch.model	= "dOgeron";
	ch.sex = "man";
	ch.location	= "Tortuga_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = FRANCE;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberStayType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

	makeref(ch,Characters[n]);		// ГУБЕРНАТОР Голландия
	ch.name 	= "Матиас";
	ch.lastname = "Бек";
	ch.id		= "hol_guber";
	ch.model	= "huber_25";
	ch.sex = "man";
	ch.location	= "Villemstad_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Common_Governor.c";
	ch.nation = HOLLAND;
	ch.rank 	= 10;
	LAi_NoRebirthEnable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_Hovernor";
	ch.notMoveAble = true; //не переезжать
	ch.notQuestLine = true; //флаг не давать задания по линейке
	n = n + 1;

//============== Генри Морган! Всем трепетать. =================
    makeref(ch,Characters[n]);
	ch.name 	= "Генри";
	ch.lastname = "Морган";
	ch.id		= "Henry Morgan";
	ch.model	= "Morgan";
	ch.model.animation = "man"; 
	ch.sex = "man";
	ch.location	= "PortRoyal_houseS1";
	ch.location.group = "sit";
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Quest\Morgan.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, GUN_COMMON);
	GiveItem2Character(ch, "blade_25");
	EquipCharacterbyItem(ch, GUN_COMMON); 
	EquipCharacterbyItem(ch, "blade_25"); 
	// ==> Кораблик Моргану делаем с хорошими пушками
	ch.Abordage.Enable = false; // НЕЛЬЗЯ!
	ch.Ship.Name = "Elisabett";
	ch.Ship.Type = GenerateShipExt(SHIP_FRIGATE, true, ch);
	ch.Ship.Stopped = true;
   	ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS48;
    SetCrewQuantityFull(ch);
    Fantom_SetBalls(ch, "pirate");    
    ch.rank = 45;
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	ch.money = "50000";
	SetCharacterPerk(ch, "FastReload");
	SetCharacterPerk(ch, "HullDamageUp");
	SetCharacterPerk(ch, "SailsDamageUp");
	SetCharacterPerk(ch, "CrewDamageUp");
	SetCharacterPerk(ch, "CriticalShoot");
	SetCharacterPerk(ch, "LongRangeShoot");
	SetCharacterPerk(ch, "CannonProfessional");
	SetCharacterPerk(ch, "ShipDefenseProfessional");
	SetCharacterPerk(ch, "ShipSpeedUp");
	SetCharacterPerk(ch, "ShipTurnRateUp");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
	LAi_NoRebirthDisable(ch);
	LAi_RebirthOldName(ch);
	LAi_SetHuberType(ch);
	ch.standUp = true; //вставать и нападать на врага
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetImmortal(ch, true);
	LAi_SetHP(ch, 230.0, 230.0);
	ch.greeting = "Gr_Morgan";
	n = n + 1;

//============== Секретать Моргана, можно расслабиться. =================
	makeref(ch,Characters[n]);
	ch.name 	= "Оливер";
	ch.lastname = "Грин";
	ch.id		= "Oliver_Green";
	ch.model	= "Helper";
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "PortRoyal_houseS1";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Quest\OliverGreen.c";
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	ch.greeting = "Gr_OliverGreen";
	ch.nation = PIRATE;
	ch.rank 	= 20;
	LAi_NoRebirthDisable(ch);
	LAi_RemoveLoginTime(ch);
	LAi_SetHuberType(ch);
	//ch.standUp = true; //вставать и нападать на врага
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetHP(ch, 100.0, 100.0);
	n=n+1; */
	
	
	//============== Мой персонаж, первый блин. =================
	/*
	makeref(ch,Characters[n]);
	ch.id		= "MyHero";
	ch.name 	= "Ричард";
	ch.lastname = "Стейси";
	ch.model	= "Blad_6";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.City = "SentJons";
	ch.location	= "SentJons_town";
	ch.location.group = "goto";
	ch.location.locator = "goto23";
	ch.Dialog.Filename = "NewPapka/RichardStacy.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	//============== Мой персонаж2, первый блин. =================
	
	makeref(ch,Characters[n]);
	ch.id		= "OlivieBlank";
	ch.name 	= "Оливье";
	ch.lastname = "Бланк";
	ch.model	= "off_fra_1";
	ch.rank 	= 4;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/OlivieBlank.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	//ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 2);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
   	
	
	//============== Мой персонаж3, первый блин. =================
	makeref(ch,Characters[n]);
	ch.id		= "MyHero3";
	ch.name 	= "Клод";
	ch.lastname = "Пикарди";
	ch.model	= "Azzy";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.City = "";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/KlodPikardi.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	//============== Мой персонаж4, первый блин. =================
	makeref(ch,Characters[n]);
	ch.id		= "AndreKoni";
	ch.name 	= "Андре";
	ch.lastname = "Кони";
	ch.model	= "Banker_1_1";
	ch.rank 	= 4;
	ch.sex = "man";
    ch.model.animation = "man";

	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/AndreKoni.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	LAi_SetHP(ch, 100.0, 100.0);
	
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	
	n=n+1;
	
	
	//============== Мой персонаж5, первый блин. =================
	makeref(ch,Characters[n]);
	ch.id		= "MyHero5";
	ch.name 	= "Виктор";
	ch.lastname = "Малье";
	ch.model	= "Banker_1_2";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.City = "FortFrance";
	//ch.location	= "FortFrance_tavern";
	//ch.location.group = "sit";
	//ch.location.locator = "sit_front1";
	ch.Dialog.Filename = "NewPapka/VictorMalie.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	
	//============== Парень в таверне, первый блин. =================
	makeref(ch,Characters[n]);
	ch.id		= "ProstoParen";
	ch.model	= "adolf";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/ProstoParen.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	
	//============== Диего Эспиноза, первый блин. =================
	makeref(ch,Characters[n]);
	ch.id		= "DiegoEspinosa";
	ch.name 	= "Диего";
	ch.lastname = "Эспиноза";
	ch.model	= "Espinosa";
	ch.rank 	= 2;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/Espinosa.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 2);
	TakeNItems(ch, "jewelry2", 1);
	GiveItem2Character(ch, "pistol4");
	GiveItem2Character(ch, "blade_20");
	EquipCharacterbyItem(ch, "pistol4");
	EquipCharacterbyItem(ch, "blade_20");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 70.0, 70.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	//============== Достойный доверия. Дарио Веспа =================
	makeref(ch,Characters[n]);
	ch.id		= "Dario";
	ch.name 	= "Дарио";
	ch.lastname = "Веспа";
	ch.model	= "usurer_3";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.City = "SentJons";
	ch.location	= "SentJons_town";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "NewPapka/DarioVespa.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = ENGLAND;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
	//============== Достойный доверия. Лора Лонг =================
	makeref(ch,Characters[n]);
	ch.id		= "LoraLong";
	ch.name 	= "Лора";
	ch.lastname = "Лонг";
	ch.model	= "Women_1";
	ch.rank 	= 40;
	ch.sex = "woman";
    ch.model.animation = "woman";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/LoraLong.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = HOLLAND;
	ch.SaveItemsForDead = true;
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;




	//============== Достойный доверия, Томас Глонг. =================
	makeref(ch,Characters[n]);
	ch.id		= "Thomas_Glong";
	ch.name 	= "Томас";
	ch.lastname = "Глонг";
	ch.model	= "officer_8";
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/ThomasGlong.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = HOLLAND;
	ch.SaveItemsForDead = true;
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "HOLLAND_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;
	
	
///////////////////////////////////////////Достойный доверия Барни Гамбл//////////////////////////////////////////////////////
    
	makeref(ch,Characters[n]);
	ch.id		= "Barny_Gamble";
	ch.name 	= "Барни";
	ch.lastname = "Гамбл";
	ch.model	= "mercen_11";
	ch.rank 	= 20;
	ch.reputation = 15;
	ch.sex = "man";
    ch.model.animation = "man";
	//ch.location	= "FortFrance_town";
	//ch.location.group = "goto";
	//ch.location.locator = "goto5";
	ch.Dialog.Filename = "NewPapka/BarnyGamble.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	SetCharacterPerk(ch, "LongRangeShoot");
	SetCharacterPerk(ch, "CriticalShoot");
	SetCharacterPerk(ch, "HullDamageUp");
	SetCharacterPerk(ch, "FastReload");
	SetCharacterPerk(ch, "SailDmageUp");
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;


//============== Начальный квест Диего =================

	makeref(ch,Characters[n]);
	ch.id		= "DiegoEnemy";
	ch.name 	= "Неизвесстный";
	ch.lastname = "Неизвестный";
	ch.model	= "Citiz_58";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/DiegoEnemy.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;


	//============== Начальный квест Жак Виктиме =================
	makeref(ch,Characters[n]);
	ch.id		= "Jak_Victime";
	ch.name 	= "Жак";
	ch.lastname = "Виктиме";
	ch.model	= "devlin";
	ch.rank 	= 40;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/JakVictime.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	//ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 500.0, 500.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;

//============== Начальный квест Рене Волёр =================
	makeref(ch,Characters[n]);
	ch.id		= "Rene_Voleur";
	ch.name 	= "Рене";
	ch.lastname = "Волёр";
	ch.model	= "Citiz_23";
	ch.rank 	= 4;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/ReneVoleur.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	//ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;


	//============== Начальный квест Жерар Эмози =================
	makeref(ch,Characters[n]);
	ch.id		= "Jerar_Emozi";
	ch.name 	= "Жерар";
	ch.lastname = "Эмози";
	ch.model	= "Citiz_21";
	ch.rank 	= 4;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/JerarEmozi.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	//ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 100.0, 100.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;



	//============== Начальный квест Валинье =================
	makeref(ch,Characters[n]);
	ch.id		= "Valinie";
	ch.name 	= "Грегуар";
	ch.lastname = "Валинье";
	ch.model	= "Guide_1";
	ch.rank 	= 4;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/Valinie.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5");
	EquipCharacterbyItem(ch, "blade_29");
	SetSPECIAL (ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 500.0, 500.0);
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;



	//============== Случай в Бастере, Жан-Люк Аморе. =================
	makeref(ch,Characters[n]);
	ch.id		= "Amore";
	ch.name 	= "Жан-Люк";
	ch.lastname = "Аморе";
	ch.model	= "off_fra_4";
	ch.rank 	= 3;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/BasterEvent/Amore.c";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol1");
	GiveItem2Character(ch, "blade_03");
	EquipCharacterbyItem(ch, "pistol1");
	EquipCharacterbyItem(ch, "blade_03");
	SetSPECIAL (ch, 7, 10, 10, 8, 7, 8, 7);
	LAi_SetHP(ch, 120.0, 120.0);
    SetSelfSkill(ch, 50, 20, 20, 20, 10);
    SetShipSkill(ch, 10, 10, 10, 10, 9, 6, 8, 9, 5);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;


	//============== Случай в Бастере, Неизвестный. =================
	makeref(ch,Characters[n]);
	ch.id		= "Mask1";
	ch.name 	= "Маска1";
	ch.lastname = "Маска1";
	ch.model	= "Citiz_58";
	ch.rank 	= 3;
	ch.sex = "man";
    ch.model.animation = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "NewPapka/Mask1";
	ch.dialog.currentnode = "First Time";
	ch.nation = PIRATE;
	ch.SaveItemsForDead = true;
	TakeNItems(ch, "potion2", 20);
	GiveItem2Character(ch, "pistol1");
	GiveItem2Character(ch, "blade_03");
	EquipCharacterbyItem(ch, "pistol1");
	EquipCharacterbyItem(ch, "blade_03");
	SetSPECIAL (ch, 7, 10, 10, 8, 7, 8, 7);
	LAi_SetHP(ch, 120.0, 120.0);
    SetSelfSkill(ch, 50, 20, 20, 20, 10);
    SetShipSkill(ch, 10, 10, 10, 10, 9, 6, 8, 9, 5);
	LAi_SetLoginTime (ch, 0.0, 24.0);
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, false);
	n=n+1;*/


	











	
	return n;
}