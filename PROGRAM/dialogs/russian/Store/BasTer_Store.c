// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Спрашивай, чего ты хочешь?",
                          "Мы только что поднимали эту тему. Вы, вероятно, запамятовали...", "Сегодня вы уже третий раз говорите о каком-то вопросе...",
                          "Послушай, это магазин, здесь люди покупают что-то. Не отвлекай меня!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("Знаешь, " + NPChar.name + ", как-нибудь в следующий раз.", "Точно, "+ GetSexPhrase("забыл","забыла") +" что-то...",
                      "Да уж, действительно в третий раз...", "Гм, не буду...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";

			// Случай в Бастере четвёртый диалог
		    if (pchar.quest.main_line == "BasterEvent3")
			{
				link.l1 = "Слушай, тут говорят про странный корабль в порту и то, что они даже закупаются у тебя всем необходимым?";
				link.l1.go = "basterevent3_dialog_1";
			}
		break;

		// Случай в Бастере четвёртый диалог

		case "basterevent3_dialog_1":
			dialog.text = "Может быть и так, но информация стоит 5 000 песо - мои риски, ваши деньги, сами понимаете.";
			if (sti(pchar.money) >= 5000)
			{
				link.l1 = "Хорошо, вот твои деньги.";
				link.l1.go = "basterevent3_dialog_2";
			}
			link.l2 = "Гм... Сейчас у меня нет нужной суммы.";
			link.l2.go = "basterevent3_nomoney";
		break;
		
		case "basterevent3_nomoney":
			dialog.text = "Тогда заходите, когда деньги будут.";
			link.l1 = "Хорошо. Я скоро вернусь!";
			link.l1.go = "exit";
		break;



		case "basterevent3_dialog_2":
		AddMoneyToCharacter(pchar, -5000);
			dialog.text = "Ну что ж, догадываюсь, о каком корабле идёт речь. Это люггер 'Фартовый'. И советую вам поторопиться, я полагаю, они скоро собираются отчалить от нашего берега.";
			link.l1 = "Надеюсь, эта информация точна.";
			link.l1.go = "basterevent3_dialog_3";
		break;



		case "basterevent3_dialog_3":
			dialog.text = "Точнее не бывает, молодой человек. У вас всё? Или желаете ещё что-то купить?";
			link.l1 = "Нет, спасибо.";
			link.l1.go = "basterevent3_dialog_exit";
		break;

		
		case "basterevent3_dialog_exit":
			pchar.quest.main_line = "";
			AddDialogExitQuest("BasterEvent_27");
			AddQuestRecord("BasterEvent", "8");
			DialogExit();
		break;




	}
	UnloadSegment(NPChar.FileDialog2);
}

