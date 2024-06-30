
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
		
		
		
	case "dialogLULU_1":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LULU"));
    dialog.text = "Странный вопрос, маркиза. Где ещё ночью быть добропорядочному супругу, как ни дома со своей законной женой. Вы так не считаете, мадам? Или вы предпочитаете общество своего супруга кому-то другому?";
    link.l1 = "";
    link.l1.go = "dialogLULU_1exit";
    break; 


    case "dialogLULU_1exit":
    AddDialogExitQuest("Memories_21");
	dialogexit();
    break; 	


    case "dialogLULU_2":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LULU"));
    dialog.text = "Ха-ха. Жена в вашем положении начинает говорить об обмане? Вы всегда мне нравились своей непосредственностью, Луиза. Ха-ха. Кстати, вы наконец представите молодого человека, который стоит рядом с вами. Мы, кажется, снова увлеклись нашими семейными раздорами и совсем забыли про гостя. Это невежливо с нашей стороны.";
    link.l1 = "";
    link.l1.go = "dialogLULU_2exit";
    break; 	


    case "dialogLULU_2exit":
    AddDialogExitQuest("Memories_23");
	dialogexit();
    break;
		
		
	case "dialogSharl_1":
    dialog.text = "Ну, если моя жена отказывается отрекомендовать вас, то, может, вы сами представитесь, месье?";
    link.l1 = "К чему весь этот дешёвый спектакль, маркиз? По-моему, здесь достаточно светло, чтобы разглядеть друг друга.";
    link.l1.go = "dialogSharl_2";
    break;  	

    case "dialogSharl_2":
    dialog.text = "Ну, знаете, де Мор, в судебных тяжбах так принято - сначала надо, чтобы ответчик сам удостоверил свою личность.";
    link.l1 = "Вы собираесь со мной судиться?";
    link.l1.go = "dialogSharl_3";
    break;	


    case "dialogSharl_3":
    dialog.text = "Нет, я собираюсь вас судить. Сегодня я для вас и обвинитель, и судья, и палач в одном лице, де Мор.";
    link.l1 = "Мне не нравятся ваши игры, маркиз, как, впрочем, не нравитесь вы сами и всё, что с вами связано. Я люблю эту женщину и смею надеяться, что она любит меня. Доставайте клинок и решим всё в честном поединке.";
    link.l1.go = "dialogSharl_4";
    break;


    case "dialogSharl_4":
    dialog.text = "Увы, де Мор, всё не так просто для вас. Измена жены, конечно, достаточный повод чтобы проткнуть вас шпагой, но мы оба знаем, что речь не об этом.";
    link.l1 = "Что вы имеете ввиду?";
    link.l1.go = "dialogSharl_exit1";
    break;

    case "dialogSharl_exit1":
    AddDialogExitQuest("Memories_24");
	dialogexit();
    break;


    case "dialogLULU_3":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LULU"));
    dialog.text = "Видите ли, дорогая жена моя Луиза. Как бы вам объяснить поделикатнее, не слишком затрагивая ваше раздутое женское эго. В общем наш славный рыцарь де Мор в вашей постели выполняет задание государственной важности от самого (переходит от ироничного к издевательскому тону) Его Высокопреосвященства. Для этой цели сей высокий духовный сан даже пытался задержать меня в Париже, чтобы его слуге было удобнее выполнять свою миссию в вашем обществе сегодняшней ночью.";
    link.l1 = "";
    link.l1.go = "dialogLULU_3exit";
    break; 	


    case "dialogLULU_3exit":
    AddDialogExitQuest("Memories_25");
	dialogexit();
    break;


    case "dialogSharl_5":
    dialog.text = "Да, де Мор, скажите, что я лгу. И в качестве доказательства покажите письмо с Мальтийской печатью, которое только что выкрали из моей спальни.";
    link.l1 = "Довольно. Это представление затянулось, я не намерен больше выслушивать смехотворные обвинения от такого ничтожества как вы, маркиз.";
    link.l1.go = "dialogSharl_6";
    break;


    case "dialogSharl_6":
    dialog.text = "А придётся, де Мор. Если вы торопитесь, то перейдём сразу к сути. Дом окружён, и вам отсюда не выбраться. Моя смерть вам не поможет, только лишит последней возможности пережить эту ночь. Мои люди убьют вас в любом случае. У вас только один выход - отдать письмо, и я вас отпущу живым и здоровым. Слово дворянина.";
    link.l1 = "Неужели вы всерьёз полагаете, что я буду играть в вашем представлении ту роль, которую вы мне отвели? С дороги, я ухожу отсюда.";
    link.l1.go = "dialogSharl_7";
    break;


    case "dialogSharl_7":
    dialog.text = "Это глупо, де Мор. Вы проиграли, и всё что вы сможете в лучшем для вас случае - это убить нескольких моих людей и умереть самому. К чему это излишнее кровопролитие?! Луиза, может, ВЫ сможете вразумить вашего 'друга'?";
    link.l1 = ".....";
    link.l1.go = "dialogSharl_exit2";
    break;


    case "dialogSharl_exit2":
    AddDialogExitQuest("Memories_27");
	dialogexit();
    break;


    case "dialogSharl_8":
    dialog.text = "Плохо выглядите, де Мор. Вы уже одной ногой в могиле. Повторяю: дом окружён, здесь ещё много моих людей! Даю вам последний шанс! Письмо!";
    link.l1 = "Вижу, ваши псы прижали хвосты, месье трус! Так и будете прятаться за их спинами?";
    link.l1.go = "dialogSharl_9";
    break;


    case "dialogSharl_9":
    dialog.text = "Вам не спровоцировать меня, де Мор. Вы сами выбрали свою судьбу. Убейте его!";
    link.l1 = "Сейчас я разделаюсь с собаками, а затем займусь хозяином!";
    link.l1.go = "dialogSharl_exit3";
    break;


    case "dialogSharl_exit3":
    AddDialogExitQuest("Memories_37");
	dialogexit();
    break;


    case "dialogMan_1":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayetMan"));
    dialog.text = "Ну что ещё, Андрэ?";
    link.l1 = "Монсеньор, у ворот люди кардинала. Их капитан требует сложить оружие и выдать Шарля де Мора.";
    link.l1.go = "dialogMan_2";
    break;


    case "dialogMan_2":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayetMan"));
    dialog.text = "Дьявол!!! Как этот лис сумел пронюхать так быстро?! Сколько их?!";
    link.l1 = "Из тех, что мы можем видеть, отряд человек в двадцать-тридцать, монсеньор.";
    link.l1.go = "dialogMan_3";
    break;


    case "dialogMan_3":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("LaFayetMan"));
    dialog.text = "Скажи капитану, что месье де Мор просто добрый гость в нашем доме, и ему ничего не угрожает. Пусть войдёт и убедится в этом.";
    link.l1 = "Слушаюсь, монсеньор.";
    link.l1.go = "dialogMan_exit";
    break;


    case "dialogMan_exit":
    AddDialogExitQuest("Memories_40");
	dialogexit();
    break;


    case "dialogOfficer_1":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("CaptainFra"));
    dialog.text = "В чём дело капитан?";
    link.l1 = "Именем Его Величества Короля прошу вас отправиться со мной. У меня приказ Его Высокопреосвященства препроводить вас в Венсен, где вы будете содержаться под стражей. Вот, можете удостовериться.";
    link.l1.go = "dialogOfficer_2";
    break;


    case "dialogOfficer_2":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("CaptainFra"));
    dialog.text = "За что, капитан?! Вот вы можете видеть месье де Мора в целости и сохранности. (указывает на Шарля)";
    link.l1 = "(Капитан оборачивается в сторону Шарля, доставая приказ Мазарини, и в этот момент маркиз мгновенно достаёт кинжал и бьёт им капитана в шею)";
    link.l1.go = "dialogOfficer_exit";
    break;


    case "dialogOfficer_exit":
    AddDialogExitQuest("Memories_43");
	dialogexit();
    break;


    case "dialogSharl_10":
    sld = characterFromID("LaFayet");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("BLAZE"));
    dialog.text = "Убейте их всех!";
    link.l1 = "Теперь вы от меня не уйдёте, маркиз!";
    link.l1.go = "dialogSharl_exit4";
    break;


    case "dialogSharl_exit4":
    AddDialogExitQuest("Memories_45");
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