
void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
	bool bOk;
	int i;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Вы что-то хотели?";
			link.l1 = "Да нет, ничего.";
			link.l1.go = "exit";			
			NextDiag.TempNode = "First time";
		break;
		
		//Найти помощника в магазин
		case "Storehelper":
			dialog.text = "Что вы хотели, месье?";
			link.l1 = "Хм. Ведь это вы - Гийом Лавуа, правильно?";
			link.l1.go = "Storehelper_1";
		break;
		
		case "Storehelper_1":
			dialog.text = "Да, я, а вам-то чего надо? Не мешайте мне пить ром, сударь, я не в настроении общаться.";
			link.l1 = "Я не отниму у вас много времени. Меня послал купец Сен-Пьера. Вы ведь работали у него на складе, так? Он разыскивает вас и...";
			link.l1.go = "Storehelper_2";
		break;
		
		case "Storehelper_2":
			dialog.text = "Ха! Он разыскивает меня! Чёртов скряга! Он думал, что я всю жизнь буду работать за его жалкие гроши? Да нет на всех Карибах жаднее купца! Я трудился на него пять лет без роздыху, а он ни разу не выдал даже маленькой премии, даже кружки рома не поставил!\nВот пусть теперь сам свои товары считает, а с меня довольно. Никто в Сен-Пьере не пойдёт работать к этому сквалыге, я-то знаю. У него только одна забота - потуже набить свой бездонный кошель и поменьше заплатить работникам.";
			link.l1 = "То есть, вы уже к нему на службу не вернётесь, как я понимаю?";
			link.l1.go = "Storehelper_3";
		break;
		
		case "Storehelper_3":
			dialog.text = "Нет, разрази меня гром! Я подожду здесь, в Ле Франсуа, какого-нибудь судна и наймусь квартирмейстером, а если не получится - пойду и простым матросом. Глаза б мои не видели этого скупердяя...";
			link.l1 = "Всё понятно. Большего мне знать и не нужно. Удачи, Гийом!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_4":
			dialog.text = "Сударь, отойдите в сторону, вы загораживаете дорогу!";
			link.l1 = "Один вопрос, месье. Ведь это вы - Гийом Лавуа?";
			link.l1.go = "Storehelper_5";
		break;
		
		case "Storehelper_5":
			dialog.text = "Ха! Ну, я. А в чём дело-то?";
			link.l1 = "Вас разыскивает купец из Сен-Пьера. Вы ведь работали у него, так?";
			link.l1.go = "Storehelper_6";
		break;
		
		case "Storehelper_6":
			dialog.text = "Ха-ха! И зачем же я ему понадобился? Он решил доплатить мне невыплаченное жалование за последние две недели? Или у него не получается одновременно бочонки считать и клиентов обманывать, а? Ха-ха-ха!";
			link.l1 = "Он поручил мне разыскать вас и выяснить, почему вы не появляетесь у него в магаз...";
			link.l1.go = "Storehelper_7";
		break;
		
		case "Storehelper_7":
			dialog.text = "Почему я у него не появляюсь? Да потому что он чёртов сквалыга! Жадина, каких свет не видел! Пускай сам на своём складе возится, а я теперь вхожу в Береговое братство, и мне это, чёрт побери, очень нравится!\nСкоро я выйду в море и буду пересчитывать песо и дублоны, добытые у испанцев, а не ящики с бананами! А что до этого скряги - пусть попробует найти мне замену. Ни один дурак в Сен-Пьере не пойдёт к нему на службу, слишком дурная у него репутация, ха-ха!";
			link.l1 = "Всё понятно. Большего мне знать и не нужно. Удачи, Гийом!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_8":
			dialog.text = "Если вы по поводу покупок - то это не ко мне.";
			link.l1 = "Добрый день. Как я понимаю, вы - Гийом Лавуа?";
			link.l1.go = "Storehelper_9";
		break;
		
		case "Storehelper_9":
			dialog.text = "Да, это я. Чем обязан, месье?";
			link.l1 = "Вас разыскивает купец из Сен-Пьера. Вы работали у него на складе...";
			link.l1.go = "Storehelper_10";
		break;
		
		case "Storehelper_10":
			dialog.text = "Ну и пусть себе разыскивает. Я ему ничего не должен. Это он мне остался должен за две недели службы, но я даже и не буду пытаться забрать у него эти деньги. Пусть подавится.";
			link.l1 = "Хм. Так вы окончательно ушли от него, как я понимаю?";
			link.l1.go = "Storehelper_11";
		break;
		
		case "Storehelper_11":
			dialog.text = "Вы всё правильно понимаете, сударь. Такого скряги, как мой бывший работодатель, свет не видывал. Я вот сейчас работаю здесь, и мои таланты оценены по достоинству - я получаю вдвое больше прежнего, и премиальные, если приходится задержаться подольше\nА этот сквалыга пусть попробует теперь отыскать мне замену. Не думаю, что у него это получится - его жадность слишком хорошо известна жителям Сен-Пьера, и ни один дурак не пойдёт к нему на службу.";
			link.l1 = "Всё понятно. Большего мне знать и не нужно. Удачи, Гийом!";
			link.l1.go = "Storehelper_12";
		break;
		
		case "Storehelper_12":
			DialogExit();
			npchar.lifeday = 0;
			AddQuestRecord("SharlieA", "2");
			pchar.questTemp.Sharlie.Storehelper = "return";
			LAi_CharacterDisableDialog(npchar);
			pchar.quest.StorehelperOver.over = "yes"; //снять таймер
		break;
		
		case "Newstorehelper_1":
			dialog.text = "Здравствуйте, месье. Не хочу показаться нескромным - но уверен, что моя кандидатура вам вполне подойдёт.";
			link.l1 = "Добрый день. И почему вы так считаете?";
			link.l1.go = "Newstorehelper_1_1";
		break;
		
		case "Newstorehelper_2":
			dialog.text = "Приветствую, сударь! Позвольте мне немного рассказать о себе.";
			link.l1 = "Я слушаю вас внимательно.";
			link.l1.go = "Newstorehelper_2_1";
		break;
		
		case "Newstorehelper_3":
			dialog.text = "Доброго здоровья, уважаемый господин. Ведь это вы принимаете на работу к купцу?";
			link.l1 = "Да, я. Что вы можете рассказать о себе?";
			link.l1.go = "Newstorehelper_3_1";
		break;
		
		case "Newstorehelper_1_1":
			dialog.text = "Потому что я служил у самого Франциска Дюбуа квартирмейстером. И Франциск был весьма доволен мной. А с морем мне пришлось расстаться из-за ранения - я долго лечился, выздоровел, но одно упоминание о качке повергает меня в уныние. Нет, я хочу обосноваться на твёрдой земле\n(шепчет) А ещё потому, что если вы порекомендуете меня, то я заплачу вам кроме пятисот песо ещё двадцать пять золотых дублонов. Ну как?";
			link.l1 = "Хорошо. Я подумаю над вашими словами.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_1_2";
		break;
		
		case "Newstorehelper_2_1":
			dialog.text = "Я был мелким торговцем, потом разорился и пошёл в море, служил казначеем на торговом судне. Волею судьбы оказался в этом посёлке. Жизнь моряка мне не по душе, и я бы с радостью принял ваше предложение\n(понижая голос) И я готов прибавить к пятистам песо вот этот увесистый мешочек с янтарём.";
			link.l1 = "Понятно. Я подумаю над тем, что вы сказали.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_2_2";
		break;
		
		case "Newstorehelper_3_1":
			dialog.text = "Я работал служащим на товарном складе в порту Глазго. Желание разбогатеть привело меня на Карибы, и мне удалось собрать немного денег, чтобы встретить старость не в нищете. Но я устал от морских походов, и хотел бы спокойной жизни на берегу вблизи моря\n(тихонько) За это место я впридачу к пятистам песо добавлю вам ещё пять раз по пятьсот.";
			link.l1 = "Ясно. Я приму это к сведению.";
			link.l1.go = "exit";
			NextDiag.TempNode = "Newstorehelper_3_2";
		break;
		
		case "Newstorehelper_1_2":
			dialog.text = "Месье, вы сделаете правильный выбор. И не забывайте про дублоны...";
			link.l1 = "Я принял решение в вашу пользу. Собирайтесь, мы отправляемся в Сен-Пьер.";
			link.l1.go = "Newstorehelper_1_3";
			link.l2 = "Я ещё не решил...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_1_2";
		break;
		
		case "Newstorehelper_2_2":
			dialog.text = "Я надеюсь, что ваш выбор падёт на мою кандидатуру. Да и янтарь - весьма ценная и полезная штука...";
			link.l1 = "Я принял решение в вашу пользу. Собирайтесь, мы отправляемся в Сен-Пьер.";
			link.l1.go = "Newstorehelper_2_3";
			link.l2 = "Я ещё не решил...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_2_2";
		break;
		
		case "Newstorehelper_3_2":
			dialog.text = "Купец не разочаруется в моей работе. Как и вы в пяти раз по пятьсот...";
			link.l1 = "Я принял решение в вашу пользу. Собирайтесь, мы отправляемся в Сен-Пьер.";
			link.l1.go = "Newstorehelper_3_3";
			link.l2 = "Я ещё не решил...";
			link.l2.go = "exit";
			NextDiag.TempNode = "Newstorehelper_3_2";
		break;
		
		case "Newstorehelper_1_3":
			dialog.text = "Только вещи соберу! Я буду ждать вас у входа в таверну.";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 0;
		break;
		
		case "Newstorehelper_2_3":
			dialog.text = "Одна нога здесь, другая там, месье! Я буду у входа в таверну.";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 1;
		break;
		
		case "Newstorehelper_3_3":
			dialog.text = "Заберу свой старый саквояж и буду у дверей таверны, сударь!";
			link.l1 = "...";
			link.l1.go = "Newstorehelper_exit";
			pchar.questTemp.Sharlie.Storehelper.Quality = 2;
		break;
		
		case "Newstorehelper_exit":
			DialogExit();
			chrDisableReloadToLocation = false;//открыть локацию
			pchar.questTemp.Sharlie.Storehelper.id = npchar.id;
			DeleteAttribute(npchar, "LifeDay")
			chrDisableReloadToLocation = true;
			for (i=1; i<=3; i++)
			{
				sld = characterFromId("Newstorehelper_"+i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "OpenTheDoors", 10.0);
			}
			pchar.quest.storehelper2.win_condition.l1 = "location";
			pchar.quest.storehelper2.win_condition.l1.location = "LeFransua_town";
			pchar.quest.storehelper2.function = "NewstorehelperAdd";
			AddQuestRecord("SharlieA", "4");
			pchar.questTemp.Sharlie.Storehelper = "choise";
			pchar.quest.storehelper.over = "yes"; //снять прерывание
		break;
		
		case "Newstorehelper_regard":
			dialog.text = "Ну, как я понимаю, это и есть моё новое место работы? Спасибо, месье, что выбрали именно меня. Вот ваши пятьсот песо и дополнительная награда, как я и обещал.";
			link.l1 = "Благодарствую... Сейчас я представлю вас вашему работодателю, а потом уже - всё в ваших руках.";
			link.l1.go = "Newstorehelper_regard_1";
		break;
		
		case "Newstorehelper_regard_1":
			DialogExit();
			npchar.lifeday = 0;
			switch (sti(pchar.questTemp.Sharlie.Storehelper.Quality))
			{
				case 0:
					AddMoneyToCharacter(pchar, 500);
					TakeNItems(pchar, "gold_dublon", 25);
				break;
				
				case 1:
					AddMoneyToCharacter(pchar, 500);
					TakeNItems(pchar, "jewelry8", 10);
					TakeNItems(pchar, "jewelry7", 1);
				break;
				
				case 2:
					AddMoneyToCharacter(pchar, 3000);
				break;
			}
		break;
		
		//контрабанда рома


		case "Rum_Capitan":
			dialog.text = "Ну? Ты кто такой, приятель?";
			link.l1 = "Выпей рому, моряк.";
			link.l1.go = "Rum_Cap_2";
		break;
		
		case "Rum_Capitanexit":
			DialogExit();
		break;



		case "Rum_Cap_Over":
			dialog.text = "Месье, я прошу вас немедленно покинуть мой корабль. Я поднимаю якоря и отплываю с минуты на минуту!";
			link.l1 = "Хорошо...";
			link.l1.go = "exit";
			NextDiag.TempNode = "Rum_Cap_Over";
			chrDisableReloadToLocation = false;
			npchar.DontDeskTalk = true;
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
		break;
		
		case "Rum_Cap":
			pchar.quest.Sharlie_rum2.over = "yes"; //снять таймер
			chrDisableReloadToLocation = false; // patch-4
			dialog.text = "Ну? Ты кто такой, приятель?";
			link.l1.edit = 1;			
			link.l1 = "";
			link.l1.go = "Rum_Cap_1";
		break;
		
		case "Rum_Cap_1":
			if(GetStrSmallRegister(pchar.questTemp.Sharlie.Rum.Pass) == GetStrSmallRegister(dialogEditStrings[1]))
			{
				dialog.text = "Выпей рому, моряк! Ха-ха! Приветствую на борту моего люггера. Ну, ты пришёл за товаром, как я понимаю?";
				link.l1 = "Да. А за чем же ещё?";
				link.l1.go = "Rum_Cap_2";
			}
			else
			{
				dialog.text = "Вот гнусное отродье! Ребята, похоже, это шпик! За борт его!";
				link.l1 = "А-ать!";
				link.l1.go = "Rum_Cap_getout";
			}
		break;
		
		case "Rum_Cap_getout":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
			setCharacterShipLocation(pchar, "Shore38"));
			setWDMPointXZ("Shore38");
			DoQuestReloadToLocation("Shore38", "goto", "goto1", "Rum_RemoveBarkas");
		break;
		
		case "Rum_Cap_2":
			dialog.text = "Ребята! Грузи ящики на баркас!";
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Rum_CarrierEnter");
		break;
		
		case "Rum_Cap_3":
			dialog.text = "Все ящики с припасами на твоём баркасе. Порт Ле Франсуа находится в южном направлении отсюда. Поторопись. Мне тоже пора поднимать якоря!";
			link.l1 = "Не будем терять времени, джентльмены! Удачи!";
			link.l1.go = "Rum_Cap_4";
		break;
		
		case "Rum_Cap_4":
			dialog.text = "И тебе того же, приятель...";
			link.l1 = "...";
			link.l1.go = "Rum_Cap_5";
		break;
		
		case "Rum_Cap_5":
			DialogExit();
			//AddQuestRecord("Sharlie", "5-17");
			log_info("Теперь на пляж Ламантен");
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation("Deck_Near_Ship")], false);
			npchar.DontDeskTalk = true;
			NextDiag.CurrentNode = "Rum_Cap_Over";
			pchar.quest.Sharlie_rum4.win_condition.l1 = "Ship_location";
			pchar.quest.Sharlie_rum4.win_condition.l1.location = "shore38";
			pchar.quest.Sharlie_rum4.function = "Rum_RemoveRum";
			//AddQuestRecord("SharlieB", "4");
			i = FindIsland("Martinique");
			Islands[i].EffectRadius = 3000;
		break;
		
		case "Rum_Carrier":
			dialog.text = "Мы уже заждались вас, месье, хе-хе. Как всё прошло? Ящики у вас? Хе-хе.";
			link.l1 = "Кто вы такие? Я не совершил ничего противозаконного!";
			link.l1.go = "Rum_Carrier_1";
		break;
		
		case "Rum_Carrier_1":
			dialog.text = "А как же контрабанда с люггера, который поблизости от этой бухты? ";
			link.l1 = "У вас нет доказательств!";
			link.l1.go = "Rum_Carrier_2";
		break;

		case "Rum_Carrier_2":
			dialog.text = "Ну почему же? Команда будет свидетельствовать против вас. А вот и доказательства.";
			link.l1 = "";
			link.l1.go = "Rum_Carrier_exit";
		break;


		case "Rum_Carrier_exit":
			DialogExit();
			AddDialogExitQuest("GuberWife_1");
		break;


		case "ContraSailor_1":
			dialog.text = "Простите, месье, но мы не хотим пострадать, если вам не повезло, и вы попались патрулю.";
			link.l1 = "Что ты несёшь?";
			link.l1.go = "ContraSailor_exit";
		break;

		case "ContraSailor_exit":
			DialogExit();
			PlaySound("People Fight\Death_NPC_08.wav");
            //RemoveAllCharacterItems(PChar, true);
			SetLaunchFrameFormParam("Вас оглушили ударом сзади", "", 0, 5);
			LaunchFrameForm();
			WaitDate("", 0, 0, 0, 0, 0); //крутим время
			RecalculateJumpTable();
			DoQuestCheckDelay("GuberWife_2", 2.0);
		break;
		
		case "Rum_Carrier_20":
			DialogExit();
			for (i=1; i<=3; i++)
			{
				
				sld = characterFromId("Rum_Carrier2_"+i);
				LAi_SetActorType(sld);
				LAi_ActorRunToLocation(sld, "goto", "goto8", "none", "", "", "OpenTheDoors", 10.0);
			}
			pchar.questTemp.Sharlie.Rum = "regard";
			i = FindLocation("Fortfrance_town");
			setCharacterShipLocation(pchar, GetCityFrom_Sea(locations[i].fastreload));
		    setWDMPointXZ(GetCityFrom_Sea(locations[i].fastreload));
		break;
		
		//доставить девочку из борделя
		case "GigoloMan":
			dialog.text = "Добрый день, месье! Клянусь, вы не похожи на этих неотёсанных мужланов, что ошиваются в нашей колонии. И, как я вижу, вы нездешний... Прибыли из Европы, я угадал?";
			link.l1 = "Именно так, сударь. "+GetFullName(pchar)+", к вашим услугам.";
			link.l1.go = "GigoloMan_1";
		break;
		
		case "GigoloMan_1":
			dialog.text = "Позвольте представиться - Арно Венгеан. Прибыл из Франции в эту глушь несколько лет назад. Но давайте перейдём к делу. Месье Валинье, вероятно, в общих чертах описал ту трагедию, которая поразила нашу семью месяц назад...Мой несчастный брат, увы, слишком склонный к пороку и соблазну, стал жертвой банды разбойников. И помогала им в этом одна из девиц местного борделя. Я навёл справки. Это блондинка по имени Люсиль Монтань. Как дворянин, месье де Мор, вы понимаете, что отомстить за смерть брата является для меня долгом чести. И первое, что я сделал, это обратился к нашему губернатору, но он, прикрываясь различными отговорками, так ничего и не предпринял.";
			link.l1 = "Вы видите в этом какой-либо умысел?";
			link.l1.go = "GigoloMan_2";
		break;
		
		case "GigoloMan_2":
			dialog.text = "Не знаю, месье де Мор. К сожалению, здесь всё несколько иначе. Местный сброд совсем распоясался и нас, дворян, ни во что не ставят. Здесь всем заправляют деньги и выгода, поэтому губернатор дворянской чести предпочитает доходы от борделя, а общению с такими как я общество шлюх и сомнительных личностей. Появление шевалье де Валинье и вас, месье де Мор, вдохнуло в меня уже угасавшую надежду на отмщение.";
			link.l1 = "Я сам оказался на этих островах по семейным делам, месье Венгеан, поэтому с радостью помогу вам. Грегуар сказал, что вы ознакомите меня с деталями предполагаемого дела.";
			link.l1.go = "GigoloMan_3";
		break;
		
		case "GigoloMan_3":
			dialog.text = "Да, конечно. Вы, месье де Мор, в Сен-Пьере человек новый, поэтому не вызовете лишних подозрений и будете идеальной приманкой. Мой брат...он был убит вскоре после того, как прибыл в нашу колонию. Мы с месье Валинье уже позаботились распустить слух о вас как о богатом парижском дворянине, прибывшем в Сен-Пьер по торговым делам и снявшем один из лучших особняков в городе. Он расположен справа от резиденции губернатора.";
			link.l1 = "Вам удалось получить информацию о том, сколько было негодяев, убивших вашего брата?";
			link.l1.go = "GigoloMan_4";
			//link.l2 = "Сударь, я дорожу своей репутацией не меньше, чем вы. Так что прошу меня простить, но вашу просьбу я исполнить не могу. Позвольте откланяться.";
			//link.l2.go = "GigoloMan_exit";
		break;
		
		case "GigoloMan_exit":
			DialogExit();
			LAi_CharacterDisableDialog(npchar);
			npchar.lifeday = 0;
		break;
		
		case "GigoloMan_4":
			dialog.text = "К сожалению, нет. Но не думаю, что их было очень много. Вероятно, эта девка ночью открыла дверь мерзавцам, и они застали брата врасплох. Для этого много людей не требуется. Трое дворян должны легко справиться с этим сбродом. Но на всякий случай я возьму с собой ещё несколько слуг.";
			link.l1 = "Ну что ж, тогда пожелайте мне удачи, месье Венгеан, и будьте наготове сегодня вечером.";
			link.l1.go = "GigoloMan_5";
		break;
		
		case "GigoloMan_5":
			DialogExit();
			AddMoneyToCharacter(pchar, 6000);
			//AddQuestRecord("SharlieC", "1");
			AddQuestUserData("SharlieC", "sName", GetFullName(npchar));
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "none", "", "", "", -1);
			LocatorReloadEnterDisable("Fortfrance_town", "houseSp1", true);
			npchar.lifeday = 0;
			pchar.questTemp.Sharlie.Gigolo = "start";
			pchar.questTemp.Sharlie.Gigolo.Rand1 = rand(1);
			pchar.questTemp.Sharlie.Gigolo.Rand2 = rand(1);
			AddDialogExitQuest("BordelGirl_5");
		break;
		
		case "GigoloGirl":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = "Здравствуйте, месье. Я бы ни за что не спутала вас с другими мужчинами. В вас сразу виден тот шарм, что заставляет слабых женщин искать вашего общества. Поэтому я с нетерпением ждала нашей встречи.";
				link.l1 = "Вы ещё более прекрасны, Люсиль, чем тогда, когда я первый раз мельком заметил незабываемую блондинку на улицах Сен-Пьера. С тех пор я не переставал думать о вас...И вот наконец решился.";
				link.l1.go = "GigoloGirl_1";
				npchar.quest.meeting = "1";
			}
			else
			{
				dialog.text = "Месье, надеюсь, вы понимаете, что я не могу гулять с вами по ночам? Давайте займёмся делом - вы отведёте меня в дом своего друга. Иначе маман в конце-концов рассердится, и вы потеряете свои деньги.";
				link.l1 = "Хорошо, я понял. Следуй за мной!";
				link.l1.go = "GigoloGirl_2";
			}
		break;
		
		case "GigoloGirl_1":
			dialog.text = "Не скромничайте месье. Уверена, что в Париже вы оставили не одно разбитое женское сердце, хи-хи. Но перед тем, как разобьёте и моё, я постараюсь сделать ваше пребывание в нашем захолустье максимально приятным.";
			link.l1 = "Тогда не будем терять времени. (шёпотом на ухо) Сегодня я отпустил слуг, и весь особняк будет в вашем полном распоряжении. Сегодня вы - моя королева. Пойдёмте же, я поведу вас к вратам счастья и удовольствия.";
			link.l1.go = "GigoloGirl_2";
		break;
		
		case "GigoloGirl_2":
			DialogExit();
			AddQuestRecord("Sharlie", "5-6");
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			pchar.quest.Sharlie_Gigolo.win_condition.l1 = "locator";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.locator_group = "reload";
			pchar.quest.Sharlie_Gigolo.win_condition.l1.locator = "houseSp1";
			pchar.quest.Sharlie_Gigolo.function = "Sharlie_GiveGigoloGirl";
			pchar.quest.Sharlie_Gigolo1.win_condition.l1 = "Timer";
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.hour  = sti(GetTime() + 2);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			pchar.quest.Sharlie_Gigolo1.function = "Sharlie_GigoloGirlOver";
		break;
		
		case "GigoloGirl_3":
			dialog.text = "Пришли? Какой великолепный дом, монсеньор.";
			link.l1 = "Сегодня я для тебя просто Шарль.";
			link.l1.go = "GigoloGirl_4";
		break;
		
		case "GigoloGirl_4":
			dialog.text = "А я  для тебя сегодня просто твоя королева, милый. Так что открывай быстрее для своей королевы свои 'врата счастья и удовольствия', хи-хи.";
			link.l1 = "С удовольствием.";
			link.l1.go = "GigoloGirl_5";
		break;
		
		case "GigoloGirl_5":
			pchar.quest.Sharlie_Gigolo1.over = "yes";
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "none", "", "", "GigoloGirl_Remove", 5.0);
			DoQuestCheckDelay("BordelGirl_9", 2.0);
		break;


		case "GigoloGirl_6":
			dialog.text = "Здесь так романтично. Иди сюда, Шарль...(обнимает Шарля)";
			link.l1 = "Секунду, моя королева. Я поднимусь наверх за лучшим парижским вином.";
			link.l1.go = "GigoloGirl_7";
		break;


		case "GigoloGirl_7":
			DialogExit();
			AddDialogExitQuest("BordelGirl_12");
		break;


		case "GigoloMan_6":
			dialog.text = "У нас всё готово, месье де Мор, поэтому смело продолжайте играть свою роль. Думаю, негодяи не заставят себя долго ждать.";
			link.l1 = "Ну по крайней мере, надеюсь, успею выпить.";
			link.l1.go = "GigoloMan_7";
		break;


		case "GigoloMan_7":
			DialogExit();
			AddDialogExitQuest("BordelGirl_15");
		break;
		

        case "GigoloGirl_8":
			dialog.text = "Ты наконец вернулся, милый. Но нельзя заставлять даму ждать так долго.";
			link.l1 = "Что здесь происходит? Кто эти люди, Люсиль?";
			link.l1.go = "GigoloGirl_9";
		break;


		case "GigoloGirl_9":
			DialogExit();
			AddDialogExitQuest("BordelGirl_19");
		break;


		case "VtngeanPirate_1":
			dialog.text = "Происходит то, что если хочешь остаться в живых, показывай, где припрятал золотишко.";
			link.l1 = "Кто вы такие? Я - важная персона в Париже. Кто у вас главный? Я смогу предложить намного больше, если вы оставите меня в живых!";
			link.l1.go = "VtngeanPirate_2";
		break;


		case "VtngeanPirate_2":
			dialog.text = "Хе-хе. Нет проблем, месье.(замечает засаду спускающуюся по лестнице)";
			link.l1 = "";
			link.l1.go = "VtngeanPirate_3";
		break;


		case "VtngeanPirate_3":
			DialogExit();
			AddDialogExitQuest("BordelGirl_20");
		break;


		case "GigoloMan_8":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloMan"));
		sld = characterFromID("GigoloMan");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Вам не придётся меня долго искать, месье Валинье. Это потому что у меня к вам вопросов не меньше.";
			link.l1 = "Что это означает, месье Венгеан?!";
			link.l1.go = "GigoloMan_9";
		break;


		case "GigoloMan_9":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloMan"));
		sld = characterFromID("GigoloMan");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Это означает, что вы расставляли ловушку, но сами в неё угодили.";
			link.l1 = "Да, вы весьма коварны и изобретательны. Но меня интересует не это, а то, кто стоял за организацией нападения на базу мальтийцев. И каковы были его цели?";
			link.l1.go = "GigoloMan_10";
		break;


		case "GigoloMan_10":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloMan"));
		sld = characterFromID("GigoloMan");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Вы, кажется, ещё не поняли: это вы с месье де Мором у меня в руках. И здесь вопросы буду задавать я, а вы будете на них отвечать, если, конечно, хотите пережить эту ночь.";
			link.l1 = "Вы явно торопитесь, месье Венгеан или как вас там. (подаёт условный знак, и в комнату врываются несколько гвардеёцев кардинала)";
			link.l1.go = "GigoloMan_11";
		break;


		case "GigoloMan_11":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloMan"));
		sld = characterFromID("GigoloMan");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Дьявол! Вали их ребята! Пощады не будет ни им, ни нам!";
			link.l1 = "Вы так категоричны. Взять их!";
			link.l1.go = "GigoloMan_12";
		break;

		case "GigoloMan_12":
			DialogExit();
			AddDialogExitQuest("BordelGirl_23");
		break;


		case "GigoloGirl_10":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloGirl"));
		sld = characterFromID("GigoloGirl");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Прошу вас, монсеньор, пощадите! (встаёт на колени) Если бы я не делала, что они от меня требовали, то они убили бы меня!";
			link.l1 = "";
			link.l1.go = "GigoloGirl_11";
		break;


		case "GigoloGirl_11":
			DialogExit();
			AddDialogExitQuest("BordelGirl_26");
		break;


		case "GigoloGirl_12":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloGirl"));
		sld = characterFromID("GigoloGirl");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Я...я ..не знаю точно....";
			link.l1 = "Не стоит испытывать моё терпение, Люсиль. Ваша красивая головка гораздо лучше смотрится без пулевого отверстия. Сегодня я их найду и прикончу, так что выбирайте на чьей будете стороне: на моей или на стороне покойников.";
			link.l1.go = "GigoloGirl_13";
		break;


		case "GigoloGirl_13":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloGirl"));
		sld = characterFromID("GigoloGirl");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "(Плачет) На вашей, монсеньор. Не стреляйте...Прошу вас...Я, правда,  мало что знаю. Но месье Кабаль, мой постоянный клиент...он...он связан с ними. Он очень богатый и щедрый господин, занимается торговлей и поставками в колонию. У него большая охрана, его дом расположен недалеко от порта. Я.. я могу показать.";
			link.l1 = "(Убирает пистоль)  Хорошее начало вашей новой жизни, Люсиль.  И эта новая жизнь полностью в ваших руках. Встаньте же, я не привык к тому, чтобы столь очаровательные женщины стояли передо мной на коленях. ";
			link.l1.go = "GigoloGirl_14";
		break;


		case "GigoloGirl_14":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GigoloGirl"));
		sld = characterFromID("GigoloGirl");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "(поднимается) Благодарю вас, монсеньор, отныне я сделаю всё, что вы пожелаете.";
			link.l1 = "Это правильный подход, Люсиль. Ваша красота может быль полезна Королю и Франции, и у вас не будет более достойного и могущественного покровителя. Утром месье де Мор как галантный кавалер сопроводит вас обратно в заведение Авроры так, как будто сегодняшней ночью не произошло ничего кроме вашего бурного свидания. А пока мы навестим вашего знакомого месье Кабаля, показывайте дорогу.";
			link.l1.go = "GigoloGirl_15";
		break;


		case "GigoloGirl_15":
			DialogExit();
			AddDialogExitQuest("BordelGirl_28");
		break;


		case "LeitenantRes_1":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("LeitenSenPier"));
		sld = characterFromID("LeitenSenPier");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Сложите оружие и следуйте за мной.";
			link.l1 = "";
			link.l1.go = "LeitenantRes_2";
		break;


		case "LeitenantRes_2":
			DialogExit();
			AddDialogExitQuest("BordelGirl_29");
		break;


		case "LeitenantRes_3":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("LeitenSenPier"));
		sld = characterFromID("LeitenSenPier");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Ваши люди тайно проникли в город, разоружив охрану у городских ворот. Этот акт агрессии не может остаться безнаказанным. Повторяю, месье: сдайте оружие и дальше решайте вопрос с губернатором.";
			link.l1 = "У меня сейчас безотлагательное дело, лейтенант. Когда я его выполню, то буду в полном распоряжении вашего губернатора. А сейчас позвольте удалиться.";
			link.l1.go = "LeitenantRes_4";
		break;


		case "LeitenantRes_4":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("LeitenSenPier"));
		sld = characterFromID("LeitenSenPier");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "В таком случае я вынужден применить силу. (подаёт знак солдатам)";
			link.l1 = "Попробуйте.";
			link.l1.go = "LeitenantRes_5";
		break;


		case "LeitenantRes_5":
			DialogExit();
			AddDialogExitQuest("BordelGirl_31");
		break;


		case "DuParke_1":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("DuParke"));
		sld = characterFromID("DuParke");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Месье Валинье, мне доложили, что ваши люди вступили в конфликт с городской стражей. (Осматриваясь) То беззаконие, которое вы творите в Сен-Пьере не может быть оправдано никакими полномочиями....";
			link.l1 = "";
			link.l1.go = "DuParke_2";
		break;



		case "DuParke_2":
			DialogExit();
			AddDialogExitQuest("BordelGirl_33");
		break;


		case "DuParke_3":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("DuParke"));
		sld = characterFromID("DuParke");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Если понадобится я отвечу перед Королём, но не перед вами. Пока я здесь губернатор, поэтому извольте подчи....";
			link.l1 = "Надеюсь, это ненадолго. Соответствующий доклад уже послан мной Его Преосвященству. А сейчас я тороплюсь, вы и так уже сделали всё возможное, чтобы задержать меня. Моё оружие и оружие моих людей вы не получите, и в случае нашей гибели вы, губернатор, окажетесь вне закона, а нам на смену придёт королевская эскадра. Что это для вас будет означать, я думаю, вы  и сами понимаете. (галантно раскланивается и уходит, губернатор даёт сигнал пропустить Валинье и его людей)";
			link.l1.go = "DuParke_4";
		break;


		case "DuParke_4":
			DialogExit();
			AddDialogExitQuest("BordelGirl_35");
		break;


		case "GuardManTown_1":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("GuardManTown"));
		sld = characterFromID("GuardManTown");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Монсеньор, только что группа вооружённых людей проследовала за городские ворота. Согласно вашему приказу отряд гвардейцев, расположенных у входа в город, постарается их задержать.";
			link.l1 = "Каналья! Немедленно за городские ворота!";
			link.l1.go = "GuardManTown_2";
		break;


		case "GuardManTown_2":
			DialogExit();
			AddDialogExitQuest("BordelGirl_38");
		break;


		case "DuParke_5":
		sld = characterFromID("AnnettduParke");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("DuParke"));
		sld = characterFromID("DuParke");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("AnnettduParke"));
			dialog.text = "Я думал...Я боялся потерять вас навсегда...Теперь я сделаю всё, чтобы этого не повторилось. Обещаю тебе.";
			link.l1 = "";
			link.l1.go = "DuParke_6";
		break;


		case "DuParke_6":
			DialogExit();
			AddDialogExitQuest("GuberWife_36");
		break;


		case "DuParke_7":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("DuParke"));
		sld = characterFromID("DuParke");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "(Подчёркнуто сухо и отстранённо) Господа, я вам весьма признателен за ту роль, которую вы сыграли в деле освобождения моей семьи, и вы всегда можете рассчитывать на мою благосклонность. А теперь нам пора. (К жене и дочери) Идёмте, мои дорогие.";
			link.l1 = "";
			link.l1.go = "DuParke_8";
		break;


		case "DuParke_8":
			DialogExit();
			AddDialogExitQuest("GuberWife_37");
		break;


		


		//пираты с пленным испанцем
		case "CaptivePirate":
			pchar.quest.Captive_CreatePiratesOver.over = "yes";//снять таймер
			dialog.text = "Ты кто такой? Что тебе здесь надо? А ну, проваливай, живо!";
			link.l1 = "Что-то вы не сильно вежливы, сударь.";
			link.l1.go = "CaptivePirate_1";
		break;
		
		case "CaptivePirate_1":
			dialog.text = "Послушай, пижон, я вежливости не обучен, как и грамоте, но вот саблей по голове огреть, или пару новых дырок в тебе проделать - это запросто. И, клянусь громом, я это сделаю, если ты сию минуту не уберёшься отсюда. Ты понял?";
			link.l1 = "А теперь ты послушай, олух. Ваш заговор раскрыт. Мне нужен этот пленник. Сопротивление бесполезно - в джунглях отряд французских солдат. Если будете бежать достаточно быстро, то, возможно, вам удастся спасти свои жалкие жизни.";
			link.l1.go = "CaptivePirate_3";
			link.l2 = "Ладно-ладно, не кипятись. Я ухожу.";
			link.l2.go = "CaptivePirate_2";
		break;
		
		case "CaptivePirate_2":
			chrDisableReloadToLocation = false;
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			DialogExit();
			n = makeint(MOD_SKILL_ENEMY_RATE/2);
			if (n <= 1) n = 2;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("CaptivePirate_"+i);
				LAi_CharacterDisableDialog(sld);
				LAi_SetImmortal(sld, true);
				sld.lifeday = 0;
			}
			sld = characterFromId("CaptiveSpain");
			LAi_SetImmortal(sld, true);
			sld.lifeday = 0;
			pchar.quest.Sharlie_captive1.over = "yes";
			pchar.quest.Sharlie_captive2.over = "yes";//снять прерывание
			AddQuestRecord("SharlieD", "5");
			CloseQuestHeader("SharlieD");
			DeleteAttribute(pchar, "questTemp.Sharlie.Captive");
			pchar.questTemp.Sharlie = "bankskipermoney";
		break;
		
		case "CaptivePirate_3":
			dialog.text = "Что-о? Да ты блефуешь, дружок! Но в любом случае, ты умрёшь первым! Ребята, к оружию!";
			link.l1 = "Ну, держитесь, ублюдки...";
			link.l1.go = "CaptivePirate_4";
		break;
		
		case "CaptivePirate_4":
			DialogExit();
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false);
			int n = makeint(MOD_SKILL_ENEMY_RATE/2);
			if (n <= 1) n = 2;
			for (i=1; i<=n; i++)
			{
				sld = characterFromId("CaptivePirate_"+i);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "EnemyFight");
			}
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("EnemyFight", "Captive_PiratesDead");
			AddDialogExitQuest("MainHeroFightModeOn");	
			sld = characterFromId("CaptiveSpain");
			LAi_SetCitizenType(sld);
		break;
		
		//пленный испанец
		case "CaptiveSpain":
			dialog.text = "Карамба! Ты француз? Ловко ты отделал этих мерзавцев. Но не думай, что я так просто сдамся!";
			link.l1 = "Постойте... послушайте, я не...";
			link.l1.go = "CaptiveSpain_1";
		break;
		
		case "CaptiveSpain_1":
			dialog.text = "От французов, кроме тюрьмы, мне ждать нечего. Я снял саблю с одного из трупов, пока ты дрался с последним пиратом... Защищайся, лягушатник!";
			link.l1 = "Вот тупой осёл!";
			link.l1.go = "CaptiveSpain_2";
		break;
		
		case "CaptiveSpain_2":
			DialogExit();
			LAi_SetPlayerType(pchar);
			NextDiag.currentnode = "CaptiveSpain_3";
			LAi_SetWarriorType(npchar);
			LAi_group_MoveCharacter(npchar, "EnemyFight");
			LAi_group_SetRelation("EnemyFight", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("EnemyFight", LAI_GROUP_PLAYER, true);
			LAi_SetCheckMinHP(npchar, 10.0, true, "CaptiveSpain_capture");
			AddDialogExitQuest("MainHeroFightModeOn");	
		break;
		
		case "CaptiveSpain_3":
			dialog.text = "Аргх... Ты победил. Я сдаюсь, проклятый француз. Делай теперь со мной, что хочешь - я в твоей власти.";
			link.l1 = "Брось оружие и дай наконец мне сказать, упрямый кастилец! Мне не нужна твоя смерть! И в тюрьму я тебя не отправлю!";
			link.l1.go = "CaptiveSpain_4";
			RemoveCharacterEquip(npchar, BLADE_ITEM_TYPE);
		break;
		
		case "CaptiveSpain_4":
			dialog.text = "Так что же тебе от меня нужно? Зачем ты тогда убил пиратов? И где твои солдаты?";
			link.l1 = "Нет никаких солдат. Я попытался напугать негодяев, но, как видишь, ничего не вышло. Я действовал в одиночку, по просьбе твоего старого друга. Его зовут "+pchar.questTemp.Sharlie.Captive.Name+", он ростовщик в Сен-Пьере.";
			link.l1.go = "CaptiveSpain_5";
		break;
		
		case "CaptiveSpain_5":
			dialog.text = ""+pchar.questTemp.Sharlie.Captive.Name+"? Я не знаю такого. Впервые слышу это имя!";
			link.l1 = "И тем не менее, о тебе, твоём пленении и передаче тебя на английское судно мне стало известно от него. У меня задача доставить тебя к нему, и, клянусь, я её выполню! Так что если тебе жизнь дорога, следуй за мной безо всяких фокусов.";
			link.l1.go = "CaptiveSpain_6";
		break;
		
		case "CaptiveSpain_6":
			dialog.text = "У меня в любом случае нет выбора... Возможно, твой ростовщик будет всё же лучше английских собак...";
			link.l1 = "Ты наконец-то стал разумно рассуждать. А теперь довольно болтовни - мы отправляемся в Сен-Пьер. Держись ко мне поближе и не вздумай бежать - всё равно догоню!";
			link.l1.go = "CaptiveSpain_7";
		break;
		
		case "CaptiveSpain_7":
			chrDisableReloadToLocation = false;
			DeleteAttribute(pchar, "GenQuest.Notsearchbody"); // 170712
			DialogExit();
			AddQuestRecord("SharlieD", "6");
			LAi_group_Register("TempFriends");
			LAi_group_SetRelation("TempFriends", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_MoveCharacter(npchar, "TempFriends");
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			SetNationRelation2MainCharacter(FRANCE, RELATION_ENEMY);
			pchar.quest.Sharlie_captive3.win_condition.l1 = "locator";
			pchar.quest.Sharlie_captive3.win_condition.l1.location = "Fortfrance_town";
			pchar.quest.Sharlie_captive3.win_condition.l1.locator_group = "reload";
			pchar.quest.Sharlie_captive3.win_condition.l1.locator = "reload8_back";
			pchar.quest.Sharlie_captive3.win_condition.l2 = "Night";
			pchar.quest.Sharlie_captive3.win_condition.l3 = "Alarm";
			pchar.quest.Sharlie_captive3.win_condition.l3.value = 0;
			pchar.quest.Sharlie_captive3.win_condition.l3.operation = "=";
			pchar.quest.Sharlie_captive3.function = "CaptiveSpain_reload";//вход ночью
			pchar.questTemp.Sharlie = "bankskipercaptive";
		break;
		
		//горожанин с пропавшей дочерью
		case "Prosper":
			pchar.quest.Sharlie_RescueDaughter.over = "yes"; //снять прерывание
			dialog.text = "Я видел, как эти краснокожие ублюдки прикончили его пару минут назад. Они тоже хотели что-то найти в его карманах, но вы их спугнули, месье.";
			link.l1 = "Кто вы и как здесь оказались?";
			link.l1.go = "Prosper_1";
		break;
		
		case "Prosper_1":
			dialog.text = "Моё имя Проспер Трубаль. Я ищу свою пропавшую дочь Селину. Она - служанка госпожи ду Парке, жены нашего губернатора. Несколько дней назад она бесследно исчезла.";
			link.l1 = "Сочувствую вам, месье. Моё имя Шарль де Мор.";
			link.l1.go = "Prosper_2";
		break;
		
		case "Prosper_2":
			dialog.text = "А эти люди, что с вами? Я слышал шум боя рядом с городскими воротами.";
			link.l1 = "Это отряд гвардейцев кардинала. А этот человек...";
			link.l1.go = "Prosper_exit1";
		break;


		case "Prosper_exit1":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_45");
			break;
		
		case "Prosper_3":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Да, месье, я провёл в этих чёртовых джунглях последние несколько дней. Но всё по порядку. Сперва я направился выяснить, где моя дочь, к мадам ду Парке. Но в резиденции губернатора меня выставили за дверь, сказав, что моя дочь 'очень занята'. На следующий день повторилось то же самое, но теперь я получил предупреждение, что если буду дальше докучать, то меня посадят в тюрьму. Тогда мне ничего не осталось, как пытаться самому выяснить, что произошло.\n За щедрую выпивку в таверне пара стражников проболталась, что в день исчезновения мадам ду Парке с дочерью прогуливались за воротами, Селина же как обычно их сопровождала. Более того, стражники сказали, что она возвращалась за зонтиком, который позабыла её хозяйка. И после этого мою дочь никто не видел. Я взял мушкет и немедленно отправился в джунгли, туда, где обычно гуляют мадам ду Парке с дочерью, но ничего не обнаружил. В отчаянии я стал бродить по джунглям в окрестностях города, и удача мне улыбнулась. Хотя (тяжело вздыхает) едва ли я могу говорить об удаче.\n Я нашёл шарфик Селины...(пытается сдержать слёзы) Это место чуть севернее отсюда... рядом с пещерой, где обосновались эти краснокожие ублюдки! (сжимает кулаки) Теперь я слежу за ними, стараясь обнаружить хоть какие-то следы своей дочери. Два ублюдка, которые прикончили этого бедолагу, (показывает на труп Кабаля) пришли оттуда. Вот моя история.";
			link.l1 = "Наш долг помочь вам, месье Трубаль.";
			link.l1.go = "Prosper_4";
		break;
		
		case "Prosper_4":
			dialog.text = "О, месье, я не смел даже надеяться и просить вас об этом. Один я никогда бы не смог освободить свою дочь, если, конечно...(ему трудно говорить) она ещё жива. Ну тогда хоть отомстим этим нехристям!";
			link.l1 = "(Шарль сигнализирует Валинье, что хочет с ним что-то обсудить) Конечно, месье Трубаль, мы немедленно выдвигаемся.";
			link.l1.go = "Prosper_exit2";
		break;

		case "Prosper_exit2":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_47");
			break;
		
		case "Prosper_5":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Позвольте спросить, месье Валинье, вы занимаетесь поисками мадам ду Парке и её дочери?";
			link.l1 = "Ну,  можно и так сказать. А почему вы вообще думаете, что их надо искать?";
			link.l1.go = "Prosper_6";
		break;
		
		case "Prosper_6":
			dialog.text = "Ну как же? Насколько я понимаю, их тоже никто больше не видел.";
			link.l1 = "Вы говорите, что осмотрели в джунглях место их обычной прогулки? И ничего не обнаружили?";
			link.l1.go = "Prosper_7";
		break;
		
		case "Prosper_7":
			dialog.text = "В том-то и дело, месье. Ничего. Никаких следов борьбы или боя. А ведь их всегда сопровождала пара солдат.";
			link.l1 = "Да, это странно. Но не будем терять время. Показывайте дорогу к пещере с дикарями.";
			link.l1.go = "Prosper_exit3";
		break;


		case "Prosper_exit3":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_50");
			break;
		
		//case "Prosper_exit":
		//	dialog.text = "Вы издеваетесь? Нет! Да у вас просто дрожат коленки! Убирайтесь к чёрту! Трус...";
		//	link.l1 = "Эй-эй, полегче!";
		//	link.l1.go = "Prosper_exit_1";
		//break;
		
		//case "Prosper_exit_1":
		//	DialogExit();
		//	npchar.lifeday = 0;
		//	LAi_SetActorType(npchar);
		//	LAi_ActorGoToLocation(npchar, "reload", "gate_back", "none", "", "", "", 10.0);
		//	CloseQuestHeader("SharlieF");
		//break;
		
		case "Prosper_8":
			dialog.text = "Мерзкие ублюдки получили по заслугам! Скорее спускаемся в пещеру!";
			link.l1 = "Да, нельзя медлить!";
			link.l1.go = "Prosper_exit4";
		break;


		case "Prosper_exit4":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_54a");
		break;
		
		case "Prosper_9":
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Selina"));
		sld = characterFromID("RD_Selina");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
			dialog.text = "(плачет) Девочка моя!...Ты жива!...(прижимает дочь к груди)";
			link.l1 = "";
			link.l1.go = "Prosper_exit5";
		break;

		case "Prosper_exit5":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_61");
		break;
		
		case "Prosper_10":
			DialogExit();
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			AddQuestRecord("SharlieF", "3");
			pchar.quest.Sharlie_RescueDaughter1.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter1.win_condition.l1.location = "Martinique_jungle_04";
			pchar.quest.Sharlie_RescueDaughter1.function = "RescueDaughter_NearCave";
			//pchar.quest.Sharlie_RescueDaughter2.win_condition.l1 = "Timer";
			//pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.hour  = sti(GetTime()+2);
			//pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
			//pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
			//pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
			//pchar.quest.Sharlie_RescueDaughter2.function = "RescueDaughter_CaveOver";
			NextDiag.CurrentNode = "Prosper_11";
			pchar.questTemp.Sharlie.RescueDaughter = "true";
		break;
		
		case "Prosper_11":
			dialog.text = "Я вам безмерно благодарен, месье. Вы спасли меня и мою дочь. Не знаю, что со мной было, если бы не стало моей девочки.";
			link.l1 = "Мы сделали только то, что должны были сделать, но я слышу звуки боя снаружи. Оставайтесь с дочерью, а я поспешу на помощь Грегуару.";
			link.l1.go = "Prosper_12";
		break;
		
		case "Prosper_12":
			dialog.text = "Нет, месье де Мор. Будем пробиваться вместе. Идём, Селина.";
			link.l1 = "И то верно, дело ещё не окончено. Вперёд.";
			link.l1.go = "Prosper_exit6";
		break;


		case "Prosper_exit6":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_62");
		break;
		
		case "Prosper_13":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "Монсеньор, ещё раз хочу выразить вам с месье де Мором свою огромную признательность за спасение моей дочери. Я не богат, поэтому не смогу достойно отплатить вам золотой монетой,  но если понадобится мой мушкет или любая другая помощь, вы знаете где меня найти.";
			link.l1 = "Ещё раз хочу повторить, что мы с месье де Мором лишь выполняли свой долг. А теперь, когда мы наконец-то в безопасности, позвольте задать пару вопросов вашей дочери.";
			link.l1.go = "Prosper_exit7";
		break;


		case "Prosper_exit7":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_70");
			break;
		
		case "Prosper_14":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "";
			link.l1 = "Месье Трубаль, не смею больше задерживать вас и вашу дочь. Но, как вы уже поняли, ситуация весьма тревожная и неопределённая. Очевидно, что в похищении жены и дочери губернатора замешана часть гарнизона Сен-Пьера. В связи с этим у меня к вам просьба пока никому не рассказывать о том, что произошло. И не стоит пока идти к губернатору.";
			link.l1.go = "Prosper_15";
		break;
		
		
		
		case "Prosper_15":
			dialog.text = "Я всё понимаю, монсеньор. Да и, как я вам уже говорил, мне пригрозили тюрьмой, если я туда ещё сунусь. Можете на меня полностью положиться, и я всегда к вашим услугам.";
			link.l1 = "Тогда всего доброго и берегите вашу дочь, месье Трубаль.";
			link.l1.go = "Prosper_exit8";
		break;

		case "Prosper_exit8":
		    DialogExit();
			AddDialogExitQuest("BordelGirl_72");
			break;
		
		case "Prosper_17":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			LocatorReloadEnterDisable("Martinique_CaveEntrance", "reload1_back", false);
			AddComplexSelfExpToScill(20, 20, 20, 20);
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter2.win_condition.l1.location = "Martinique_Grot";
			pchar.quest.Sharlie_RescueDaughter2.function = "RescueDaughter_CreateIndiansGrot";
			NextDiag.CurrentNode = "Prosper_18";
		break;
		
		case "Prosper_18":
			dialog.text = "Моя дочь жива! Слава Богу! Мы успели вовремя, "+pchar.name+". Я в долгу перед вами. Вы отважный человек и хороший боец. Я восхищён!";
			link.l1 = "Тогда всего доброго и берегите вашу дочь, месье Трубаль.";
			link.l1.go = "Prosper_19";
		break;
		
		case "Prosper_19":
			DialogExit();
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 0, 0);
			AddComplexSelfExpToScill(30, 30, 30, 30);
		break;
		
		case "Prosper_20":
			dialog.text = "Ещё раз огромное спасибо, "+pchar.name+"! Давайте теперь все вместе вернёмся в город. Жизнь моей дочери бесценна, и никакими деньгами это не измерить, но я всё же хочу отблагодарить вас, подарив остатки своих сбережений. Как только мы придём в Сен-Пьер - я с радостью отдам вам их. И не вздумайте отказываться!";
			link.l1 = "Не откажусь, Проспер. Хотя я помогал вам вовсе не из-за денег.";
			link.l1.go = "Prosper_21";
		break;
		
		case "Prosper_21":
			dialog.text = "Вы благородный человек, "+pchar.name+"! А теперь давайте не будем здесь задерживаться и отправимся домой.";
			link.l1 = "...";
			link.l1.go = "Prosper_22";
		break;
		
		case "Prosper_22":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetImmortal(npchar, true);
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
			sld = characterFromId("RD_Jilberte");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
		break;
		
		case "Prosper_23":
			SelectPresentAmulet();
			dialog.text = "Вот мы и пришли. Шарль, я ещё раз благодарю вас за помощь и присоединяю к словам вот эту скромную сумму в песо и мешочек золотых дублонов. Это немного за такую услугу, но зато от чистого сердца. Также возьмите вот этот амулет - "+pchar.questTemp.SMQ.Text+"";
			link.l1 = "Спасибо. Прощайте, Проспер, желаю вам и вашей милой дочке счастья!";
			link.l1.go = "Prosper_24";
		break;
		
		case "Prosper_24":
			AddMoneyToCharacter(pchar, 5000);
			TakeNItems(pchar, "gold_dublon", 15);
			TakeNItems(pchar, pchar.questTemp.SMQ.Amulet, 1);
			Log_Info("Вы получили 15 дублонов");
			Log_Info("Вы получили амулет");
			PlaySound("interface\important_item.wav");
			dialog.text = "Ей бы мужа такого, как вы, а то бегают за ней всякие тонконогие хлыщи, а как беда пришла - так все и исчезли куда-то... Эх, ладно. Удачи, Шарль!";
			link.l1 = "...";
			link.l1.go = "Prosper_25";
		break;
		
		case "Prosper_25":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload10_back", "none", "", "", "", 10.0);
			sld = characterFromId("RD_Selina");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload10_back", "none", "", "", "", 10.0);
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterComplexReputation(pchar,"authority", 2);
			AddCharacterExpToSkill(pchar, "Leadership", 120);//авторитет
			AddCharacterExpToSkill(pchar, "Fortune", 70);//везение
			AddCharacterExpToSkill(pchar, "Sneak", 70);//скрытность
			AddQuestRecord("SharlieF", "7");
			CloseQuestHeader("SharlieF");
			DeleteAttribute(pchar, "questTemp.SMQ");
			pchar.questTemp.Prosper_fmql = "true"; // Addon-2016 Jason, французские миниквесты (ФМК)
		break;
		
		case "Selina":
		sld = characterFromID("RD_Prosper");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Selina"));
		sld = characterFromID("RD_Selina");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Prosper"));
			dialog.text = "(плачет) Папочка!!! Я знала, что ты придёшь за мной! (бросается на шею Трубаля)";
			link.l1 = "";
			link.l1.go = "Selina_exit1";
		break;

		case "Selina_exit1":
			DialogExit();
			AddDialogExitQuest("BordelGirl_60");
		break;
		
		case "Selina_1":
		sld = characterFromID("Valinie");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("RD_Selina"));
		sld = characterFromID("RD_Selina");
        Lai_SetActorType(sld);
        LAi_ActorTurnToCharacter(sld, characterFromID("Valinie"));
			dialog.text = "";
			link.l1 = "Селина, расскажи нам, что с тобой произошло? Как ты попала в руки дикарей?";
			link.l1.go = "Selina_2";
		break;
		
		//case "Selina_2":
		//	DialogExit();
		//	LAi_SetActorType(npchar);
		//	LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_2", "", 5.0);
		//	sld = characterFromId("RD_Prosper");
		//	LAi_SetActorType(sld);
		//	LAi_ActorGoToLocation(sld, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_1", "", 5.0);
		//	AddQuestRecord("SharlieF", "5");
		//	sld = characterFromId("RD_Jilberte");
		//	LAi_SetStayType(sld);
		//break;
		
		case "Selina_2":
			dialog.text = "Ах, месье. (плачет) Несколько дней назад мадам ду Парке с дочерью как обычно отправились на прогулку за город, и я их сопровождала. Когда мы удалились от городских ворот, мадам обнаружила, что её зонтик был повреждён, и отправила меня за запасным. Но только по пути я вспомнила, что прошлый раз его не видела на своём обычном месте. Возможно, госпожа переложила его или отдала одной из своих подруг. В общем, уже предвкушая её недовольство моей нерасторопностью, я направилась обратно, чтобы узнать у госпожи, где запасной зонтик. Но...я не обнаружила их на обычном месте прогулки.\n Тогда я побежала дальше в джунгли и...(плачет) увидела ужасную картину. Двое стражников, которые должны были охранять мадам и её дочь, тащили их без чувств вглубь джунглей в окружении каких-то других солдат...";
			link.l1 = "Они тоже выглядели как солдаты гарнизона?";
			link.l1.go = "Selina_3";
		break;
		
		case "Selina_3":
			dialog.text = "Да, месье. Но, признаться, я долго их не рассматривала. Я очень испугалась. Сперва я быстро побежала к городским воротам чтобы поднять тревогу, но потом...я подумала, а вдруг и другая стража тоже...я была так напугана. Некоторое время я просто сидела и плакала...И даже не заметила, как подкрались эти мерзкие дикари. Они оглушили меня и приволокли в пещеру.";
			link.l1 = "Что им было от тебя нужно?";
			link.l1.go = "Selina_4";
		break;
		
		case "Selina_4":
			dialog.text = "Не знаю, месье. (плачет) Я даже думала, что лучше бы они меня сразу убили....Больше я ничего не знаю.";
			link.l1 = "Не буду тебя больше пытать, Селина. Вижу, ты едва держишься на ногах. Выздоравливай и спасибо тебе.";
			link.l1.go = "Selina_exit2";
		break;


		case "Selina_exit2":
			DialogExit();
			AddDialogExitQuest("BordelGirl_71");
		break;
		
		case "Selina_6":
			dialog.text = "(сквозь слезы) Да... Жильберт Курси. Он там... он до сих пор ещё не пришёл в себя. Поговорите с ним... И давайте побыстрее уйдём отсюда!";
			link.l1 = "Да, конечно. Мы ни на одну лишнюю минуту не останемся здесь.";
			link.l1.go = "Selina_7";
		break;
		
		case "Selina_7":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_2", "", 5.0);
			AddQuestRecord("SharlieF", "6");
			sld = characterFromId("RD_Jilberte");
			LAi_SetStayType(sld);
			AddComplexSelfExpToScill(20, 20, 20, 20);
		break;
		
		case "Selina_8":
			dialog.text = "Мой отец... Мой бедный отец! Ах, месье, я даже не поблагодарила вас за спасение...";
			link.l1 = "Я просто рад, Селина, что ты и Жильберт остались живы. Во всяком случае, героическая смерть твоего отца не была напрасной.";
			link.l1.go = "Selina_9";
		break;
		
		case "Selina_9":
			dialog.text = "(плачет) Пожалуйста, месье, проведите нас до города. Надо, чтобы сюда пришли солдаты и забрали тело отца, чтобы похоронить по-христиански...";
			link.l1 = "Конечно, Селина. Следуйте за мной!";
			link.l1.go = "Selina_10";
		break;
		
		case "Selina_10":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorFollowEverywhere(npchar, "", -1);
			sld = characterFromId("RD_Jilberte");
			LAi_SetActorType(sld);
			LAi_ActorFollowEverywhere(sld, "", -1);
		break;
		
		case "Selina_11":
			dialog.text = "Спасибо вам, месье, за то, что пошли с моим бедным отцом... Спасибо за то, что спасли меня от неминуемой смерти. Я... я... вот, возьмите этот мешочек с дублонами. Я нашла его дома в сундуке отца. И даже не вздумайте отказываться!";
			link.l1 = "Хорошо, Селина. Я рад, что нам удалось спасти тебя, и искренне соболезную тебе по поводу смерти твоего отца.";
			link.l1.go = "Selina_12";
		break;
		
		case "Selina_12":
			TakeNItems(pchar, "gold_dublon", 15);
			PlaySound("interface\important_item.wav");
			dialog.text = "Вы благородный человек, месье. Я никогда не забуду вас. Прощайте!";
			link.l1 = "Прощай, Селина.";
			link.l1.go = "Selina_13";
		break;
		
		case "Selina_13":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload10_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			ChangeCharacterComplexReputation(pchar, "nobility", 3);
			ChangeCharacterComplexReputation(pchar,"authority", 1);
			AddCharacterExpToSkill(pchar, "Leadership", 100);//авторитет
			AddCharacterExpToSkill(pchar, "Fortune", 50);//везение
			AddCharacterExpToSkill(pchar, "Sneak", 50);//скрытность
			AddQuestRecord("SharlieF", "8");
			CloseQuestHeader("SharlieF");
		break;
		
		case "Jilberte":
			PlaySound("Voice\Russian\other\robinzons-08.wav");
			dialog.text = "Господи, неужели всё позади? Я даже не верю... Вы спасли и меня, и Селину. Если бы вы не пришли, завтра её бы постигла участь несчастного Сезара, а через несколько дней то же было бы уготовано и мне.";
			link.l1 = "Эти индейцы - они что, действительно людоеды?!";
			link.l1.go = "Jilberte_1";
		break;
		
		case "Jilberte_1":
			dialog.text = "А вы что, сомневаетесь? Хотите - поройтесь в золе их костра. Думаю, вы там найдёте что-нибудь от бедняги Сезара. Пару обглоданных костей, например...";
			link.l1 = "Б-р-р... Нет уж, увольте. Просто я совсем недавно из Европы, и даже не предполагал, что на нашей Земле творятся такие мерзости.";
			link.l1.go = "Jilberte_2";
		break;
		
		case "Jilberte_2":
			dialog.text = "На Карибах происходит много такого, о чем в вашей Европе даже и слыхом не слыхивали... Индейские колдуны, шаманы, тайные обряды. Поживите у нас подольше - и не такого насмотритесь. Впрочем, простите меня, я так и не поблагодарил вас за спасение - я до сих пор в шоке\nВы спасли мою жизнь, и я намерен выразить свою глубокую признательность за это не только словами, но и звонкой монетой. Проводите меня и Селину до города. Там я смогу отблагодарить вас, как вы того заслуживаете, месье.";
			link.l1 = "Хорошо. Ступайте наружу, а я ещё тут немного осмотрюсь.";
			link.l1.go = "Jilberte_3";
		break;
		
		case "Jilberte_3":
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload1_back", "Martinique_CaveEntrance", "officers", "reload1_3", "OpenTheDoors", 10.0);
			pchar.quest.Sharlie_RescueDaughter5.win_condition.l1 = "location";
			pchar.quest.Sharlie_RescueDaughter5.win_condition.l1.location = "Martinique_CaveEntrance";
			pchar.quest.Sharlie_RescueDaughter5.function = "RescueDaughter_GoHome";
		break;
		
		case "Jilberte_4":
			dialog.text = "Позвольте ещё раз выразить вам свою глубокую благодарность за спасение, месье! Как я и обещал - присоединяю к словесной благодарности благодарность материальную, в серебряных песо и золотых дублонах.";
			link.l1 = "Я рад, что всё закончилось хорошо, Жильберт.";
			link.l1.go = "Jilberte_5";
		break;
		
		case "Jilberte_5":
			AddMoneyToCharacter(pchar, 3000);
			TakeNItems(pchar, "gold_dublon", 20);
			Log_Info("Вы получили 20 дублонов");
			PlaySound("interface\important_item.wav");
			dialog.text = "А как я-то этому рад, вы не представляете! Спасибо ещё раз и позвольте откланяться, месье.";
			link.l1 = "Удачи, Жильберт!";
			link.l1.go = "Jilberte_6";
		break;
		
		case "Jilberte_6":
			chrDisableReloadToLocation = false;
			DialogExit();
			LAi_SetActorType(npchar);
			LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "", 10.0);
			npchar.lifeday = 0;
			DeleteAttribute(pchar, "questTemp.Sharlie.RescueDaughter");
		break;
		
		//замечание по обнаженному оружию от персонажей типа citizen
		case "CitizenNotBlade":
			dialog.text = NPCharSexPhrase(NPChar, "Послушайте, я, как гражданин этого города, прошу вас не ходить у нас с обнажённым клинком.", "Знаете, я, как гражданка этого города, прошу вас не ходить у нас с обнажённым клинком.");
			link.l1 = LinkRandPhrase("Хорошо.", "Ладно.", "Как скажете...");
			link.l1.go = "exit";
			NextDiag.TempNode = "First time";
			if (npchar.id == "GigoloMan") NextDiag.TempNode = "GigoloMan";
		break;
		
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
	}
}

void SelectPresentAmulet()
{
	switch (pchar.HeroParam.HeroType)
	{        
		case "HeroType_1":
			pchar.questTemp.SMQ.Amulet = "indian_7";
			pchar.questTemp.SMQ.Text = "он прибавляет выносливости и открывает второе дыхание.";
		break;
		
		case "HeroType_2":
			pchar.questTemp.SMQ.Amulet = "amulet_7";
			pchar.questTemp.SMQ.Text = "он повышает стойкость к ранениям в бою.";
		break;
		
		case "HeroType_3":
			pchar.questTemp.SMQ.Amulet = "indian_4";
			pchar.questTemp.SMQ.Text = "он увеличит силу удара вашего оружия.";
		break;
		
		case "HeroType_4":
			pchar.questTemp.SMQ.Amulet = "indian_1";
			pchar.questTemp.SMQ.Text = "он делает огнестрельное оружие намного убойнее.";
		break;
	}
}