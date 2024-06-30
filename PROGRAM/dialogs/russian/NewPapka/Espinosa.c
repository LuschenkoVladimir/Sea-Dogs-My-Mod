
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
    dialog.text = "Вы, кажется, куда-то спешите, сударь.";
    link.l1 = "Да, мне интересно, чтобы вы сказали, Диего, перед своей смертью.";
    link.l1.go = "dialog1";
    break;
	
	
	case "dialog1":
    dialog.text = "Я бы сказал, что не собираюсь умирать. (Достаёт клинок)";
    link.l1 = "На всё воля Провидения.";
    link.l1.go = "exit";
    break;
	
	
	case "exit":
	AddDialogExitQuest("MyQ4");
	NextDiag.CurrentNode = "First Time";
	dialogexit();
    break;
	
	
	case "":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "";
    break;
	
	
	
	case "":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "";
    break;
	
	
	case "":
    dialog.text = "";
    link.l1 = "";
    link.l1.go = "";
    break;
	
	
	
	}
}	