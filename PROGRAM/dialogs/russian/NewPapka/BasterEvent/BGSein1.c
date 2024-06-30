
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
    dialog.text = "Что вам надо, месье?";
    link.l1 = "Ничего.";
    link.l1.go = "exit";
    break;  	


    case "exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;


    case "Second Time":
    dialog.text = "Преркратите надоедать нам.";
    link.l1 = "Моё право - делать то, что пожелаю.";
    link.l1.go = "exit";
    break;



    




	
		
		}
}