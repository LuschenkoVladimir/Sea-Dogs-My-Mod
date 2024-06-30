
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
    dialog.text = "Я спешу, сударь. Служба.";
    link.l1 = "Тогда простите за беспокойство.";
    link.l1.go = "exit";
    break;  	
		


    case "exit":
    NextDiag.CurrentNode = "Second Time";
	dialogexit();
    break;



    case "Second Time":
    dialog.text = "Не отвлекайте меня от несения службы.";
    link.l1 = "Ещё раз простите.";
    link.l1.go = "exit";
    break;




    case "Check_1":
    AddDialogExitQuest("DeMor_17");
    dialog.text = "Ну что?";
    link.l1 = "Всё по плану. Иду к аббату. Будьте наготове.";
    link.l1.go = "Checkexit";
    break;  	
		


    case "Checkexit":
    NextDiag.CurrentNode = "Check_2";
	dialogexit();
    break;



    case "Check_2":
    dialog.text = "Поторапливайся. Все уже готовы.";
    link.l1 = "Уже иду.";
    link.l1.go = "Checkexit";
    break;



    case "Check_3":
    dialog.text = "Сдайте оружие, месье, и следуйте за мной.";
    link.l1 = "На каких основаниях?";
    link.l1.go = "Checkexit2";
    break;


    case "Checkexit2":
    AddDialogExitQuest("DeMor_32");
	dialogexit();
    break;



    case "Check_4":
    sld = characterFromID("OlivieBlank");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
    dialog.text = "Сопротивление городской страже? Тогда пеняйте на себя!";
    link.l1 = ".....";
    link.l1.go = "Checkexit3";
    break;


    case "Checkexit3":
    AddDialogExitQuest("DeMor_34");
	dialogexit();
    break;


    case "BanditHut_1":
    sld = characterFromID("OlivieBlank");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("Sharlie_Second1"));
    sld = characterFromID("Sharlie_Second1");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("OlivieBlank"));
    dialog.text = "Сдохни, тварь!";
    link.l1 = ".....";
    link.l1.go = "BanditHut_exit1";
    break;


    case "BanditHut_exit1":
    dialogexit();
    AddDialogExitQuest("GuberWife_19");
    break;


    case "BanditHut_2":
    sld = characterFromID("OlivieBlank");
    Lai_SetActorType(sld);
    LAi_ActorTurnToCharacter(sld, characterFromID("Blaze"));
    dialog.text = "";
    link.l1 = "У тебя хорошо получается убивать безоружных, мерзавец. Теперь попробуй убить меня. На этот раз ты никуда не сбежишь! ";
    link.l1.go = "BanditHut_exit2";
    break;


    case "BanditHut_exit2":
    dialogexit();
    AddDialogExitQuest("GuberWife_21");
    break;
		
		
		
		
	




	
		
		}
}