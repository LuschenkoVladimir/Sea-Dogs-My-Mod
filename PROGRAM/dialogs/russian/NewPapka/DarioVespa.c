
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
    dialog.text = "Капитан, ваш казначей просил передать, что рабочие закончили загрузку, и можно отчаливать.";
    link.l1 = "Вы не представились.";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Меня зовут Дарио Веспа, я служащий местного банка. А вы капитан Саймон Дэвис.?";
    link.l1 = "Вы ошиблись, милейший. Меня зовут Шарль де Мор.";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "Как? Но мне сказали.... Прошу прощения.";
    link.l1 = "Капитан Саймон Дэвис был на приёме у губернатора до меня. Возможно, он ещё не покинул город.";
    link.l1.go = "dialog3";
    break;  		
		
		
	

    case "dialog3":
    dialog.text = "Да, возможно. Погодите, вы сказали де Мор? Шарль де Мор?";
    link.l1 = "К вашим услугам.";
    link.l1.go = "dialog4";
    break;  



    case "dialog4":
    dialog.text = "Говорят, что вы - человек достойный доверия. Могу ли я попросить вас об одной услуге?";
    link.l1 = "А как же Саймон Дэвис?";
    link.l1.go = "dialog5";
    break;


	
	case "dialog5":
    dialog.text = "Увы, на него нельзя полностью положиться";
    link.l1 = "Что у вас случилось?";
    link.l1.go = "dialog6";
	link.l2 = "Простите, у меня нет на это времени.";
	link.l2.go = "otkaz";
    break;  	



	case "otkaz":
    dialog.text = "Жаль, простите за беспокойство.";
    link.l1 = "Всего доброго.";
    link.l1.go = "otkazexit";
    break;


    case "otkazexit":
	sld = characterFromID("Dario");
	Lai_SetActorType(sld);
	Lai_ActorRunToLocation (sld, "reload", "reload8_back", "non", "", "", "", -1);
	dialogexit();
    break;    	
		
	

    case "dialog6":
    dialog.text = "Недавно у меня гостил мой старый друг Томас Глонг. Так получилось, что его жена заболела.";
    link.l1 = "Хорошо. Я выполню вашу просьбу.";
    link.l1.go = "dialog7";
	link.l2 = "Увы, у меня другие планы.Вынужден отказать";
	link.l2.go = "otkaz";
    break;
	
	
	case "dialog7":
    dialog.text = "Томас Глонг живёт в городе Филипсбург. Его дом с правой стороны от резиденции губернатора.";
    link.l1 = "Полагаю, с ним будет интересно побеседовать.";
    link.l1.go = "dialog9";
    break;
	
	
	case "dialog9":
    dialog.text = "Он может поделиться своими корабельными знаниями.";
    link.l1 = "Люблю деловых людей.";
    link.l1.go = "dialog10";
    break;
	
	
	case "dialog10":
	AddMoneyToCharacter(pchar, 2000);
    dialog.text = "Вот вам аванс. Основную компенсацию за беспокойство вам выплатит Глонг.";
    link.l1 = "Спасибо. Всего доброго.";
    link.l1.go = "diaex";
    break;


    case "diaex":
	GiveItem2Character(pchar, "Glong_ring");
	AddDialogExitQuest("Trustwothy_1");
	sld = characterFromID("Dario");
	Lai_SetActorType(sld);
	Lai_ActorRunToLocation (sld, "reload", "reload8_back", "non", "", "", "", -1);
	dialogexit();
    break;



    


	
		
		}
}