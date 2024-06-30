
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
		
	case "Klod_Deck":
    dialog.text = "Что вам угодно, месье?";
    link.l1 = "Дело в том, что я здесь по поручению Его Светлости Филиппа де Пуанси собираю сведения о делах здешней колонии. Ваш корабль первый, который я заметил в бухте, поэтому...";
    link.l1.go = "Klod_Deck_1";
    break; 


	case "Klod_Deck_1":
    dialog.text = "Чем же я могу помочь вам и Его Светлости?";
    link.l1 = "Ну, вы могли бы рассказать, как обстоят дела с преступностью и пиратством.";
    link.l1.go = "Klod_Deck_2";
    break; 


	case "Klod_Deck_2":
    dialog.text = "Знаете, в здешней колонии всё нормально... было, пока не появились вы.";
    link.l1 = "Что вы имеете в виду?! Вы меня явно с кем-то путаете! Ладно, мне пора на свой корабль.";
    link.l1.go = "Klod_Deck_3";
    break; 


	case "Klod_Deck_3":
    dialog.text = "Ты всерьёз думаешь, урод, что я вот так просто отпущу убийцу своего брата?! Ты ещё жив только потому, что мне непонятно, зачем и по чьему приказу ты вообще полез не в свои дела. Вяжи его, ребята!";
    link.l1 = "Да, ты мне тоже нужен живым, мерзавец.";
    link.l1.go = "Klod_Deck_exit";
    break;  	


    case "Klod_Deck_exit":
    AddDialogExitQuest("BasterEvent_28");
	dialogexit();
    break;



    case "After_FightDeck":
    dialog.text = "Погоди...Чего ты хочешь?";
    link.l1 = "Где бумаги, украденные у Сейна?";
    link.l1.go = "After_FightDeck_1";
    break; 


    case "After_FightDeck_1":
    dialog.text = "Ты действительно хочешь это знать? Они уже у заказчика. Это серьёзные люди, тебе не....";
    link.l1 = "Заткнись, не думай, что сможешь тянуть время, пока не подбежит подмога. Имя и адрес, или я с удовольствием проткну тебя насквозь!";
    link.l1.go = "After_FightDeck_2";
    break;


    case "After_FightDeck_2":
    dialog.text = "Андрэ...Андрэ Рэно...Его резиденция напротив губернаторской....";
    link.l1 = "(После этих слов Таро ловко и быстро ныряет на нижнюю палубу за подмогой) Чёрт, я не могу дать ему уйти, иначе в городе меня будет ждать засада. Надо уходить на свой корабль и брать этот люггер на абордаж.";
    link.l1.go = "After_FightDeck_exit";
    break;


    case "After_FightDeck_exit":
    AddDialogExitQuest("BasterEvent_31");
	dialogexit();
    break;
		
		
		
	



	
		
		}
}