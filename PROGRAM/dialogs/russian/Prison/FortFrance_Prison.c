// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
 	switch(Dialog.CurrentNode)
	{
        case "quests":
            dialog.text = "Говорите, я слушаю.";
			link.l1 = "Я "+ GetSexPhrase("ошибся","ошиблась") +". Прощайте.";
			link.l1.go = "Exit";
			//--> Бремя гасконца
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "jailskiper")
			{
				link.l1 = "Офицер, Мне сказали, что в вашей тюрьме содержится человек по имени Франк Дюгари.";
                link.l1.go = "Sharlie";
			}
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "freeskiper")
			{
				link.l1 = "Вот, возьмите ваши долговые расписки. Я купил право на ваш долг у ростовщика и теперь хочу, чтобы мне передали Франка Дюгари.";
                link.l1.go = "Sharlie_5";
			}	
			if (CheckAttribute(pchar, "questTemp.Sharlie") && pchar.questTemp.Sharlie == "freeDugari")
			{
				link.l1 = "У меня ваши долговые расписки. Наш уговор относительно Дюгари в силе?";
                link.l1.go = "Sharlie_8";
			}
			//<-- Бремя гасконца
		break;
		
		//--> Бремя гасконца
		case "Sharlie":
			dialog.text = "Да, отпетый мерзавец. По нему давно верёвка плачет. Едва ли можно пересчитать бедолаг, которых он проткнул своей шпагой. Возможно, ему позволили бы и дальше развлекаться, но несколько дней назад он отправил на тот свет двух офицеров гарнизона. Пока пускай и не самый лучший дворянин выпускал кишки всякому пьяному сброду, власти смотрели на это сквозь пальцы. Но теперь дело касается подрыва обороноспособности города, поэтому виселицы ему не избежать.";
			link.l1 = "С ним можно побеседовать?";
			link.l1.go = "Sharlie_1";
		break;
		
		case "Sharlie_1":
			dialog.text = "Конечно нет, месье. Да и зачем вам это?";
			link.l1 = "(Наклоняясь и говоря шёпотом) Я хотел бы забрать этого человека...на поруки, так сказать....";
			link.l1.go = "Sharlie_2";
		break;
		
		case "Sharlie_2":
			dialog.text = "(Отвечая шёпотом) Вы с ума сошли. Это невозможно. Повторяю, этот человек опасен.";
			link.l1 = "Но мне как раз такой и нужен. Я готов щедро заплатить.";
			link.l1.go = "Sharlie_3";
		break;

		case "Sharlie_3":
			dialog.text = "(раздумывая и решаясь) Считайте, что вам повезло. Но предупреждаю, это вам обойдётся действительно недёшево. Напрямую мне ваши деньги не нужны, это будет слишком подозрительно, но у меня есть долг перед местным ростовщиком в размере ста тысяч....";
			link.l1 = "Ого, как это вас угораздило?";
			link.l1.go = "Sharlie_4";
		break;

		case "Sharlie_4":
			dialog.text = "Пришлось отдавать карточный долг... И теперь из-за него я сам одной ногой в тюрьме. Если бы не это обстоятельство, я бы никогда не пошёл на должностное преступление. Но даже если меня разжалуют, это всяко лучше, чем оказаться по ту сторону решётки. Уж я то это точно знаю. В любом случае это единственное моё условие. Принесите мне мои долговые расписки, и я сразу выпущу Дюгари. Потом постараюсь представить это как ошибку.";
			link.l1 = "Хорошо, я посмотрю, что можно сделать.";
			link.l1.go = "exit";
			pchar.questTemp.Sharlie = "bankskiper";
			AddQuestRecord("Sharlie", "5-29");
		break;

		
		case "Sharlie_5":
			Log_Info("Вы передали долговые расписки");
			PlaySound("interface\important_item.wav");
			RemoveItems(pchar, "letter_open", 1);
			dialog.text = "Я немало удивлён, что вам удалось их получить у этого барыги. Наш уговор в силе, но хочу вас предупредить, если только он возьмётся в Сен-Пьере за старое, то сразу же вернётся в наше заведение, теперь с ним никто церемониться не станет.  И мой вам совет на прощание - не питайте иллюзий насчёт этого человека и будьте осторожны.";
			link.l1 = "Спасибо за предупреждение, а мой вам совет - больше не играйте в азартные игры.";
			link.l1.go = "Sharlie_6";
		break;
		
		
		case "Sharlie_6":
			dialog.text = "Да, конечно. Сержант! Привести сюда заключённого Франка Дюгари.";
			link.l1 = "...";
			link.l1.go = "Sharlie_7";
		break;
		
		case "Sharlie_7":
			DialogExit();
			chrDisableReloadToLocation = true;//закрыть локацию
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);//запретить драться
			// замораживаем ГГ
			LAi_SetActorType(pchar);
			LAi_ActorTurnToLocator(pchar, "goto", "goto17"); // 170712
			//создаем штурмана
			ref sld = GetCharacter(NPC_GenerateCharacter("FrankDugari", "Azzy", "man", "man", 1, FRANCE, -1, false, "quest"));
			sld.name = "Франк";
			sld.lastname = "Дюгари";
			sld.greeting = "officer_hire";
			sld.Dialog.Filename = "Quest\Sharlie\OtherNPC.c";
			sld.dialog.currentnode = "Folke";
			LAi_SetImmortal(sld, true);
			sld.CompanionDisable = true;
			sld.rank = 5;
			LAi_SetHP(sld, 90, 90);
			sld.money = 0;
			SetSelfSkill(sld, 25, 28, 21, 24, 22);
			SetShipSkill(sld, 10, 5, 24, 22, 25, 15, 5, 15, 18);
			SetSPECIAL(sld, 8, 9, 6, 5, 10, 7, 5);
			SetCharacterPerk(sld, "ShipSpeedUp");
			SetCharacterPerk(sld, "HullDamageUp");
			SetCharacterPerk(sld, "BasicDefense");
			GiveItem2Character(sld, "unarmed");
			EquipCharacterbyItem(sld, "unarmed");
			ChangeCharacterAddressGroup(sld, "Fortfrance_prison", "goto", "goto23");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload1", "FolkeStay", -1);
			pchar.questTemp.Sharlie = "takeskiper";
		break;

		case "Sharlie_8":
			dialog.text = "Где вы были хотя бы пару дней назад?! Я больше не мог отсрочить его казнь, приказ самого губернатора...Дьявол!!! Когда его на неё повели....он сбежал! Мерзавец! У него явно несколько жизней! Прежде чем он сумел прыгнуть в подземные  катакомбы, по нему успели сделать несколько выстрелов в упор! Теперь я понимаю, как он выжил в дуэлях сразу с толпой выпивох!";
			link.l1 = "Да, вероятно, он очень удачлив, чего не скажешь о вас. Что же мне теперь делать с вашим долгом?";
			link.l1.go = "Sharlie_9";
		break;

		case "Sharlie_9":
			dialog.text = "Месье, прошу вас...Я не могу отдать вам всей суммы, но... от Дюгари у меня осталась его великолепная сабля. Посмотрите! Никогда бы с такой не расстался, но теперь у меня нет выхода.";
			link.l1 = "Да, сабля отменная, вот только это не тот человек, чьи вещи я хотел бы забирать себе. Разве что сохранить в целости для хозяина.";
			link.l1.go = "Sharlie_10";
		break;

		case "Sharlie_10":
			dialog.text = "Тогда договорились. Вот половина долга пятьдесят тысяч и эта сабля в обмен на мои расписки.";
			link.l1 = "Идёт, и постарайтесь больше не играть в азартные игры.";
			link.l1.go = "Sharlie_11";
		break;

		case "Sharlie_11":
			DialogExit();
			AddQuestRecord("Sharlie", "5-44");
			Log_Info("Вы передали долговые расписки");
			PlaySound("interface\important_item.wav");
			RemoveItems(pchar, "letter_open", 1);
			AddMoneyToCharacter(pchar, 50000);
			GiveItem2Character(pchar, "blade_20");
			pchar.questTemp.Sharlie = "fadey";//к Фадею на Гваделупу

		    Island_SetReloadEnableGlobal("Martinique", true);
	        bQuestDisableMapEnter = false;
	        bDisableFastReload = false;
	        DeleteAttribute(pchar, "GenQuest.CannotWait");
	        i = FindColony("Fortfrance");
	        DeleteAttribute(colonies[i], "DontSetShipInPort");//ставить корабли
	        bNoEatNoRats  = false; // включаем еду и крыс
		    break;



		//<-- Бремя гасконца
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}
