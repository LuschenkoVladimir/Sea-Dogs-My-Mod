
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
		
		
		
	case "Sharlieshore_1":
    dialog.text = "Кто вы и чем обязан, месье?";
    link.l1 = "Вот так сюрприз...никогда не знаешь, где найдёшь, а где потеряешь. Прикажите сложить оружие своим людям и снимите маску. Мне не терпится полюбоваться на вас и узнать, что вы хотели от меня и моего брата.";
    link.l1.go = "Sharlieshore_2";
    break;  		
		
		
	case "Sharlieshore_2":
    dialog.text = "Не представляю, о чём вы. Если вы и ваши матросы немедленно уберётесь отсюда, то я сделаю вид, что вас здесь не было, и ничего не произошло.";
    link.l1 = "Тогда придётся содрать с тебя эту маску! К бою!";
    link.l1.go = "Sharlieshore_exit";
    break;  	


    case "Sharlieshore_exit":
	AddDialogExitQuest("FirstOut_19"); 
    dialogexit();
    break;	


    case "Sharlieshore_3":
    dialog.text = "Нам незачем воевать, де Мор, и мне не нужна ваша смерть. Прикажите своим людям остановиться.";
    link.l1 = "(Шарль тяжело ранен и даёт сигнал своей команде остановить бой. Люди незнакомца также убирают шпаги в ножны) Кто вы?";
    link.l1.go = "Sharlieshore_4";
    break;  


    case "Sharlieshore_4":
    dialog.text = "Этого я вам сказать не могу. По крайней мере, пока. Вы истекаете кровью, поэтому не теряйте времени и позвольте матросам отнести вас к лекарю.";
    link.l1 = "Но...(Шарль теряет сознание и впадает в беспамятство)";
    link.l1.go = "Sharlieshore_exit1";
    break;


    case "Sharlieshore_exit1":
	AddDialogExitQuest("FirstOut_22"); 
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