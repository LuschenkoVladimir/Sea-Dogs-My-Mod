
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
    dialog.text = "Ну, что?";
    link.l1 = "Всё по плану. Иду к аббату. Будьте наготове.";
    link.l1.go = "First TimeExit";
    break;  

    case "First TimeExit":	
    NextDialod.CurrentNode = "Second Time";
	dialogexit();
    break;


    case "Second Time":
    dialog.text = "Давай, поторапливайся.";
    link.l1 = "Уже иду.";
    link.l1.go = "First TimeExit";
    break;
		
		
		
		
	





	
		
		}
}