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
    dialog.text = "Я отдыхаю, не мешай мне.";
    link.l1 = "Как скажешь.";
    link.l1.go = "exit1";
    break;
	
	case "exit1":
	NextDiag.CurrentNode = "First Time";
	dialogexit();
    break;
	
	
	case "dialog1":
    dialog.text = "Я отдыхаю, не мешай мне.";
    link.l1 = "Не хочешь подзаработать?";
    link.l1.go = "dialog2";
    break;
	
	
	case "dialog2":
    dialog.text = "Чего тебе..и-ик... надо?";
    link.l1 = "Информация, которая стоит сотню песо.";
    link.l1.go = "dialog3";
    break;
	
	
	case "dialog3":
    dialog.text = "Идёт...и-ик.";
    link.l1 = "Диего Эспиноза. куда он направился?";
    link.l1.go = "dialog4";
    break;
	
	case "dialog4":
	AddMoneyToCharacter(pchar, -100);
	AddDialogExitQuest("MyQ3");
    dialog.text = "Он отправился... и-ик.. за городские ворота.";
    link.l1 = "Спасибо. Возьми свои монеты.";
    link.l1.go = "dialog5";
    break;
	
	case "dialog5":
	NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;
	
	
	case "Second Time":
    dialog.text = "Что?..и-ик..ещё кто-нибудь интересует?";
    link.l1 = "Чуть позже.";
    link.l1.go = "dialog5";
    break;
	
	
	case "":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "";
    break;
	
	
	
	}
}