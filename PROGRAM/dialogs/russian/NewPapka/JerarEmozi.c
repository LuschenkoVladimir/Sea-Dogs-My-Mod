
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
    dialog.text = "Не нравится мне эта задержка, Рене. Что будем делать, если у парней ничего не выгорит?";
    link.l1 = "Ты видел, сколько золотишка было у месье? Жак сказал, что когда он вернётся мы получим свою долю. Ради таких денег я готов рискнуть. Да и какой у нас выбор? Если к вечеру он не явится, то возьмём этого месье и двинем к бухте. Судя по всему, он - важная птица, так что нас с ним не оставят.";
    link.l1.go = "dialog1";
    break;  	
		
		
		
	case "dialog1":
    dialog.text = "Да, я и сам жду не дождусь Жака с нашим золотишком, хе-хе. Постой, что это за шум?";
    link.l1 = "Кажется это внизу. Ты не открывал дверь, идиот?! Пошли посмотрим, кто там. Может, это Жак? Говорил же тебе сидеть внизу и смотреть в оба!";
    link.l1.go = "exit";
    break;  		
		
		
	

    case "exit":
    AddDialogExitQuest("DeMor_25");
	dialogexit();
    break;



    





	
		
		}
}