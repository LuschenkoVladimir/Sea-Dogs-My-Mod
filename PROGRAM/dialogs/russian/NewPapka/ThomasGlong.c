
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
    dialog.text = "Ещё и пираты! Проклятье! Что за день сегодня?";
    link.l1 = "Всё не так плохо. Меня зовут Шарль де Мор, и я прбыл по поручению Дарио Веспы.";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Что? Как это понимать?";
    link.l1 = "Ваша жена забыла у дарио своё фамильное кольцо. Я согласился вернуть его.";
    link.l1.go = "dialog2";
    break;  		
		
		
	case "dialog2":
    dialog.text = "Это что шутка? Или вас послало само Провидение?";
    link.l1 = "Скорее Дарио, но можете считать как вам угодно.";
    link.l1.go = "dialog3";
    break;  



    case "dialog3":
    dialog.text = "И я могу вернуться к себе домой?";
    link.l1 = "Я даже вам помогу. Курс на Филипсбург!";
    link.l1.go = "exitdialog";
    break;  


    case "exitdialog":
    AddDialogExitQuest("Trustwothy_10");
	dialogexit();
    break;



    case "dialog4":
    dialog.text = "Не знаю, что и сказать. Вы спасли мне жизнь, я обязан вам по гроб жизни!";
    link.l1 = "Говорят, вы когда-то служили под началом самого капитана Мингса?";
    link.l1.go = "dialog5";
    break;  	



    case "dialog5":
    dialog.text = "О, да! Это было чудесное время! Я поступил на службу простым матросом, но уже через два года занял должность щтурмана.";
    link.l1 = "Очень интересно, люблю людей с большим опытом в своём деле.";
    link.l1.go = "dialog6";
    break;  


    case "dialog6":
    dialog.text = "Знаете, я ведь смлг бы кое-чему научит вас. Не сочтите за оскорбление, но я заметил, что вы ещё новичок в морском деле.";
    link.l1 = "Буду рад послушать ваши наставления.";
    link.l1.go = "exit";
    break;  


    case "dialog7":
    dialog.text = "Ну, теперь всё уяснили?";
    link.l1 = "Спасибо за ценные уроки. Мне это очень пригодится.";
    link.l1.go = "dialog8";
    break;  	



    case "dialog8":
    AddMoneyToCharacter(pchar, 15000);
    dialog.text = "Не благодарите. Примите ещё эту скромную компансацию из наших сбережений. В конце концов вы спасли мне жизнь.";
    link.l1 = "Ещё раз спасибо, но теперь мне пора. Приятно было пообщаться.";
    link.l1.go = "dialog9";
    break;  


    case "dialog9":
    dialog.text = "Подождите, Шарль. Я хотел спросить вас.";
    link.l1 = "Да, слушаю.";
    link.l1.go = "dialog10";
    break; 	


    case "dialog10":
    dialog.text = "Вам не нужен офицер?";
    link.l1 = "Вы хотите поступить ко мне на службу?";
    link.l1.go = "dialog11";
    break; 	



    case "dialog11":
    dialog.text = "Нет. Дело в том... в общем уже несколько дней я скрываю у себя одного человека. У него проблемы с законом, но при этом я могу вам его зарекоммендовать как отличного канонира.";
    link.l1 = "Надеюсь, он никого не убил?";
    link.l1.go = "dialog12";
    break; 	



    case "dialog12":
    dialog.text = "Нет, просто он оказался не в то время и не в том месте. Его зовут Барни Гамбл. Не отказывайтесь, Шарль это может быть отличным решением для всех.";
    link.l1 = "Прошу прощения, Томас, но я не могу брать в команду сомнительного человека. Мне действительно уже пора. Всего доброго.";
    link.l1.go = "ofexit";
	link.l2 = "Ну, если вы его так рекоммендуете... Где он?";
	link.l2.go = "dialog13";
    break;  




    case "ofexit":
    dialog.text = "Воля ваша. Попутного ветра.";
    link.l1 = ".....";
    link.l1.go = "offexit";
    break; 	



     case "offexit":
     AddDialogExitQuest("Trustwothy_exit");
     dialogexit();
     break;


    case "sectime":
    dialog.text = "Однажды вы спасли мне жизнь. Спасибо, капитан.";
    link.l1 = "Я не мог поступить иначе.";
    link.l1.go = "exitquest";
    break; 	


    case "dialog13":
    dialog.text = "В надёжном месте. У верфи есть старая лодка. Пусть ваши люди встретят его там.";
    link.l1 = "Хорошо. Я перегоню корабль в залив Симпсон и буду ждать Барни там.";
    link.l1.go = "exit1";
    break; 	


    case "exit1":
    dialogexit();
    AddDialogExitQuest("Trustwothy_13");
    break;

    case "exit":
    AddDialogExitQuest("Trustwothy_12");
    NextDiag.CurrentNode = "first_time";
    dialogexit();
    break;



    


	





	
		
		}
}