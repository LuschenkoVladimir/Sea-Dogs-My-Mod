
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
    dialog.text = "Почему вы врываетесь без стука?! Уходите или я позову стражу!";
    link.l1 = "Простите, но я стучал. Наверное, вы были чем-то заняты и не услышали.";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Что вам нужно? Если вы торговец, то уходите сразу, я ничего не покупаю.";
    link.l1 = "Моё имя Шарль де Мор и мне нужен Томас Глонг.";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "Я его жена Лора Глонг. Что ему передать?";
    link.l1 = "Мне хотелось бы поговорить с ним лично.";
    link.l1.go = "dialog3";
    break;  		
		
		
		
	case "dialog3":
    dialog.text = "Это невозможно! Мой муж сейчас на судне "Хайрок". И он не любит, когда его отвлекают от работы.";
    link.l1 = "Я привёз золотую брошь, которую вы забыли у Дарио Веспы.";
    link.l1.go = "dialog5";
    break;  	



	case "dialog5":
    dialog.text = "О, это просто чудесно! Я думала, что потеряла её навсегда, а оказывается, что просто забыла у Дарио.";
    link.l1.edit = 1;
	link.l1 = "";
    link.l1.go = "dialog7";
    break;


    case "dialog6":
    dialog.text = "Назовите сумму ещё раз.";
    link.l1.edit = 1;
	link.l1 = "";
    link.l1.go = "dialog7";
    break; 
    


    case "dialog7": 
                int iTemp = sti(DialogEditStrings[1]);
              if (iTemp <= 0)
			  {
                    dialog.text = "Не поняла. Можно ещё раз?";
                 	link.l1 = "";
                    link.l1.go = "dialog6";
					break;
			  }
			  
			  if (iTemp > 1 && iTemp < 999)
			  {
				  AddMoneyToCharacter(pchar, 4000); 
                  dialog.text = "Воспитание не позволит мне заплатить такому скромному человеку меньше 4000. Вот держите.";
                  link.l1 = "Благодарю вас.";
                    link.l1.go = "dialog8";
			  }
          			  
			  if (iTemp > 1000 && iTemp <= 1500)
			  {
				  AddMoneyToCharacter(pchar, iTemp); 
                  dialog.text = "Немного. Вот держите.";
                  link.l1 = "Благодарю вас.";
                    link.l1.go = "dialog8";
			  }	  
			  
			  if (iTemp > 1501 && iTemp <= 3199)
			  {
				  AddMoneyToCharacter(pchar, iTemp); 
                  dialog.text = "Прилично. Вот держите.";
                  link.l1 = "Благодарю вас.";
                    link.l1.go = "dialog8";
			  }
			  
			  if (iTemp > 3200)
			  {
				  AddMoneyToCharacter(pchar, 2000); 
                  dialog.text = "Вы с ума сошли? Хватит с вас и 2000. Держите.";
                  link.l1 = "Как скажете.";
                    link.l1.go = "dialog8";
			  }
	
	break;
	
	case "dialog8":
	log_info("Вы отдали предмет");
	TakeItemFromCharacter(pchar, "Glong_ring");
    dialog.text = "Рада это слышать.";
    link.l1 = "Скажите, когда я смогу застать вашего мужа?";
    link.l1.go = "dialog9";
    break;  	
	
	
	
	case "dialog9":
    dialog.text = "Я не знаю, когда он вернётся. Если хотите, можете наведаться на судно "Хайрок".";
    link.l1 = "Понятно. Рад был познакомиться с вами, всего доброго.";
    link.l1.go = "exit";
    break;  



    case "Second Time":
    dialog.text = "Что-нибудь ещё, капитан?";
    link.l1 = "Нет, в другой раз.";
    link.l1.go = "exit1";
    break;  	
		


    case "exit":
	AddDialogExitQuest("Trustwothy_4");
	sld = characterFromID("LoraLong");
	Lai_SetCitizenType(sld);
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;


    case "exit1":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;


	
		
		}
}