
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
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialogSharlie_1":
    dialog.text = "Любимый, мне кажется, разлука с тобой длилась целую вечность.";
    link.l1 = "Любимая, я чуть не загнал коня, не дав ему передохнуть от самого Парижа.";
    link.l1.go = "dialogSharlie_2";
    break;  		
		
		
	case "dialogSharlie_2":
    dialog.text = "Его Высокопреосвященство сделал меня снова счастливой женщиной, задержав мужа ещё на два дня, хи-хи. ";
    link.l1 = "Надо будет подать ему прошение, чтобы он сделал его своим миньономи и определил ему покои в Лувре, ха-ха.";
    link.l1.go = "dialogSharlie_3";
    break;  


    case "dialogSharlie_3":
    dialog.text = "Хи-хи, не будь столь жесток, любимый. Даже он не заслуживает такой участи.";
    link.l1 = "К чёрту его. К чёрту эту тень, которая стоит между нами. Иди сюда, моя любовь.";
    link.l1.go = "dialogSharlie_4";
    break;


    case "dialogSharlie_4":
    dialog.text = "Да, этот день и эта ночь будут только нашими, я отпустила всех слуг. Идём наверх.";
    link.l1 = "(Берёт Лулу на руки и относит в покои наверху)";
    link.l1.go = "dialogSharlie_exit";
    break;		


    case "dialogSharlie_exit":
    AddDialogExitQuest("Memories_5a");
	dialogexit();
    break;


    case "dialogSharlie_5":
    dialog.text = "Где ты был?! Я тебя обыскалась! Тебе срочно надо бежать! Это муж...Чёрт! Чёрт! Чёрт! Мы пропали!";
    link.l1 = "И, как я вижу, он не один...";
    link.l1.go = "dialogSharlie_exit1";
    break;	


    case "dialogSharlie_exit1":
    //AddDialogExitQuest("Memories_18");
	dialogexit();
    break;


    case "dialogLaFayet_1":
    sld = characterFromID("LULU");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayet"));
    dialog.text = "Маркиз?! Почему вы не в Париже?";
    link.l1 = "";
    link.l1.go = "dialogLaFayet_1exit";
    break;

    case "dialogLaFayet_1exit":
    AddDialogExitQuest("Memories_20");
	dialogexit();
    break;


    case "dialogLaFayet_2":
    sld = characterFromID("LULU");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayet"));
    dialog.text = "Но вы мне писали, что задержитесь в Париже ещё на пару дней! Вы обманули меня!";
    link.l1 = "";
    link.l1.go = "dialogLaFayet_2exit";
    break;


    case "dialogLaFayet_2exit":
    AddDialogExitQuest("Memories_22");
	dialogexit();
    break;

    


    case "dialogSharlie_6":
    dialog.text = "(Начинает плакать) Шарль, скажи, что он лжёт!";
    link.l1 = "Я тебе всё обьясню, Лулу.";
    link.l1.go = "dialogSharlie_exit2";
    break;

    case "dialogSharlie_exit2":
    AddDialogExitQuest("Memories_26");
	dialogexit();
    break;


    case "dialogSharlie_7":
    dialog.text = "(Рыдает) Сударь, отдайте ему его письмо. Я...я не желаю вам смерти, хотя вы меня оскорбили только так, как мужчина может оскорбить женщину.";
    link.l1 = "Лулу, я люблю тебя! Я просто хочу, чтобы ты это знала!";
    link.l1.go = "dialogSharlie_exit3";
    break;

    case "dialogSharlie_exit3":
    AddDialogExitQuest("Memories_28");
	dialogexit();
    break;


    case "dialogLaFayet_3":
    sld = characterFromID("LULU");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayet"));
    dialog.text = "(Продолжает рыдать) Анри...прошу вас...умоляю! Отпустите его! Я сделаю всё, что вы хотите, только не убивайте его...";
    link.l1 = "";
    link.l1.go = "dialogLaFayet_3exit";
    break;


    case "dialogLaFayet_3exit":
    AddDialogExitQuest("Memories_29");
	dialogexit();
    break;


    case "dialogLaFayet_4":
    sld = characterFromID("LULU");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayet"));
    dialog.text = "(Продолжает рыдать) Нет!...Нет!...Не убивайте его!...Умоляю!...";
    link.l1 = "Уберите её! А с трупа её рыцаря снимите письмо. И постарайтесь его не повредить... Чёрт, что там ещё?!";
    link.l1.go = "dialogLaFayet_4exit";
    break;


    case "dialogLaFayet_4exit":
    AddDialogExitQuest("Memories_38");
	dialogexit();
    break;


    case "dialogSharlie_8":
    dialog.text = "Ты жив, Шарль! (Бросается на шею Шарлю, но тут же отступает) Мой муж мёртв? Поздравляю, ты выполнил задание...а теперь...а теперь оставьте меня...(разворачивается и уходит).";
    link.l1 = "Стой, Лулу! Не уходи, я люблю тебя! Я не...(шатается и теряет сознание от полученных ран)";
    link.l1.go = "dialogSharlie_9";
    break;


    case "dialogSharlie_9":
    dialog.text = "Шарль! Нет! Врача! Он ранен!";
    link.l1 = "";
    link.l1.go = "dialogSharlie_exit4";
    break;


    case "dialogSharlie_exit4":
    AddDialogExitQuest("Memories_49");
	dialogexit();
    break;
		
		
		
	case "dialog3":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog4";
	link.l2 = "";
	link.l2.go = "dialogexit";
    break;  	



	case "dialog4":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog5";
    break;  	
		
	

    case "dialog5":
	AddDialogExitQuest("MyQuest");
    dialog.text = "Тогда буду ждать вас в местной таверне.";
    link.l1 = "До скорой встречи.";
    link.l1.go = "exit";
    break;


    case "exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;



    case "dialogexit":
    NextDiag.CurrentNode = "Second Time2";
	dialogexit();
    break;




    case "Second Time":
    dialog.text = "Капитан, вы уже выполнили мою просьбу?";
    link.l1 = "Немного терпения, сударь.";
    link.l1.go = "exit";
    break;



    case "Second Time2":
    dialog.text = "Ваш отказ достоин сожаления.";
    link.l1 = "Держитесь от меня подальше, сударь.";
    link.l1.go = "dialogexit";
    break;
	
	
	
	case "complete":
    dialog.text = "Капитан, вы уже выполнили мою просьбу?";
    link.l1 = "Господин, о котором вы мне говорили, напал на меня. Мне пришлось защищаться. На его трупе я нашёл алмаз. Держите, мне он не нужен.";
    link.l1.go = "complete1";
    break;
	
	
	
	case "complete1":
	AddQuestRecord("MyQuest", "4");
	CloseQuestHeader("MyQuest");
	log_info("вы отдали алмаз");
	TakeItemFromCharacter(pchar, "jewelry2");
	AddMoneyToCharacter(pchar, 10000);
    dialog.text = "Да, я вас понял. Стечение обстоятельств и только, хе-хе. Возьму этот камень на память. Но я не могу его взять просто так, вот ваша компенсация.";
    link.l1 = "Не знаешь, где найдёшь, а где потеряешь. Всего доброго.";
    link.l1.go = "exitcomplete";
    break;
	
	
	
	case "exitcomplete":
	NextDiag.CurrentNode = "Three Time";
	dialogexit();
    break;
	
	
	case "Three Time":
    dialog.text = "Здравствуйте, сударь. Мы разве знакомы?";
    link.l1 = "Нет, просто хотел выразить вам своё почтение.";
    link.l1.go = "exitcomplete";
    break;





	
		
		}
}