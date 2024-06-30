
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
    dialog.text = "Здравствуйте, капитан.";
    link.l1 = "Здравствуйте.";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Это случайно не вы капитан "+GetFullName(Pchar)+"?";
    link.l1 = "Да, это я.";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "Отлично, мне как раз нужен капитан с вашими талантами. У меня к вам деловое предложение.";
    link.l1 = "Готов внимательно его выслушать.";
    link.l1.go = "dialog3";
    break;  		
		
		
		
	case "dialog3":
    dialog.text = "Ничего сложного. Нужно найти одного человека и заставить его замолчать навсегда.";
    link.l1 = "Если вы сможете меня заинтересовать, то я не исключаю своего участия.";
    link.l1.go = "dialog4";
	link.l2 = "С подобными предложениями вы обратились не по адресу.";
	link.l2.go = "dialogexit";
    break;  	



	case "dialog4":
    dialog.text = "Насчёт щедрого вознаграждения не извольте беспокоиться. Я вам предлагаю очистить свет от одного негодяя, его зовут Диего Эспиноза. Вы сможете найти его на Сент-Кристофере. Когда всё будет кончено, снимите алмаз с его тела.";
    link.l1 = "Хорошо. По рукам.";
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