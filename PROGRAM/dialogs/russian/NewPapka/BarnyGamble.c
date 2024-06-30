
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
    dialog.text = "Я должен незаметно пробраться к лодке возле верфи.";
    link.l1 = "......";
    link.l1.go = "exit";
    break;  


    case "exit":	
    dialogexit();
    break;
		
		
		
	case "officer":
    dialog.text = "Капитан Шарль де Мор, я рад с вами познакомиться. Томас сказал, что вы готовы предоставить мне место оффицера.";
    link.l1 = "Да, Томас отрекоммендовал мне вас как отличного канонира, поэтому я согласился на его предложение.";
    link.l1.go = "officer1";
    break;  		
		
		
	case "officer1":
    dialog.text = "Я вам очень благодарен. Мне не терпится снова выйти в море.";
    link.l1 = "Тогда добро пожаловать на борт.";
    link.l1.go = "officer2";
    break;  		
		
		
		
	case "officer2":
    AddDialogExitQuest("Trustwothy_18");
    dialogexit();
    break;  	



	



	
		
		}
}