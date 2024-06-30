
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
    dialog.text = "Какого дьявола?! Кто вы такие?!";
    link.l1 = "Если я не ошибаюсь, месье Рэно?";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Да, чёрт возьми, не ошибаетесь! Я Андрэ Рэно, доверенное лицо губернатора, и вы ответите.... ";
    link.l1 = "Я вас хорошо слышу и понимаю, месье, поэтому перестаньте кричать и сыпать угрозами, вы не в том положении. Если вы думаете этими криками привлечь внимание тех, головорезов, которые внизу, то это лишь ускорит вашу скоропостижную кончину.";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "(Понижая тон) Хорошо, хорошо, только уберите оружие. Кто вы и что вам надо?";
    link.l1 = "Ну вот уже лучше, месье Рэно. Разве вы не приглашали меня к вам в гости через посыльного к местному тавернщику? Было бы невежливо отказывать столь значимой особе, поэтому я здесь и внимательно вас слушаю, только постарайтесь уложиться в несколько минут, потому как я человек занятой и не люблю, когда меня отрывают от моих дел по пустякам.";
    link.l1.go = "dialog3";
    break;  		


	case "dialog3":
    dialog.text = "А-а-а, это вы....Я должен был догадаться. Вы уже многое натворили, но я вас недооценил.....";
    link.l1 = "Я просил вас быть лаконичным, не стоит тянуть время, а заодно и моё терпение.";
    link.l1.go = "dialog4";
    break; 


    case "dialog4":
    dialog.text = "Да, к делу, месье. Я хотел лишь с вами побеседовать и ввести в курс здешних дел, объяснить вам, что вы взялись помогать бесчестному человеку. Франсуа Сейн - вор. Бумаги, которые, вероятно, он просил вернуть, ему не принадлежат.";
    link.l1 = "Кому же они принадлежат?";
    link.l1.go = "dialog5";
    break; 


    case "dialog5":
    dialog.text = "Мне. Это записи некоторых финансовых операций, которые я...впрочем, это уже лишняя для вас информация.";
    link.l1 = "Как 'неожиданно', месье. Значит, вы ждали меня в гости 'только поговорить', а несколько головорезов на первом этаже предназначались для моего почётного эскорта. Охотно верю. И каковы же ваши предложения?";
    link.l1.go = "dialog6";
    break;  	


    case "dialog6":
    dialog.text = "Если вы выдадите мне Сейна, и этот вор понесёт заслуженную кару, то я заплачу вам пятьдесят тысяч. Кроме того, я имею некоторый вес при дворе местного губернатора, так что вы сможете получать выгодные контракты и поручения. Смею вас заверить, что дружба со мной стоит гораздо больше тех денег, что могу вам немедленно дать я или тем более Сейн.";
    link.l1 = "Звучит убедительно.";
    link.l1.go = "exit";
    break; 



    case "exit":
    AddDialogExitQuest("BasterEvent_39");
	dialogexit();
    break;





    case "Last Time":
    dialog.text = "Какие вам нужны гарантии?";
    link.l1 = "Документы, сударь. Вы отдадите мне их.";
    link.l1.go = "Last Time_1";
    break; 



    case "Last Time_1":
    dialog.text = "Это невозможно. У меня их нет, но даже если бы и были....";
    link.l1 = "Повторяю, документы, сударь! Или я проткну вас насквозь! Немедленно!";
    link.l1.go = "Last Time_2";
    break; 


    case "Last Time_2":
    GiveItem2Character(pchar, "SeinDocument");
    dialog.text = "Ну, хорошо. Чёрт бы вас побрал! Держите! (доставая из стола бумаги и скрытно оружие)";
    link.l1 = "Вот так бы раньше. (начинаем рассматривать)";
    link.l1.go = "Last Time_exit";
    break; 


    
    case "Last Time_exit":
    AddDialogExitQuest("BasterEvent_41");
	dialogexit();
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