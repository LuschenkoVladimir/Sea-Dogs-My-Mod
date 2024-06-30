
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		
	case "First Time":
    dialog.text = "Добро пожаловать на мой корабль. Вы торговец? Хотите что-то продать?";
    link.l1 = "А где смешные усики?";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Усики? У меня их никогда не было. В должно быть про прежнего капитана. Забудьте о нём. Он мёртв.";
    link.l1 = "А что случилось?";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "Он вёз рабов с барбадоса и плохо с ними обращался. Нам удалось поднять восстание и расквитаться с ним. Как вас зовут?";
    link.l1 = "Шарль де Мор. Мне нужен человек по имени Томас Глонг. Надеюсь, он не...";
    link.l1.go = "dialog3";
    break;  



    case "dialog3":
    dialog.text = "Жив. Но вы не сможете его увидеть.";
    link.l1 = "Почему?";
    link.l1.go = "dialog4";
    break; 



    case "dialog4":
    dialog.text = "Он заложник. А теперь попрошу покинуть мой корабль.";
    link.l1 = "Сколько вы хотите за него?";
    link.l1.go = "dialog5";
    break; 



    case "dialog5":
    dialog.text = "Разве я назначал цену? Мы просто хотим безопасно покинуть здешние воды. ";
    link.l1 = "Капитан, но зачем он вам?";
    link.l1.go = "dialog6";
    break; 	



    case "dialog6":
    dialog.text = "Время нашей беседы истекло. Прошу покинуть мой корабль во избежание неприятностей.";
    link.l1 = "Я вас услышал.";
    link.l1.go = "exitdia";
    break; 	


    case "Second Time":
    dialog.text = "Я же просмл вас покинуть корабль!";
    link.l1 = "Уже ухожу.";
    link.l1.go = "exit";
    break; 



    case "exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;


    case "exitdia":
    AddDialogExitQuest("Trustwothy_5");
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;


     case "Djek_abordage":
     dialog.text = "Постой, капитан! Ты победил. Тебе нужен Глонг? Забирай его и оставь мой корабль в покое!";
    link.l1 = "Теперь уже поздно, мерзавец. Я тебе давал шанс договориться в Филипсбурге. А теперь ты умрёшь.";
    link.l1.go = "Djek_abordage1";
    break; 


    case "Djek_abordage1":
     dialog.text = "Ну тогда мы все взлетим на воздух!";
    link.l1 = "Посмотрим.";
    link.l1.go = "Djek_abordage2";
    break; 



    case "Djek_abordage2":
    dialogexit();
    LAi_SetCurHPMax(npchar);
    QuestAboardCabinDialogFree();
    LAi_group_SetRelation(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
    LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
    LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "TrustVictory");
    AddDialogExitQuest("MainHeroFightModeOn");
    break;
		
		
	





	
		
		}
}