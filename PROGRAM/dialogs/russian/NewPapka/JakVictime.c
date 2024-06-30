
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
		
		
		
	case "doclad":
    dialog.text = "Всё готово, монсеньор.";
    link.l1 = "Тогда не будем медлить. Как только получите сигнал, действуйте.";
    link.l1.go = "docladexit";
    break;  		
		
		
	case "docladexit":
    dialogexit();
    AddDialogExitQuest("DeMor_6");
    break;  		
		
		
		
	


	case "dialog1":
    dialog.text = "Месье Де Мор? С вами очень хочет поговорить близкий друг вашего брата аббат Бенуа. Ваше появление в местной церкви не безопасно. Следуйте за мной.";
    link.l1 = "Подождите.... Стойте....";
    link.l1.go = "dialogexit";
    break;  



    
    case "dialogexit":
	dialogexit();
    AddDialogExitQuest("DeMor_10");
    break;



    
	case "dialog2":
    dialog.text = "Проходите, месье де Мор. Присаживайтесь.";
    link.l1 = "Я бы хотел знать ....";
    link.l1.go = "dialogexit2";
    break;  



    
    case "dialogexit2":
	dialogexit();
    AddDialogExitQuest("DeMor_13");
    break;



    



	
		
		}
}