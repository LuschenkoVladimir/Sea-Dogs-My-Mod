
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
		
		
		
	case "AnnettBanditHut_1":
    dialog.text = "Сударь, кто бы вы ни были, умоляю, спасите нас! Я - жена губернатора Аннетт ду Парке. А это - моя дочь Катрин. Эти мерзкие предатели (с ненавистью смотрит на труп только что убитого Шарлем офицера) похитили нас несколько дней назад....";
    link.l1 = "Да, мадам, мы здесь как раз для того, чтобы найти вас. Это ваше ожерелье? (Шарль показывает ожерелье, снятое с трупа Кабаля)";
    link.l1.go = "AnnettBanditHut_2";
    break;  		
		
		
	case "AnnettBanditHut_2":
    dialog.text = "О да, сударь! Эти негодяи заставили меня его снять и отдать им (плачет)....";
    link.l1 = "Но теперь они мертвы, и ожерелье возвращается к вам (протягивает мадам ду Парке её ожерелье).";
    link.l1.go = "AnnettBanditHut_3";
    break; 


    case "AnnettBanditHut_3":
    TakeItemFromCharacter(pchar, "jewelry25");
    dialog.text = "Вы так добры, сударь. Но кто вы?  И как вам стало известно о нашем несчастье? Мы вам обязаны жизнью.";
    link.l1 = "Моё имя - Шарль де Мор, и я прибыл в Сен-Пьер уже после вашего похищения. И, по правде сказать, я бы не стал преувеличивать свою роль в вашем освобождении. Если бы не мой друг, Грегуар Валинье, я сейчас сидел бы в тюрьме и ничем не смог бы вам помочь. А вот, кстати, и он....";
    link.l1.go = "AnnettBanditHut_exit1";
    break; 		


    case "AnnettBanditHut_exit1":
    dialogexit();
    AddDialogExitQuest("GuberWife_23");
    break;


    case "AnnettBanditHut_4":
    sld = characterFromID("Valinie");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("AnnettduParke"));
	sld = characterFromID("AnnettduParke");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
    dialog.text = "Месье де Мор сказал, что именно вам мы с дочерью обязаны своим спасением. Примите нашу искреннюю благодарность и соболезнования в связи с гибелью этого человека. Когда мы доберёмся до Сен-Пьера, я и мой муж лично займёмся организацией его похорон со всеми почестями, которых он заслуживает.";
    link.l1 = "Спасибо, мадам. Кстати, насчёт вашего мужа. Получали ли вы какие-либо сведения от него, пока были в плену?";
    link.l1.go = "AnnettBanditHut_5";
    break; 

    case "AnnettBanditHut_5":
    dialog.text = "Нет, месье. С ним всё в порядке?";
    link.l1 = "Да, мадам. Я понимаю, что вам сейчас не до моих распросов, но я должен знать, кого вы подозреваете и каковы обстоятельства вашего пленения?";
    link.l1.go = "AnnettBanditHut_6";
    break; 

    case "AnnettBanditHut_6":
    dialog.text = "Увы, я мало что знаю и понимаю, месье. Это произошло на прогулке за городом. Наша стража вместо того, чтобы нас охранять, схватила меня и мою дочь и приволокла в эту лачугу, где мы пробыли несколько дней. Ужасных дней (плачет).....";
    link.l1 = "Хорошо, мадам, если вы можете идти, то мы немедленно выдвигаемся в Сен-Пьер, где ваш муж, надеюсь, сможет обеспечить вам надёжную защиту.";
    link.l1.go = "AnnettBanditHut_exit2";
    break; 


    case "AnnettBanditHut_exit2":
    dialogexit();
    AddDialogExitQuest("GuberWife_25");
    break;


    case "AnnettAfterFight_1":
    sld = characterFromID("DuParke");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("AnnettduParke"));
	sld = characterFromID("AnnettduParke");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("DuParke"));
    dialog.text = "Жак! (Губернатор и его жена крепко обнимаются) Ты не представляешь, что мы с Катрин пережили....";
    link.l1 = "";
    link.l1.go = "AnnettAfterFight_exit1";
    break; 


    case "AnnettAfterFight_exit1":
    dialogexit();
    AddDialogExitQuest("GuberWife_35");
    break;


    case "dialog4":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "dialog5";
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